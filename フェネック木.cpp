/*
フェニック木
https://algo-logic.info/binary-indexed-tree/

struct binary_indexed_tree{
    int N;
    const ll mod = 998244353;
    vector<ll> bit;
    binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    ll addition(ll x, ll y){//オペレーター
        return (x+y)%mod;
    }
    void add(int x,ll a){
        x++;
        for(x; x<=N; x+=(x&-x)) bit[x] = addition(bit[x],a);
    }
    ll sum(int x){
        x++;
        ll ret=0;
        for(x; x>0; x-=(x&-x)) ret = addition(ret,bit[x]);
        return ret;
    }
};







*/