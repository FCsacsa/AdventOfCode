typedef void (*test)();

// not actually implemented in `test.c`
void register_tests();

void assert_int_equals(int exp, int val);
void assert_str_equals(char *exp, char *val);
void assert_ptr_equals(void *exp, void *val);
void assert_true(int val);
void assert_false(int val);

/**
 * Adds test to the tests that will be run.
 *
 * `test`: Test to be run.
 */
void register_test(test t);

/**
 * Basic main function, to run the tests.
 */
int main(int argc, char const *argv[]);
