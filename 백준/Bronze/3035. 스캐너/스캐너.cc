#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char scanner[251][251];

int main() {
    int r, c, zr, zc;
    
    cin >> r >> c >> zr >> zc;
    
    for (int i = 1; i <= r; i++)
        for(int j = 1; j<=c; j++)
            cin >> scanner[i][j];
    
    for (int i = 1; i <= r; i++)
        for(int p = 1; p <= zr; p++,puts(""))
            for (int j = 1; j <= c; j++)
                for(int k = 1; k<=zc; k++)
                    cout << scanner[i][j];

}