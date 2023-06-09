#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, rcnt = 0, ccnt = 0;
    cin >> N;
    vector<string> v(N);

    for (int i = 0;i < N;i++) cin >> v[i];

    for (int i = 0;i < N;i++) {
        int cnt = 0;
        string now = v[i];

        for (int j = 0;j < N;j++) {          
            if (now[j] == '.') {
                cnt++;
                if (cnt == 2) rcnt++;
            }

            else cnt = 0;
        }
    }

    for (int i = 0;i < N;i++) {
        int cnt = 0;

        for (int j = 0;j < N;j++) {
            if (v[j][i] == '.') {
                cnt++;
                if (cnt == 2) ccnt++;
            }

            else cnt = 0;
        }
    }

    cout << rcnt << " " << ccnt;
    return 0;
}