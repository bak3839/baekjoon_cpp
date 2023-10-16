#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long;

vector<string> command;

void Execute(ll n) {
    stack<ll> s;
    s.push(n);

    for (int i = 0; i < command.size(); i++) {
        string c = command[i].substr(0, 3);

        if (c == "END") {
            if (s.size() != 1) cout << "ERROR\n";
            else cout << s.top() << "\n";
            break;
        }

        else if (c == "NUM") {
            s.push(stoi(command[i].substr(4)));
        }

        else if (c == "POP" || c == "INV" || c == "DUP") {
            if(s.size() < 1) {
                cout << "ERROR\n";
                break;
            }

            if (c == "POP") s.pop();

            else if (c == "DUP") s.push(s.top());

            else if (c == "INV") {
                int p = s.top();
                s.pop();
                s.push(-1 * p);
            }
        }

        else {           
            if (s.size() < 2) {
                cout << "ERROR\n";
                break;
            }

            ll n1, n2;
            n1 = s.top(); s.pop();
            n2 = s.top(); s.pop();
            
            if (c == "SWP") {
                s.push(n1); s.push(n2);
            }

            else if (c == "ADD") {
                if (abs(n1 + n2) > 1000000000) {
                    cout << "ERROR\n";
                    break;
                }

                s.push(n1 + n2);
            }

            else if (c == "SUB") {
                if (abs(n2 - n1) > 1000000000) {
                    cout << "ERROR\n";
                    break;
                }

                s.push(n2 - n1);
            }

            else if (c == "MUL") {
                if (abs(n1 * n2) > 1000000000) {
                    cout << "ERROR\n";
                    break;
                }

                s.push(n1 * n2);
            }

            else if (c == "DIV") {
                if (n1 == 0) {
                    cout << "ERROR\n";
                    break;
                }

                if((n1 > 0 && n2 >= 0) || (n1 < 0 && n2 < 0)) s.push(abs(n2) / abs(n1));
                else s.push(abs(n2) / abs(n1) * -1);
            }

            else if (c == "MOD") {
                if (n1 == 0) {
                    cout << "ERROR\n";
                    break;
                }

                if (n2 < 0) s.push(abs(n2) % abs(n1) * -1);
                else s.push(abs(n2) % abs(n1));
            }
        }      
    }    
}

void Solution() {
    int N;
    ll num;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        Execute(num);
    }
}

void Input() {
    string c;

    while (true) {
        getline(cin, c);

        if (c == "QUIT") break;
        if (c.empty()) continue;

        command.push_back(c);

        if (c == "END") {
            Solution();
            command.clear();
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    return 0;
}
