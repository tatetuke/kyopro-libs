/*
* 

cout <<setprecision();
整数値へ切り上げ
ceil(),cillf(),ceill()
double ceil(double x);
float ceil(float x);
float ceilf(float x);
long double ceill(long double x);

https://www.madopro.net/entry/2016/09/08/091348
昇順にしないmap。mapより早くなる。使い方はmapと同様
unordered_map


fixed << setprecision(2)


//str[1～]を出力する
string str = "atcoder";
cout << str.substr(1)<< endl;

//str[1,1+2)(str[1]を先頭として2文字出力
cout << str.substr(1, 2)<< std::endl;

10ms早くなる。
ios::sync_with_stdio(false);


next_permutation
https://qiita.com/siser/items/a91022071b24952d27d9
		do {
		 }while (next_permutation(a.begin(), a.end()));


ラムダ再帰
auto dfs = [&](auto& f,...)-> void{

};

setの値がない時、返り値はend()
set.find()!=set.end()


map降順(できない)
for(auto &&[x,y]:mp|reversed){

}

//空白を含む文字列を取得する．
string S;
getline(cin,S);

priority_queue昇順
priority_queue<
      int,                // 要素の型はint
      vector<int>,   // 内部コンテナはstd::vector (デフォルトのまま)
      greater<int>   // 昇順 (デフォルトはstd::less<T>)
    >

setのlower_bound
https://cpprefjp.github.io/reference/set/set/lower_bound.html
最後の要素かどうかは、it!=set.end()を見ればわかる

    //snukeさんのライブラリ
    https://github.com/atcoder/live_library




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


multiset
set.eraseは要素をすべて削除する
一つだけ削除したい場合はset.erase(set.find(値))とする
set.countは計算量がO(setの要素数+log(set.size()))
findを使い工夫することで計算量を落とす。


bitset
複数のsetを合体したい時に使う
bitが64bitより大きくても大丈夫
リファレンス
https://cpprefjp.github.io/reference/set/set.html
使用問題
https://atcoder.jp/contests/abc152/tasks/abc152_f


to_string(a)
https://cpprefjp.github.io/reference/string/to_string.html
実数型をstring型に


// y != 0
template <typename T>
constexpr T floor_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return x / y;
    } else {
        return -((-x + y - 1) / y);
    }
}

// y != 0
template <typename T>
constexpr T ceil_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return (x + y - 1) / y;
    } else {
        return -(-x / y);
    }
}


https://codechacha.com/ja/cpp-isdigit/
isdigit 与えたASCII文字が数値であるかどうか
isdigit('a') :0
isdigit('1') :0以外


*/