#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "WelcomeToSMUPC";
    int N;
    cin >> N;
    int index = N % 14 - 1;
    if (index == -1) index = 13;
    cout << s[index];
    return 0;
}