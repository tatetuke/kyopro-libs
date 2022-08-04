/*

	ll N;//右端
	for (ll l = 0, r = -1; l < N; l++) {
		chmax(r, l - 1);
		while (r + 1 < N && ) {//右端が移動した際の条件
			r++;
			//右端の移動後の変化

		}
		//rは条件を満たす何かであるから評価する
		//ex:chmax(ans, r - l + 1);

		//lをインクリメントする時に何かする
		//ex:if (S[l] != 'X')K++;
	}




	//条件を満たすように配列を分割する。

	VVL B;
	for (ll l = 0, r = -1; l < N; l++) {
		chmax(r, l - 1);
		VL tmp;
		while (r + 1 < N&&A[r+1]<=X&&A[r+1]>=Y) {//右端が移動した際の条
			r++;
			//右端の移動後の変化
			tmp.push_back(A[r]);
		}
		//rは条件を満たす何かであるから評価する
		//ex:chmax(ans, r - l + 1);
		//配列を保存する
		if (tmp.size()!=0)B.push_back(tmp);
		//lをインクリメントする時に何かする
		//ex:if (S[l] != 'X')K++;
	}

*/