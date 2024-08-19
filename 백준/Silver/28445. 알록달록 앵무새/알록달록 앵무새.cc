#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<string> s;
vector<int> index;

void Search(int cnt, int size, vector<string>& color) {
    if (cnt == 2) {
        cout << color[index[0]] << " " << color[index[1]] << "\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        index.push_back(i);
        Search(cnt + 1, size, color);
        index.pop_back();
    }
}

void Solution() {
    vector<string> color(s.begin(), s.end());
    sort(color.begin(), color.end());

    Search(0, color.size(), color);
}

void Input() {
    string str;
    
    for (int i = 0; i < 4; i++) {
        cin >> str;
        s.insert(str);
    }     
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}