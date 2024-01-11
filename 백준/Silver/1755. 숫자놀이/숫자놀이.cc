#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using pis = pair<int, string>;

int N, M;
vector<pis> num;

bool cmp(pis p1, pis p2) {
    return p1.second < p2.second;
}

void Solution() {
    sort(num.begin(), num.end(), cmp);

    for (int i = 0; i < num.size(); i++) {
        cout << num[i].first << " ";
        if (i % 10 == 9) cout << "\n"; 
    }
}

void Input() {
    cin >> N >> M;

    for (int i = N; i <= M; i++) {
        string n = to_string(i), res = "";

        for (int j = 0; j < n.size(); j++) {
            if (j != 0) res.push_back(' ');

            switch (n[j]) {
            case '0':
                res.append("zero");
                break;
            case '1':
                res.append("one");
                break;
            case '2':
                res.append("two");
                break;
            case '3':
                res.append("three");
                break;
            case '4':
                res.append("four");
                break;
            case '5':
                res.append("five");
                break;
            case '6':
                res.append("six");
                break;
            case '7':
                res.append("seven");
                break;
            case '8':
                res.append("eight");
                break;
            case '9':
                res.append("nine");
                break;
            default:
                break;
            }
        }
        num.push_back({ i, res });
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
