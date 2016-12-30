#include <stdlib.h>
#include <string.h>
#include "mm.h"
#include "error.h"


void mm_init()
{
    mm_var_num = 0;
    mm_var_addr = (Type *)malloc(sizeof(Type)*1);
}

int mm_add_variable(char* name)
{
    mm_var_num ++;
    Type *tmp = (Type *)realloc(mm_var_addr, sizeof(Type)*mm_var_num);
    
    if (tmp == NULL)
        err_output_error("mm","realloc failed.");
    mm_var_addr = tmp;

    strcpy(mm_var_addr[mm_var_num-1].name, name);
    mm_var_addr[mm_var_num-1].value = 0;

    return 0;
}

int mm_get_value(char* name)
{
    int i;
    for(i=0; i<mm_var_num; i++)
    {
        if(strcmp(mm_var_addr[i].name, name) == 0)
            return mm_var_addr[i].value;
    }
    char msg[64] = "variable can't find to get. ";
    err_output_error("mm", strcat(msg, name));
}

int mm_set_value(char* name, int value)
{
    int i;
    for(i=0; i<mm_var_num; i++)
    {
        if(strcmp(mm_var_addr[i].name, name) == 0)
        {
            mm_var_addr[i].value = value;
            return 0;
        }
    }
    char msg[64] = "variable can't find to set. ";
    err_output_error("mm", strcat(msg, name));
}


// DEBUG_CODE_BEGIN

#include <stdio.h>

void mm_dbg_print()
{
    int i;
    printf("___\n");
    for(i=0; i<mm_var_num; i++)
    {
        printf("%s|%d\n", mm_var_addr[i].name, mm_var_addr[i].value);
    }
    printf("---\n");
}
