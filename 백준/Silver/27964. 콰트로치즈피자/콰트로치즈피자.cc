#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    set<string> s;
    string toping;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> toping;

        if (toping.size() >= 6) {
            if(toping.substr(toping.size() - 6, 6) == "Cheese") s.insert(toping);
        }

        if (s.size() == 4) break;
    }

    cout << (s.size() == 4 ? "yummy" : "sad");
    return 0;
}
