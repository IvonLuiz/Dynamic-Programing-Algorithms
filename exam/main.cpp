#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k, instance = 1;
    
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        
        vector<string> names(n);
        for (int i = 0; i < n; ++i) {
            cin >> names[i];
        }
        
        for (int i = 0; i < n && k > 0; ++i) {
            // Find the smallest name that can be swapped to position i
            int min_index = i;
            for (int j = i + 1; j < n && (j - i) <= k; ++j) {
                if (names[j] < names[min_index]) {
                    min_index = j;
                }
            }
            // Calculate how many swaps are needed to move min_index to i
            int swaps_needed = min_index - i;
            if (swaps_needed > 0) {
                // Perform the swap
                string temp = names[min_index];
                for (int j = min_index; j > i; --j) {
                    names[j] = names[j - 1];
                }
                names[i] = temp;
                k -= swaps_needed;
            }
        }
        
        cout << "Instancia " << instance++ << endl;
        for (int i = 0; i < n; ++i) {
            cout << names[i] << " ";
        }
        cout << endl << endl;
    }
    
    return 0;
}
