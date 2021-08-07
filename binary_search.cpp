#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int, int>
#define fs first
#define sc second
#define SoulRRRRR AC

/*----------------------------------------------------------------

Problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

------------------------------------------------------------------*/
const int N = 1e6+10;
int w, h, n;
const int mod = 998244353;
vector<int> v(100005);

void io() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
}

//avoid overflow
int findr() {
    int r = 1;
    while((r/w)*(r/h) < n)
        r <<= 1;
    return r;
}

signed main() {
    io();
    cin >> w >> h >> n;
    int l = 0, r = findr();
    while(l + 1 < r) {
        int m = (l + r) / 2;
        if ((m/w)*(m/h) >= n) // can achieve
            r = m;
        else l = m; // can't achieve
    }
    // l: maximum of can't achieve
    // r: minimum of can achieve
    cout << r << endl;

    return 0;
}
