#include <iostream>
#include <vector>

using namespace std;

int a, b, c;
int DP[101][101][101];

int Recursive(int x, int y, int z) {
    if (DP[x + 50][y + 50][z + 50] != 0) return DP[x + 50][y + 50][z + 50];

    if (x <= 0 || y <= 0 || z <= 0) return DP[x + 50][y + 50][z + 50] = 1;

    if (x > 20 || y > 20 || z > 20) return DP[x + 50][y + 50][z + 50] = Recursive(20, 20, 20);

    if (x < y && y < z)
        return DP[x + 50][y + 50][z + 50] = Recursive(x, y, z - 1) + Recursive(x, y - 1, z - 1) - Recursive(x, y - 1, z);

    return DP[x + 50][y + 50][z + 50] = Recursive(x - 1, y, z) + Recursive(x - 1, y - 1, z) + Recursive(x - 1, y, z - 1) - Recursive(x - 1, y - 1, z - 1);

}

void Input() {
    while (1) {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        DP[a + 50][b + 50][c + 50] = Recursive(a, b, c);

        cout << "w(" << a << ", " << b << ", " << c << ") = " << DP[a + 50][b + 50][c + 50] << "\n";
    }
}

void Solve() {
    Input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
