#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    cin >> N;

    int s, e;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        cin >> s >> e;

        while (s <= e) {
            if (s == e) {
                sum += v[s];
                s++; e--;
            }

            else {
                sum += v[s++] + v[e--];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
