#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N;
string ans;

void DeleteDash(int s, int len) {
    int start = len / 3 + s, end = len / 3 * 2 + s;

    for(int i = start; i < end; i++) {
        ans[i] = ' ';
    }

    if(len > 3) {
        DeleteDash(s, len / 3);
        DeleteDash(end, len / 3);
    }
}

void Solution() {
    int n = pow(3, N);
    ans = "";

    for(int i=0;i<n;i++) {
        ans.push_back('-');
    }

    DeleteDash(0, n);
    cout << ans << "\n";
}

void Solve() {   
    while(cin >> N) {
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}