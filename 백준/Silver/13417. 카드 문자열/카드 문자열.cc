#include <iostream>
#include <deque>

using namespace std;

void Solution() {
    int N, t;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char ch;
        deque<char> dq;
        cin >> t;

        for (int j = 0; j < t; j++) {
            cin >> ch;

            if (j == 0) 
                dq.push_back(ch);
            else 
                ch <= dq.front() ? dq.push_front(ch) : dq.push_back(ch);
        }

        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution();
    return 0;
}
