#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<string> v;
    vector<int> size;
    int end = 0;
    string s;

    while (getline(cin, s)) {
        v.push_back(s);
        size.push_back(s.size());
        end = end > s.size() ? end : s.size();
    }

    for (int i = 0; i < end; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (size[j] <= i) continue;

            cout << v[j][i];
        }
    }
    return 0;
}