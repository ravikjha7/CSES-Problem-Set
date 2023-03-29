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

ll mincoins(ll i, ll x, vector<ll> &arr, vector<vector<ll>> &dp) {

	if(x == 0) return 0;

	if(i < 0) return 1e9;

	if(dp[i][x] != -1) return dp[i][x];

	ll take = 1e9;
	if(arr[i] <= x) take = 1 + mincoins(i, x - arr[i], arr, dp);

	ll nottake = mincoins(i - 1, x, arr, dp);

	// cout << i << " " << take << " " << nottake << endl;

	return min(take, nottake);

}

void solve()
{
	ll n, x;
	cin >> n >> x;

	vector<ll> arr(n);
	for(ll i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<ll> dp(x + 1, 0);

	for(ll i = 1; i <= x; i++) dp[i] = 1e9;

	for(ll i = 1; i <= n; i++) {

		vector<ll> curr(x + 1, 0);

		for(ll j = 1; j <= x; j++) {

			ll take = 1e9;
			if(arr[i - 1] <= j) take = 1 + curr[j - arr[i - 1]];
			ll nottake = dp[j];

			curr[j] = min(take, nottake);

		}

		dp = curr;

	}

	dp[x] = dp[x] == 1e9 ? -1 : dp[x];

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