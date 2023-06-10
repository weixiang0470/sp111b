#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a , int b){
    if (a==0) return b;
    else return gcd(b%a,a);
}


int main(void){
    char tmp1[15], tmp2[15];
    int test1,test2;
    printf("Please enter only positive integer! Beside that will be see as 0\n");
    printf("Enter integer 1 : ");
    scanf("%s",tmp1);
    test1 = atoi(tmp1);
    //if(tmp1<=-1)printf("Please enter only positive integer\n");
    //if(test1 == 0){printf("Error input\n");}
    printf("Enter integer 2 : ");
    scanf("%s",tmp2);
    test2 = atoi(tmp2);
    //printf("%s %s\n",tmp1,tmp2);
    //printf("%d %d\n",test1,test2);


    if(test1==0 && test2==0)printf("Error input\n");
    else printf("GCD of %d and %d is %d\n",test1,test2,gcd(test1,test2));
    //if(tmp2<=-1)printf("Please enter only positive integer\n");
    //printf("Enter number1 : ");
    //scanf("%d",&tmp1);
    //printf("Enter number2 : ");
    //scanf("%d",&tmp2);
  
    
    
}
/*
int checkdigit(int a){
    int num=0;
    printf("Enter integer%d : ",a);
    if(scanf("%d",&num))return num;
    else {
        printf("Only positive integer please : ");
        scanf("%d",&num);
        return num;
    }

}
*/