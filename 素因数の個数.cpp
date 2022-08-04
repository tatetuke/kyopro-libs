/*



//O(NlogN)
//1`K‚Ü‚Å‚Ì”‚Ì‘fˆö”‚ÌŒÂ”(–¢ŒŸØ)

VL prime(K+1,-1);
	repi(i,2, K+1) {
		if (prime[i] != -1)continue;
		prime[i] = i;
		for (ll j = 2; j * i <= K; j++) {
			if (prime[i*j] != -1)continue;
			prime[i * j] = i;
		}
	}
	VL primeN(K + 1);
	repi(i,1, K + 1) {
		ll v = i;
		set<ll>mse;
		while (v != 1) {
			mse.insert(prime[v]);
			v /= prime[v];
		}
		primeN[i] = mse.size();
	}


//O(NlogN)
//1`K‚Ü‚Å‚Ì”‚Ì–ñ”‚ÌŒÂ”(–¢ŒŸØ)
VL prime(K+1,-1);
	repi(i,2, K+1) {
		if (prime[i] != -1)continue;
		prime[i] = i;
		for (ll j = 2; j * i <= K; j++) {
			if (prime[i*j] != -1)continue;
			prime[i * j] = i;
		}
	}
	VL factorN(K + 1);//–ñ”‚ÌŒÂ”
	repi(i,1, K + 1) {
		ll v = i;
		map<ll,ll>mse;

		while (v != 1) {
			mse[prime[v]]++;
			v /= prime[v];
		}
		ll cnt = 1;
		repp(j, mse) {
			cnt *= 1 + j.second;
		}
		factorN[i] = cnt;
	}




*/