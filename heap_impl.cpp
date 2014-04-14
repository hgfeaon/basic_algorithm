#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class Heap {
    private:
        int size;
        int capacity;
        int* mem;
        float load_factor;
    public:
        Heap(int _capacity = 8, float _load_factor = 0.75) {
            load_factor = _load_factor;
            capacity = _capacity;
            mem = new int[capacity];
        }
        
        ~Heap() {
            delete[] mem;
        }
        
        void push(int i) {
            int ch = size++;
            try_expand(size); 
            int p = (ch - 1) / 2;
            while (ch > 0) {
                p = (ch - 1) / 2;
                if (mem[p] > i) {
                    mem[ch] = mem[p];
                    ch = p;
                } else {
                    break;
                }
            }
            mem[ch] = i;
        }
        
        int pop() {
            if (size == 0) return 0;
            int ret = mem[0];
            int last = mem[--size];
            int p = 0;
            int cr = p*2 + 2;
            int cl = p*2 + 1;
            
            while (cl < size) {
                int c = cl;
                if (cr < size && mem[cr] < mem[cl]) c = cr;
                
                if (mem[c] >= last) {
                    break;
                } else {
                    mem[p] = mem[c];
                }
                p = c;
                cr = p*2 + 2;
                cl = p*2 + 1;
            }
            
            mem[p] = last;
            return ret;
        }
        
        void show() {
            for (int i=0; i<size; i++) {
                printf("%d ", mem[i]);
            }
            printf("\n");
        }
    private:
        void try_expand(int newsize) {
            if (newsize <= capacity * 0.75) {
                return;
            } else {
                capacity = newsize * 2;
                int* tmp = new int[capacity];
                memcpy(tmp, mem, capacity*sizeof(int));
                delete[] mem;
                mem = tmp;
            }
        }
};

int main() {
    Heap p;
    
    for (int i=0; i<100; i++) {
        int n = rand();
        printf("%d\n", n);
        p.push(n);
    }
    
    printf("================\n");
    
    for (int i=0; i<100; i++) {
        printf("%d\n", p.pop());
    }
    system("pause");
    return 0;
}
