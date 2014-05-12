#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int sunday(string str, string pattern) {
    int str_len = str.length();
    int pat_len = pattern.length();
    
    int char_pos[256];
    for (int i = 0; i<256; i++) char_pos[i] = -1;
    
    for (int i = pat_len - 1; i>=0; i--) char_pos[pattern[i]] = i;
    
    int i = 0;
    int j = 0;
    
    while (i + pat_len <= str_len) {
        while (j < pat_len && str[i] == pattern[j]) {
            i++, j++;
        }
        if (j == pat_len) return i - pat_len;

        int k = i + pat_len - j;
        int p = 0;
        
        while ( k < str_len && (p = char_pos[str[k]]) == -1) {
            k += pat_len;
        }
        
        i = k - p;
        j = 0;
    }
    return -1;
}


int main() {

    cout<<sunday("Unix Linux Unique", "Uniq")<<endl;

	system("pause");
	return 0;
}

