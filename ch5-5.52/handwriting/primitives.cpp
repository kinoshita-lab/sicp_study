#include <string>
#include "primitives.h"
#include "cons_man.h"

/*
(define primitive-procedures
        (list 'cdr cdr)
        (list 'cons cons)
        (list 'null? null?)
	;;above from book -- here are some more
	(list '+ +)
	(list '- -)
	(list '* *)
	(list '= =)
	(list '/ /)
	(list '> >)
	(list '< <)
        ))
*/
enum 
{
    NumberOfPrimitives = 10,
};

struct PrimitiveProcedures
{
    std::string name;
    PrimitiveFunction primitiveFunction;
};

/**
(define primitive-procedures
        (list 'cdr cdr)
        (list 'cons cons)
        (list 'null? null?)
	;;above from book -- here are some more
	(list '+ +)
	(list '- -)
	(list '* *)
	(list '= =)
	(list '/ /)
	(list '> >)
	(list '< <)
        ))
*/
PrimitiveProcedures primitiveProcedures[NumberOfPrimitives] {
    {"car", car},
    {"cdr", cdr},
    {"null?", null_p_primitive},
    {"+", cons_num_add},
    {"*", cons_num_mul},
    {"-", cons_num_minus},
    {"=", cons_num_equal},
    {"/", cons_num_div},
    {">", cons_num_gt},
    {"<", cons_num_lt},
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
