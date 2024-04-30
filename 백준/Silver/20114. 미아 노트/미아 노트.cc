#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, H, W;
vector<string> word;

void Solution() {
    string ans = "";

    for (int i = 0; i < N; i++) {
        int s = i * W;
        bool pass = false;

        for (int w = s; w < s + W; w++) {
            for (int h = 0; h < H; h++) {
                if (word[h][w] == '?') continue;

                pass = true;
                ans.push_back(word[h][w]);
                break;
            }

            if (pass) break;
        }

        if(!pass) ans.push_back('?');
    }

    cout << ans;
}

void Input() {
    cin >> N >> H >> W;
    
    word.resize(H);

    for (int i = 0; i < H; i++)
        cin >> word[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}