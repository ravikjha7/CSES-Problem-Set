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
	ll n, x;
	cin >> n >> x;

	ll h[n];
	ll s[n];

	for(ll i = 0; i < n; i++) cin >> h[i];
	for(ll i = 0; i < n; i++) cin >> s[i];

	vector<ll> dp(x + 1, 0);

	for(ll i = h[0]; i <= x; i++) dp[i] = s[0];

	for(ll i = 1; i < n; i++) {

		vector<ll> curr(x + 1, 0);

		for(ll j = 0; j <= x; j++) {

			ll take = 0;
			if(h[i] <= j) take = s[i] + dp[j - h[i]];
			ll nottake = dp[j];

			curr[j] = max(take, nottake);

		}
		dp = curr;
	}

	cout << dp[x] << endl;

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