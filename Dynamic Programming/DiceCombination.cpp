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

ll dicecomb(ll n, vector<ll> &dp) {

	if(n < 0) return 0;
	if(n == 0) return 1;

	if(dp[n] != -1) return dp[n];

	ll ans = 0;
	for(ll i = 1; i <= 6; i++) {
		ans += dicecomb(n - i, dp);
		ans %= mod;
	}

	return dp[n] = ans;

}

void solve()
{
	ll n;
	cin >> n;

	vector<ll> dp(n + 1, -1);

	ll ans = dicecomb(n, dp);

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