#include <iostream>
#include <vector>

using namespace std;

int S, P, ans;
string DNA;

vector<int> cnt(21, 0);
vector<int> need(21, 0);
char base[4] = { 'A', 'C', 'G', 'T' };

void Check() {
    bool pass = true;

    for (int i = 0; i < 4; i++) {
        char ch = base[i];

        if (cnt[ch - 'A'] < need[ch - 'A']) {
            pass = false;
            break;
        }
    }

    if (pass) ans++;
}

void Solution() {
    for (int i = 0; i < P; i++) {
        char ch = DNA[i];

        cnt[ch - 'A']++;
    }

    Check();

    for (int i = P; i < S; i++) {
        char prev = DNA[i - P];
        char next = DNA[i];

        cnt[prev - 'A']--;
        cnt[next - 'A']++;

        Check();
    }

    cout << ans;
}

void Input() {
    
    cin >> S >> P;
    cin >> DNA;
    
    for (int i = 0; i < 4; i++)
        cin >> need[base[i] - 'A'];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}