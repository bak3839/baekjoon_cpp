#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    (N % 2) == 0 ? cout << "SK" : cout << "CY";
    return 0;
}