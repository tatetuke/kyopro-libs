/*
* 
* //その1，引数が座標圧縮したvector
* vector<int> compress(vector<int> a) {
      int n = a.size();
      map<int,int> mp;
      rep(i,n) mp[a[i]] = 0;
      int id = 1;//1から始まるので注意
      for (auto& p : mp) p.second = id++;
      rep(i,n) a[i] = mp[a[i]];
      return a;
    }


    //最も使いやすい
    //その2，引数が座標圧縮後のvectorのサイズpenguinman
    int comp(vector<ll> &A){
    map<ll,ll> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

    //その3，関数を用いないタイプ
    //vector<ll>tを座標圧縮
    sort(all(t));
    t.erase(unique(all(t)), t.end());
    for(auto u : a){
    auto index=lower_bound(all(t), u) - t.begin();
    t[i]=index+1;
    }
*/