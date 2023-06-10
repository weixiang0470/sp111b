#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int square(long long int x){
    return x*x;
}

long long int mpower(long long int b, long long int n,long long int m){
    if(n==0)return 1;
    else if(n%2==0){
        return square(mpower(b,n/2,m)) % m;
    }
    else {
        return ((square(mpower(b,n/2,m)) % m) *(b%m)) % m;
    }
}


int main(void){
    long long int b,n,m;
    char tmp_b[15],tmp_n[15],tmp_m[15];
    printf("For b^n mod m formula\n");
    printf("b need to be greater or equal to 1\n");
    printf("n need to be greater or equal to 0\n");
    printf("m need to be greater or equal to 2\nAnything else will be see as 0\n");
    

    printf("Enter b : ");
    scanf("%s",tmp_b);
    b = (long long int)atoi(tmp_b);
    //scanf("%lld",&b);

    printf("Enter n : ");
    scanf("%s",tmp_n);
    n = (long long int)atoi(tmp_n);
    //scanf("%lld",&n);
    printf("Enter m : ");
    scanf("%s",tmp_m);
    m = (long long int)atoi(tmp_m);
    //scanf("%lld",&m);
    if(b<1 || n<0 || m<2){
        if(b<1)printf("b need to be greater or equal to 1\n");
        if(n<0)printf("n need to be greater or equal to 0\n");
        if(m<2)printf("m need to be greater or equal to 2\n");
    }
    else printf("Ans = %lld\n",mpower(b,n,m));
}