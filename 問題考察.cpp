/*
//�����̊֌W�Ȃ��O���b�h���2�_�ԂɊւ�����́C�Ֆʂ����E���]�����邱�Ƃœ���DP�ŉ����邩������Ȃ�
//https://atcoder.jp/contests/abc210/tasks/abc210_d

��Ԑ����グ���́C�Е���S�񋓂��āC�����Е��������ɐ����グ��̂����
https://blog.hamayanhamayan.com/entry/2020/04/26/232032

Xor�v�Z�͌����Ƃɍl���邱�Ƃ��ł���D
https://blog.hamayanhamayan.com/entry/2019/12/13/214444

�`��ԈȊO�́`�͉E�ƍ��̗ݐϘa����邱�Ƃŋ��߂��D(gcd,lmc,+,-,*�Ƃ��Ȃ�ł�)
https://blog.hamayanhamayan.com/entry/2019/04/28/085936

Binary Indexed Tree(�t�F�l�b�N��)https://www.slideshare.net/hcpc_hokudai/binary-indexed-tree
�ݐϘa�������ŉ����A���S���Y��
������W�̒l��ύX����Ƃ���O(logN)�ōX�V�ł���.�ݐϘa����TLE
�������C��ԍX�V�͂ł��Ȃ��D��ԍX�V��SegTree��p����
�񎟌��ɂ��g���ł���
i<j�Cai<=aj�ƂȂ�(i,j)�̑g
LBS��i&(-i)�Ŏ擾�ł���

�ŏ��S���
��@
�N���X�J���@��p����

��ނ̐��͎�ނ�bit�ŊǗ�������@������(set�Ȃǂ����邪,��Ԃ����ނƓ��)
����a�`z��26��ނ�2^26<longlong�Ŏ��܂�
OR����邱�ƂŁC��ԂɊւ��Ď�ނ̐������߂邱�Ƃ��ł���

https://atcoder.jp/contests/abc221/tasks/abc221_e
2^i(2^-j+...)�ł��鎞.modinv��p���āC���ꕪ�q�ɕ������čl����D

https://atcoder.jp/contests/abc220/editorial/2679
�؂�S�񋓂��鎞,LCA���l���邱�ƂŊȒP�ɂł���D

https://atcoder.jp/contests/abc185/editorial/356
LCS=�Œ����ʕ�����

https://atcoder.jp/contests/abc222/editorial/2751
dp �I�ԕ��̂ݍl����������D
R-B=K;�ƂȂ�z��̑I�ѕ�
(K+R+B)/2�ƂȂ�z��̑I�ѕ�

https://atcoder.jp/contests/abc203/tasks/abc203_d
�ő�C�ŏ��Ȃǂ̋��E��������ɂ͓񕔒T�����L��

�g�[�i�����g(�񕪖�)
�؂̐[������킪����D

https://atcoder.jp/contests/abc224/tasks/abc224_d
�Ֆʂ�string�ŕێ�����B


https://algo-logic.info/combinatorial-games/#toc_id_2_2
nim:xorsum��0�Ȃ���K��,����ȊO�Ȃ���K���B

//�T�C�N�������A����������


https://atcoder.jp/contests/abc207/tasks/abc207_e
x-y��j�Ŋ������]�肪0�ł���悤��y��T������̂�O(N)�����遨x��j�Ŋ������]��t�ł�����̂�memo����B

https://atcoder.jp/contests/abc200/tasks/abc200_e
�ʑ�12���݂����ȏꍇ�̐���dp�ŋ��߂�Ba�l�ň�l��N�ȉ��ɂȂ�悤��X�𕪂���B

https://atcoder.jp/contests/abc201/tasks/abc201_e
N��xN��XOR�̐ς̗ւ́A�e�ʂ�1�̐�������2��n�悷��Ɨǂ��ł�
��{�I�ɘax�a�̌`�ɂł��Ȃ�����bit�ɒ��ڂ��邱�ƂŌv�Z�ʂ����炷���Ƃ��ł��܂�



https://atcoder.jp/contests/abc191/tasks/abc191_d
10^10�`10^-8���炢���ƌ덷�������ł��Ȃ��B
********************************�덷�ɋl�܂����Ƃ��̉������@******************************************
�S�̂�10^x�������Č�Ŋ���
sqrt��sqrtl�ɒ���
double��lond double�ɒ���

�×~���͎��͎}����S�T��������ꍇ������B�i�������򂪕��G�����ʕ\�ŉ����Ă���l�������ꍇ�͂���j
https://blog.hamayanhamayan.com/entry/2017/12/23/155922
https://blog.hamayanhamayan.com/entry/2020/05/03/224516


�z��̗������Q�Ƃł���f�[�^�\�����i���f�[�^�\���ƌĂ΂��B
�����t�񕪒T���؁A�Z�Otree�Ŏ����ł���B


��ԉ��Z�ɂ���
�E�ݐϘa �Q�ł���K�v������B
�@gcd�Ȃǂ͋t�������݂��Ȃ����߂ł��Ȃ��B

�ESparseTable �p�����m�C�h���Ȃ��Ƃ��K�p�ł���B

�ESegmentTree�@���m�C�h���Ȃ��Ƃ��K�p�ł���B	


*/





