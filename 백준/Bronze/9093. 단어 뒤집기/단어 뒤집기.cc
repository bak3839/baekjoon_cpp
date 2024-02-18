#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s, word;
        getline(cin, s);

        stringstream ss(s);

        while (ss >> word) {
            for (int i = word.size() - 1; i >= 0; i--)
                cout << word[i];
            cout << " ";
        }
        cout << "\n";
    }    

    return 0;
}
