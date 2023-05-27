#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, sum;
vector<int> kinder;
vector<int> diff;

void Solution() {
    int index = diff.size() - 1;

    for (int i = 0; i < K - 1; i++)
        sum -= diff[index--];

    cout << sum;
}

void Input() {
    cin >> N >> K;
    kinder.resize(N);
    diff.resize(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> kinder[i];

        if (i > 0) {
            diff[i - 1] = kinder[i] - kinder[i - 1];
            sum += diff[i - 1];
        }
    }
        
    sort(diff.begin(), diff.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}