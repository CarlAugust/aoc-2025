#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0;
    char* buffer = calloc(100, 1); 
    while (scanf("%s\n", buffer) == 1) {
        int first = -1, second = -1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] > first && buffer[i + 1] != '\0') {
                first = buffer[i];
                second = -1;
            } else if (buffer[i] > second) {
                second = buffer[i];
            }
        }
        sum += (first - '0') * 10 + (second - '0');
    }
    printf("Total sum %i\n", sum);
    return 0;
}