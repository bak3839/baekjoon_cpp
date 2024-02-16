#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, c, d, ans = 0;
    vector<vector<int>> Dot;

    cin >> N;
    Dot.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> d >> c;
        Dot[c - 1].push_back(d);
    }

    for (int i = 0; i < N; i++)
    {
        sort(Dot[i].begin(), Dot[i].end());
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Dot[i].size(); j++)
        {
            if (j == 0)
            {
                ans += Dot[i][j + 1] - Dot[i][j];
            }
            else if (j == Dot[i].size() - 1)
            {
                ans += Dot[i][j] - Dot[i][j - 1];
            }
            else
            {
                ans += min(Dot[i][j + 1] - Dot[i][j], Dot[i][j] - Dot[i][j - 1]);
            }
        }
    }

    cout << ans;
    return 0;
}