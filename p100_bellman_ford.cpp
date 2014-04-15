#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Edge {
public:
    int from;
    int to;
    int cost;
};

int main() {
    
    int graph[5][5] =   {
                            0, 1, 5, 0, 0,
                            0, 0, 3,10, 9,
                            0, 0, 0, 5, 0,
                            0, 1, 0, 0, 1,
                            0, 0, 0, 0, 0,
                        };
    Edge edge;

    vector<Edge> E;
    vector<int>  vd(5, INT_MAX);
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            edge.cost = graph[i][j];
            if (edge.cost == 0) continue;
            edge.to  = j;
            edge.from= i;
            E.push_back(edge);
        }
    }
    
    vd[0] = 0; // start point

    bool update = true;
    while (update) {
        update = false;
        for (int i=0; i<E.size(); i++) {
            Edge& e = E[i];
            if (vd[e.from] != INT_MAX && vd[e.to] > vd[e.from] + e.cost) {
                update = true;
                vd[e.to] = vd[e.from] + e.cost;
            }
        }
    }

    for (int i=0; i<5; i++)
        cout<<i<<":"<<vd[i]<<endl;
	system("pause");
	return 0;
}

