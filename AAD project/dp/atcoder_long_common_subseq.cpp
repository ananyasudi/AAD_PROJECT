#include <bits/stdc++.h>
using namespace std;
string Ans;
int lcs(int l, int r, string s, string t, vector<vector<int>> &m)
{
    if (l >= s.size() || r >= t.size())
    {
        return 0;
    }
    if (m[l][r] != -1)
    {
        return m[l][r];
    }
    else
    {
        if (s[l] == t[r])
        {
            return 1 + lcs(l + 1, r + 1, s, t, m);
        }
        else
        {
            return max(lcs(l, r + 1, s, t, m), lcs(l + 1, r, s, t, m));
        }
    }
}

int main()
{
    string s;
    string t;
    cin >> s >> t;
    vector<vector<int>> m(s.size() + 1, vector<int>(t.size() + 1, -1));
    int a = s.size();
    int b = t.size();
    int l = 0;
    int r = 0;
    int ans = lcs(l, r, s, t, m);
    cout << ans << "\n";
    // cout<<Ans<<"\n";
}