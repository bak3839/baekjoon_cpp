#include <algorithm>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N;
vector<ll> ink;
vector<ll> visc;

void Solution() {
    for (int i = 0; i < N; i++) {
        int index = upper_bound(visc.begin() + i, visc.end(), ink[i]) - visc.begin();

        cout << index - 1 - i << " ";
    }
}

void Input() {
    cin >> N;
    ink.resize(N);
    visc.resize(N);

    for (int i = 0; i < N; i++)
        cin >> ink[i];

    for (int i = 0; i < N; i++)
        cin >> visc[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}