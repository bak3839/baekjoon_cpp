#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int a;
    int b;
}dot;

bool cmp(dot d1, dot d2) {
    if (d1.a < d2.a) return true;
    else if (d1.a == d2.a) return d1.b < d2.b;
    else return false;

//4
//6 7
//2 5
//2 7
//3 5
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dot d;
    int N;
    vector<dot> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d.a >> d.b;
        v.push_back(d);
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 0, low, high; 
    low = v[0].a;
    high = v[0].b;
    ans += high - low;

    for (int i = 1; i < N; i++) {
        d = v[i];

        if (d.a < high) {
            if (high < d.b) {
                ans += d.b - high;
                high = d.b;
            }
        }

        else {
            ans += d.b - d.a;
            low = d.a;
            high = d.b;
        }
    }
    
    cout << ans;
    return 0;
}

