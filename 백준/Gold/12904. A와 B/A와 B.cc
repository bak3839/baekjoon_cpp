#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    while (s.size() != t.size()) {
        int idx = t.size();

        if (t[idx - 1] == 'A') t.pop_back();
        else {     
            t.pop_back();            
            string tmp = t;
            int size = t.size() - 1;

            for (int i = 0; i < t.size(); i++) {
                t[size - i] = tmp[i];
            }
        }
    }
    
    if (s == t) cout << 1;
    else cout << 0;
    return 0;
}