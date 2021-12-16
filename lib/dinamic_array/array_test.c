#include "../test/test.h"
#include "dinamic_array.h"


typedef struct array *Array;

int main(int argc, char const *argv[]);

void creation_test(){
  Array array = create_array();
  assert_true(array != 0);
}

void register_tests(){
  register_test(creation_test);
}
