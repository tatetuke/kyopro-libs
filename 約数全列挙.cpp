/*
//N<1e10ÇÃñÒêîëSóÒãì

//    N<1e10 Ç…å¿ÇÈ     //

vector<ll> Divisor(ll N) {
	ll t = N;
	VL ret;
	map<ll, ll> mp;
	for (int j = 2; j < 1e5; j++) {
		while (t % j == 0) {
			t /= j;
			mp[j]++;
		}
	}
	if (t != 1)mp[t]++;
	vector<PR>x;
	repp(j, mp) {
		x.push_back({ j.first, j.second });
	}
	auto dfs = [&](auto& f, ll v, ll w)-> void {
		if (v == x.size()) {
			ret.push_back(w);
			return;
		}
		rep(j, x[v].second + 1) {
			f(f, v + 1, w * powl(x[v].first, j));
		}
	};
	dfs(dfs, 0, 1);
	return ret;
}

//2êiêîÇ≈âΩåÖÇ©

ll Mul2(ll N) {
	ll ret = 0;
	while (N !=0) {
		ret++;
		N /= 2;
	}
	return ret;
}





*/