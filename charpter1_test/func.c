#include <stdio.h>
#include "common.h"
/*  Exercise 1-2    */
static void print_c(void)
{
//    printf("EOF is %d\n", EOF);
//    printf("print test:\c");
    char c = '\v';
    printf("It is %d", c);
}

/*  Exercise 1-4    */
static void cel_to_fahr(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	while(celsius <= upper){
            fahr = 32.0 + (5.0/9.0)*celsius;
            printf("%3.0f\t%6.3f\n", celsius, fahr);
            celsius += step;
	}
}

static void replace_chars(void)
{
    int c;
    int tab = 't';
    int backspace = 'b';
    int backslash = '\\';

//    c = getchar();
    while ((c = getchar()) != EOF){
            if (c == '\t' ){
                c = 't';
                putchar(backslash);
            }
            else if (c == '\b'){
                c = 'b';
                putchar(backslash);
            }
            else if (c == '\\'){
                c = '\\';
                putchar(backslash);
            }
        putchar(c);
    }

}
static const struct func_ops chapter1 = {
    .print_watch        =   print_c,
    .celsius_to_fahr    =   cel_to_fahr,
    .rep_char               =   replace_chars,
};

struct func_ops *func_setup(void)
{
    struct func_ops *test;

//    test = malloc(sizeof(struct func_ops));
    test = &chapter1;
    return test;
};
