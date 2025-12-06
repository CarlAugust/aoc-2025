#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[1024];
    buffer[1023] = '\0';
    scanf("%s\n", buffer);

    printf("Length %li\n", strlen(buffer));

    return 0;
}