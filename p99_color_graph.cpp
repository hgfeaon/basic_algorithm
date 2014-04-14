#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#define MAX_V 100

using namespace std;

vector<int> G[MAX_V];
char color[MAX_V];

bool dfs(int v) {
    int cv = color[v];
    vector<int>::iterator iter = G[v].begin();
    while(iter != G[v].end()) {
        int cu = color[*iter];
        if (cu == cv) return false; // color collision
        if (cu == 0) {
            color[*iter] = -cv;     // set a different color 
            if (!dfs(*iter)) return false;
        }
        iter++;
    }
    return true;
}

int main() {

    memset(color, 0, sizeof(color));
    
    int e;
    cin>>e;
    int maxv = -1;
    for (int i=0; i<e; i++) {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        int m = max(u,v);
        if (m > maxv) maxv = m;
    }
    
    for (int i=0; i<=maxv; i++) {
        if (G[i].empty()) continue;
        if (color[i] == 0) {
            color[i] = 1;
            if (!dfs(i)) {
                cout<<"false"<<endl;
                break;
            }
        }
    }
    
    
    system("pause");
    return 0;
}
