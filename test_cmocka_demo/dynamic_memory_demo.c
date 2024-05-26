#include "dynamic_memory_demo.h"

#define UNIT_TESTING

#ifdef UNIT_TESTING
#define malloc test_malloc
#define realloc test_realloc
#define calloc test_calloc
#define free test_free
#endif

//内存泄漏
void leak_memory(void **state) {
    int * const temporary = (int*)malloc(sizeof(int));
    *temporary = 0;
}

//访问越界
void buffer_overflow(void **state) {
    char * const memory = (char*)malloc(sizeof(int));
    memory[sizeof(int)] = '!';
    free(memory);
}

void buffer_underflow(void **state) {
    char * const memory = (char*)malloc(sizeof(int));
    memory[-1] = '!';
    free(memory);
}

int dynamic_memory_demo(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(leak_memory),
        cmocka_unit_test(buffer_overflow),
        cmocka_unit_test(buffer_underflow),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
