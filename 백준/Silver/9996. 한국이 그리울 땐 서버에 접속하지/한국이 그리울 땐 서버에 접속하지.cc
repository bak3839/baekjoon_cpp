#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

int N;
string pattern;
vector<string> file;

void Solution() {
    regex re(pattern);
    smatch match;

    for (int i = 0; i < N; i++) {
        if (regex_search(file[i], match, re)) cout << "DA\n";
        else cout << "NE\n";
    }
}

void Input() {
    string tmp = "";
    cin >> N >> tmp;

    file.resize(N);

    for (int i = 0; i < N; i++)
        cin >> file[i];

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] != '*') continue;

        pattern.append("^" + tmp.substr(0, i));
        pattern.append("[a-z]*");
        pattern.append(tmp.substr(i + 1) + "$");
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}