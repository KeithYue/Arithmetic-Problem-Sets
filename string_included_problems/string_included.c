/*
 * =====================================================================================
 *
 *       Filename:  string_included.c
 *
 *    Description:  string included problem (Hash Table)
 *
 *        Version:  1.0
 *        Created:  08.08.2013 20:25:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wang Yue (Keithyue), buaawangyue@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    // char *str1 = "ASDF"; //大写字母
    // char *str2 = "ASD";
    char str1[20];
    char str2[20];
    gets(str1);
    gets(str2);
    int hash[26] = {0};
    int i, len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int count = 0;
    for(i=0; i< len2;i++){
        int index = str2[i] -'A';
        if(hash[index] == 0 ){
            hash[index] = 1;
            count ++;
        }
    }
    for(i=0;i<len2;i++){
        int index = str1[i] - 'A';
        if(hash[index] == 1){
            hash[index] = 0;
            count --;
        }
        if(count == 0){
            break;
        }
    }
    if(count == 0){
        printf ( "True! \n" );
    }else{
        printf ( "False! \n" );
    }
}
