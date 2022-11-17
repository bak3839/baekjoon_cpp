#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    string s, num;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int index = 0, sum = 0;
        cin >> s;

        if (s[0] == 'P') {
            cout << "skipped\n";
            continue;
        }

        while (index < s.size()) {
            if (s[index] == '+') {
                sum += stoi(num);
                num.clear();
            }

            else num.push_back(s[index]);
            ++index;
        }
        sum += stoi(num);
        cout << sum << "\n";
        num.clear();
    }

    return 0;
}
