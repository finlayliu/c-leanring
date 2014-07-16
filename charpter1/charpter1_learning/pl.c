#include "pl.h"
#include <stdio.h>

#define IN			1
#define OUT		0
#define MAXLINE	1000

int print_hellword(void)
{
    int ret;
    ret = printf("hello, world!\n");
    return ret;
}

int fahr_to_celsius(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr <= upper){
		celsius =  5 * (fahr - 32) / 9;
		printf("%3.0f\t%6.3f\n", fahr, celsius);
		fahr += step;
	}
}

int file_copy(void)
{
    int c;

    c = getchar();
    while(c != EOF){
        putchar(c);
        c = getchar();
    }
}

int char_counting(void)
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
        nc ++;
    printf("\n%ld\n", nc);
}

int line_counting(void)
{
    int c, nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            nl++;
    printf("%d\n", nl);
}

static void word_counting(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c =  getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state ==  OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d  %d  %d\n", nl, nw, nc);
}

static void arrays_counting(void)
{
	int c, i, nwhite, nother;
	int ndigit[10];

    nwhite = nother =  0;
    for (i = 0; i < 10; i++){
        ndigit[i] =  0;
    }

    while ((c = getchar()) != EOF)
        if ( c >= '0' && c <= '9')
            ndigit[c-'0']++;
        else if (c == ' ' || c == '\n' || c == '\t')
            nwhite++;
        else
            nother++;

    printf("digitals = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf("\nwhite sapce = %d, other = %d\n", nwhite, nother);
}

static int power(int m, int n)
{
	int i, p;

	p = 1;
	for (i=1; i <= n; i++ )
		p *= m;
	return p;
}

static int getline(char s[], int lim)
{
	int c, i;

	for ( i =0; i < lim -1 && (c = getchar()) != EOF && c != '\n' ; i++)
		s[i] = c;
	if ( c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;
}

static void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
static int longest_line(void)
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);

	return 0;
}

static int getline_test(void)
{
	int c, i;
    extern char line[];

	for ( i =0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n' ; i++)
		line[i] = c;
	if ( c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return i;
}

static void copy_test(void)
{
	int i;
    extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		i++;
}

static int longest_line_test(void)
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline_test()) > 0)
		if (len > max){
			max = len;
			copy_test();
		}
	if (max > 0)
		printf("%s", longest);

	return 0;
}

static const struct pl_ops chapter1_ops = {
    .wordcounting	= word_counting,
    .arrays			= arrays_counting,
    .pow			= power,
    .longest		= longest_line_test,
};

struct pl_ops *pl_setup(void)
{
     const struct pl_ops *func_ops;

    func_ops = malloc(sizeof(const struct pl_ops));
    if (!func_ops)
        return NULL;

    func_ops = &chapter1_ops;
    return func_ops;
}
