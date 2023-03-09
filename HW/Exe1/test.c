#include <stdio.h>

int nextTemp() {
    static int tempIdx = 0;
    return tempIdx++;
}

int main()
{
    int i1 = nextTemp();
    int i2 = nextTemp();
    int i3 = nextTemp();
    printf("i1=%d i2=%d i3=%d\n",i1,i2,i3);
}