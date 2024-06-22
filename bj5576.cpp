#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> W(10);
    vector<int> V(10);

    for(int i=0;i<10;i++) {
        cin >> W[i];
    }

    for(int i=0;i<10;i++) {
        cin >> V[i];
    }

    sort(W.begin(), W.end(), greater<int>());
    sort(V.begin(), V.end(), greater<int>());

    cout << W[0] + W[1] + W[2] << " " << V[0] + V[1] + V[2];
    return 0;
}
