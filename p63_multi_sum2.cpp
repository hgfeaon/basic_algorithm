#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#define MAX_K 100
#define MAX_N 100

/*
 * Give the number array a[], and their amount array m[]
 * and an expected sum, show the possible ways to get the sum
 * within available numbers.
 */

void print(int* dp, int* a, int* m, int i, int j, std::vector<int>& path) {
    if (j == 0) {
        std::vector<int>::iterator iter  = path.begin();
        while (iter != path.end()) {
            printf("%d ", *iter++);
        }
        printf("\n");
        return;
    }
    int ai = a[i-1];
    if (j >= ai && dp[(MAX_K+1) * i + j - ai] > 0 && m[i-1] > 0) {
        path.push_back(ai);
        m[i-1]--;
        print(dp, a, m, i, j - ai, path);
        m[i-1]++;
        path.pop_back();
    } 
    if (dp[(MAX_K+1) * (i-1) + j] >= 0) {
        m[i-1]--;
        print(dp, a, m, i - 1, j, path);
        m[i-1]++;
    }
}

int main() {
    int dp[MAX_N + 1][MAX_K + 1];
    memset(dp, -1, sizeof(dp));
    
    
    int K = 12;             // expected sum
    int a[] = {3, 6, 12};   // number available
    int m[] = {2, 1, 1};    // amount of these numbers
    
    int N = std::min(sizeof(a)/sizeof(int), sizeof(m)/sizeof(int));
    
    dp[0][0] = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<=K; j++) {
            if (dp[i][j] >= 0) {
                dp[i+1][j] = m[i];
            } else if ((j < a[i]) || (dp[i+1][j-a[i]] <= 0)) {
                dp[i+1][j] = -1;
            } else {
                dp[i+1][j] = dp[i+1][j-a[i]] - 1;
            }
        }
    }

    if (dp[N][K] >= 0) {
        printf("possible:\n");
        std::vector<int> path;
        print((int *)dp, a, m, N, K, path);
    } else {
        printf("can not get the sum.");
    }
    system("pause");
    return 0;
}
