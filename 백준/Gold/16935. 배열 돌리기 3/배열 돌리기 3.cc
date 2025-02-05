#include <bits/stdc++.h>
#include <cstddef>
#include <random>

using namespace std;

int N, M, R;
vector<vector<int>> A, ans;

// 1
void UpDown() {
    for(int i = 0; i < N / 2; i++) {
        for(int j = 0; j < M; j++) {
            ans[i][j] = A[N - i - 1][j];
            ans[N - i - 1][j] = A[i][j];
        }
    }
    A = ans;
}

// 2
void LeftRight() {
    for(int j = 0; j < M / 2; j++) {
        for(int i = 0; i < N; i++) {
            ans[i][j] = A[i][M - j - 1];
            ans[i][M - j - 1] = A[i][j];
        }
    }
    A = ans;
}

// 3
void RightRotate() {
    // 4  6
    int len = N - M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ans[j][M - i - 1 + len] = A[i][j];
        }
    }
    int tmp = N;
    N = M;
    M = tmp;
    A = ans;
}

// 4
void LeftRotate() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ans[M - j - 1][i] = A[i][j];
        }
    }
    int tmp = N;
    N = M;
    M = tmp;
    A = ans;
}

// 5
void RightSub() {
    for(int i = 0; i < N / 2; i++) {
        for(int j = 0; j < M / 2; j++) {
            ans[i][j + M / 2] = A[i][j];
        }
        for(int j = M / 2; j < M; j++) {
            ans[i + N / 2][j] = A[i][j];
        }
    }
    for(int i = N / 2; i < N; i++) {
        for(int j = 0; j < M / 2; j++) {
            ans[i - N / 2][j] = A[i][j];
        }
        for(int j = M / 2; j < M; j++) {
            ans[i][j - M / 2] = A[i][j];
        }
    }
    A = ans;
}

// 6
void LeftSub() {
    for(int i = 0; i < N / 2; i++) {
        for(int j = 0; j < M / 2; j++) {
            ans[i + N / 2][j] = A[i][j];
        }
        for(int j = M / 2; j < M; j++) {
            ans[i][j - M / 2] = A[i][j];
        }
    }
    for(int i = N / 2; i < N; i++) {
        for(int j = 0; j < M / 2; j++) {
            ans[i][j + M / 2] = A[i][j];
        }
        for(int j = M / 2; j < M; j++) {
            ans[i - N / 2][j] = A[i][j];
        }
    }
    A = ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, maxL = 0;
  vector<int> cnt(7, 0);

  cin >> N >> M >> R;
  maxL = max(N, M);

  ans.resize(maxL, vector(maxL, 0));
  A.resize(maxL, vector(maxL, 0));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
        cin >> A[i][j];
    }
  }

  for(int i = 0; i < R; i++) {
    cin >> n;

    if(n == 1) UpDown();
    else if(n == 2) LeftRight();
    else if(n == 3) RightRotate();
    else if(n == 4) LeftRotate();
    else if(n == 5) RightSub();
    else if(n == 6) LeftSub();
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
        cout << A[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
