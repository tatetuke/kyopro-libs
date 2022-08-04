/*
///���_�ȊO�ɂ���Ԑ������_�C�N�X�g��
///���̗�ł͒��_�Ə��������������Ă���B
///��Ԃ��n���Ƃ��́Apriority_queue�ɍ\���̂ł͂Ȃ�pair�����Ȃ���TLE����B
///d[i][j]��i����Ԏ�1�Aj����Ԑ�2�ƂȂ�B

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

typedef pair<ll, ll>P;//first�͍ŒZ�����Asecond�͒��_�̔ԍ�
ll V;
vector<vector<edge>>G(Max_V);
VVL d(Max_V,VL(Max_C));//���_�A������
//s�͎n�_
void dijkstra(ll s,ll S) {
	priority_queue<P, vector<P>, greater<P>>que;
	rep(i, Max_V) {
		rep(j, Max_C) {
			d[i][j] = INF;
		}
	}
	chmin(S, Max_C-1);
	d[s][S] = 0;//�����̎���
	que.push({0,s+S*Max_V});
	while (que.size()) {
		P p = que.top();
		que.pop();
		ll v = p.second%Max_V;
		ll money = p.second / Max_V;
		ll cost = p.first;
		if (d[v][money] < cost)continue;
		//���ւ���
		ll change = min(money + C[v], Max_C-1);
		if (d[v][change] > cost + D[v]) {
			d[v][change] = cost + D[v];
			que.push({ d[v][change],v+change*Max_V });
		}
		//�ړ�����
		repp(nv,G[v]){
			if (money-nv.coin < 0)continue;
			if (d[nv.to][money-nv.coin] <=cost+nv.cost)continue;//v����nv��nv.coin�����Ĉړ�����B�ړ��ɂ�nv.cost�~������
			d[nv.to][money - nv.coin] = cost + nv.cost;
			que.push({ d[nv.to][money - nv.coin], nv.to+( money - nv.coin)*Max_V});
		}
	}
}




*/