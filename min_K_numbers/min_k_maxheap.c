/*
 * =====================================================================================
 *
 *       Filename:  min_k_maxheap.c
 *
 *    Description:  求最小K个数，使用大根堆的方法
 *
 *        Version:  1.0
 *        Created:  10.08.2013 17:58:04
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
#include <memory.h>

#define MAX 100

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// log(n)
void max_heapify(int *a, int i, int length){
    int left = (i+1)*2 -1;
    int right = left + 1;
    int largest;
    if( left < length && a[i] < a[left]){ // not left < length - 1
        largest = left;
    }else{
        largest = i;
    }
    if( right < length && a[largest] < a[right]){
        largest = right;
    }
    if(largest != i){
        swap(&a[i], &a[largest]);
        max_heapify(a, largest, length); // do not need to heapify the other side, we have assumed that both sides are already heapified
    }
}

void build_max_heap(int *a, int length){
    int i;
    for(i = (length/2)-1; i>=0; i--){
        max_heapify(a,i,length);
    }
}

//最大优先级队列相关

int heap_maximum(int * a){
    return a[0];
}

int heap_extract_max(int *a, int *length){ //需要修改堆长度，所以使用指针
    if(*length < 1){
        return 0;
    }
    int max = a[0];
    a[0] = a[*length - 1];
    // printf ( "%d\n", a[0] );
    *length = *length - 1;
    max_heapify(a, 0, *length);
    return max;
}

int max_heap_insert(int *a, int key, int *length){ //跟heapify没有关系
    (*length)++;
    a[*length - 1] =  key;
    int child = *length - 1;
    int parent = *length/2;
    while( parent >=0 && a[parent] < a[child]){
        swap(&a[parent], &a[child]);
        child = parent;
        parent = child/2;
    }
}
void print_array(int *a, int length){
    int i;
    for(i = 0;i< length;i++){
        printf ( "%d " , a[i]);
    }
    printf ( "\n" );
}

void get_min_k_number(int *a, int length, int k){
    int *max_heap;
    max_heap = (int*)malloc(sizeof(int) * k);
    int heap_length = k;
    int i;
    for(i = 0; i<k ;i++){
        max_heap[i] = a[i];
    }
    build_max_heap(max_heap,heap_length);
    for(i = k;i<length;i++){
         if(a[i] < max_heap[0]){
             heap_extract_max(max_heap, &heap_length);
             max_heap_insert(max_heap, a[i], &heap_length);
         }
    }
    print_array(max_heap, heap_length);
}
int main(){
    int length = 10;
    int k = 5;
    int a[10] = {12,523,2340,23423,231,98,45,9000,7,1};
    print_array(a, length);
    get_min_k_number(a,length,k);
    return 0;
}

