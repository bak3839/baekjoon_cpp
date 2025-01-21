#include <bits/stdc++.h>

using namespace std;
 
int n;
long long k;
 
vector<pair<int, int>> vec;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
 
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(make_pair(a, i + 1));
    }
 
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += vec[i].first;
        if (cnt > k)
        {
            cout << vec[i].second;
            return 0;
        }
    }
 
    for (int i = n - 1; i > -1; i--)
    {
        cnt += vec[i].first;
        if (cnt > k)
        {
            cout << vec[i].second;
            return 0;
        }
    }
 
    cout << vec[n * 2 - 1].second;
 
    return 0;
}