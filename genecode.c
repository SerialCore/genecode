#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"

void get_help();
void get_version();


int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        if (!strcmp(argv[1], "--help"))
        {
            get_help();
        }
        else if (!strcmp(argv[1], "--vers"))
        {
            get_version();
        }
        else
        {
            get_help();
        }
    }
    else if (argc == 3)
    {
        if (!strcmp(argv[1], "-x"))
        {
            display_code(argv[2]);
        }
        else if (!strcmp(argv[1], "-c"))
        {
            create_random(argv[2]);
        }
        else
        {
            get_help();
        }
    }
    else if (argc == 5)
    {
        if (!strcmp(argv[1], "-m"))
        {
            merge_code(argv[2],argv[3],argv[4]);
        }
    }
    else
    {
        get_help();
    }

    return 0;
}

void get_help() 
{
    printf("A genecode controller for anOS\n");
    printf("\nUSAGE\n");
    printf("\tgenecode <command> [file1] [file2]\n");
    printf("\nCOMMANDS\n");
    printf("\t-c\tcreate a fully random code\n");
    printf("\t-x\tdisplay a hex dump for code\n");
    printf("\t-m\tmerge two codes for a new code\n");
    printf("\nOPTIONS\n");
    printf("\t--help\tdisplay this instruction\n");
    printf("\t--vers\tget the version of genecode\n");
    printf("\nEXAMPLES\n");
    printf("\t$ genecode -c file\n");
    printf("\t$ genecode -m file1 file2 newfile\n");
}

void get_version()
{
    printf("genecode 0.1 by SerialCore\n");
}