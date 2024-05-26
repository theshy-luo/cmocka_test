#include "cmocka_unit_test_setup_teardown_demo.h"
#include "check_mock_fun_demo.h"
#include "dynamic_memory_demo.h"

int main(void)
{
    cmocka_unit_test_setup_teardown_demo();

    printf("======================================================\n");

    cmocka_unit_check_demo();

    printf("======================================================\n");

    dynamic_memory_demo();

    printf("======================================================\n");
    
    return 0;
}
