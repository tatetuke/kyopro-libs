/*


ax=b(mod M)
https://drken1215.hatenablog.com/entry/2020/12/20/015100


���[�N���b�h�̌ݏ��@�A�g�����[�N���b�h�̌ݏ��@
https://qiita.com/drken/items/b97ff231e43bce50199a
https://qiita.com/drken/items/b97ff231e43bce50199a#3-4-%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E7%9A%84%E8%A8%98%E8%BF%B0
// �Ԃ�l: a �� b �̍ő����
// ax + by = gcd(a, b) �𖞂��� (x, y) ���i�[�����
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}



�g�����[�N���b�h�̌ݏ��@�i���Z���w���x���j
ax+by=gcd(a,b)�𖞂��� (x,y) �̈�����߂�A���S���Y��
�ꎟ�s�������ax+by=c�̐������̈�����߂�A���S���Y��

�E���ׂẲ������߂鎞
��A,B��a,b��gcd(a,b)�Ŋ���������.
��x1,y1�͈ꎞ�s��������𖞂������̈��
x=Bt+x1
y=-At+y1

���̈��(x1,y1)�Ƃ���
ax+by=c
ax1+by1=c
a(x-x1)=-b(y-y1)
a,b��gcd(a,b)�Ŋ��������̂�A,B
A(x-x1)=-B(y-y1)
x=Bt+x1
y=-At+y1







*/