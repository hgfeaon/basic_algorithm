#include <iostream>
#include <cstdlib>

using namespace std;

class UnionFindSet {
    private:
        int *pref;
        int *rank;
        int capacity;
    public:
        UnionFindSet(int n) {
            if (n <= 0) {
                capacity = 0;
                return;
            }
            capacity = n;
            pref = new int[n];
            rank = new int[n];
            for (int i=0; i<n; i++) {
                rank[i] = 0;
                pref[i] = i;
            }
        }
        
        int find(int s) {
            if (s >= capacity || s < 0) return -1;
            if (s == pref[s]) return s;
            return pref[s] = find(pref[s]);
        }
        
        void unite(int a, int b) {
            if (a >= capacity || b >= capacity || a < 0 || b < 0) return;
            int pa = find(a), pb = find(b);
            if (pa == pb) return; // already united
            if (rank[pa] < rank[pb]) {
                pref[pa] = pb;
            } else {
                pref[pb] = pa;
            }
            if (rank[pa] == rank[pb]) rank[pa]++;
        }
        
        bool same(int a, int b) {
            return find(a) == find(b);
        }
};

int main() {
    UnionFindSet ufs(10);
    
    cout<<ufs.same(1,2)<<endl;

    ufs.unite(1,2);
    
    cout<<ufs.same(1,2)<<endl;
    
    cout<<ufs.same(3,6)<<endl;
    ufs.unite(3,4);
    ufs.unite(6,9);
    ufs.unite(4,6);
    cout<<ufs.same(3,6)<<endl;
	system("pause");
	return 0;
}

