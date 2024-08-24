#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int P;
        cin >> P;
        
        vector<pair<int, int>> orders(N); // pair<tempo, pizzas>
        for (int i = 0; i < N; ++i) {
            cin >> orders[i].first >> orders[i].second;
        }

        vector<int> dp(P + 1, 0);

        for (int i = 0; i < N; ++i) {
            int time = orders[i].first;
            int pizzas = orders[i].second;
            for (int j = P; j >= pizzas; --j) {
                if (dp[j - pizzas] + time > dp[j]) {
                    dp[j] = dp[j - pizzas] + time;
                }
            }
        }

        int max_time = dp[0];
        for (int j = 1; j <= P; ++j) {
            if (dp[j] > max_time) {
                max_time = dp[j];
            }
        }

        cout << max_time << " min." << endl;
    }

    return 0;
}
