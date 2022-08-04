/*
ダイクストラ法
蟻本97p
列車の問題(コストを少し工夫した)
https://atcoder.jp/contests/abc192/tasks/abc192_e

const ll Max_V = 1e5;

struct edge {
	ll to, cost;

};
typedef pair<ll, ll>P;//firstは最短距離、secondは頂点の番号
ll V;
vector<vector<edge>>G(Max_V);
vector<ll> d(Max_V);
//sは始点
void dijkstra(ll s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d.begin(), d.end(), INF);
	d[s] = 0;//初期の時間
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		ll v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];

			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));

			}
		}
	}
}
ワ―シャルフロイド法
void warshall_floyd(vector<vector<ll>>& dist,int V) {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}





//再作成



const ll Max_V = 3*1e2;

struct edge {
	ll to, cost;

};
typedef pair<ll, ll>P;//firstは最短距離、secondは頂点の番号
ll V;
ll L;
vector<vector<edge>>G(Max_V);
vector<ll> d(Max_V);
//sは始点
void dijkstra(ll s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d.begin(), d.end(), INF);
	d[s] = 0;//初期の時間
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		ll v = p.second;
		ll w = p.first;
		if (d[v] < w)continue;
		repp(e,G[v]) {
			ll tmp = 0;//次のコスト
			if (w%((ll)1e15)+e.cost>L) {
				if (e.cost > L)continue;
				tmp= w / ((ll)1e15)*1e15 + (ll)1e15+e.cost;
			}
			else {
				tmp = w + e.cost;
			}

			if (d[e.to] > tmp) {
				d[e.to] = tmp;
				que.push(P(tmp, e.to));
			}
		}
	}
}



*/