#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int *arr1, int size);
void swap(int* a, int* b);
void Next_R_Combination(int *arr2, int r, int n){

    int i=r;
    //int n=sizeof(arr1)/sizeof(int) - 1;
    //printf("n=%d : r=%d : i=%d : arr2[i]=%d\n",n,r,i,arr2[i]);
    while(arr2[i]==n-r+i+1){
        i--;
    }
    
    arr2[i]++;
    //swap(&arr2[0],&arr2[2]);
    for(int j = i+1;j<=r;j++){
        arr2[j]=arr2[i]+j-i;
    }
}

int main(void){
    int arr1[6]={1,2,3,4,5,6};
    int arr2[4]={1,2,5,6};
    int r=0,n=0;
    
    r = sizeof(arr2)/sizeof(int);
    n = sizeof(arr1)/sizeof(int);
    //printf("%d %d\n",r,n);
    printf("Original array : ");
    print_arr(arr2,r);
    Next_R_Combination(arr2,r-1,n-1);
    printf("Next r-c array : ");
    print_arr(arr2,r);


}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int arr1[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}