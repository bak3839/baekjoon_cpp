#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int getRoot(int x) {
    if (parent[x] == x) return x;
    else return getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    else if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, connect;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> connect;
            if (i == j || !connect) continue;
            Union(i, j);
        }
    }

    bool pass = true;
    int x, root = 0;
    for (int i = 1; i <= M; i++) {
        cin >> x;
        if (i == 1) root = getRoot(x);
        else {
            if (getRoot(x) != root) {
                pass = false;
                break;
            }
        }
    }
    
    if (pass) cout << "YES";
    else cout << "NO";
    return 0;
}