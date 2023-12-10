#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str;
vector<int> num;

void Solution() {
    if (!next_permutation(num.begin(), num.end())) 
        cout << "BIGGEST\n";
    else {
        for (auto n : num)
            cout << n;
        cout << "\n";
    }

    num.clear();
}

void Input() {
    cin >> str;

    num.resize(str.size());

    for (int i = 0; i < str.size(); i++)
        num[i] = str[i] - '0';
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
