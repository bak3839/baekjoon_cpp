#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N;

void Solution() {
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    map<int, int> delMax;
    map<int, int> delMin;
    vector<int> res;
    string s;
    int n, tmp;

    while (N--) {
        getline(cin, s);
        char mode = s[0];
        int num = stoi(s.substr(2));

        if (mode == 'I') {
            max_pq.push(num);
            min_pq.push(num);
        }

        else if(mode == 'D') {
            if (num == 1) {
                while (!max_pq.empty()) {
                    n = max_pq.top();

                    if (delMin.find(n) != delMin.end()) {
                        tmp = delMin[n] - 1;
                        delMin[n] = tmp;
                        max_pq.pop();

                        if (tmp == 0) {
                            delMin.erase(n);
                        }
                    }
                    else {
                        delMax[n]++;
                        max_pq.pop();
                        break;
                    }
                }
            }
            else {
                while (!min_pq.empty()) {
                    n = min_pq.top();

                    if (delMax.find(n) != delMax.end()) {
                        tmp = delMax[n] - 1;
                        delMax[n] = tmp;
                        min_pq.pop();

                        if (tmp == 0) {
                            delMax.erase(n);
                        }
                    }
                    else {
                        delMin[n]++;
                        min_pq.pop();
                        break;
                    }
                }
            }
        }
    }

    if (max_pq.empty() || min_pq.empty()) {
        cout << "EMPTY\n";
        return;
    }

    while (!max_pq.empty()) {
        n = max_pq.top();

        if (delMin.find(n) != delMin.end()) {
            tmp = delMin[n] - 1;
            delMin[n] = tmp;

            max_pq.pop();

            if (tmp == 0) {
                delMin.erase(n);
            }
        }
        else {
            res.push_back(n);
            max_pq.pop();
        }
    }

    while (!min_pq.empty()) {
        n = min_pq.top();

        if (delMax.find(n) != delMax.end()) {
            tmp = delMax[n] - 1;
            delMax[n] = tmp;
            min_pq.pop();

            if (tmp == 0) {
                delMax.erase(n);
            }     
        }
        else {
            res.push_back(n);
            min_pq.pop();
        }
    }

    if (res.empty()) {
        cout << "EMPTY\n";
        return;
    }

    sort(res.begin(), res.end());
    cout << res[res.size() - 1] << " " << res[0] << "\n";
}

void Input() {
    cin >> N;
    cin.ignore();
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
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}