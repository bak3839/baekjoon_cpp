#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> ans;

void zeroAvailable(string exp) {
    int sum = 0, s = 0;
    string num = "";
    char prev = ' ';

    for(int i = 0; i < exp.size(); i++) {
        if(exp[i] == ' ') {
            continue;
        }

        else if(exp[i] == '+' || exp[i] == '-') {
            s = i + 1;
            prev = exp[i] == '+' ? '+' : '-';
            sum = stoi(num);
            num.clear();
            break;
        }

        else {
            num.push_back(exp[i]);
        }
    }

    for(int i = s; i < exp.size(); i++) {
        if(exp[i] == ' ') {
            continue;
        }

        else if(exp[i] == '+') {
            if(prev == '-') {
                sum -= stoi(num);
                num.clear();
            }

            else if(prev == '+') {
                sum += stoi(num);
                num.clear();
            }

            prev = '+';
        }

        else if(exp[i] == '-') {
            if(prev == '-') {
                sum -= stoi(num);
                num.clear();
            }

            else if(prev == '+') {
                sum += stoi(num);
                num.clear();
            }

            prev = '-';
        }

        else {
            num.push_back(exp[i]);
        }
    }

    if(num.size() != 0) {
        if(prev == '+') sum += stoi(num);
        else if(prev == '-') sum -= stoi(num);
    }

    if(sum == 0 && prev != ' ') {
        ans.push_back(exp);
    }
}

void Search(string exp, int n) {
    if(n > N) {
        zeroAvailable(exp);
        return;
    }

    Search(exp + " " + to_string(n), n + 1);
    Search(exp + "+" + to_string(n), n + 1);
    Search(exp + "-" + to_string(n), n + 1);
}

void Solution() {
    Search("1", 2);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    cout << "\n";
    ans.clear();
}

void Input() {
    cin >> N;
}

void Solve() {
    int T;
    cin >> T;

    while(T--) {
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