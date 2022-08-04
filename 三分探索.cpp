/*
三分探索
https://qiita.com/ganariya/items/1553ff2bf8d6d7789127
高々1つしかない歔欷うちの無い関数fにおける極値を探索するアルゴリズム。
関数fは凸関数である必要がある。


int main() {

    double P;
    cin >> P;

    // 目的関数(最小化したい)
    auto f = [P](double x) {
        return x + P / pow(2, x / 1.5);
    };

    // 左側
    double low = 0;
    // 右側
    double high = 1e9;

    // 500回繰り返す
    int cnt = 500;
    while (cnt--) {
        double c1 = (low * 2 + high) / 3;
        double c2 = (low + high * 2) / 3;

        // もしf(c2)のほうが良い(小さい)なら、駄目な方lowを更新する
        if (f(c1) > f(c2)) low = c1;
        else high = c2;
    }

    cout << fixed << setprecision(20) << f(low) << endl;

}


*/