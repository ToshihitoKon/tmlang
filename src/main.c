#include <stdio.h>
#include <stdbool.h>
#include "mm.h"
#include "error.h"
#include "parser.h"
#include "exec.h"

int main(int argc, char** argv)
{
    FILE *fp;
    if((fp = fopen(argv[1],"r")) == NULL)
        err_output_error("main", "main: file can't open.");
    
    char buf[81];
    // printf("=== parse begin ===\n");
    while(fgets(buf,81,fp))
    {
        psr_add_mcode(buf);
    }
    // printf("=== execute ===\n");
    exc_exec();
    return 0;
}
