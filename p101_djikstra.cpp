#include <iostream>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int main() {
    // zero means no connection
    int graph[5][5] =   {
                            0, 1, 5, 0, 0,
                            0, 0, 3,10, 9,
                            0, 0, 0, 5, 0,
                            0, 1, 0, 0, 1,
                            0, 0, 0, 0, 0,
                        };

    priority_queue<pair<P, P>, vector<P>, greater<P> > que;

    vector<int> vd(5, INT_MAX); // min distance from source to each vertex
    que.push(make_pair(0, 0));  // start from 0
    vd[0] = 0;
    
    while (!que.empty()) {
        P cv = que.top();
        que.pop();
        if (cv.second != vd[cv.first]) continue;
        for (int i=0; i<5; i++) {
            if (cv.first == i || graph[cv.first][i] == 0) continue;
            int dst = graph[cv.first][i] + vd[cv.first];
            if (dst < vd[i]) {
                vd[i] = dst;
                que.push(make_pair(i, dst));
            }
        }
    }

    for (int i=0; i<5; i++)
        cout<<i<<":"<<vd[i]<<endl;
        
    system("pause");
	return 0;
}

