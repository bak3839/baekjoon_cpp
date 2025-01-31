#include <bits/stdc++.h>

using namespace std;

typedef struct {
  int r; int c; double d;
}Fly;

int N;
// 좌:0 하:1 우:2 상:3
int mv[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
vector<vector<int>> A;

// 좌측 기준
// 우측일 때 r c -1 곱하기
// 아래일 떄 r c 교환
// 위일 떄 r c 교환 후 -1 곱하기
Fly fly[10] = {
  {-1, 1, 0.01}, {1, 1, 0.01},
  {-1, 0, 0.07}, {1, 0, 0.07},
  {-2, 0, 0.02}, {2, 0, 0.02},
  {-1, -1, 0.1}, {1, -1, 0.1},
  {0, -2, 0.05}, {0, -1, 0.55}
};

int Move(int r, int c, int idx, int sand) {
  int tmp, total = 0, nr, nc, lr = 1, lc = 1, res, rest = sand, fr, fc;

  if(idx == 1 || idx == 2) {
    lr = -1; lc = -1;
  } 

  for(int i = 0; i < 10; i++) {
    fr = fly[i].r; fc = fly[i].c;

    if(idx == 1 || idx == 3) {
      int tmp = fr;
      fr = fc;
      fc = tmp;
    }

    nr = r +  fr * lr;
    nc = c + fc * lc; 
    res = i != 9 ? sand * fly[i].d : rest;

    if(nr < 1 || nc < 1 || nr > N || nc > N) {
      total += res;
    } else {
      A[nr][nc] += res;
    }
    rest -= res;
  }

  return total;
}

void Tornado() {
  int r = N / 2 + 1, c = r, idx = 0, cnt = 1, ans = 0;

  while(1) {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < cnt; j++) {
        if(r == 1 && c == 1) {
          cout << ans;
          return;
        }

        r = r + mv[idx][0];
        c = c + mv[idx][1];
        ans += Move(r, c, idx, A[r][c]);
        A[r][c] = 0;
      }

      idx = (idx + 1) % 4;
    }

    cnt++;
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N + 1, vector<int>(N + 1));

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        cin >> A[i][j];
      }
    }

    Tornado();

    return 0;
}