#pragma region include
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cmath>
#include<complex>
#include<cstdint>
#include<cstdlib>
#include<deque>
#include<functional>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<tuple>
#include<unordered_map>  
#include<utility>
#include<vector>
using namespace std;
using ll = long long;

#pragma endregion


#include<atcoder/all>
using namespace atcoder;


//using mint = modint998244353;
//const ll MOD = 998244353;

//
using mint = modint1000000007;
const ll MOD = (ll)1e9 + 7;

//using mint = modint;

using VM = vector<mint>;
using VVM = vector<VM>;
using VVVM = vector<VVM>;


#pragma region template

using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VC = vector<char>;
using VVC = vector<VC>;
using VVVC = vector<VVC>;
using VS = vector<string>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;


template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;



#define BIT(n) (1LL<<(n))
#define SZ(x) ((ll)(x).size())
#define rep(i,n)for(ll i=0;i<(n);i++)
#define repi(i,s,t) for (ll i = s; i < t; ++i)
#define rrep(i,s,t) for (ll i = s; i >= t; --i)
#define repp(x,arr) for(auto& x:arr)
#define repp2(x,y,arr) for(auto& [x,y]:arr)
#define all(a) (a.begin()),(a.end())
#define PERM(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define pass cout<<"pass"<<endl;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define DCOUT cout << fixed << setprecision(20);
#define LCOUT cout << fixed << setprecision(0);

#define PR pair<ll, ll>
//vectorやdequeなどのランダムアクセスイテレータはO(1)、setやmapなどそれ以外はO(N)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x))) //x以上の要素のうち最小のindexを返す。x以上の要素がないときはc.size()を返す
#define lbs(c, x,f) distance((c).begin(), lower_bound(all(c), (x),(f))) //構造体cの配列を引数に与える.x以上の要素のうち最小のindexを返す。x以上の要素がないときはc.size()を返す
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x))) //xより大きい要素のうち最小のindexを返す。xより大きい要素がないときはc.size()を返す。
#define SUM(v) accumulate(all(v), 0LL)//少数型は使用不可
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))



const ll INF = (ll)1e18 + 5;
//const ll INF = numeric_limits<ll>::max();

const double EPS = 1e-10;
const double PI = acos(-1);

#define equals(a, b) (fabs((a) - (b)) < EPS) // 誤差を考慮した同値判定
template <class T>bool chmax(T& a, const T& b) { if (a < b) a = b; return a < b; }
template <class T>bool chmin(T& a, const T& b) { if (b < a) a = b; return b < a; }



ll pcnt(ll bit) { ll ret = 0; while (bit > 0) { if (bit & 1)ret++; bit >>= 1; }return ret; }
ll modpow(ll x, ll n, ll m) { if (n == 0)return 1; x %= m; if (n % 2 == 0)return modpow(x * x % m, n / 2, m); else return x * modpow(x, n - 1, m) % m; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll ctoi(char c) { return (ll)c - (ll)'0'; }
ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }



//返り値(値,個数)
template <class S> vector<pair<S, int>> runLength(const vector<S>& v) {
	vector<pair<S, int>> res;
	for (auto& e : v) {
		if (res.empty() or res.back().fi != e)
			res.eb(e, 1);
		else
			res.back().se++;
	}
	return res;
}

//素数判定O(√N)
bool is_prime(ll n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


//素因数分解,(値,個数)
vector<PR> factor(ll x) {
	vector<PR> ans;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ans.push_back({ i, 1 });
			while ((x /= i) % i == 0) ans.back().second++;
		}
	if (x != 1) ans.push_back({ x, 1 });
	return ans;
}

// AとBの加算がオーバーフローする:true
template <typename T>
constexpr bool isAddOverflow(T a, T b) {
	return a > numeric_limits<T>::max() - b;
}
// AとBの乗算がオーバーフローする:true
template <typename T>
constexpr bool isProdOverflow(T a, T b) {
	if (b == 0) return false;
	return a > numeric_limits<T>::max() / b;
}

///X<=A/Bを満たす最大の整数X(B!=0)
ll floor_div(ll A, ll B) {
	ll X;
	if ((A >= 0 && B > 0) || (A < 0 && B < 0))X = A / B;
	else if (A < 0 && B>0)X = (A - B + 1) / B;
	else if (A >= 0 && B < 0)X = (A - B - 1) / B;
	else assert(0);
	return X;
}

/// X>=A/Bを満たす最小の整数X(B!=0)
ll ceil_div(ll A, ll B) {
	ll X;
	if ((A >= 0 && B > 0) || (A < 0 && B < 0))X = (abs(A) + abs(B) - 1) / abs(B);
	else if (A < 0 && B>0)X = -abs(A) / abs(B);
	else if (A >= 0 && B < 0)X = -abs(A) / abs(B);
	else assert(0);
	return X;
}


//argsort https://gist.github.com/HViktorTsoi/58eabb4f7c5a303ced400bcfa816f6f5
//返り値は0-indexed
template<typename T>
std::vector<size_t> argsort(const std::vector<T>& array) {
	std::vector<size_t> indices(array.size());
	std::iota(indices.begin(), indices.end(), 0);
	std::sort(indices.begin(), indices.end(),
		[&array](int left, int right) -> bool {
		// sort indices according to corresponding array element
		return array[left] < array[right];
	});

	return indices;
}


#pragma endregion


int main() {
	

}







