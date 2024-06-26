#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> v(5);
        
        for (int j = 0; j < 5; j++) cin >> v[j];

        sort(v.begin(), v.end());

        if (v[3] - v[1] >= 4) {
            cout << "KIN\n";
            continue;
        }
        
        int ssum = 0;
        
        for (int j = 1; j < 4; j++) ssum += v[j];
        
        cout << ssum << '\n';
    }
}