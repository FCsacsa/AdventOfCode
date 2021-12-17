#include "test.h"

#include <stdio.h>
#include <string.h>

typedef void (*test)();

test tests[1024];
int passed = 0;
int test_nums = 0;
int failed = 0;

void assert_int_equals(int exp, int val){
  if (exp != val){
    failed = 1;
    printf(" \e[1;31mExpected: %d, but was: %d.\e[0m\n", exp, val);
  }
}
void assert_str_equals(char *exp, char *val){
  if (strcmp(exp, val) != 0){
    failed = 1;
    printf(" \e[1;31mExpected: '%s', but was: '%s'.\e[0m\n", exp, val);
  }
}
void assert_ptr_equals(void *exp, void *val){
  if (exp != val){
    failed = 1;
    printf(" \e[1;31mExpected: %u, but was: %u.\e[0m\n", exp, val);
  }
}
void assert_true(int val){
  if (val != 1){
    failed = 1;
    printf(" \e[1;31mExpected %d to be true(1).\e[0m\n", val);
  }
}
void assert_false(int val){
  if (val != 0){
    failed = 1;
    printf(" \e[1;31mExpected %d to be false(0).\e[0m\n", val);
  }
}

/**
 * Adds test to the tests that will be run.
 *
 * `test`: Test to be run.
 */
void register_test(test t){
  if (test_nums == 1024){
    printf("%s\n", "Too many tests registered.");
    assert(0 == 1);
  }
  tests[test_nums++] = t;
}

/**
 * Basic main function, to run the tests.
 */
int main(int argc, char const *argv[]){
  register_tests();

  for (int i = 0; i < test_nums; ++i) {
    printf("Test %4d:\n", i);
    failed = 0;
    tests[i]();
    if (failed = 0) {
      passed++;
      printf(" ->\e[1;32mPASSED\e[0m\n");
    } else {
      printf(" ->\e[1;31mFAILED\e[0m\n");
    }
  }
  printf("\nTests passed: %d/%d", passed, test_nums);
}
