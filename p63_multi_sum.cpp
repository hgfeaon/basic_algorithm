#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAX_N 100
#define MAX_K 1000

void print(int* dp, int* a, int k, int n, int i, int j, std::vector<int>& path) {
    if (i == 0) {
        std::vector<int>::iterator iter = path.begin();
        while(iter != path.end()) {
            printf("%d ", *iter++);
        }
        printf("\n");
        return;
    }
    int ai = a[i-1];
    if (j < ai) {
        if (dp[(i-1) * (MAX_K+1) + j]) {
            print(dp, a, k, n, i-1, j, path);
        }
    } else {
        if (dp[(i-1) * (MAX_K + 1) + j]) {
            print(dp, a, k, n, i-1, j, path);
        }
        
        if (dp[i * (MAX_K + 1) + j - ai]) {
            if (!path.empty() && path.back() == ai) return; // avoid use the same number twice(assuming that every number is unique)
            path.push_back(ai);
            print(dp, a, k, n, i, j - ai, path);
            path.pop_back();
        }
    }
}

int main() {
    
    int dp[MAX_N+1][MAX_K+1];
    memset(dp, 0, sizeof(int) * (MAX_N + 1) * (MAX_K + 1));
    
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);
    int k = 24;
    
    dp[0][0] = 1;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<=k; j++) {
            if (j<a[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = dp[i][j] | dp[i][j-a[i]];
            }
        }
    }
    
    printf("%d\n", dp[n][k]);
    if (dp[n][k]) {
        std::vector<int> path;
        print((int *)dp, a, k, n, n, k, path);
    }
    system("pause");
    return 0;
}
