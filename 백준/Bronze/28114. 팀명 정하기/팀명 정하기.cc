#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int p;
    int y;
    string s;
}Member;

bool compare1(Member m1, Member m2) {
    return ((m1.y % 100) < (m2.y % 100));
}

bool compare2(Member m1, Member m2) {
    return m1.p > m2.p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int p, y;
    string s;
    vector<Member> team(3);

    for (int i = 0; i < 3; i++) {
        cin >> p >> y >> s;
        team[i] = { p, y, s };
    }

    sort(team.begin(), team.end(), compare1);

    for (int i = 0; i < 3; i++)
        cout << team[i].y % 2000;
    cout << "\n";

    sort(team.begin(), team.end(), compare2);

    for (int i = 0; i < 3; i++)
        cout << team[i].s[0];

    return 0;
}