#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char* buffer = "ACDBCB";
    char* p = buffer;
    char* q = buffer + strlen(buffer) - 1;
    
    while (p <= q) { 
        if (*p < *q) {
            putchar(*p++);
        } else {
            putchar(*q--);
        }
    }
    system("pause");
    return 0;
}
