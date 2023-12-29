#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int A, P;
vector<int> index;

void Solution() {
    int cnt = 1;
    index[A] = 0;

    while (1) {
        string num = to_string(A);
        int sum = 0;

        for (int i = 0; i < num.size(); i++)
            sum += pow(num[i] - '0', P);

        if (index[sum] != -1) {
            cout << index[sum];
            break;
        }

        index[sum] = cnt++;
        A = sum;
    }
}

void Input() {
    cin >> A >> P;

    index.resize(1000001, -1);
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
