#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

typedef struct {
    double x;
    double y;
}Star;

typedef struct {
    int v1;
    int v2;
    double cost;
}Edge;

vector<Star> star;
vector<Edge> edge;

vector<int> parent;
double ans = 0.0;

int getRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(Edge e) {
    e.v1 = getRoot(e.v1);
    e.v2 = getRoot(e.v2);

    if (e.v1 == e.v2) return;

    if (e.v1 < e.v2) parent[e.v2] = e.v1;
    else parent[e.v1] = e.v2;
    ans += e.cost;
}

bool cmp(Edge e1, Edge e2) {
    if (e1.cost < e2.cost) return true;
    return false;
}

void Solution() {
    Edge e;
    double sum = 0.0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double x = pow(star[j].x - star[i].x, 2);
            double y = pow(star[j].y - star[i].y, 2);
            sum = sqrt(x + y);

            e.v1 = i; e.v2 = j;
            e.cost = sum;
            edge.push_back(e);
        }
    }

    sort(edge.begin(), edge.end(), cmp);

    for (int i = 0; i < edge.size(); i++) {
        Union(edge[i]);
    }
    cout << ans;
}

void Input() {
    cin >> N;

    star.resize(N);
    parent.resize(N);

    Star s;
    for (int i = 0; i < N; i++) {
        cin >> s.x >> s.y;
        star[i] = s;
        parent[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}