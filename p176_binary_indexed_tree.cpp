#include <iostream>
#include <cstdlib>

using namespace std;

class BinaryIndexedTree {
private:
    int *mem;
    int capacity;
public:
    BinaryIndexedTree (int n) {
        if (n <= 0) {
            capacity = 0;
            return;
        }
        capacity = n;
        mem = new int[capacity + 1];
        for (int i=0; i<=capacity; i++) mem[i] = 0;
    }
    ~BinaryIndexedTree() {
        delete[] mem;
    }
    int sum(int idx) {
        if (idx++ >= capacity) idx = capacity;
        int s = 0;
        while(idx > 0) {
            s += mem[idx];
            idx -= idx & -idx;
        }
        return s;
    }
    
    void add(int idx, int val) {
        idx++;
        while (idx <= capacity) {
            mem[idx] += val;
            idx += idx & -idx;
        }
    }
};

int main() {
    int nums[] = {5, 3, 7, 9, 6, 4, 1, 2};
    int n = sizeof(nums) / sizeof(int);
    
    BinaryIndexedTree bit(n);
    
    for (int i=0; i<n; i++) {
        bit.add(i, nums[i]);
    }
    
    for (int i=0; i<n; i++) {
        cout<<"["<<0<<", "<<i<<"] :"<<bit.sum(i)<<endl;
    }

    // solve a problem using BIT, calculate how many reverse order pairs
    // in a shuffled array{1, 2, 3...n}; n = array.length
    int array[] = {3,1,2,5,4};
    int size = sizeof(array) / sizeof(int);
    BinaryIndexedTree bt(size);
    int rsum = 0;
    for (int i=0; i<size; i++) {
        rsum += i - bt.sum(array[i]);
        bt.add(array[i], 1);
    }
    cout<<rsum<<endl;
    
	system("pause");
	return 0;
}

