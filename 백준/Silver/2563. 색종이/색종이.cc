#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
}Coor;

int N;
vector<vector<bool>> area;
vector<Coor> dot;


void Solution() {
    int ans = 0;

    for (int k = 0; k < N; k++) {
        int x = dot[k].x, y = dot[k].y;

        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (area[i][j]) continue;

                ans++;
                area[i][j] = true;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    dot.resize(N);
    area.resize(100, vector<bool>(100, false));

    for (int i = 0; i < N; i++)
        cin >> dot[i].x >> dot[i].y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}