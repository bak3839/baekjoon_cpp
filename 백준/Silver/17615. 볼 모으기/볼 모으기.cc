#include <bits/stdc++.h>

using namespace std;

bool flag = false;
int ans = INT_MAX;
int N;
string ball;

void left(char ch) {
    int cnt = 0;
    bool flag = false;

    for(int i = 0; i < ball.size(); i++) {
        if(ball[i] == ch) flag = true;
        
        else {
            if(flag) cnt++;
        }
    }

    ans = min(ans, cnt);
}

void right(char ch) {
    int cnt = 0;
    bool flag = false;

    for(int i = ball.size() - 1; i >= 0; i--) {
        if(ball[i] == ch) flag = true;
        
        else {
            if(flag) cnt++;
        }
    }

    ans = min(ans, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> ball;
    left('R'); left('B');
    right('R'); right('B');
    cout << ans;
    return 0;
}