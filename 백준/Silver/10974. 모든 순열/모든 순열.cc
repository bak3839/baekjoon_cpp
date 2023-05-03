#include <iostream>
#include <vector>

using namespace std;

vector<int> permu;
bool check[9];
int N;

void Print() {
    for (int i = 0; i < N; i++)
        cout << permu[i] << " ";
    cout << "\n";
}

void Solution() {
    if (permu.size() == N) Print();

    for (int i = 1; i <= N; i++) {
        if (check[i]) continue;
        check[i] = true;
        permu.push_back(i);
        Solution();
        check[i] = false;
        permu.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    Solution();
    return 0;
}