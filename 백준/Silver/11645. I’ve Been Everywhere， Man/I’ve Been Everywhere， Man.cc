#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, N;
    cin >> T;

    while(T--) {
        set<string> s;
        string city;
        cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> city;
            s.insert(city);
        }

        cout << s.size() << "\n";
    }
    
    return 0;
}