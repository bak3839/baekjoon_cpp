#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent, counts;

int GetRoot(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = GetRoot(parent[x]);
}

int Union(int a, int b) {
    if(a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    counts[a] += counts[b];
    parent[b] = a;
    return counts[a];
}

void Solution() {
    int a, b;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;

        a = GetRoot(a);
        b = GetRoot(b);

        if(a != b) {
            cout << Union(a, b) << "\n";
        } else {
            cout << counts[a] << "\n";
        }
    }
}

void Input() {
    cin >> N >> M;

    parent.resize(N + 1);
    counts.resize(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> counts[i];
        parent[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}