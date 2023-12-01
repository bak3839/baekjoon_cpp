#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string s, sub1, sub2;

void Solution() {
    int index = 0;

    for (int i = 0; i < sub2.size(); i++) {
        if (sub1[index] == sub2[i]) index++;
        if (index == sub1.size()) break;
    }

    if (index == sub1.size()) cout << "Yes\n";
    else cout << "No\n";
}

bool Input() {
    getline(cin, s);

    if (s.empty()) return true;

    stringstream ss(s);
    ss >> sub1 >> sub2;
  
    return false;
}

void Solve() {
    while (1) {
        if (Input()) break;
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
