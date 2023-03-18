#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y;
    cin >> x >> y;
    int days = 0;
    for (int i = 1; i < x; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        }
        else if (i == 2) {
            days += 28;
        }
        else {
            days += 31;
        }
    }
    days += y;
    switch (days % 7) {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    }
}