#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, ans = 0;
    bool pass = false;
    cin >> N;

    for(int i = 1; i < N; i++) {
        int res = i;
        string num = to_string(i);

        for(int j = 0; j < num.size(); j++) {
            res += num[j] - '0';
        }

        if(res == N) {
            ans = i;
            break;
        }
    }

    cout << ans;  
    return 0;
}