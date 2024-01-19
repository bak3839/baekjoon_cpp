#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, ans = 0;
    string name;
    set<string> s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name;

        if (name == "ENTER") {
            ans += s.size();
            s.clear();
            continue;
        }

        s.insert(name);
    }
    ans += s.size();

    cout << ans;
    return 0;
}
