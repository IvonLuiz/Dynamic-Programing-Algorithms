#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check_denis_function(int N, int M, const vector<int>& coefficients) {
    // Generate all possible unique tuples (rankings)
    vector<int> ranks(M);
    for (int i = 0; i < M; ++i) {
        ranks[i] = i + 1;
    }
    
    set<long long> function_values;
    
    do {
        // Calculate function value for this ranking
        long long func_value = 0;
        for (int i = 0; i < N; ++i) {
            func_value += coefficients[i] * ranks[i];
        }
        
        // Check if this value has already been seen
        if (function_values.find(func_value) != function_values.end()) {
            return false;
        }
        
        function_values.insert(func_value);
        
    } while (next_permutation(ranks.begin(), ranks.begin() + N));
    
    return true;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<int> coefficients(N);
        for (int i = 0; i < N; ++i) {
            cin >> coefficients[i];
        }
        
        if (check_denis_function(N, M, coefficients)) {
            cout << "Lucky Denis!" << endl;
        } else {
            cout << "Try again later, Denis..." << endl;
        }
    }
    
    return 0;
}
