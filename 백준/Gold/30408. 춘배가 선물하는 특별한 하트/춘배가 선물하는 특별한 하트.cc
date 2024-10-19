#include <iostream>
#include <set>

using namespace std;
using ll = long long;

ll N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    set<ll> S;
    cin >> N >> M;
    
    S.insert(N);

    while(N > 1) {
        ll A1, A2;
        
        if(N % 2) {
            A1 = (N - 1) / 2;
            A2 = A1 + 1;
            S.insert(A1);
            S.insert(A2);

            N = (A1 % 2 ? A1 : A2);
        } else {
            A1 = N / 2;
            S.insert(A1);

            N = A1;
        }
    }

    if(S.find(M) != S.end()) cout << "YES";
    else cout << "NO";
    return 0;
}