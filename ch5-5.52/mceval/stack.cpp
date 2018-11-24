#include <iostream>
#include "stack.h"
#include "global.h"

Stack::Stack()
{
    initialize();
}

void Stack::initialize()
{
    s = empty_stack;
    number_pushes = 0;
    max_depth = 0;
    current_depth = 0;
}

void Stack::print_statistics()
{
    using namespace std;
    cout << "number_pushes: " << number_pushes;
    cout << ", max_depth: " << max_depth << endl;;
}

void Stack::save(SchemeDataType* reg)
{
    if (reg->type == SchemeDataType::TypeId::Environment) {
        s.push(deepCopyOf(reg));
    } else {
        s.push(reg);
    }

    number_pushes++;
    current_depth = s.size();

    if (max_depth < number_pushes) {
        max_depth = number_pushes;
    }
}

void Stack::save(const int registerId)
{
    save(registers[registerId]);
}

SchemeDataType* Stack::restore()
{
    auto* r = s.top();
    s.pop();
    current_depth = s.size();

    return r;
}

void Stack::restore(const int registerId)
{
    auto* r = restore();
    registers[registerId] = r;
}