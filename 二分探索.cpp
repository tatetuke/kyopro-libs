/*



�񕪒T��
�L�`�P������
�߂��鎮�񕪒T��
https://qiita.com/drken/items/97e37dd6143e33a64c8c

std;lower_bound();
�ukey�v�ȏ�Ƃ��������𖞂����ŏ���index��������B
//lower_bound-a.begin() b�ȏ��index��Ԃ��Bb�ȏ��index�����݂��Ȃ��ꍇ�͔z��̓Y�����ő�+1��Ԃ��B(vector<ll>a(N)�Ȃ�N��Ԃ�)
	auto it=lower_bound(A.begin(), A.end(), b);
	int index = it - A.begin();




// �ėp�I�ȓ񕪒T���̃e���v��
int binary_search(ll key,vector<ll>&a) {
	int left = -1; //�uindex = 0�v�������𖞂������Ƃ�����̂ŁA�����l�� -1
	int right = (int)a.size(); // �uindex = a.size()-1�v�������𖞂����Ȃ����Ƃ�����̂ŁA�����l�� a.size()


while (right - left > 1) {
	int mid = left + (right - left) / 2;

	if (a[mid] >= key) right = mid;
	else left = mid;
}

return right;
}
























*/