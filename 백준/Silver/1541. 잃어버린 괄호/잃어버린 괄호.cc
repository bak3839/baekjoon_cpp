#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, n;
    cin >> s;
    int index = 0, plus = 1, sum1 = 0, sum2 = 0;

    while (index < s.size()) {
        if (plus && s[index] == '+') sum1 += stoi(n);
        else if (!plus && s[index] == '+') sum2 += stoi(n);
        else if (s[index] == '-') {
            if (plus) sum1 += stoi(n);
            else sum2 += stoi(n);
            plus = 0;        
        }
        else n.push_back(s[index]);

        if (s[index] == '+' || s[index] == '-') n.clear();
        ++index;
    }
    if (plus) sum1 += stoi(n);
    else sum2 += stoi(n);

    cout << sum1 - sum2;
    return 0;
}