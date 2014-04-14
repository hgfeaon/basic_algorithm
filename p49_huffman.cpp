#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

/* not actually huffman but the fence repair */

using namespace std;

int main() {
    int L[] = {1, 2, 3, 4, 5};
    int N = 5;
    priority_queue<int, vector<int>, std::greater<int> > heap(L, L+N);
    
    int total = 0;
    
    while (heap.size() >= 2) {
        int L1 = heap.top();
        heap.pop();
        int L2 = heap.top();
        heap.pop();
        total += L1 + L2;
        heap.push(L1 + L2);
    }
    cout<<total<<endl;
    system("pause");
    return 0;
}
