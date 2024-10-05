#include <iostream>
#include <string>

using namespace std;
using ll = long long;

char change(string s) {
    char ret;
    if (s == ".-") ret = 'A';
    if (s == "-...") ret = 'B';
    if (s == "-.-.") ret = 'C';
    if (s == "-..") ret = 'D';
    if (s == ".") ret = 'E';
    if (s == "..-.") ret = 'F';
    if (s == "--.") ret = 'G';
    if (s == "....") ret = 'H';
    if (s == "..") ret = 'I';
    if (s == ".---") ret = 'J';
    if (s == "-.-") ret = 'K';
    if (s == ".-..") ret = 'L';
    if (s == "--") ret = 'M';
    if (s == "-.") ret = 'N';
    if (s == "---") ret = 'O';
    if (s == ".--.") ret = 'P';
    if (s == "--.-") ret = 'Q';
    if (s == ".-.") ret = 'R';
    if (s == "...") ret = 'S';
    if (s == "-") ret = 'T';
    if (s == "..-") ret = 'U';
    if (s == "...-") ret = 'V';
    if (s == ".--") ret = 'W';
    if (s == "-..-") ret = 'X';
    if (s == "-.--") ret = 'Y';
    if (s == "--..") ret = 'Z';
    if (s == ".----") ret = '1';
    if (s == "..---") ret = '2';
    if (s == "...--") ret = '3';
    if (s == "....-") ret = '4';
    if (s == ".....") ret = '5';
    if (s == "-....") ret = '6';
    if (s == "--...") ret = '7';
    if (s == "---..") ret = '8';
    if (s == "----.") ret = '9';
    if (s == "-----") ret = '0';
    if (s == "--..--") ret = ',';
    if (s == ".-.-.-") ret = '.';
    if (s == "..--..") ret = '?';
    if (s == "---...") ret = ':';
    if (s == "-....-") ret = '-';
    if (s == ".--.-.") ret = '@';
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll N, i;
    string s;
    
    cin >> N;
    
    for (i = 0; i < N; i++) {
        cin >> s;
        cout << change(s);
    }
}