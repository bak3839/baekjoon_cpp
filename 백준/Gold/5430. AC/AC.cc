#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int N;
string function, nums;

void Solution() {
    deque<int> dq;
    string num = "";
    bool front = true;

    for (int i = 1; i < nums.size(); i++) {
        char n = nums[i];

        if ('0' <= n && n <= '9')
            num.push_back(n);

        else if(!num.empty()) {
            dq.push_back(stoi(num));
            num = "";
        }
    }

    for (auto f : function) {
        if (f == 'R') {
            front = !front;
            continue;
        }

        if (dq.empty()) {
            cout << "error\n";
            return;
        }

        if (front) dq.pop_front();
        else dq.pop_back();
    }

    cout << "[";
    while (!dq.empty()) {
        if (front) {
            cout << dq.front();
            dq.pop_front();
            if (!dq.empty()) cout << ",";
        }
        else {
            cout << dq.back();
            dq.pop_back();
            if (!dq.empty()) cout << ",";
        }
    }
    cout << "]\n";
}

void Input() {
    cin >> function >> N >> nums;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}