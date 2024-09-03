#include <iostream>
#include <vector>
using namespace std;

int main() {
    int NC;
    cin >> NC;

    while (NC--) {
        int N;
        cin >> N;

        // Array para armazenar as contagens das alturas
        int count[231] = {0};  // 231 para incluir a altura máxima 230

        for (int i = 0; i < N; ++i) {
            int height;
            cin >> height;
            count[height]++;
        }

        bool first = true;
        for (int h = 20; h <= 230; ++h) {  // Itera no intervalo de alturas válidas
            while (count[h]--) {
                if (!first) cout << " ";
                cout << h;
                first = false;
            }
        }
        cout << endl;
    }

    return 0;
}
