#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int llu;

int main(void) {

    char* row1 = NULL, *row2 = NULL, *row3 = NULL, *row4, *ops = NULL;
    
    size_t columns;
    getline(&row1, &columns, stdin);
    getline(&row2, &columns, stdin);
    getline(&row3, &columns, stdin);
    getline(&row4, &columns, stdin);
    getline(&ops, &columns, stdin);

    llu sum = 0; 

    while (1) {
        llu a, b, c, d;
        char op = ' ';
        int bytes;


        // THIS IS UNSAFE AS IT PRACTICALLY REMOVES THE ABILITY TO PROPERLY FREE ROWS AND OPS
        if (sscanf(row1, "%llu%n", &a, &bytes) != 1) break;
        row1 += bytes;

        if (sscanf(row2, "%llu%n", &b, &bytes) != 1) break;
        row2 += bytes;

        if (sscanf(row3, "%llu%n", &c, &bytes) != 1) break;
        row3 += bytes;

        if (sscanf(row4, "%llu%n", &d, &bytes) != 1) break;
        row4 += bytes;

        while (op == ' ') {
            op = ops[0];
            ops++;
        }
        if (op == '\n') break;


        printf("a=%llu, b=%llu, c=%llu, d=%llu, op=%c\n", a, b, c, d, op);
        llu tsum = op == '*' ? a * b * c * d : a + b + c + d;
        sum += tsum;

    }

    printf("The sum is %llu\n", sum);

}