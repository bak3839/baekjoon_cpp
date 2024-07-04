#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    string name;
    int k;
    int e;
    int m;
}Info;

int N;
vector<Info> student;

bool cmp(Info i1, Info i2) {
    if (i1.k == i2.k) {
        if (i1.e == i2.e) {
            if (i1.m == i2.m) {
                return i1.name < i2.name;
            }
            else return i1.m > i2.m;
        }
        else return i1.e < i2.e;
    }
    else return i1.k > i2.k;
}


void Solution() {
    sort(student.begin(), student.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << student[i].name << "\n";
}

void Input() {
    cin >> N;

    student.resize(N);

    for (int i = 0; i < N; i++)
        cin >> student[i].name >> student[i].k >> student[i].e >> student[i].m;
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