/*
///頂点以外にも状態数をもつダイクストラ
///下の例では頂点と所持金を持たせている。
///状態を二つ渡すときは、priority_queueに構造体ではなくpairを入れないとTLEする。
///d[i][j]はiが状態種1、jが状態数2となる。

https://atcoder.jp/contests/abc162/tasks/abc162_e
const ll Max_V = 50;
const ll Max_C = 3000;

struct edge {
	ll to;
	ll coin;
	ll cost;
};
VL C(50);
VL D(50);

typedef pair<ll, ll>P;//firstは最短距離、secondは頂点の番号
ll V;
vector<vector<edge>>G(Max_V);
VVL d(Max_V,VL(Max_C));//頂点、所持金
//sは始点
void dijkstra(ll s,ll S) {
	priority_queue<P, vector<P>, greater<P>>que;
	rep(i, Max_V) {
		rep(j, Max_C) {
			d[i][j] = INF;
		}
	}
	chmin(S, Max_C-1);
	d[s][S] = 0;//初期の時間
	que.push({0,s+S*Max_V});
	while (que.size()) {
		P p = que.top();
		que.pop();
		ll v = p.second%Max_V;
		ll money = p.second / Max_V;
		ll cost = p.first;
		if (d[v][money] < cost)continue;
		//両替する
		ll change = min(money + C[v], Max_C-1);
		if (d[v][change] > cost + D[v]) {
			d[v][change] = cost + D[v];
			que.push({ d[v][change],v+change*Max_V });
		}
		//移動する
		repp(nv,G[v]){
			if (money-nv.coin < 0)continue;
			if (d[nv.to][money-nv.coin] <=cost+nv.cost)continue;//vからnvへnv.coin払って移動する。移動にはnv.cost円かかる
			d[nv.to][money - nv.coin] = cost + nv.cost;
			que.push({ d[nv.to][money - nv.coin], nv.to+( money - nv.coin)*Max_V});
		}
	}
}




*/