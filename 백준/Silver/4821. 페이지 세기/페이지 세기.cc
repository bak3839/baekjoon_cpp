#include <bits/stdc++.h>

using namespace std;

int N;
bool checked[1001];

vector<string> split(const string& input, string delimiter) {
    vector<string> res;

    auto start = 0;
    auto end = input.find(delimiter);

    while (end != string::npos) {
        res.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }

    res.push_back(input.substr(start));
    return res;
}

int calc(vector<string> res) {
    int ans = 0;
    
    for (string s : res) {
        string tmp = "";
        int low = 0, high = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                low = stoi(tmp);
                tmp = "";
                continue;
            }

            tmp.push_back(s[i]);
        }

        if (low == 0) {
            low = stoi(tmp);
            high = low;
            if (low > N) continue;
        }
        else {
            high = stoi(tmp);

            if (high > N) high = N;
        }
        
        while (low <= high) {
            checked[low] = true;
            low++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (checked[i]) ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    vector<string> res;

    while (1) {
        cin >> N;

        if (N == 0) break;

        cin >> input;
        res = split(input, ",");
        cout << calc(res) << "\n";
        memset(checked, false, sizeof(checked));
    }
    return 0;
}