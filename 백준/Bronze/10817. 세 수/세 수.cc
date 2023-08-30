#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> num(3);

    for (int i = 0; i < 3; i++)
        cin >> num[i];
    sort(num.begin(), num.end());

    cout << num[1];
    return 0;
}
