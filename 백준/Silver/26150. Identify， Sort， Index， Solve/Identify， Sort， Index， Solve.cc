#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct {
    string name;
    int num;
    int level;
}Problem;

int N;
string ans;
vector<Problem> problems;

bool compare1(Problem p1, Problem p2) {
    return p1.num < p2.num;
}

void Sort() {
    sort(problems.begin(), problems.end(), compare1);
}

void Index() {
    for (auto p : problems) 
        ans.push_back(p.name[p.level - 1]);
}

void Solve() {
    for (int i = 0; i < ans.size(); i++)
        ans[i] = toupper(ans[i]);

    cout << ans;
}

void Solution() {
    Sort();
    Index();
    Solve();
}

void Input() {
    string name;
    int n, l;
    cin >> N;

    problems.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> name >> n >> l;
        problems[i] = { name, n, l};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}