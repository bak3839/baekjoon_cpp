#include <iostream>
#include <vector>

using namespace std;

string gear[5];
bool visit[5];
int loc[5];

void Rotation(int n, int d);

void check(int n, int d) {
    string now = gear[n];
    visit[n] = true;

    if (n - 1 > 0 && !visit[n - 1]) {
        string left = gear[n - 1];
        int l_loc = loc[n - 1] + 2;
        int n_loc = loc[n] - 2;

        if (l_loc > 7) l_loc -= 8;
        if (n_loc < 0) n_loc += 8;

        if (left[l_loc] != now[n_loc]) Rotation(n - 1, d * -1);
    }

    if (n + 1 <= 4 && !visit[n + 1]) {
        string right = gear[n + 1];
        int r_loc = loc[n + 1] - 2;
        int n_loc = loc[n] + 2;

        if (r_loc < 0) r_loc += 8;
        if (n_loc > 7) n_loc -= 8;

        if (right[r_loc] != now[n_loc]) Rotation(n + 1, d * -1);
    }
}

void Rotation(int n, int d) {
    check(n, d);

    if (d == 1) {
        loc[n] -= 1;
        if (loc[n] < 0) loc[n] += 8;
    }

    else {
        loc[n] += 1;
        if (loc[n] > 7) loc[n] -= 8;
    }
}

void Input() {
    int N, num, dir;

    for (int i = 1;i <= 4;i++) cin >> gear[i];

    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> num >> dir;
        Rotation(num, dir);
        for (int j = 1;j <= 4;j++) visit[j] = false;
    }
}

void Summary() {
    int sum = 0;
    int point[5] = { 0, 1, 2, 4, 8 };

    for (int i = 1;i <= 4;i++) {
        string now = gear[i];

        if (now[loc[i]] == '1')
            sum += point[i];
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
  
    Input();
    Summary();
    return 0;
}