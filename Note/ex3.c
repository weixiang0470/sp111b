#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[10]={0,2,4,6,8,10,11,13,15,17};

int binary_search(int x, int low, int top){
    int m= (low+top)/2;

    if(arr[m]==x)return m;
    else if(arr[m]>x && m>low)return binary_search(x,low,m-1);
    else if(arr[m]<x && m<top)return binary_search(x,m+1,top);
    else return -1;
}

int sort_arr(){
    int count=0;

    for(int i=0;i<10;i++){if(arr[count]==-1)break;count++;}

    for(int i=0;i<count;i++){
        for(int j=0;j<i;j++){
            int tmp;

            if(arr[j]>arr[i]){
                tmp=arr[j];
                arr[j]=arr[i];
                arr[i]=tmp;
            }
        }

    }

    return count;
}

int main(void){
    char tmp_x[15],tmp_mode[1];
    int x,target;
    int count=1;
    int mode;
    printf("Mode 1 array = {0,2,4,6,8,10,11,13,15,17} \nMode 2 customize array by yourself\nChoose mode(enter 1 or 2) : ");
    scanf("%c",tmp_mode);
    mode = atoi(tmp_mode);
    if(mode == 1){
        for(int i=0;i<10;i++)printf("%d ",arr[i]);
        printf("\n");

        printf("Enter target value : ");
        scanf("%s",tmp_x);
        x=atoi(tmp_x);

        target = binary_search(x,0,9);
        if(target==-1)printf("Target not found\n");
        else printf("Target at %d location\n",binary_search(x,0,9)+1);
    }
    else if(mode==2) {
        while(1){
            printf("Enter array number%d(Maximum 10, -1 to stop) : ",count);
            scanf("%s",tmp_x);
            x=atoi(tmp_x);
            arr[count-1]=x;
            if(x==-1 || count==10)break;
            count++;
        }
        count = sort_arr();
        printf("Sorted array : ");
        for(int i=0;i<count;i++)printf("%d ",arr[i]);
        printf("\n");

        printf("Enter target value : ");
        scanf("%s",tmp_x);
        x=atoi(tmp_x);

        target = binary_search(x,0,9);
        if(target==-1)printf("Target not found\n");
        else printf("Target at %d location\n",binary_search(x,0,9)+1);
    }
    else printf("Wrong mode!!! Bye~\n");
}