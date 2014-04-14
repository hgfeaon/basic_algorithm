#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class SegmentTree {
    private:
        int *mem;
        int capacity;
        int storage_size;
    private:
        void init_level_update() {
            int k = capacity - 1;
            while (--k >= 0) {
                int L = (k<<1) + 1;
                int R = L + 1;
                mem[k]= min(mem[L], mem[R]);
            }
        }

        int query(int a, int b, int idx, int L, int R) {
            if (b <= L || a >= R) return INT_MAX;
            if (a <= L && R <= b) return mem[idx];

            int ml = query(a, b, (idx<<1) + 1, L, (L+R)/2);
            int mr = query(a, b, (idx<<1) + 2, (L+R)/2, R);
            return min(ml, mr);
        }
        
        void init_mem(int _capacity) {
            if (_capacity <= 0) {
                capacity = 0;
                return;
            }
            int n = 1;
            while (n < _capacity) n<<=1;
            capacity = n;
            storage_size = capacity * 2 - 1;
            mem = new int[storage_size];

            int k = 0;
            while (k < storage_size) mem[k++] = INT_MAX;
        }
    public:
        SegmentTree(int _capacity) {
            init_mem(_capacity);
        }
        SegmentTree(vector<int>::iterator begin, vector<int>::iterator end) {
            capacity = end - begin;
            init_mem(capacity);

            int k = capacity - 1;
            vector<int>::iterator iter = begin;
            while (iter != end) mem[k++] = *iter++;

            init_level_update();
        }
        
        // update value in original data index
        void update(int idx, int val) {
            if (idx >= capacity || idx < 0) return;
            int k = idx + capacity - 1; // internal storage index
            mem[k] = val;
            while (k > 0) {
                k = (k - 1) >> 1;
                int L = (k << 1) + 1;
                int R = L + 1;
                mem[k] = min (mem[L], mem[R]);
            }
        }
        
        // retrive the min value in index range [a, b)
        int query(int a, int b) {
            return query(a, b, 0, 0, capacity);
        }
        
        void print_mem(const char* msg) {
            cout<<msg<<endl;
            for (int i=0; i<(capacity*2-1); i++) {
                cout<<mem[i]<<" ";
            }
            cout<<endl;
        }
};


void test(const char* msg, SegmentTree& seg_tree, int* data, int size) {
    cout<<msg<<endl;
    for (int i=0; i<=size; i++) {
        for (int j=i+1; j<=size; j++) {
            int tmin = seg_tree.query(i, j);
            cout<<"min of ("<<i<<","<<j<<") = "<<tmin<<endl;
            int amin = INT_MAX;
            for (int k=i; k<j; k++) if (data[k] < amin) amin = data[k];
            if (amin != tmin)
                cout<<"fail"<<endl;
            else
                cout<<"ok"<<endl;
        }
    }
}
int main() {
    int h[] = {6, 2, 5, 4, 5, 3, 6};
    int size= sizeof(h) / sizeof(int);
    vector<int> hs(h, h + size);
    
    SegmentTree seg_tree(hs.begin(), hs.end());
    test("Test construction with data :", seg_tree, h, size);
    
    SegmentTree init_empty_tree(size);
    for (int i=0; i<size; i++) init_empty_tree.update(i, h[i]);
    test("Test construction without data", init_empty_tree, h, size);
    
	system("pause");
	return 0;
}

