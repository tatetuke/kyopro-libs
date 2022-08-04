/*

以下の条件を満たす問題を牛ゲーと呼ぶ
(1)Bx-By<=Wxy (最大化したい)
(2)Bi<=B{i+1}
(3)B{i+1}<=Bi+1
(4)B0=0

牛ゲーは以下の要領で最短経路問題に帰着できる
最短経路のグラフの構成手順は下記URLを参照
https://atcoder.jp/contests/abc216/editorial/2474





*/