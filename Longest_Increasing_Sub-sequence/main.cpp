#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const auto __optimize__ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int longestIncreasingSubsequence(const vector<int>& sequence) {
    if (sequence.empty()) return 0;
    vector<int> dp(sequence.size(), 1);
    int maxLength = 1;
    for (size_t i = 1; i < sequence.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (sequence[i] > sequence[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

int main() {
    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> matrix[i][j];
            }
        }

        int maxSize = 0;

        for (int r1 = 0; r1 < N; ++r1) {
            for (int c1 = 0; c1 < M; ++c1) {
                for (int r2 = r1; r2 < N; ++r2) {
                    for (int c2 = c1; c2 < M; ++c2) {
                        vector<int> linearized;
                        for (int r = r1; r <= r2; ++r) {
                            for (int c = c1; c <= c2; ++c) {
                                linearized.push_back(matrix[r][c]);
                            }
                        }
                        if (longestIncreasingSubsequence(linearized) == linearized.size()) {
                            maxSize = max(maxSize, (r2 - r1 + 1) * (c2 - c1 + 1));
                        }
                    }
                }
            }
        }

        cout << maxSize << endl;
    }
    return 0;
}
