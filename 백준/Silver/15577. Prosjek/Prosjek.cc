#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<double> num;

void Solution() {
    double avg = num[0];

    for (int i = 1; i < N; i++) 
        avg = (avg + num[i]) / 2;

    cout << fixed;
    cout.precision(6);
    cout << avg;
}

void Input() {
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
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