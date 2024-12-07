#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_digit(string input) {
    if (input[0] != '0' && input.size() <= 17 && atoi(input.c_str()) != 0 && input != "0") return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int a = 0, ans = 0;

    do {
        cin >> input;

        if (input == "[") a++;
        else if (input == "]") {
            a--;
            ans += 8;
        }
        else if (is_digit(input)) ans += 8;
        else ans += (12 + input.size());

    } while (a > 0);

    cout << ans;
    return 0;
}