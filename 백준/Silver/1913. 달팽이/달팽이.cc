#include <iostream>
#include <queue>

using namespace std;

int N, D, X, Y;
vector<vector<int>> map;

void Solution() {
    int n = 1, base = (N - 1) / 2;
    map[base][base] = n++;

    for (int i = 1; i <= N / 2; i++) {
        int prev = base - i + 1;

        for (int y = prev; y <= base + i; y++)
            map[base - i][y] = n++;

        for (int x = prev; x <= base + i; x++)
            map[x][base + i] = n++;

        for (int y = base + i - 1; y >= prev - 1; y--)
            map[base + i][y] = n++;

        for (int x = base + i - 1; x >= prev - 1; x--)
            map[x][base - i] = n++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";

            if (map[i][j] == D) {
                X = i; Y = j;
            }
        }           
        cout << "\n";
    }

    cout << X + 1 << " " << Y + 1;
}

void Input() {
    cin >> N >> D;

    map.resize(N, vector<int>(N));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}