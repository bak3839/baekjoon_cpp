#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    char ch;
    int N, M, K, x1, y1, x2, y2;
    cin >> N >> M >> K;;

    vector<vector<pair<int, int>>> map(N + 1, vector<pair<int, int>>(M + 1));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> ch; 

            map[i][j].first = map[i][j - 1].first + map[i - 1][j].first - map[i - 1][j - 1].first;
            map[i][j].second = map[i][j - 1].second + map[i - 1][j].second - map[i - 1][j - 1].second;

            if (ch == 'J') map[i][j].first++;
            else if (ch == 'O') map[i][j].second++;
        }
    }

    for (int i = 0; i < K; i++) {
        int J = 0, O = 0, I = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        J = map[x2][y2].first - map[x2][y1 - 1].first - map[x1 - 1][y2].first + map[x1 - 1][y1 - 1].first;
        O = map[x2][y2].second - map[x2][y1 - 1].second - map[x1 - 1][y2].second + map[x1 - 1][y1 - 1].second;
        I = (x2 - x1 + 1) * (y2 - y1 + 1) - (J + O);

        cout << J << " " << O << " " << I << "\n";
    }
    return 0;
}