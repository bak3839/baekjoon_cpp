#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
long long ansMax, ansMin = 9900000000;
string ans_max, ans_min;
vector<char> sign;
vector<bool> num;

void Search(string res, int idx) {
    if (idx == N) {
        if (ansMax < stoll(res)) {
            ansMax = stoll(res);
            ans_max = res;
        }

        if (ansMin > stoll(res)) {
            ansMin = stoll(res);
            ans_min = res;
        }

        return;
    }
    
    if (sign[idx] == '<') {
        for (int i = res.back() - 48 + 1; i < 10; i++) {
            if (num[i]) continue;
            
            num[i] = true;
            res.push_back(i + 48);
            Search(res, idx + 1);
            num[i] = false;
            res.pop_back();
        }
    }

    else {
        for (int i = res.back() - 48 - 1; i >= 0; i--) {
            if (num[i]) continue;
            
            num[i] = true;
            res.push_back(i + 48);
            Search(res, idx + 1);
            num[i] = false;
            res.pop_back();
        }
    }
    
    return;
}

void Solution() {
    for (int i = 0; i < 10; i++) {
        num[i] = true;
        Search(to_string(i), 0);
        num[i] = false;
    }
    cout << ans_max << "\n" << ans_min;
}

void Input() {
    cin >> N;
    sign.resize(N);
    num.resize(10, false);

    for (int i = 0; i < N; i++)
        cin >> sign[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    
    return 0;
}