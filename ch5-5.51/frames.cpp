#include "frames.h"
#include "cons_man.h"

SchemeDataType* first_frame(SchemeDataType* env)
{
    return car(env);
}

SchemeDataType* frame_variables(SchemeDataType* frame)
{
    return car(frame);
}

SchemeDataType* frame_values(SchemeDataType* frame)
{
    return cdr(frame);
}