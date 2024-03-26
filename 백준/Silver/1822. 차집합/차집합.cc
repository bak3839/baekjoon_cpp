#include <iostream>
#include <set>

using namespace std;

int N, M;

void Solution() {
    int n;
    set<int> s;
    set<int>::iterator iter;

    for (int i = 0; i < N; i++) {
        cin >> n;
        s.insert(n);
    }

    for (int i = 0; i < M; i++) {
        cin >> n;
        iter = s.find(n);

        if (iter != s.end()) s.erase(iter);
    }

    cout << s.size() << "\n";

    for (auto num : s) 
        cout << num << " ";
}

void Input() {
    cin >> N >> M;
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