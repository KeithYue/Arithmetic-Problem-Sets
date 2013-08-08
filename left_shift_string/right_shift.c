/*
 * =====================================================================================
 *
 *       Filename:  right_shift.c
 *
 *    Description:  right shift strings in O(n) time
 *
 *        Version:  1.0
 *        Created:  08.08.2013 17:19:05
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

void rotate(char *start, char *end){
    while( start != NULL && end != NULL && start < end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start ++;
        end --;
    }
}

void leftrotate(char *p, int m){
    if(p == NULL){
        return;
    }
    int len = strlen(p);
    char *xstart, *xend;
    char *ystart, *yend;
    xstart = p;
    xend = p+m-1;
    ystart = p+m;
    yend = p+len-1;
    rotate(xstart,xend);
    rotate(ystart,yend);
    rotate(p,p+len-1);
}

void rightrotate(char *p, int m){
    if(p == NULL){
        return;
    }
    int len = strlen(p);
    char *xstart, *xend;
    char *ystart, *yend;
    xstart = p;
    xend = p+len-m-1;
    ystart = p+len-m;
    yend = p+len-1;
    rotate(xstart,xend);
    rotate(ystart,yend);
    rotate(p,p+len-1);
}

int main(){
    char a [] = "Hello world";
    int m = 3;
    rightrotate(a,3);
    printf ( "%s\n" , a);
    return 0;
}
