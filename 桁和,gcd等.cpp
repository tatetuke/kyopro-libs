/*


char�^��int�^�ɕϊ�����.
int ctoi(char c) {

	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;

}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};



dfs
if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
dfs

���a�����߂�
ll digsum(ll n) {
	ll res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
���a�����߂�

cin,cout�𑁂�����
ios::sync_with_stdio(false);
cin cout�𑁂�����B


//������pow
ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

ll factorial(ll n) {//n!�����߂�
	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
}


https://betrue12.hateblo.jp/entry/2020/09/23/005940
*/