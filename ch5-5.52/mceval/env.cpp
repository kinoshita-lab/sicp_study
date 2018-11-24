#include <iostream>
#include <string>
#include <algorithm>

#include "env.h"
#include "global.h"
#include "cons_man.h"
#include "frames.h"
#include "user_print.h"
#include "primitives.h"
#include "global.h"

using namespace std;

void setup_environment()
{ 
	the_empty_environment = new SchemeDataType(SchemeDataType::TypeId::Environment);
	SchemeDataType* p_names = primitive_procedure_names();
	SchemeDataType* p_objs = primitive_procedure_objects();
  the_global_environment = extend_environment(p_names, p_objs, the_empty_environment);
  registers[ENV] = the_global_environment;
  registers[PROC] = registers[ENV];
}

SchemeDataType* extend_environment(SchemeDataType* const vars, SchemeDataType* const vals, SchemeDataType* const base_env)
{
  EnvironmentFrame frame;
  
  auto* variables = vars;
  if (!vals) {
    return base_env;
  }

  auto* values = vals;

  if (vars->type == SchemeDataType::TypeId::Cons) {
    while (true) {
      auto* var = car(variables);
      auto* val = car(values);

      if (null_p(var)) {
        break;
      }

      frame.push_front(new EnvironmentItem(var, val));
      variables = cdr(variables);
      values = cdr(values);
    }
  } else {
    frame.push_front(new EnvironmentItem(variables, car(values)));
  }

  base_env->environmentFrames.push_front(frame);

  return base_env;
}

SchemeDataType* lookup_variable_value(SchemeDataType* const var, SchemeDataType* const env)
{
    auto& frames = env->environmentFrames;

    for (auto&& frame : frames) {
        auto val_candidate = std::find_if(frame.begin(), frame.end(), [&](auto item) {
            return *(item->variable) == var;
        });

        if (val_candidate != frame.end()) {
            return (*val_candidate)->value;
        }
    }

    if (env != primitive_objects) {
      return lookup_variable_value(var, primitive_objects);
    }

    return new SchemeDataType();
}
