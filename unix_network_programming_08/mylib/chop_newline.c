//
//  chop_newline.c
//  unix_network_programming_02
//
//  Created by 太田浩二 on 2015/07/12.
//
//
#include "mylib.h"

char * chop_newline(char *str, int len)



{
    int n = strlen(str);


    if(n < len && str[n-1] == '\n'){
        str[n-1] = '\0';
    }


    return str;
}
