/*
 * =====================================================================================
 *
 *       Filename:  string_match.c
 *
 *    Description:  to identify about whether given two strings are matched
 *
 *        Version:  1.0
 *        Created:  09.08.2013 16:17:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wang Yue (Keithyue), buaawangyue@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int is_match(char *a, char *b){
    if(strlen(a) != strlen(b)){
        return 0;
    }
    int hash[26] = {0};
    int count = 0;
    while(*a){
        int index = *a - 'A';
        hash[index]++;
        count ++;
        a++;
    }
    while(*b){
        int index = *b - 'A';
        if(hash[index] != 0){
            hash[index] --;
            count --;
        }else{
            return 0;
        }
        b++;
    }
    if(count == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char a[20], b[20];
    gets(a);
    gets(b);
    printf ( "%d\n",is_match(a,b) );

}

