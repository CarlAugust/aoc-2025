#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 12

int main() {
    long long int sum = 0;
    char* buffer = calloc(100, 1); 
    while (scanf("%s\n", buffer) == 1) {

        char nums[N] = {-1};
        int len = strlen(buffer);
        for (int i = 0; buffer[i] != '\0'; i++) {
            for (int j = 0; j < N; j++) {
                if (nums[j] < buffer[i] && i + (N - j - 1) < len) {
                    nums[j] = buffer[i];
                    if (j != N - 1) memset(nums + j + 1, -1, 1);
                    break;
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            sum += (nums[i] - '0') * pow(10, N - i - 1);
        }

    }
    printf("Total sum %lli\n", sum);

    free(buffer);
    return 0;
}