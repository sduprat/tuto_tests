// test file for CallStackfile1
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <stdio.h>

#include "cmocka.h"

#include "file1.h"
#include "file2.h"

void test_f1__1(void **state)
{
    (void) state; /* unused */
    int ret;

    ret = f1(1);
    assert_int_equal(0, ret);

}

int fa(int x)
{
  return mock();
}


/*
 * scenario ok with 2 call to fa with success
 */
void test_f2__1(void **state)
{
    (void) state; /* unused */
    int ret;

    will_return(fa, 0);
    will_return(fa, 0);
    ret = f2(1);
    assert_int_equal(0, ret);

}

void test_f2__2(void **state)
{
    (void) state; /* unused */
    int ret;

    will_return(fa, 0);
    will_return(fa, 2);
    ret = f2(1);
    assert_int_equal(-1, ret);

}

const struct CMUnitTest do_something_tests[] = {
    cmocka_unit_test(test_f1__1),
    cmocka_unit_test(test_f2__1),
    cmocka_unit_test(test_f2__2),
};


int main(void)
{
    return cmocka_run_group_tests(do_something_tests, NULL, NULL);
}
