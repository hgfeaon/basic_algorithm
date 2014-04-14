#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100;

int max(int a, int b) {
    return a<b?b:a;
}

int main() {
    int dp[100][100];
    memset(dp, 0, sizeof(int) * 100 * 100);
    int w[] = {0, 3, 4, 2};
    int v[] = {0, 4, 5, 3};
    int W = 7;
    int n = 3;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=W; j++) {
            for (int k=0; k*w[i]<=j; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    }
    printf("%d", dp[n][W]);
    system("pause");    
    return 0;
}
