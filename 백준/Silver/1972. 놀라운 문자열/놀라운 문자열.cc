#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> s;
    string str;

    while (1) {
        cin >> str;

        if (str == "*") break;

        bool surpise = true;

        for (int i = 1; i < str.size(); i++) {
            for (int j = 0; j < str.size(); j++) {
                int next = j + i;

                if (next >= str.size()) break;

                string res = "";
                res.push_back(str[j]);
                res.push_back(str[next]);

                if (s.find(res) != s.end()) {
                    surpise = false;
                    goto line;
                }

                s.insert(res);
            }
            s.clear();
        }

    line:
        cout << str << (surpise ? " is surprising.\n" : " is NOT surprising.\n");
        s.clear();
    }

    return 0;
}