#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<bool> check;
vector<int> num;
vector<int> S;

void Sequence() {
    if (S.size() == M) {
        for (int i = 0; i < M; i++)
            cout << S[i] << " ";
        cout << "\n";
        return;
    }
    
    int prev = 0;

    for (int i = 0; i < N; i++) {
        if(num[i] == prev || check[i]) continue;
        
        prev = num[i];
        
        S.push_back(num[i]);
        check[i] = true;
        
        Sequence();
        
        S.pop_back();
        check[i] = false;
    }
}

void Solution() {
    Sequence();
}

void Input() {
    cin >> N >> M;

    num.resize(N);
    check.resize(N, false);

    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
