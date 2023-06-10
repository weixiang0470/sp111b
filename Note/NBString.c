#include <stdio.h>
#include <string.h>
#define SMAX 100

char arr1[SMAX];

char* Next_bit_string(char* Str1){

    int length = 0;
    int count=0;
    char* tmp=Str1;
    //printf("STR = %c\n",*Str1);
    //printf("TMP = %c\n",*tmp);
    while(*Str1!='\0'){
        //printf("%d",*Str1);
        if(arr1[length]!='0' && arr1[length]!='1')arr1[length]='0';
        length++;
        Str1++;
    }
    printf("Origin = %s\n",arr1);
    //printf("\n");
    //printf("STR = %d\n",Str1);
    //printf("TMP = %d\n",tmp);
    //printf("STR = %c\n",*Str1);
    //printf("TMP = %d\n",tmp);
    Str1--;
    while(*Str1!='0'){
        //*Str1='0';
        //arr1[length - count -1]='0';
        //printf("%d %c\n",length - count -1,arr1[length - count -1]);
        Str1--;
        count++;
        if(count==length)break;
        arr1[length - count]='0';
        //printf("%c ",*Str1);
    }
    //printf("%d\n",count);
    //printf("%d\n",length);
    if(count==length){
        int count2=0;
        while(count2<count){
            arr1[0]='1';
            count2++;
            arr1[count2]='0';
            //printf("c2 = %d ",count2);
        }
        //printf("\n");
    }
    else{
    arr1[length - count-1]='1';
    //printf("STR = %c\n",*Str1);
    }
    return tmp;
}


int main(void){
    char* tmp;
    printf("請輸入二進制 : ");
    scanf("%s",arr1);
    tmp = Next_bit_string(arr1);
    printf(" Next  = ");
    while(*tmp!='\0'){
            //printf("%c",*Str1);
            printf("%c",*tmp);
            tmp++;
        }
    printf("\n");
    
    //printf("%d\n",tmp);


}