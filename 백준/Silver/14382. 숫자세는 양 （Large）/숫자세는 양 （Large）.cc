#include <bits/stdc++.h>

using namespace std;

bool visited[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, cnt = 1, tmp, n;
    string N;
    cin >> T;

   

    while (T--) {
        int res = 10;
        cin >> N;
        n = stoi(N);

        if (N == "0") {
            cout << "Case #" << cnt++ << ": INSOMNIA\n";
            continue;
        }

        int j = 1;

        while (1) {
            N = to_string(n * j++);

            for (int i = 0; i < N.size(); i++) {
                if (visited[N[i] - '0']) continue;

                res--;
                visited[N[i] - '0'] = true;
            }

            if (res == 0) break;
        }

        cout << "Case #" << cnt++ << ": " << N << "\n";
        memset(visited, false, sizeof(visited));
    }
    return 0;
}