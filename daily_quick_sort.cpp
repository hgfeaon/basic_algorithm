#include <iostream>
#include <cstdlib>

using namespace std;

void print(int *arr, int len) {
    for (int i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void insertionsort(int *a, int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int cur = a[i];
        int j = i - 1;
        for (; j>=start && cur < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = cur;
    }
}

void quicksort(int* a, int start, int end) {
    if (end - start < 2) return;
    if (end - start < 4) {
        insertionsort(a, start, end);
        return;
    }
    int tmp;
    int pv = a[start];
    int i = start, j = end;
    while (true) {
        while (i < end && a[++i] < pv);
        while (j > start && a[--j] > pv);
        if (i > j) break;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    tmp = a[i-1];
    a[i-1] = pv;
    a[start] = tmp;
    
    quicksort(a, start, i-1);
    quicksort(a, i, end);
}

int main() {
    int arr[] = {6, 5, 3, 1, 8, 2};
    int len = sizeof(arr) / sizeof (arr[0]);

    insertionsort(arr, 0, len);
    print(arr, len);
    
    int arr2[] = {7, 6, 5, 4, 3, 2};
    len = sizeof(arr2) / sizeof (arr2[0]);
    quicksort(arr2, 0, len);
    print(arr2, len);
    
	system("pause");
	return 0;
}

