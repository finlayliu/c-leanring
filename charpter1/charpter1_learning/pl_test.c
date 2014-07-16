#include <stdio.h>
#define MAXLINE 1000
int max;
char line[MAXLINE];
char longest[MAXLINE];


int test_char(void)
{
    int c;

    c = getchar();
    while(c != EOF){
        putchar(c);
        printf("\n%c is %d\n", c, c);
        c = getchar();
    }
//    putchar(c);
//    c = getchar();
//    putchar(c);
//    printf("\nprintf:%c\n", c);
}
