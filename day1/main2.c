#include <stdio.h>
#include <stdbool.h>

#define N 4081

bool getDirection(int n) {
    if (n < 0) return false;
    return true;
}

int main() {
    int dial = 50;
    int sum = 0;
    char d;
    int a;

    for (int i = 0; i < N; i++) {
        scanf("%c%i\n", &d, &a);    
        sum += a / 100;
        a = a % 100;
        
        bool direction = getDirection(dial);
        bool isZero = !dial;
        if (d == 'R') dial += a;
        else dial -= a;

        if ((dial != dial % 100) || 
            (dial == 0 && a != 0) ||
            (direction != getDirection(dial) && !isZero)
        ) sum++;
        dial = dial % 100;
    }
    
    printf("Password: %i\n", sum);
    return 0;
}