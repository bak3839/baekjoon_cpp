#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int N;

void Solution() {
    queue<int> q;
    q.push(2);
    int sum = 2, prime = 3, ans = 0;

    while (1) {
        if (sum > N) {
            sum -= q.front();
            q.pop();
        }

        else if (sum == N) {
            ans++;
            sum -= q.front();
            q.pop();
        }

        else if (q.size() == 0) break;

        else {
            int end = (int)sqrt(prime);
            bool pass = true;

            for (int i = 2; i <= end; i++) {
                if (prime % i == 0) {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                sum += prime;

                q.push(prime);
            }

            prime++;
        }          
    }

    cout << ans;
}

void Input() {
    cin >> N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}