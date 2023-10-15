#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> key1;
vector<string> key2;
vector<string> ciper;
vector<string> plain;

void Solution() {
    vector<int> index(N);
    plain.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (key1[i] == key2[j])
                index[i] = j;
        }
    }

    for (int i = 0; i < N; i++)
        plain[i] = ciper[index[i]];

    for (int i = 0; i < N; i++)
        cout << plain[i] << " ";
    cout << "\n";

    key1.clear(); key2.clear();
    ciper.clear(); plain.clear();
}

void Input() {   
    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        key1.push_back(str);
    }

    for (int i = 0; i < N; i++) {
        cin >> str;
        key2.push_back(str);
    }

    for (int i = 0; i < N; i++) {
        cin >> str;
        ciper.push_back(str);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }  

    return 0;
}
