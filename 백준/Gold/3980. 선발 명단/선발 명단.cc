#include <iostream>
#include <vector>

using namespace std;

int ans;
vector<bool> position;
vector<vector<int>> avil(11, vector<int>(11));

void Search(int x, int cnt, int sum) {
    if (cnt == 11) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (position[i] || avil[x][i] == 0) continue;

        position[i] = true;
        Search(x + 1, cnt + 1, sum + avil[x][i]);
        position[i] = false;
    }
}

void Solution() {
    Search(0, 0, 0);

    cout << ans << "\n";
}

void Input() {
    ans = 0;
    position.resize(11, false);

    for (int i = 0; i < 11; i++) 
        for (int j = 0; j < 11; j++)
            cin >> avil[i][j];
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
