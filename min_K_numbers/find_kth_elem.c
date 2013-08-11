/*
 * =====================================================================================
 *
 *       Filename:  find_kth_elem.c
 *
 *    Description:  使用快排的分治法来寻找数组中第K小的元素
 *
 *        Version:  1.0
 *        Created:  11.08.2013 19:47:16
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

void print_array(int *a, int length){
    int i;
    for(i = 0;i< length;i++){
        printf ( "%d " , a[i]);
    }
    printf ( "\n" );
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int kth_element(int *a, int low, int high, int k){
    int j = low;
    int i = low - 1;
    if(low <= high){
        int x = a[high];
        for(;j<high;j++){
            if(a[j] < x){
                i ++;
                swap(&a[i], &a[j]);
            }
        }
        i++;
        swap(&a[i], &a[high]);
        // printf ( "the provital is %d\n", a[i] );
        // printf ( "now the array is :\n" );
        // print_array(a, 10);
        if( i- low + 1 == k){
            return a[i];
        }else if(i - low + 1 > k){
            return kth_element(a, low, i-1, k);
        }else{
            return kth_element(a, i+1, high, k-(i-low+1));
        }
    }
}

int main(){
    int a[10] = {2,3,4,8,1,5,6,7,0,9};
    int k = 6;
    printf ( "the %dth min number is :%d\n",k,kth_element(a,0,9,k) );
    return 0;
}
