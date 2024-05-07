#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
string original, target;

bool DeleteVowel() {
    string s1, s2;

    for(int i = 0; i < N; i++) {
        if(original[i] != 'a' &&
        original[i] != 'i' &&
        original[i] != 'o' &&
        original[i] != 'e' &&
        original[i] != 'u') {
            s1.push_back(original[i]);
        }

        if(target[i] != 'a' &&
        target[i] != 'i' &&
        target[i] != 'o' &&
        target[i] != 'e' &&
        target[i] != 'u') {
            s2.push_back(target[i]);
        }
    }

    if(s1 == s2) return true;
    return false;
}

bool Count() {
    vector<int> cnt(26, 0);

    for(int i = 0; i < N; i++) {
        cnt[original[i] - 'a']++;
    }

    for(int i = 0; i < N; i++) {
        if(cnt[target[i] - 'a'] == 0) {
            return false;
        }
    }

    return true;
}

bool FirstLastSame() {
    if(original[0] != target[0]) {
        return false;
    }

    if(original[N - 1] != target[N - 1]) {
        return false;
    }

    return true;
}

bool Sorting() {
    string c1 = original, c2 = target;

    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());

    if(c1 != c2) return false;
    return true;
}

void Solution() {
    if(Sorting() && FirstLastSame() && Count() && DeleteVowel()) {
        cout << "YES";
        return;
    }

    cout << "NO";
}

void Input() {    
    cin >> N >> original >> target;
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