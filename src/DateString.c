#include "DateString.h"
#include "string.h"

#define PATTERN "([0-1][0-9]|[2][0-3]):[0-5][0-9]:[0-5][0-9]"

size_t print(char ** strings,int count) {
    if(strings == NULL)
        return 0;
    size_t c = 0;
    while (c < count) {
        char *p = strings[c];
        size_t i = 0;
        printf("%s", p);
        printf("%c", '\n');
        ++c;
    }
}

size_t getDateStringsReg(StringData *pStrings, StringData *pResStrings) {
    if(pStrings == NULL)
        return 0;
    size_t size = 8;
    pResStrings->data = (char**)malloc(size * sizeof(char *));
    if(pResStrings->data == NULL)
        return 0;
    size_t c = 0;
    int resCount = 0;
    regex_t regex;
    int err = regcomp(&regex, PATTERN, REG_EXTENDED);
    if(err == -1)
        return -1;
    while ( c < pStrings->size) {
        char *p = pStrings->data[c];
        regmatch_t  pm;
        int flag = regexec(&regex, p, 0, &pm, 0);
        if(flag == 0){
            if(size == resCount)
            {
                size *= 2;
                pResStrings->data = (char**)realloc(pResStrings->data,size * sizeof(char*));
                if(pResStrings->data == NULL)
                    return 0;
            }

            size_t lineSize = 128;
            pResStrings->data[resCount] = (char*)calloc(sizeof(char),lineSize);
            if(pResStrings->data[resCount] == NULL)
                return 0;

            unsigned long len = strlen(pStrings->data[c]);
            if(len > lineSize)
            {
                lineSize *= 2;
                pResStrings->data[resCount] = (char*)realloc(pResStrings->data,lineSize * sizeof(char));
                if(pResStrings->data[resCount] == NULL)
                    return 0;
            }
            memcpy(pResStrings->data[resCount],pStrings->data[c], len);
            ++resCount;
        }
        ++c;
    }
    regfree(&regex);
    pResStrings->size = resCount;
    print(pResStrings->data,pResStrings->size);
    return resCount;
}

size_t getStringsFromInput(StringData *pStrings)
{
    size_t size = 8;
    pStrings->data = (char **) malloc(size * sizeof(char*));
    if(pStrings->data == NULL)
        return 0;
    char *line = NULL;
    size_t len = 128;
    size_t count = 0;

    while(getline(&line, &len, stdin) != EOF){
        if(count == size){
            size *= 2;
            pStrings->data = (char**)realloc(pStrings->data, size * sizeof(char*));
            if(pStrings->data == NULL)
                return 0;
        }
        size_t i = 0;
        pStrings->data[count] = (char *) calloc(sizeof(char),len);
        if(pStrings->data[count] == NULL)
            return 0;
        while(line[i] != '\n'){
            pStrings->data[count][i] = line[i];
            ++i;
        }
        ++count;
        if(count == 5)
            break;
    }
    if(line != NULL){
        free(line);
    }
    pStrings->size = count;
}

void FreeStrings(StringData *pStrings)
{
    for(size_t i = 0; i < pStrings->size; ++i){
        free(pStrings->data[i]);
    }
    free(pStrings->data);
}

void FreeTestStrings(StringData *pStrings)
{
    free(pStrings->data);
}