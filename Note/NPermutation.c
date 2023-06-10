#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b);
void print_arr(int arr1[], int size);

bool Next_Permutation(int* arr1,int size){
    
    int j=size-2;
    //printf("j1=%d : ",j);
    while (j >= 0 && arr1[j] > arr1[j + 1]){j--;}
    //printf("j2=%d\n",j);

    if (j < 0)return false;  // No next permutation exists

    int k=size-1;
    //printf("k1=%d : ",k);
    while (arr1[k] < arr1[j]){k--;}
    //printf("k2=%d\n",k);

    swap(&arr1[k], &arr1[j]);

    int r=size-1;
    int s=j+1;
    //printf("r1=%d : s1=%d\n",r,s);
    while(r>s){
        swap(&arr1[r],&arr1[s]);
        r--;
        s++;
    }
    //printf("r2=%d : s2=%d\n",r,s);
    return true;

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

int main(void){
    int arr1[6]={3,6,2,5,4,1};
    int i=0;
    int *ptr=arr1;
    int size=0;

    printf("Original : ");
    size = sizeof(arr1)/sizeof(int);
    print_arr(arr1,size);

    if(Next_Permutation(arr1,size)){printf(" Next    : ");print_arr(arr1,size);}
    else printf("No next permutation\n");

}