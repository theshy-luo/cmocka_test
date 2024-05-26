#include "cmocka_unit_test_setup_teardown_demo.h"
/*cmocka 测试示例 判断answer 是否等于一个整数*/
static int setup(void **state) {
    int *answer = malloc(sizeof(int));
    assert_non_null(answer);
    *answer = 41;
    *state = answer;
    return 0;
}

static int teardown(void **state) {
    free(*state);
    return 0;
}

static void int_test_success(void **state) {
    int *answer = *state;
    assert_int_equal(*answer, 41);
}

int cmocka_unit_test_setup_teardown_demo()
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test_setup_teardown(int_test_success, setup, teardown),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}