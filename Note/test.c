#include <stdio.h>
#include <stdbool.h>

void printCombination(int combination[], int r) {
    for (int i = 0; i < r; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

bool getNextCombination(int combination[], int n, int r) {
    for (int i = r - 1; i >= 0; i--) {
        if (combination[i] < n - r + i + 1) {
            printf("com[i]=%d\n",combination[i]);
            combination[i]++;
            for (int j = i + 1; j < r; j++) {
                combination[j] = combination[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

int main() {
    int n = 6;  // 元素总数
    int r = 4;  // 组合长度

    int combination[4]={1,2,5,6};

    printf("当前组合：");
    printCombination(combination, r);

    printf("下一个按字典顺序排列的组合：");
    if (getNextCombination(combination, n, r)) {
        printCombination(combination, r);
    } else {
        printf("没有下一个组合。\n");
    }

    return 0;
}
