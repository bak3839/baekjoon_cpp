#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double cnt = 0;
    string str, parse;
    map<string, int> m;

    while (getline(cin, str)) {
        stringstream ss(str);

        while (ss >> parse) {
            cnt++;

            m[parse]++;
        }
    }

    vector<string> work = { "Re","Pt","Cc","Ea","Tb","Cm","Ex" };

    for (int i = 0; i < 7; i++) {
        if (m.find(work[i]) != m.end()) {
            int res = m[work[i]];

            cout << work[i] << " " << res << " ";
            cout << fixed << setprecision(2) << res/cnt << "\n";
        }
        else {
            cout << work[i] << " " << 0 << " " << "0.00\n";
        }
    }
    cout << "Total " << (int)cnt << " 1.00";
    return 0;
}
