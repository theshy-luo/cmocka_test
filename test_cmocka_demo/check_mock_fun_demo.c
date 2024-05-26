#include "check_mock_fun_demo.h"
/*测试 cmocka check 输出期望参数和返回值*/
int mock_function_check_return(char **out)
{
    *out = (char *) mock();
    return (int) mock();
}

static void test_function(void **state)
{
    char *out = NULL;
    const char * const hel = "hello";

    will_return(mock_function_check_return, hel);
    will_return(mock_function_check_return, 42);

    assert_int_equal(mock_function_check_return(&out), 42);
    assert_ptr_equal(out, hel);
}

/*测试 cmocka check 输入期望参数
1.expect_value 宏为模拟函数 mock_function_check_input 的形参 a 设定了参数期望值42
2.紧接着调用模拟函数 mock_function_check_input 进行测试
*/
void mock_function_check_input(int a)
{
    check_expected(a);
}

static void test_check_parameter(void **state)
{
    expect_value(mock_function_check_input, a, 41);
    mock_function_check_input(41);
}

/*检查模拟函数调用顺序*/
static void mock_test_a_called(void)
{
    function_called();
}

static void mock_test_b_called(void)
{
    function_called();
}

static void test_does_succeed_for_expected(void **state)
{
    (void)state;
    expect_function_call(mock_test_a_called);
    expect_function_call(mock_test_b_called);

    mock_test_a_called();
    mock_test_b_called();
}
//忽略mock_test_b_called的调用
static void test_ordering_does_ignore_calls(void **state)
{
    (void)state;
    expect_function_call(mock_test_a_called);
    ignore_function_calls(mock_test_b_called);

    mock_test_a_called();
    mock_test_b_called();
    mock_test_b_called();
}


int cmocka_unit_check_demo()
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(test_function),
        cmocka_unit_test(test_check_parameter),
        cmocka_unit_test(test_does_succeed_for_expected),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}