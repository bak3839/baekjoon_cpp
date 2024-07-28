#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> word;

bool cmp(string s1, string s2) {
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return  s1 < s2;
}

void Solution() {
    sort(word.begin(), word.end(), cmp);

    cout << word[0] << "\n";
}

void Input() {
    string str;
    word.clear();

    for (int i = 0; i < N; i++) {
        cin >> str;
        word.push_back(str);
    }
}

void Solve() {
    while (1) {
        cin >> N;

        if (N == 0) break;

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