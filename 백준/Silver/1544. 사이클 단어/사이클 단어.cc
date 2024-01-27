#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string word;
    set<string> s;

    cin >> N;

    for (int i = 0; i < N; i++){
        bool dup = false;
        cin >> word;

        if (s.size() == 0) s.insert(word);

        for (int j = 0; j < word.size(); j++) {
            word.push_back(word[0]);
            word.erase(0, 1);

            if (s.find(word) != s.end()) {
                dup = true;
                break;
            }
        }

        if (!dup) s.insert(word);
    }

    cout << s.size();
    
    return 0;
}
