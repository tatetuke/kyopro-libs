/*



二分探索
広義単調増加
めぐる式二分探索
https://qiita.com/drken/items/97e37dd6143e33a64c8c

std;lower_bound();
「key」以上という条件を満たす最小のindexを見つける。
//lower_bound-a.begin() b以上のindexを返す。b以上のindexが存在しない場合は配列の添え字最大+1を返す。(vector<ll>a(N)ならNを返す)
	auto it=lower_bound(A.begin(), A.end(), b);
	int index = it - A.begin();




// 汎用的な二分探索のテンプレ
int binary_search(ll key,vector<ll>&a) {
	int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()


while (right - left > 1) {
	int mid = left + (right - left) / 2;

	if (a[mid] >= key) right = mid;
	else left = mid;
}

return right;
}
























*/