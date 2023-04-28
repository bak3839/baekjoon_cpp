#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int s;
    int e;
    int w;
}Road;

vector<int> parent;
vector<Road> road;
int c, v;

int getRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (a > b) parent[b] = a;
    else parent[a] = b;
}

void Solution() {
    for (auto r : road) {
        Union(r.s, r.e);
        if (getRoot(c) == getRoot(v)) {
            cout << r.w;
            break;
        }
    }
}

bool cmp(Road r1, Road r2) {
    return r1.w > r2.w ? true : false;
}

void Input(int P, int W) {
    Road r;
    int s, e, w;
    parent.resize(P);
    road.resize(W);

    cin >> c >> v;
    for (int i = 0;i < P;i++)
        parent[i] = i;

    for (int i = 0;i < W;i++) {
        cin >> r.s >> r.e >> r.w;
        road[i] = r;
    }
    sort(road.begin(), road.end(), cmp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int p, w;
    cin >> p >> w;
    Input(p, w);
    Solution();
    return 0;
}