#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string word;
    set<string> s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> word;
        sort(word.begin(), word.end());
        s.insert(word);
    }

    cout << s.size();
    return 0;
}
