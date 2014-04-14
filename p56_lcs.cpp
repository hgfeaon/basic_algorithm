#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100
int max(int a, int b) {
    return a<b?b:a;
}
int main() {
    int MEMO[MAX_N+1][MAX_N+1];
    memset(MEMO, 0, sizeof(int) * 100 * 100);
    
    char SA[MAX_N+1], SB[MAX_N+1];
    
    scanf("%s", SA);
    scanf("%s", SB);
    
    int na = strlen(SA);
    int nb = strlen(SB); 
    
    for (int i=0; i<= MAX_N; i++)MEMO[i][0]=0;
    for (int i=0; i<= MAX_N; i++)MEMO[0][i]=0;
    
    for (int i=1; i<= na; i++)
        for (int j=1; j<= nb; j++)
            if (SA[i] == SB[j]) {
                MEMO[i][j] = 1 + MEMO[i-1][j-1];
            } else {
                MEMO[i][j] = max(MEMO[i-1][j], MEMO[i][j-1]);
            }
    printf("%d", MEMO[na][nb]);
    system("pause");
    return 0;
}
