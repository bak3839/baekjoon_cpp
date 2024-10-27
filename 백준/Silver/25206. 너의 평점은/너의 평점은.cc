#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<string, double> m;
    m["A+"] = 4.5;
    m["A0"] = 4.0;
    m["B+"] = 3.5;
    m["B0"] = 3.0;
    m["C+"] = 2.5;
    m["C0"] = 2.0;
    m["D+"] = 1.5;
    m["D0"] = 1.0;
    m["F"] = 0.0;

    string subject, point;
    double unit;

    double sum = 0.0, cnt = 0.0;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> unit >> point;

        if (point == "P") continue;

        cnt += unit;
        sum += (unit * m[point]);
    }

    cout << fixed;
    cout.precision(6);
    cout << sum / cnt;
    return 0;
}