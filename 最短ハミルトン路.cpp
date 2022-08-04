/*

//最短ハミルトン路
//グラフ上の全ての頂点を 1 度ずつ通るパス(サイクル)の最小コストを求める問題
//https://pm4.hatenadiary.jp/entry/2021/06/27/160926
///adj:辺のコスト
///is_cycle サイクル(巡回セールスマン)かどうか
///s 始点を何処にするか。指定がなければ始点を全て試す。
ll shortest_Hamiltonaian_Path(vector<vector<ll>>& adj, bool is_cycle = false, int s = -1) {
	int k = SZ(adj);
	VVL dp(BIT(k), VL(k, INF));
	if (s == -1)rep(i, k)dp[0][i] = 0;
	else dp[0][s] = 0;
	for (int mask = 1; mask < BIT(k) - 1; mask++) {
		rep(i, k) {
			if (!(mask >> i & 1)) {
				rep(j, k) {
					if (mask >> j & 1) {
						chmin(dp[mask][i], adj[j][i] + dp[mask ^ 1 << j][j]);
					}
				}

			}
		}
	}
	ll res = INF;
	rep(i, k)chmin(res, dp[(BIT(k) - 1) ^ BIT(i)][i] + (is_cycle ? adj[i][s] : 0));
	return res;
}



*/