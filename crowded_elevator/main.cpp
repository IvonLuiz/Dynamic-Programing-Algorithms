#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculate_min_energy(int N, int C, const vector<int>& floors) {
    vector<int> sorted_floors = floors;
    sort(sorted_floors.begin(), sorted_floors.end(), greater<int>());
    
    int total_energy = 0;
    int index = 0;
    while (index < sorted_floors.size()) {
        int max_floor = sorted_floors[index];
        int batch_end = min(index + C, (int)sorted_floors.size());
        int highest_floor = sorted_floors[index];
        
        total_energy += 2 * highest_floor; // Go to highest floor and return to floor 0
        index = batch_end;
    }
    
    return total_energy;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, C, M;
        cin >> N >> C >> M;
        
        vector<int> floors(M);
        for (int i = 0; i < M; ++i) {
            cin >> floors[i];
        }
        
        cout << calculate_min_energy(N, C, floors) << endl;
    }
    
    return 0;
}
