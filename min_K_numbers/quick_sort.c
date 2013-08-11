/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.c
 *
 *    Description:  快速排序
 *
 *        Version:  1.0
 *        Created:  11.08.2013 16:03:55
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
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *a, int length){
    int i;
    for(i = 0;i< length;i++){
        printf ( "%d " , a[i]);
    }
    printf ( "\n" );
}


int partition(int *a, int p, int r){
    int x = a[r];
    int i = p - 1;
    int j;
    for(j = p;j<r;j++){
        if( a[j] < x){
            i ++;
            swap( &a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i+1;
}

// 这种算法能够使得快排再n内时间完成
int random_partition(int *a, int p, int r){
    int i;
    if(p <= r){  // 使用p <= r 而不是 p < r, 保证每次能够返回值
        srand((unsigned)time(NULL));
        i = (rand() % (r - p + 1)) + p;
        printf ( "%d\n", i );
        swap(&a[i], &a[r]);
        return random_partition(a, p, r);
    }
}


void quick_sort(int *a, int p, int r){
    if(p < r){
        int q = partition(a,p,r);
        quick_sort(a, p , q-1);
        quick_sort(a, q+1, r);
    }
}

int main(){
    int a[10] = {9,8,7,6,5,12,3,34,1,0};
    print_array(a, 10);
    quick_sort(a,0,9);
    print_array(a, 10);
    return 0;
}
