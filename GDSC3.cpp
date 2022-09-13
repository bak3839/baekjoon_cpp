#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int num, cnt = 0;
    stack<int> s;
    vector<vector<int>> board = {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1} 
    };

    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            int doll = board[j][moves[i] - 1];

            if (doll != 0) {
                if (s.empty() || s.top() != doll) {
                    s.push(doll);
                    board[j][moves[i] - 1] = 0;
                    break;
                }

                else if (s.top() == doll) {
                    s.pop();
                    board[j][moves[i] - 1] = 0;
                    cnt += 2;
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}