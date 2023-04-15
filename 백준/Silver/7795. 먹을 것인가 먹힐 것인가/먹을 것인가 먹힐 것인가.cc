#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;

void Solution(int a, int b) {
    int index = b - 1, ans = 0;
    bool end = false;

    for (int i = a - 1;i >= 0;i--) {
        int now = A[i];

        while (now <= B[index]) {
            index--;
            if (index < 0) {
                end = true;
                break;
            }
        }
        if (end) break;

        ans += index + 1;
    }
    cout << ans << "\n";
}

void Input(int a, int b) {
    int n;
    for (int i = 0;i < a;i++) {
        cin >> n;
        A.push_back(n);
    }

    for (int i = 0;i < b;i++) {
        cin >> n;
        B.push_back(n);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

void Clear() {
    A.clear();
    B.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, a, b;
    cin >> T;

    while (T--) {
        cin >> a >> b;

        Input(a, b);
        Solution(a, b);
        Clear();
    }

    return 0;
}