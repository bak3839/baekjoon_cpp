#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    set<string, greater<string>> s;
    set<string>::iterator iter;
    string str, name, status;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, str);
        stringstream parse(str);

        parse >> name >> status;
        
        if (!status.compare("enter")) 
            s.insert(name);

        else {
            iter = s.find(name);
            if(iter != s.end())s.erase(iter);
        }
    }

    for (iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << "\n";
    }
    return 0;
}
