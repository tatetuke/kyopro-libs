/*
* 
* //����1�C���������W���k����vector
* vector<int> compress(vector<int> a) {
      int n = a.size();
      map<int,int> mp;
      rep(i,n) mp[a[i]] = 0;
      int id = 1;//1����n�܂�̂Œ���
      for (auto& p : mp) p.second = id++;
      rep(i,n) a[i] = mp[a[i]];
      return a;
    }


    //�ł��g���₷��
    //����2�C���������W���k���vector�̃T�C�Ypenguinman
    int comp(vector<ll> &A){
    map<ll,ll> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

    //����3�C�֐���p���Ȃ��^�C�v
    //vector<ll>t�����W���k
    sort(all(t));
    t.erase(unique(all(t)), t.end());
    for(auto u : a){
    auto index=lower_bound(all(t), u) - t.begin();
    t[i]=index+1;
    }
*/