/*


bit全探索
https://qiita.com/hareku/items/3d08511eab56a481c7db
 int n = 3;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        //ここから中身

    }

//尺取り法
https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
int right = 0;
for (int left = 0; left < n; ++left) {
    while (right < n && (right を 1 個進めたときに条件を満たす)) {
        // 実際に right を 1 進める
        // ex: sum += a[right];
        ++right;
    }

    // break した状態で right は条件を満たす最大なので、何かする
    // ex: res += (right - left);

    // left をインクリメントする準備
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
}


*/