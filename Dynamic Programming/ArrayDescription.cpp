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
	ll n, m;
	cin >> n >> m;
 
	vector<ll> arr(n, 0);
	for(ll i = 0; i < n; i++) cin >> arr[i];
 
	vector<vector<ll>> dp(n, vector<ll> (m + 2, 0));
 
	if(arr[0] == 0) for(ll i = 1; i <= m; i++) dp[0][i] = 1;
	else dp[0][arr[0]] = 1;

	for(ll i = 1; i < n; i++) {

		for(ll j = 1; j <= m; j++) {

			if(arr[i] != 0) {
				if(arr[i] == j) {
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= mod;
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= mod;
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= mod;
				}
			} else {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= mod;
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= mod;
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}

		}

	}

	ll ans = 0;
	for(ll i : dp[n - 1]) {
		ans += i;
		ans %= mod;
	}

	cout << ans << endl;
 
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