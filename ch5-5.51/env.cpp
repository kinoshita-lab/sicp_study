#include "global.h"
#include "cons_man.h"
#include "env.h"

void setup_environment()
{ 
	SchemeDataType* the_empty_environment = new SchemeDataType;
	SchemeDataType* primitive_procedure_names = new SchemeDataType;
	SchemeDataType* primitive_procedure_objects = new SchemeDataType;
	the_global_environment = extend_environment(primitive_procedure_names, primitive_procedure_objects, the_empty_environment);
}

/**
 * @todo length error checking
 */
SchemeDataType* extend_environment(SchemeDataType* const vars, SchemeDataType* const vals, SchemeDataType* const base_env)
{
	return cons(make_frame(vars, vals), base_env);
}

SchemeDataType* make_frame(SchemeDataType* const variables, SchemeDataType* const values)
{
	return cons(variables, values);
}

SchemeDataType lookup_variable_value(const RegisterType &reg)
{
	 return SchemeDataType();
}