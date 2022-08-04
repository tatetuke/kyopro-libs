/*
�_�C�N�X�g���@
�a�{97p
��Ԃ̖��(�R�X�g�������H�v����)
https://atcoder.jp/contests/abc192/tasks/abc192_e

const ll Max_V = 1e5;

struct edge {
	ll to, cost;

};
typedef pair<ll, ll>P;//first�͍ŒZ�����Asecond�͒��_�̔ԍ�
ll V;
vector<vector<edge>>G(Max_V);
vector<ll> d(Max_V);
//s�͎n�_
void dijkstra(ll s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d.begin(), d.end(), INF);
	d[s] = 0;//�����̎���
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
���\�V�����t���C�h�@
void warshall_floyd(vector<vector<ll>>& dist,int V) {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}





//�č쐬



const ll Max_V = 3*1e2;

struct edge {
	ll to, cost;

};
typedef pair<ll, ll>P;//first�͍ŒZ�����Asecond�͒��_�̔ԍ�
ll V;
ll L;
vector<vector<edge>>G(Max_V);
vector<ll> d(Max_V);
//s�͎n�_
void dijkstra(ll s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d.begin(), d.end(), INF);
	d[s] = 0;//�����̎���
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		ll v = p.second;
		ll w = p.first;
		if (d[v] < w)continue;
		repp(e,G[v]) {
			ll tmp = 0;//���̃R�X�g
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