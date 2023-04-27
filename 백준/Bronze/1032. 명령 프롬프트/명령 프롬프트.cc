#include <iostream>
#include <vector>

using namespace std;
string ans;

vector<string> s;

void Solution(int N) {
    int size = s[0].size();

    for (int i = 0; i < size; i++) {
        string str = s[0];
        ans.push_back(str[i]);

        for (int j = 1; j < N; j++) {
            string tmp = s[j];
            if (tmp[i] != str[i]) {
                ans.pop_back();
                ans.push_back('?');
            }
        }
    }
    cout << ans;
}

void Input(int N) {
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.push_back(str);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    Input(N);
    Solution(N);
    return 0;
}