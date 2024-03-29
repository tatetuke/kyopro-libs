/*

https://emtubasa.hateblo.jp/entry/2018/11/12/213000

grundy数とは
必負の状態を0とする。遷移先はmexをとる。
初期状態でgrundy数が0ならば先手必負、それ以外なら先手必勝

1.小さい数で試す
2.規則性を見つける
3.規則性を証明する

*証明方法
数学的帰納法で次を示す
入力に対して規則性を適用したときに
・グランディ数が0であるとき、0から遷移するグランディス数に0が含まれない
・グランディ数が非0であるとき、遷移するグランディ数に0か含まれる

＊規則性の見つけ方
典型パターンを覚える

・2つの数字を操作するパターン
加算・減算なら規則性に加算・減算が含まれることが多い
掛け算・割り算などはそれらが含まれることが多い

・文字列を扱うパターン
文字を減らす操作であれば、文字列の長さの偶奇が絡む→XOR

・終了条件が多いパターン
終了条件だけを見て何かしらの規則が見つかることが多い。

他は経験を積むしかない

*/