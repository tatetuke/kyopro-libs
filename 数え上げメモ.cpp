/*

B-extension
https://img.atcoder.jp/agc046/editorial.pdf
一つの状態を一つの操作列に対応させて状態の重複をなくす.
一つの状態を作るための操作列は様々ありうるが、一つの状態を一つの操作列に1対1に対応させる

https://atcoder.jp/contests/dp/tasks/dp_y
初めにXXする場合の数を求める。

完全順列A_i!=iである順列
https://ja.wikipedia.org/wiki/%E5%AE%8C%E5%85%A8%E9%A0%86%E5%88%97
求め方は以下の式に従う
https://kanpurin.hatenablog.com/entry/2020/08/11/175007


重複を取り除く方針は頓挫しがち
判定問題をとくとうまくいくことがある。
https://drken1215.hatenablog.com/entry/2020/06/27/125500


形式的べき級数を使うとうまくいく（まったくわからない）
https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%ef%bc%88%ef%bc%93%ef%bc%89%e7%b7%9a%e5%bd%a2%e6%bc%b8%e5%8c%96%e5%bc%8f%e3%81%a8%e5%bd%a2%e5%bc%8f

wolframalpha
https://www.wolframalpha.com/input?i=Sum%5BBinomial%5Bn-i%2Ck%5D*2%5E%28i-1%29*%28k%2B1%29%2C%7Bk%2C0%2Cn-i%7D%5D&lang=ja
Binomial[,]=C

期待値を考えて解く
https://atcoder.jp/contests/abc150/tasks/abc150_e

*/