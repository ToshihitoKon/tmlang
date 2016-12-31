#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exec.h"
#include "mcode.h"
#include "mm.h"
#include "error.h"

int exc_exec()
{
    int pc=0;
    int mem=0;
    int loopCount;
    int loopBeginPC;
    while(mcd_isExist_mcode(pc))
    {
        if(strcmp(mcd_get_mcode(pc).opecode, "put")==0)
            printf("%s\n", mcd_get_mcode(pc).parameter);
        else if(strcmp(mcd_get_mcode(pc).opecode, "print")==0)
            printf("%d\n", mem);
        else if(strcmp(mcd_get_mcode(pc).opecode, "int")==0)
            mm_add_variable(mcd_get_mcode(pc).parameter);
        else if(strcmp(mcd_get_mcode(pc).opecode, "load")==0)
            mem = mm_get_value(mcd_get_mcode(pc).parameter);
        else if(strcmp(mcd_get_mcode(pc).opecode, "save")==0)
            mm_set_value(mcd_get_mcode(pc).parameter, mem);
        else if(strcmp(mcd_get_mcode(pc).opecode, "set")==0)
            mem = atoi(mcd_get_mcode(pc).parameter);
        else if(strcmp(mcd_get_mcode(pc).opecode, "loop")==0)
            if(strcmp(mcd_get_mcode(pc).parameter, "end") == 0)
            {
                loopCount--;
                if(loopCount != 0)
                    pc = loopBeginPC;
            }
            else
            {
                loopCount = mem;
                loopBeginPC = pc;
            }
        else
            printf("🍣");
        pc ++;
    }
}
