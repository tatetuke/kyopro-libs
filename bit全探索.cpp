/*


bit�S�T��
https://qiita.com/hareku/items/3d08511eab56a481c7db
 int n = 3;

    // {0, 1, ..., n-1} �̕����W���̑S�T��
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // �񋓂� i ���܂܂�邩
                S.push_back(i);
            }
        }
        //�������璆�g

    }

//�ڎ��@
https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
int right = 0;
for (int left = 0; left < n; ++left) {
    while (right < n && (right �� 1 �i�߂��Ƃ��ɏ����𖞂���)) {
        // ���ۂ� right �� 1 �i�߂�
        // ex: sum += a[right];
        ++right;
    }

    // break ������Ԃ� right �͏����𖞂����ő�Ȃ̂ŁA��������
    // ex: res += (right - left);

    // left ���C���N�������g���鏀��
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
}


*/