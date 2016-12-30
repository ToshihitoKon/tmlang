#ifndef MCODE_H
#define MCODE_H

#include <stdbool.h>

typedef struct Mcode
{
    char    opecode[32];
    char    parameter[64];
    int     type;
    int     nice;
} Mcode;

int mcd_mcode_num;
Mcode* mcd_mcode_addr;

int mcd_init();
int mcd_add_mcode(char*, char*, int, int);
Mcode mcd_get_mcode(int);
bool mcd_isExist_mcode(int);

#endif
