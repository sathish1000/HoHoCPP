/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   findandreplace.c
 * Author: sivagusa
 *
 * Created on April 22, 2018, 10:42 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char str[] = "This is a message";
    char findStr[] = "is";
    char replaceStr[] = "was";
    char findStrNotFound[] = "was";
    char findStrEmpty[] = "";
    char* p;
    char* result;
    int cnt = 0;
    
    p = strstr(str, findStr);
    printf("String after the first occurence of '%s' in '%s' is '%s'\n",findStr, str, p);

    p = strstr(str, findStrNotFound);
    printf("String after the first occurence of '%s' in '%s'  is '%s'\n",findStrNotFound, str, p);

    p = strstr(str, findStrEmpty);
    printf("String after the first occurence of '%s' in '%s'  is '%s'\n",findStrEmpty, str, p);
      
    //Find the number of occurences of word.
    for (int i=0; str[i]!='\0'; i++)
    {
        if (strstr(&str[i],findStr) == &str[i])
        {
            cnt++;
            i = i + (strlen(findStr) - 1);
        }
    }
    
    printf("Number of occurences of word '%s' in string '%s' is '%d'\n", findStr, str, cnt);
    
    int newCharLen = strlen(str) + cnt*(strlen(replaceStr) - strlen(findStr)) + 1;
    result = (char*) malloc(newCharLen);
    
    for (int i=0;i<newCharLen;i++)
    {
        for (int j=0;str[j]!='\0';j++)
        {
            if (strstr(&str[j],findStr) == &str[j])
            {
                strcpy(&result[i],replaceStr);
                i = i + strlen(replaceStr) - 1;
            }
            else
            {
                result[i++] = str[j];
            }
        }
    }
    result[newCharLen] = '\0';
    
    printf("Replace new string for old string '%s' is '%s'", str, result);

    return (EXIT_SUCCESS);
}

