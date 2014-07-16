#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
struct func_ops {
    void (*print_watch)(void);
    void (*celsius_to_fahr)(void);
    void (*rep_char)(void);
};

struct func_ops *func_setup(void);

#endif // COMMON_H_INCLUDED
