#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<string, string> m;
    m.insert(make_pair("ADD", "0000"));
    m.insert(make_pair("SUB", "0001"));
    m.insert(make_pair("MOV", "0010"));
    m.insert(make_pair("AND", "0011"));
    m.insert(make_pair("OR", "0100"));
    m.insert(make_pair("NOT", "0101"));
    m.insert(make_pair("MULT", "0110"));
    m.insert(make_pair("LSFTL", "0111"));
    m.insert(make_pair("LSFTR", "1000"));
    m.insert(make_pair("ASFTR", "1001"));
    m.insert(make_pair("RL", "1010"));
    m.insert(make_pair("RR", "1011"));

    string bitO[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
    string bitH[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

    while (N--) {
        string opcode, ans = "";
        int rD, rA, rB;
        bool isC = false;

        cin >> opcode >> rD >> rA >> rB;

        if (opcode.back() == 'C') {
            isC = true; 
            opcode.pop_back();
        }
        
        cout << m[opcode];

        if (isC) cout << "10";
        else cout << "00";

        cout << bitO[rD] << bitO[rA];

        if (isC) cout << bitH[rB] << "\n";
        else cout << bitO[rB] << "0\n";
    }
    
    return 0;
}