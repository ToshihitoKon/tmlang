#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mcode.h"
#include "error.h"

#include <stdio.h>

int mcd_init()
{
    mcd_mcode_num = 0;
    mcd_mcode_addr = (Mcode *)malloc(sizeof(Mcode)*1);
    return 0;
}

int mcd_add_mcode(char* opecode, char* parameter, int type, int nice)
{
    mcd_mcode_num ++;
    Mcode* tmp = (Mcode *)realloc(mcd_mcode_addr, sizeof(Mcode)*mcd_mcode_num);
    if(tmp == NULL)
        err_output_error("mcd", "mcd_add_mcode: realloc failed.");
    mcd_mcode_addr = tmp;
    strcpy(mcd_mcode_addr[mcd_mcode_num-1].opecode, opecode);
    strcpy(mcd_mcode_addr[mcd_mcode_num-1].parameter, parameter);
    mcd_mcode_addr[mcd_mcode_num-1].type = type;
    mcd_mcode_addr[mcd_mcode_num-1].nice = nice;
    
    // DEBUG_BEGIN =======
    /*
    printf("%s|%s|%d|%d\n",
            mcd_mcode_addr[mcd_mcode_num-1].opecode,
            mcd_mcode_addr[mcd_mcode_num-1].parameter,
            mcd_mcode_addr[mcd_mcode_num-1].type,
            mcd_mcode_addr[mcd_mcode_num-1].nice
            );
    // DEBUG_END ========= */
    return 0;
}

// return Mcode instance (zero base)
Mcode mcd_get_mcode(int num)
{
    if(num >= mcd_mcode_num)
        err_output_error("mcd", "mcd_get_mcode: segmentation fault.");
    return mcd_mcode_addr[num];
}

bool mcd_isExist_mcode(int num)
{
    if(num < mcd_mcode_num)
        return true;
    else
        return false;
}
