#include <iostream>
#include <string>
#include <map>

using namespace std;

int cnt;
map<string, float> m;

void Solution() {
    cout << fixed;
    cout.precision(4);

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " ";
        cout << (iter->second / cnt) * 100 << "\n";
    }

}

void Input() {
    string str;

    while (getline(cin, str)) {
        cnt++;

        if (m.find(str) != m.end()) m[str]++;
        else m.insert({ str, 1 });
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}