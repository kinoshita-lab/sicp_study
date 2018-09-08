#include "compiled.h"
#include "global.h"
#include "types.h"
void compiled_code_entry() {
  assign(VAL, new SchemeDataType(SchemeDataType::Integer, 1));
  return;
}
