#include <iostream>
#include <vector>

using namespace std;

int value[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

vector<int> point;

void Solution() {
    while (point.size() > 2) {
        for (int i = 0; i < point.size() - 1; i++) {
            point[i] = (point[i] + point[i + 1]) % 10;
        }
        point.pop_back();
    }

    cout << point[0] << point[1];
}

void Input() {
    string my, her;
    cin >> my >> her;

    for (int i = 0; i < my.size() * 2; i++) {
        if (i % 2) point.push_back(value[her[i / 2] - 'A']);
        else point.push_back(value[my[i / 2] - 'A']);
    }
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
