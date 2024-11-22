#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> num;

void Solution() {
    if (next_permutation(num.begin(), num.end())) {
        for (auto n : num)
            cout << n << " ";
    }
    else {
        cout << -1;
    }
}

void Input() {
    cin >> N;
    
    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}