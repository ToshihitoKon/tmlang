#include <stdbool.h>
#include <string.h>
#include "parser.h"
#include "error.h"
#include "mcode.h"

#include <stdio.h>

int psr_add_mcode(char* state)
{
    int i=0;
    int type;
    bool flag=false;    // for no parameters function
    while(true)
    {
        if(state[i] == '(')
        {
            state[i] = '\0';
            type = 0;
            break;
        }
        else if(state[i] == ' ')
        {
            state[i] = '\0';
            type = 1;
            break;
        }
        else if(state[i] == '\n')
        {
            state[i] = '\0';
            flag=true;
            break;
                /*err_output_error("psr",
                        "psr_add_cmode: syntax error. can't parse opecode.");*/
        }
        i++;
    }
    if(flag)
    {
        mcd_add_mcode(state, "", 0,0);
        return 0;
    }

    char* tmp = state;
    int j=0;
    while(true)
    {
        if(state[i+1+j] == ')' || state[i+1+j] == '\n')
        {
            state[i+1+j] = '\0';
            break;
        }
        else if(state[i+1+j] == '\0')
            err_output_error("psr",
                "psr_add_cmode: syntax error. can't parse parameter.");
        j++;
    }
    mcd_add_mcode(tmp, &state[i+1], 0,0);
    return 0;
}
