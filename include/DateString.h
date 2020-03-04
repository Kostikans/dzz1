#pragma once
#define _GNU_SOURCE
#include "stdlib.h"
#include "stdio.h"
#include "regex.h"

typedef struct StringData
{
    char **data;
    size_t size;
} StringData;

size_t print(char ** strings,int count);
size_t getDateStringsReg(StringData *pStrings, StringData *pResStrings);
size_t getStringsFromInput(StringData *pStrings);
void FreeStrings(StringData *pStrings);
void FreeTestStrings(StringData *pStrings);
