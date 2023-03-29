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

	ll dp[n + 1];

	for(ll i = 0; i <= n; i++) dp[i] = 1e9;

	for(ll i = 1; i <= min(n, 9ll); i++) dp[i] = 1;

	for(ll i = 10; i <= n; i++) {

		ll temp = i;

		ll minm = 1e9;

		while(temp > 0) {

			ll r = temp % 10;
			minm = min(minm, dp[i - r] + 1);
			temp /= 10;
		}

		dp[i] = minm;

	}

	cout << dp[n] << endl;

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