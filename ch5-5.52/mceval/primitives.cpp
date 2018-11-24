#include <string>
#include "primitives.h"
#include "cons_man.h"
#include "env.h"
#include "support.h"

enum 
{
    NumberOfPrimitives = 26,
};

struct PrimitiveProcedures
{
    std::string name;
    PrimitiveFunction primitiveFunction;
};

PrimitiveProcedures primitiveProcedures[NumberOfPrimitives] {
    {"car", car},
    {"cdr", cdr},
    {"null?", null_p_primitive},
    {"null_p", null_p_primitive},
    {"+", primitive_num_add},
    {"*", primitive_num_mul},
    {"-", primitive_num_minus},
    {"=", primitive_num_equal},
    {"/", primitive_num_div},
    {">", primitive_num_gt},
    {"<", primitive_num_lt},
    {"list", primitive_list},
    {"cons", primitive_cons},
    {"newline", primitive_newline}, 
    {"display", primitive_display},
    {"pair_p", primitive_pair_p},
    {"eq_p", primitive_eq_p},
    {"read", primitive_read},
    {"number_p", primitive_num_p},
    {"string_p", primitive_string_p},
    {"symbol_p", primitive_symbol_p},
    {"lookup_variable_value", lookup_variable_value},
    {"primitive_procedure_p", primitive_procedure_p},
    {"apply_primitive_proedure", apply_primitive_procedure},
    {"list_of_values", primitive_list_of_values},
    {"apply_primitive_procedure", primitive_apply}
};



SchemeDataType* primitive_procedure_names()
{
    SchemeDataType* r = new SchemeDataType(SchemeDataType::TypeId::Cons);

    for (auto i = 0; i < NumberOfPrimitives; ++i) {
        SchemeDataType* l = new SchemeDataType(SchemeDataType::TypeId::Symbol, 
            primitiveProcedures[i].name.c_str());
        r->cellValue->listPush(l);
    }

    return r;
}

SchemeDataType* primitive_procedure_objects()
{
     SchemeDataType* r = new SchemeDataType(SchemeDataType::TypeId::Cons);
    
    for (auto i = 0; i < NumberOfPrimitives; ++i) {

        SchemeDataType* l = new SchemeDataType(SchemeDataType::TypeId::Cons);
        l->cellValue->listPush(new SchemeDataType(SchemeDataType::TypeId::Symbol, std::string("primitive").c_str()));
        l->cellValue->listPush(new SchemeDataType(primitiveProcedures[i].primitiveFunction));
        r->cellValue->listPush(l);
    }

    return r;
}
