#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<int, int> m;
    int N, c, w, x;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> c;

        if(c == 1) {
            cin >> x >> w;
            m[w] = x;
        }
        else {
            cin >> w;
            cout << m[w] << "\n";
        }
    }
    return 0;
}