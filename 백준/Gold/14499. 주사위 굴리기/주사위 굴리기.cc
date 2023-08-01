#include <iostream>
#include <vector>

using namespace std;

int N, M, X, Y, K;

vector<vector<int>> map;
vector<int> command;
vector<int> dice;

// 동쪽으로 굴리기
void rollEast(){
    dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}

// 서쪽으로 굴리기
void rollWest(){
    dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
}

// 북쪽으로 굴리기
void rollNorth(){
    dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}

// 남쪽으로 굴리기
void rollSouth(){
    dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}

void roll(int dir) {
    if (dir == 1) rollEast();
    else if (dir == 2) rollWest();
    else if (dir == 3) rollNorth();
    else rollSouth();
}

bool Move(int* x, int* y, int dir) {
    int nx = *x, ny = *y;

    if (dir == 1) ny++;
    else if (dir == 2) ny--;
    else if (dir == 3) nx--;
    else nx++;

    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return false;

    *x = nx; *y = ny;
    return true;
}

void Solution() {
    for (int i = 0; i < K; i++) {
        if (!Move(&X, &Y, command[i])) continue;

        roll(command[i]);

        if (map[X][Y] != 0) {
            dice[6] = map[X][Y];
            map[X][Y] = 0;
        }
        else map[X][Y] = dice[6];

        cout << dice[1] << "\n";
    }
}

void Input() {
    cin >> N >> M >> X >> Y >> K;

    dice.resize(7, 0);
    command.resize(K);
    map.resize(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < K; i++)
        cin >> command[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}