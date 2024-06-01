#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<stack<int>> dish;

void Solution() {
    int c, d;

    while (dish[2].size() != N) {
        cin >> c >> d;

        while (d--) {
            dish[c].push(dish[c - 1].top());
            dish[c - 1].pop();
        }
    }

    while (!dish[2].empty()) {
        cout << dish[2].top() << "\n";
        dish[2].pop();
    }
}

void Input() {
    cin >> N;

    dish.resize(3);

    for (int i = N; i > 0; i--)
        dish[0].push(i);
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