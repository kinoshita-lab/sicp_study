#include <iostream>
#include "eval.h"
#include "types.h"
#include "global.h"
#include "env.h"
#include "syntax.h"
#include "eceval.h"
#include "stack.h"
#include "support.h"

using namespace std;


/**
 ev-self-eval
  (assign val (reg exp))
  (goto (reg continue))
*/
void ev_self_eval()
{
	registers[VAL] = registers[EXP];
    goto_with_label(registers[CONTINUE]);
}

/**
 ev-variable
  (assign val (op lookup-variable-value) (reg exp) (reg env))
  (goto (reg continue))
 */
void ev_variable()
{
	registers[VAL] = lookup_variable_value(registers[EXP], the_global_environment);
  goto_with_label(registers[CONTINUE]);
}

/**
ev-quoted
  (assign val (op text-of-quotation) (reg exp))
  (goto (reg continue))
  */
void ev_quoted()
{
	registers[VAL] = text_of_quotation(registers[EXP]);
    goto_with_label(registers[CONTINUE]);
}

/**
 ev-lambda
  (assign unev (op lambda-parameters) (reg exp))
  (assign exp (op lambda-body) (reg exp))
  (assign val (op make-procedure)
              (reg unev) (reg exp) (reg env))
  (goto (reg continue))
  */
void ev_lambda()
{
  assign(UNEV, lambda_parameters(registers[EXP]));
  assign(EXP, lambda_body(registers[EXP]));
  assign(VAL, make_procedure(registers[UNEV], registers[EXP], registers[ENV]));
   goto_with_label(registers[CONTINUE]);
}
/**
ev-application
  (save continue)
  (save env)
  (assign unev (op operands) (reg exp))
  (save unev)
  (assign exp (op operator) (reg exp))
  (assign continue (label ev-appl-did-operator))
  (goto (label eval-dispatch))
  */
void ev_application()
{
  s.save(registers[CONTINUE]);
  s.save(registers[ENV]);
  assign(UNEV, operands(registers[EXP]));
  s.save(registers[UNEV]);
  assign(EXP, operator_(registers[EXP]));
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_APPL_DID_OPERATOR"));
  goto_with_label("EVAL_DISPATCH");
}

/**
 ev-appl-did-operator
  (restore unev)
  (restore env)
  (assign argl (op empty-arglist))
  (assign proc (reg val))
  (test (op no-operands?) (reg unev))
  (branch (label apply-dispatch))
  (save proc)
*/
void ev_appl_did_operator()
{
  registers[UNEV] = s.restore();
  registers[ENV] = s.restore();
  assign(ARGL, empty_arglist());
  assign(PROC, registers[VAL]);
  if (no_operands_p(registers[UNEV])) {
    apply_dispatch();
  }

  s.save(registers[PROC]);

  ev_appl_operand_loop(); // (save procの後はev-appl-operand-loop)
}

/**
 ev-appl-operand-loop
  (save argl)
  (assign exp (op first-operand) (reg unev))
  (test (op last-operand?) (reg unev))
  (branch (label ev-appl-last-arg))
  (save env)
  (save unev)
  (assign continue (label ev-appl-accumulate-arg))
  (goto (label eval-dispatch))
 */
void ev_appl_operand_loop()
{
  s.save(registers[ARGL]);
  assign(EXP, first_operand(registers[UNEV]));
  if (last_operand_p(registers[UNEV])) {
    ev_appl_last_arg();
    return;
  }

  s.save(registers[ENV]);
  s.save(registers[UNEV]);
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_APPL_ACCUMULATE_ARG"));
  eval_dispatch();
}

/**
 ev-appl-accumulate-arg
  (restore unev)
  (restore env)
  (restore argl)
  (assign argl (op adjoin-arg) (reg val) (reg argl))
  (assign unev (op rest-operands) (reg unev))
  (goto (label ev-appl-operand-loop))
*/
void ev_appl_accumulate_arg()
{
  registers[UNEV] = s.restore();
  registers[ENV] = s.restore();
  registers[ARGL] = s.restore();
  assign(ARGL, adjoin_arg(registers[VAL], registers[ARGL]));
  assign(UNEV, rest_operands(registers[UNEV]));
  ev_appl_operand_loop();
}

/**
ev-appl-last-arg
  (assign continue (label ev-appl-accum-last-arg))
  (goto (label eval-dispatch))
  */
void ev_appl_last_arg()
{
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_APPL_ACCUM_LAST_ARG"));
  eval_dispatch();
}

/**
apply-dispatch
  (test (op primitive-procedure?) (reg proc))
  (branch (label primitive-apply))
  (test (op compound-procedure?) (reg proc))  
  (branch (label compound-apply))
  (goto (label unknown-procedure-type))
*/
void apply_dispatch()
{
  if (primitive_procedure_p(registers[PROC])) {
    primitive_apply();
    return;
  }

  if (compound_procedure_p(registers[PROC])) {
    compound_apply();
    return;
  }

  unknown_procedure_type();
}

/**
primitive-apply
  (assign val (op apply-primitive-procedure)
              (reg proc)
              (reg argl))
  (restore continue)
  (goto (reg continue))
*/
void primitive_apply()
{
  assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));
  registers[CONTINUE] = s.restore();
  goto_with_label(registers[CONTINUE]);
}

/**
compound-apply
  (assign unev (op procedure-parameters) (reg proc))
  (assign env (op procedure-environment) (reg proc))
  (assign env (op extend-environment)
              (reg unev) (reg argl) (reg env))
  (assign unev (op procedure-body) (reg proc))
  (goto (label ev-sequence))
*/
void compound_apply()
{
  assign(UNEV, procedure_parameters(registers[PROC]));
  assign(ENV, procedure_environment(registers[PROC]));
  assign(ENV, extend_environment(registers[UNEV], registers[ARGL], registers[ENV]));
  assign(UNEV, procedure_body(registers[PROC]));
  ev_sequence();
}

/**
ev-begin
  (assign unev (op begin-actions) (reg exp))
  (save continue)
  (goto (label ev-sequence))
*/
void ev_begin()
{
  assign(UNEV, begin_actions(registers[EXP]));
  s.save(registers[CONTINUE]);
  ev_sequence();
}

/**
ev-sequence
  (assign exp (op first-exp) (reg unev))
  (test (op last-exp?) (reg unev))
  (branch (label ev-sequence-last-exp))
  (save unev)
  (save env)
  (assign continue (label ev-sequence-continue))
  (goto (label eval-dispatch))
*/
void ev_sequence()
{
  assign(EXP, first_exp(registers[UNEV]));
  if (last_exp_p(registers[UNEV])) {
    ev_sequence_last_exp();
    return;
  }
  s.save(registers[UNEV]);
  s.save(registers[ENV]);
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_SEQUENCE_CONTINUE"));
  eval_dispatch();
}

/**
ev-sequence-continue
  (restore env)
  (restore unev)
  (assign unev (op rest-exps) (reg unev))
  (goto (label ev-sequence))
*/
void ev_sequence_continue()
{
  registers[ENV] = s.restore();
  registers[UNEV] = s.restore();
  assign(UNEV, rest_exps(registers[UNEV]));
  ev_sequence();
}

/**
ev-sequence-last-exp
  (restore continue)
  (goto (label eval-dispatch))
*/
void ev_sequence_last_exp()
{
  registers[CONTINUE] = s.restore();
  eval_dispatch();
}

/**
ev-if
  (save exp)
  (save env)
  (save continue)
  (assign continue (label ev-if-decide))
  (assign exp (op if-predicate) (reg exp))
  (goto (label eval-dispatch))
*/
void ev_if()
{
  s.save(registers[EXP]);
  s.save(registers[ENV]);
  s.save(registers[CONTINUE]);
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_IF_DECIDE"));
  assign(EXP, if_predicate(registers[EXP]));
  eval_dispatch();
}

/**
ev-if-decide
  (restore continue)
  (restore env)
  (restore exp)
  (test (op true?) (reg val))
  (branch (label ev-if-consequent))
*/
void ev_if_decide()
{
  registers[CONTINUE] = s.restore();
  registers[ENV] = s.restore();
  registers[EXP] = s.restore();

  if (true_p(registers[VAL])) {
    ev_if_consequent();
    return;
  }

  ev_if_alternative();  // (branch の後はev_if_alternative)
}

/**
ev-if-alternative
  (assign exp (op if-alternative) (reg exp))
  (goto (label eval-dispatch))
*/
void ev_if_alternative()
{
  assign(EXP, if_alternative(registers[EXP]));
  eval_dispatch();
}
/**
ev-if-consequent
  (assign exp (op if-consequent) (reg exp))
  (goto (label eval-dispatch))
*/
void ev_if_consequent()
{
  assign(EXP, if_consequent(registers[EXP]));
  eval_dispatch();
}

/**
ev-assignment
  (assign unev (op assignment-variable) (reg exp))
  (save unev)
  (assign exp (op assignment-value) (reg exp))
  (save env)
  (save continue)
  (assign continue (label ev-assignment-1))
  (goto (label eval-dispatch))
  */
void ev_assignment()
{
  assign(UNEV, assignment_variable(registers[EXP]));
  s.save(registers[UNEV]);
  assign(EXP, assignment_value(registers[EXP]));
  s.save(registers[ENV]);
  s.save(registers[CONTINUE]);
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_ASSIGNMENT_1"));
  goto_with_label("EVAL_DISPATCH");
}

/**
ev-assignment-1
  (restore continue)
  (restore env)
  (restore unev)
  (perform
   (op set-variable-value!) (reg unev) (reg val) (reg env))
  (assign val (const ok))
  (goto (reg continue))
*/
void ev_assignment_1()
{
  registers[CONTINUE] = s.restore();
  registers[ENV] = s.restore();
  registers[UNEV] = s.restore();
  set_variable_value(registers[UNEV], registers[VAL], registers[ENV]);
  assign(VAL, new SchemeDataType(SchemeDataType::String, "OK"));
  goto_with_label(registers[CONTINUE]);
}

/**
ev-definition
  (assign unev (op definition-variable) (reg exp))
  (save unev)
  (assign exp (op definition-value) (reg exp))
  (save env)
  (save continue)
  (assign continue (label ev-definition-1))
  (goto (label eval-dispatch))
  */
void ev_definition()
{
  assign(UNEV, definition_variable(registers[EXP]));
  s.save(registers[UNEV]);
  assign(EXP, definition_value(registers[EXP]));
  s.save(registers[ENV]);
  s.save(registers[CONTINUE]);
  assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "EV_DEFINITION-1"));
  eval_dispatch();
}

/**
ev-definition-1
  (restore continue)
  (restore env)
  (restore unev)
  (perform
   (op define-variable!) (reg unev) (reg val) (reg env))
  (assign val (const ok))
  (goto (reg continue))
*/
void ev_definition_1()
{
  registers[CONTINUE] = s.restore();
  registers[ENV] = s.restore();
  registers[UNEV] = s.restore();
  define_variable(registers[UNEV], registers[VAL], registers[ENV]);
  assign(VAL, new SchemeDataType(SchemeDataType::String, "OK"));
  goto_with_label(registers[CONTINUE]);
}
