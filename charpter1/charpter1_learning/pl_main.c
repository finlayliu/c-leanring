#include <stdio.h>
#include "pl.h"
#define FUNC_PL

int main()
{
    int ret;
#ifdef HELLO_WORLD
    ret = print_hellword();
 #endif // HELLO_WORLD

 #ifdef FAHR_TO_CELSIUS
    ret = fahr_to_celsius();
 #endif // FAHR_TO_CELSIUS

 #ifdef FILE_COPY
    ret = file_copy();
 #endif // FILE_COPY

#ifdef TEST_CHAR
    ret = test_char();
#endif // TEST_CHAR

#ifdef CHAR_COUNTING
    ret = char_counting();
#endif // CHAR_COUNTING

#ifdef LINE_COUNTING
    ret = line_counting();
#endif // LINE_COUNTING

#ifdef FUNC_PL
    struct pl_ops *func_pl;
    func_pl = pl_setup();
    func_pl->arrays();
#endif // FUNC_PL

#ifdef FUNC_PL_TEST
    char s1[] = "hello world";
    char *s2   = "hello world";

    printf("s1 is %d\n", sizeof(s1));
    printf("s2 is %d\n", sizeof(s2));
#endif // FUNC_PL_TEST
     ret = 0;
     if (ret > 0){
        printf("\nprint successfully!, result is 0x%x.\n", ret);
    }
}
