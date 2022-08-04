/*
//方向の関係ないグリッド上の2点間に関する問題は，盤面を左右反転させることで二回のDPで解けるかもしれない
//https://atcoder.jp/contests/abc210/tasks/abc210_d

区間数え上げ問題は，片方を全列挙して，もう片方を高速に数え上げるのが定石
https://blog.hamayanhamayan.com/entry/2020/04/26/232032

Xor計算は桁ごとに考えることができる．
https://blog.hamayanhamayan.com/entry/2019/12/13/214444

～区間以外の～は右と左の累積和を取ることで求めれる．(gcd,lmc,+,-,*とかなんでも)
https://blog.hamayanhamayan.com/entry/2019/04/28/085936

Binary Indexed Tree(フェネック木)https://www.slideshare.net/hcpc_hokudai/binary-indexed-tree
累積和を高速で解くアルゴリズム
ある座標の値を変更するときにO(logN)で更新できる.累積和だとTLE
ただし，区間更新はできない．区間更新はSegTreeを用いる
二次元にも拡張できる
i<j，ai<=ajとなる(i,j)の組
LBSはi&(-i)で取得できる

最小全域木
解法
クラスカル法を用いる

種類の数は種類をbitで管理する方法がある(setなどもあるが,区間が絡むと難しい)
特にa～zの26種類は2^26<longlongで収まる
ORを取ることで，区間に関して種類の数を求めることができる

https://atcoder.jp/contests/abc221/tasks/abc221_e
2^i(2^-j+...)である時.modinvを用いて，分母分子に分解して考える．

https://atcoder.jp/contests/abc220/editorial/2679
木を全列挙する時,LCAを考えることで簡単にできる．

https://atcoder.jp/contests/abc185/editorial/356
LCS=最長共通部分列

https://atcoder.jp/contests/abc222/editorial/2751
dp 選ぶ方のみ考慮するやり方．
R-B=K;となる配列の選び方
(K+R+B)/2となる配列の選び方

https://atcoder.jp/contests/abc203/tasks/abc203_d
最大，最小などの境界を見つけるには二部探索が有効

トーナメント(二分木)
木の深さ分回戦がある．

https://atcoder.jp/contests/abc224/tasks/abc224_d
盤面をstringで保持する。


https://algo-logic.info/combinatorial-games/#toc_id_2_2
nim:xorsumが0なら後手必勝,それ以外なら先手必勝。

//サイクル→強連結成分分解


https://atcoder.jp/contests/abc207/tasks/abc207_e
x-yをjで割った余りが0であるようなyを探索するのはO(N)かかる→xをjで割った余がtであるものをmemoする。

https://atcoder.jp/contests/abc200/tasks/abc200_e
写像12相みたいな場合の数はdpで求める。a人で一人がN個以下になるようにX個を分ける。

https://atcoder.jp/contests/abc201/tasks/abc201_e
N個xN個のXORの積の輪は、各位の1の数を求め2のn乗すると良いです
基本的に和x和の形にできない式はbitに着目することで計算量を減らすことができます



https://atcoder.jp/contests/abc191/tasks/abc191_d
10^10～10^-8ぐらいだと誤差が無視できない。
********************************誤差に詰まったときの解決方法******************************************
全体に10^xをかけて後で割る
sqrtはsqrtlに直す
doubleをlond doubleに直す

貪欲解は実は枝刈り全探索解ける場合がある。（条件分岐が複雑かつ順位表で解けている人が多い場合はこれ）
https://blog.hamayanhamayan.com/entry/2017/12/23/155922
https://blog.hamayanhamayan.com/entry/2020/05/03/224516


配列の履歴を参照できるデータ構造を永続データ構造と呼ばれる。
→平衡二分探索木、セグtreeで実装できる。


区間演算について
・累積和 群である必要がある。
　gcdなどは逆元が存在しないためできない。

・SparseTable 冪等モノイドをなすとき適用できる。

・SegmentTree　モノイドをなすとき適用できる。	


*/





