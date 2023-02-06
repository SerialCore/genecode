#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "code.h"
#include "fileio.h"


void create_random(char* _file)
{
    srand((unsigned)time(NULL));
    unsigned char code[CODEL];
    for (int i = 0; i < CODEL; i++)
    {
        code[i] = (unsigned char)(rand() % 256);
    }

    if (write_binary(_file, code, CODEL))
        printf("%s is written.", _file);
}

void display_code(char* _file)
{
    long length;
    if ((length = get_length(_file)) == FER)
        return;

    unsigned char code[length];
    if (!read_binary(_file, code, length))
        return;

    long rows = length / 16;
    rows += (rows * 16) < length? 1 : 0;

    printf("\nOFFSET     %s", _file);
    printf("\n-----------------------------------------------------------");
    for (long i = 0; i < rows; i++)
    {
        printf("\n0x%08X", i * 16);
        for (int j = 0; j < 16; j++)
        {
            if ((i * 16 + j) < length)
                printf(" \033[1;31m%02X\033[0m", code[i * 16 + j]); // code with red font
            else
                printf(" XX");
        }
    }
}

void merge_code(char* _file1, char* _file2, char* _newfile)
{
    long length1, length2;
    if ((length1 = get_length(_file1)) == FER || (length2 = get_length(_file2)) == FER)
        return;

    if (length1 != length2 || length1 != CODEL)
        return;

    unsigned char highf;
    unsigned char lowf;
    unsigned char code1[CODEL];
    unsigned char code2[CODEL];
    unsigned char newcode[CODEL];
    if (read_binary(_file1, code1, CODEL) && read_binary(_file2, code2, CODEL))
    {
        for (long i = 0; i < CODEL; i++)
        {
            highf = code1[i] & 0xF0;
            lowf = code2[i] & 0x0F;
            newcode[i] = highf + lowf;
        }
    }

    if (write_binary(_newfile, newcode, CODEL))
        printf("%s is written.", _newfile);
}
