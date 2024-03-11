#include <iostream>
#include <vector>

using namespace std;

int N, W, B;
string ans;
vector<string> binary;

char Division(int x, int y, int len) {
    char n = binary[x][y];

    for (int i = x; i < len + x; i++) {
        for (int j = y; j < y + len; j++) {
            if (binary[i][j] != n) return '2';
        }
    }

    return n;
}

void Search(int x, int y, int len) {
    int halfLen = len / 2;
    char color = Division(x, y, len);

    if (color == '1' || color == '0') {
        ans.push_back(color);
    }

    else if (len > 1 && color == '2') {
        ans.push_back('(');
        Search(x, y, halfLen);
        Search(x, y + halfLen, halfLen);
        Search(x + halfLen, y, halfLen);
        Search(x + halfLen, y + halfLen, halfLen);
        ans.push_back(')');
    }
}

void Solution() {
    Search(0, 0, N);

    cout << ans;
}

void Input() {
    cin >> N;

    binary.resize(N);

    for (int i = 0; i < N; i++)
        cin >> binary[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
