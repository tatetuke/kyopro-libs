/*
�O���T��
https://qiita.com/ganariya/items/1553ff2bf8d6d7789127
���X1�����Ȃ��`�W�����̖����֐�f�ɂ�����ɒl��T������A���S���Y���B
�֐�f�͓ʊ֐��ł���K�v������B


int main() {

    double P;
    cin >> P;

    // �ړI�֐�(�ŏ���������)
    auto f = [P](double x) {
        return x + P / pow(2, x / 1.5);
    };

    // ����
    double low = 0;
    // �E��
    double high = 1e9;

    // 500��J��Ԃ�
    int cnt = 500;
    while (cnt--) {
        double c1 = (low * 2 + high) / 3;
        double c2 = (low + high * 2) / 3;

        // ����f(c2)�̂ق����ǂ�(������)�Ȃ�A�ʖڂȕ�low���X�V����
        if (f(c1) > f(c2)) low = c1;
        else high = c2;
    }

    cout << fixed << setprecision(20) << f(low) << endl;

}


*/