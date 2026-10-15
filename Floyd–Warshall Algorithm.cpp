#include <iostream>
using namespace std;

int main() {
    int n = 4;

    int dist[4][4] = {
        {0,   5,  999, 10},
        {999, 0,   3, 999},
        {999, 999, 0,   1},
        {999, 999, 999, 0}
    };

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != 999 &&
                    dist[k][j] != 999 &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        cout << "[ ";
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 999)
                cout << "\u221E ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
