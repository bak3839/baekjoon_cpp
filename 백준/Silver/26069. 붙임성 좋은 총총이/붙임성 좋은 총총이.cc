#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    string p1, p2;
    set<string> s;

    for (int i = 0; i < N; i++) {
        bool b1 = false, b2 = false;
        cin >> p1 >> p2;

        if (p1 == "ChongChong" || p2 == "ChongChong") {
            s.insert(p1);
            s.insert(p2);
        }

        else if (s.find(p1) != s.end()) b1 = true;
        else if (s.find(p2) != s.end()) b2 = true;

        if (b1 && b2) continue;

        else if (b1) s.insert(p2);
        else if (b2) s.insert(p1);
    }

    cout << s.size();
    return 0;
}