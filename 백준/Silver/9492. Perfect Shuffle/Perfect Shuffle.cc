#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    

    while (1) {
        cin >> N;

        if (N == 0) break;

        string card;
        vector<string> v1, v2;
        int half = N / 2, v1Count = 0, v2Count = 0;

        if (N % 2) half++;

        for (int i = 0; i < N; i++) {
            cin >> card;

            if (i < half) v1.push_back(card);
            else v2.push_back(card);
        }

        for (int i = 1; i <= N; i++) {
            if (i % 2) cout << v1[v1Count++] << "\n";
            else cout << v2[v2Count++] << "\n";
        }
    }
    return 0;
}