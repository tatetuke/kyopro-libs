/*









:巡回セールスマン問題
https://algo-logic.info/bit-dp/

蟻本173p

ll max_N=17;
vector<vector<ll>>d(max_N, vector<ll>(max_N));
vector<vector<ll>>dp(1<<max_N, vector<ll>(max_N));
ll n;//巡回する頂点数
void solve() {
	for (ll S = 0; S < 1 << n; S++) {
		fill(dp[S].begin(), dp[S].begin() + n, inf);

	}
	dp[(1 << n) - 1][0] = 0;
	for (ll S = (1 << n) - 2; S >= 0; S--) {
		for (int v = 0; v < n; v++) {
			for (int u = 0; u < n; u++) {
				if (!(S >> u & 1)) {
					dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
				}
			}
		}
	}
}


巡回セールスマン(経路復元)
struct TSPV {
	ll cost; ll p;//p=親,経路復元用

};
ll max_N=17;
vector<vector<ll>>d(max_N, vector<ll>(max_N));
vector<vector<TSPV>>dp(1 << max_N, vector<TSPV>(max_N));
ll n;//巡回する頂点数
void solve() {
	for (ll S = 0; S < 1 << n; S++) {
		for (int i = 0; i < dp[S].size(); i++) {
			dp[S][i].cost = inf;
			dp[S][i].p = -1;


		}

	}
	dp[(1 << n) - 1][0].cost = 0;
	for (ll S = (1 << n) - 2; S >= 0; S--) {
		for (int v = 0; v < n; v++) {
			for (int u = 0; u < n; u++) {
				if (!(S >> u & 1)) {
					if (dp[S][v].cost > dp[S | 1 << u][u].cost + d[v][u]) {
						dp[S][v].cost = dp[S | 1 << u][u].cost + d[v][u];
						dp[S][v].p = u;

					}

				}
			}
		}
	}
};

//経路復元(pv{from,to})
ll S = 0;
	vector<pair<ll, ll>>pv;
	ll e=0;
	while (dp[S][e].p != -1) {
		pv.push_back({ e,dp[S][e].p });
		cout << dp[S][e].p << endl;
		e =dp[S][e].p;
		S |= 1<<e;

	}





*/