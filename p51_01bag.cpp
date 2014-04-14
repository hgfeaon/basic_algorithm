#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* use memo to accelarate */
int memo[100][100];

int max(int a, int b) {
    return (a<b)?b:a; 
}

int bag(int i, int* w, int* v, int r) {
    if (i < 0 || r == 0) return 0;
    if (memo[i][r] >= 0) return memo[i][r];
    int ret = 0;
    if (r<w[i]) {
        ret = bag(i-1, w, v, r);
    } else {
        ret = max(bag(i-1, w, v, r), v[i] + bag(i-1, w, v, r-w[i]));
    }
    memo[i][r] = ret;
    return ret;
}

int main() {
    memset(memo, -2, sizeof(int)*100*100);
    int W[] = {2, 1, 3, 2};
    int V[] = {3, 2, 4, 2};
    int w = 5;
    printf("%d", bag(3, W, V, w));
    
    system("pause");
    return 0;
}
