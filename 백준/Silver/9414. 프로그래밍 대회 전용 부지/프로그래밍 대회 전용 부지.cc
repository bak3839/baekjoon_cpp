#include <bits/stdc++.h>

using namespace std;

const int MONEY = 5000000;
vector<int> v;

int calc() {
    sort(v.begin(), v.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += (pow(v[i], i + 1) * 2);

        if (res > MONEY) return -1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, n, ans;
    cin >> T;

    while (T) {
        cin >> n;

        if (n != 0) v.push_back(n);
        else {
            ans = calc();

            if (ans == -1) cout << "Too expensive\n";
            else cout << ans << "\n";
            T--;
            v.clear();
        }       
    }
   
    return 0;
}