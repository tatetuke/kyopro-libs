/*

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


std::pair<std::vector<Weight>, bool> bellmanFord(const Graph& g, int s) {
	int n = g.size();
	const Weight inf = std::numeric_limits<Weight>::max() / 8;
	Edges es;
	for (int i = 0; i < n; i++)
		for (auto& e : g[i]) es.emplace_back(e);
	std::vector<Weight> dist(n, inf);
	dist[s] = 0;
	bool negCycle = false;
	for (int i = 0;; i++) {
		bool update = false;
		for (auto& e : es) {
			if (dist[e.src] != inf && dist[e.dst] > dist[e.src] + e.weight) {
				dist[e.dst] = dist[e.src] + e.weight;
				update = true;
			}
		}
		if (!update) break;
		if (i > n) {
			negCycle = true;
			break;
		}
	}
	return std::make_pair(dist, !negCycle);
}



*/