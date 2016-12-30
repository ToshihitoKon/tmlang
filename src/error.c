#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void err_output_error(char* where, char* msg)
{
    printf("(EE)[%s] %s\n", where, msg);
    exit(-1);
}
