#include <iostream>
#include <vector>

using namespace std;

vector<int> cost;
vector<int> parent;
vector<bool> check;

int getRoot(int x) {
    if (parent[x] == x) return x;
    else return getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (cost[a] > cost[b] || (cost[a] == cost[b] && a > b)) {
        int tmp = a;
        a = b;
        b = tmp;
    }
  
    parent[b] = a;
}

void input(int N, int M) {
    int v1, v2;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        Union(v1, v2);
    }
}

int solve(int N, int k) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int x = getRoot(i);
        if (!check[x]) {
            sum += cost[x];
            check[x] = true;
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, k, ans;
    cin >> N >> M >> k;

    cost.resize(N + 1);
    parent.resize(N + 1);
    check.resize(N + 1, false);

    input(N, M);
    ans = solve(N, k);

    if (ans > k) cout << "Oh no";
    else cout << ans;

    return 0;
}