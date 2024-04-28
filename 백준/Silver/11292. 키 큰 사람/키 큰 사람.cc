#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using psf = pair<string, float>;

int N;

void Solution() {
    string name;
    float stature, res = 0.0;

    vector<psf> student;

    for (int i = 0; i < N; i++) {
        cin >> name >> stature;
        student.push_back({ name, stature });

        res = max(res, stature);
    }

    for (int i = 0; i < N; i++) {
        if (student[i].second != res) continue;

        cout << student[i].first << " ";
    }
    cout << "\n";
}

void Solve() {
    while (1) {
        cin >> N;
        if (N == 0) return;

        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}