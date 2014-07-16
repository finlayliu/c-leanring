#ifndef PL_H_INCLUDED
#define PL_H_INCLUDED

int print_hellword(void);
int fahr_to_celsius(void);
int file_copy(void);
int test_char(void);
int char_counting(void);
int line_counting(void);

struct pl_ops {
    void (*wordcounting)(void);
    void (*arrays)(void);
    int (*pow)(int m, int n);
    int (*longest)(void);
};

struct pl_ops *pl_setup(void);

#endif // PL_H_INCLUDED
