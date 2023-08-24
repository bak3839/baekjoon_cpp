#include <iostream>
#include <string>

using namespace std;

string Change(int t) {
    string str = "";

    int m = t / 60, s = t % 60;

    if (m == 0) str.append("00:");
    else if (m < 10) str.append("0" + to_string(m) + ":");
    else str.append(to_string(m) + ":");

    if (s == 0) str.append("00");
    else if (s < 10) str.append("0" + to_string(s));
    else str.append(to_string(s));

    return str;
}

void Solution() {
    string time;
    int N, t, M, S, point1 = 0, point2 = 0;
    int t1_time = 0, t2_time = 0, res1 = 0, res2 = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t >> time;
      
        if (t == 1) point1++;
        else point2++;

        M = stoi(time.substr(0, 2)) * 60;
        S = stoi(time.substr(3, 2));

        if (t == 1 && point1 - 1 == point2) t1_time = M + S;

        else if (t == 2 && point2 - 1 == point1) t2_time = M + S;

        if (point1 == point2) {
            if (t == 1) {
                res2 += (M + S) - t2_time;
                t2_time = M + S;
            }

            else {
                res1 += (M + S) - t1_time;
                t1_time = M + S;
            }
        }
    }

    if (point1 > point2) res1 += (48 * 60) - t1_time;
    else if (point2 > point1) res2 += (48 * 60) - t2_time;

    cout << Change(res1) << "\n" << Change(res2);    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution();
    return 0;
}