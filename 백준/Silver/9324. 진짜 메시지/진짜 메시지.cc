#include <iostream>
#include <vector>

using namespace std;

string s;
vector<int> cnt;

void Solution() {
    bool pass = true;

    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'A';
        cnt[index]++;

        if (cnt[index] == 3) {

            if (i + 1 >= s.size()) {
                pass = false;
                break;
            }
            
            else if (s[i + 1] != s[i]) {
                pass = false;
                break;
            }

            cnt[index] = 0;
            i++;
        }
    }

    if (pass) cout << "OK\n";
    else cout << "FAKE\n";
}

void Input() {
    cin >> s;

    cnt.resize(26, 0);
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        cnt.clear();
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
