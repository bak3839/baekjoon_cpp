#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void Solution() {
    vector<int> v;
    deque<char> q;
    int N, n;
    char ch;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        if (n != 3) {
            cin >> ch;
            v.push_back(n);
            (n > 1) ? q.push_front(ch) : q.push_back(ch);
        }
        else {
            if (v.size() == 0) continue;

            int end = v.back();
            v.pop_back();
            (end > 1) ? q.pop_front() : q.pop_back();
        }
    }

    int size = q.size();

    if (size == 0) {
        cout << 0;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << q.front();
        q.pop_front();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution();
    return 0;
}