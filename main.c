#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool sumsTo(int arr[], int len, int subsetSize, int sum){
    if(sum == 0 && subsetSize == 0) return true;
    if(sum != 0 && subsetSize == 0)return false;
    if(len == 0)return false;
    int res1 = 0;
    if(sum >= arr[0]) res1 = sumsTo(arr + 1, len - 1, subsetSize - 1, sum - arr[0]);
    int res2 = sumsTo(arr + 1, len - 1, subsetSize, sum);
    return res1 + res2 >0;
}

int main(){
    int test1[] = {1, 2, 3, 4};
    printf("***This should be true***\n");
    if(sumsTo(test1, 4, 2, 4)){
        printf("It is true\n");
    } else{
        printf("It is false\n");
    }

    int test2[] = {44, 112, 333, 4, 5, 6, 7};
    printf("***This should be false***\n");
    if(sumsTo(test2, 7, 6, 1)){
        printf("It is true\n");
    } else{
        printf("It is false\n");
    }


    return 0;
}