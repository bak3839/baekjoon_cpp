#include <bits/stdc++.h>

using namespace std;
typedef struct {
    int a; int b; int c;
}Bucket;

int A, B, C;
vector<int> ans;
bool visited[201][201][201], checked[201];

void Pour(int a, int b, int c) {
    queue<Bucket> q;
    q.push({ a, b, c });
    visited[a][b][c] = true;

    while (q.size()) {
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();

        if (a == 0) 
            ans.push_back(c);

        // a -> b
        if (a + b <= B && !visited[0][a + b][c]) {
            q.push({ 0, a + b, c });
            visited[0][a + b][c] = true;
        }
        else if (a + b > B && !visited[a + b - B][B][c]) {
            q.push({ a + b - B, B, c });
            visited[a + b - B][B][c] = true;
        }

        // a -> c
        if (a + c <= C && !visited[0][b][a + c]) {
            q.push({ 0, b, a + c });
            visited[0][b][a + c] = true;
        }
        else if (a + c > C && !visited[a + c - C][b][C]) {
            q.push({ a + c - C, b, C });
            visited[a + c - C][b][C] = true;
        }

        // b -> a
        if (b + a <= A && !visited[b + a][0][c]) {
            q.push({ b + a, 0, c });
            visited[b + a][0][c] = true;
        }
        else if (b + a > A && !visited[A][b + a - A][c]) {
            q.push({ A, b + a - A, c });
            visited[A][b + a - A][c] = true;
        }

        // b -> c
        if (b + c <= C && !visited[a][0][b + c]) {
            q.push({ a, 0, b + c });
            visited[a][0][b + c] = true;
        }
        else if (b + c > C && !visited[a][b + c - C][C]) {
            q.push({ a, b + c - C, C });
            visited[a][b + c - C][C] = true;
        }

        // c -> a
        if (c + a <= A && !visited[c + a][b][0]) {
            q.push({ c + a, b, 0 });
            visited[c + a][b][0] = true;
        }
        else if (c + a > A && !visited[A][b][c + a - A]) {
            q.push({ A, b, c + a - A });
            visited[A][b][c + a - A] = true;
        }

        // c -> b
        if (c + b <= B && !visited[a][c + b][0]) {
            q.push({ a, c + b, 0 });
            visited[a][c + b][0] = true;
        }
        else if (c + b > B && !visited[a][B][c + b - B]) {
            q.push({ a, B, c + b - B });
            visited[a][B][c + b - B] = true;
        }
    }

    sort(ans.begin(), ans.end());

    for (int n : ans)
        cout << n << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    Pour(0, 0, C);
    return 0;
}
