#include "DateString.h"

int main() {

    StringData str;
    str.size = 6;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[2] = (char*)"rewklrewkl";
    str.data[1] = (char*)"g 23:50:40 tkrekt";
    str.data[0] = (char*)"4534 23:65:1 r";
    str.data[3] = (char*)"00:50:40";
    str.data[4] = (char*)"tr 23:20:43 t";
    str.data[5] = (char*)"tr 01:10:20 t";

    //StringData Strings;
    StringData pResStrings;

   //getStringsFromInput(&str);
    getDateStringsReg(&str,&pResStrings);
    //FreeStrings(&str);
    FreeTestStrings(&str);
    FreeStrings(&pResStrings);

    return 0;
}
