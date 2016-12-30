#ifndef MM_H
#define MM_H

typedef struct Type {
    char name[32];
    int value; 
} Type;

int mm_var_num;
Type *mm_var_addr;

void mm_init();
int mm_add_variable(char*);
int mm_get_value(char*);
int mm_set_value(char*, int);

void mm_dbg_print();

#endif
