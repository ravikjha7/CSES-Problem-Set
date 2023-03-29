#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a,ll b)
{
	return (a / gcd(a,b)) * b;
}

void solve()
{
	ll n;
	cin >> n;

	vector<vector<char>> arr(n, vector<char> (n));

	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < n; j++) cin >> arr[i][j];
	}

	ll dp[n][n];
	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < n; j++) dp[i][j] = 0;
	}

	if(arr[0][0] == '*' || arr[n - 1][n - 1] == '*') {
		cout << "0" << endl;
		return;
	}

	dp[0][0] = 1;

	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < n; j++) {

			if(i == 0 && j == 0) continue;
			if(arr[i][j] == '*') dp[i][j] = 0;
			else {

				ll curr = 0;
				if(i != 0) curr += dp[i - 1][j];
				if(j != 0) curr += dp[i][j - 1];
				curr %= mod;
				dp[i][j] = curr;
			}

		}
	}

	cout << dp[n - 1][n - 1] << endl;

}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}