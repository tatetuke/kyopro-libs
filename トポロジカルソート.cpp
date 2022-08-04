/*
https://keita-matsushita.hatenablog.com/entry/2016/12/08/141328
vector<int> indeg(N);//ì¸éüêî
vector<vector<int>> out(N);//ÉpÉX
for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    indeg[b] += 1;
    out[a].push_back(b);
}
priority_queue<int, vector<int>, greater<int>> heap;
for (int i = 0; i < N; ++i) {
    if (indeg[i] == 0) {
        heap.push(i);
    }
}
vector<int> ans;
ans.reserve(N);
while (!heap.empty()) {
    int i = heap.top();
    heap.pop();
    ans.push_back(i);
    for (int j : out[i]) {
        indeg[j] -= 1;
        if (indeg[j] == 0) {
            heap.push(j);
        }
    }
}

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph& g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph& g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }



std::vector<int> tsort(const Graph& g) {
	int n = g.size(), k = 0;
	std::vector<int> ord(n), in(n);
	for (auto& es : g)
		for (auto& e : es) in[e.dst]++;
	priority_queue<int, vector<int>,greater<int>> q;
	for (int i = 0; i < n; ++i)
		if (in[i] == 0) q.push(i);
	while (q.size()) {
		int v = q.top();
		q.pop();
		ord[k++] = v;
		for (auto& e : g[v])
			if (--in[e.dst] == 0) q.push(e.dst);
	}
	return *std::max_element(in.begin(), in.end()) == 0 ? ord : std::vector<int>();
}




	

	}*/


