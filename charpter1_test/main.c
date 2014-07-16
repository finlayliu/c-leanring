#include <stdio.h>
#include "common.h"

int main()
{
    struct func_ops *test;
    int ret;

    test = func_setup();
    test->rep_char();

    return 0;
}
