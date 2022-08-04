/*

//�ŒZ�n�~���g���H
//�O���t��̑S�Ă̒��_�� 1 �x���ʂ�p�X(�T�C�N��)�̍ŏ��R�X�g�����߂���
//https://pm4.hatenadiary.jp/entry/2021/06/27/160926
///adj:�ӂ̃R�X�g
///is_cycle �T�C�N��(����Z�[���X�}��)���ǂ���
///s �n�_�������ɂ��邩�B�w�肪�Ȃ���Ύn�_��S�Ď����B
ll shortest_Hamiltonaian_Path(vector<vector<ll>>& adj, bool is_cycle = false, int s = -1) {
	int k = SZ(adj);
	VVL dp(BIT(k), VL(k, INF));
	if (s == -1)rep(i, k)dp[0][i] = 0;
	else dp[0][s] = 0;
	for (int mask = 1; mask < BIT(k) - 1; mask++) {
		rep(i, k) {
			if (!(mask >> i & 1)) {
				rep(j, k) {
					if (mask >> j & 1) {
						chmin(dp[mask][i], adj[j][i] + dp[mask ^ 1 << j][j]);
					}
				}

			}
		}
	}
	ll res = INF;
	rep(i, k)chmin(res, dp[(BIT(k) - 1) ^ BIT(i)][i] + (is_cycle ? adj[i][s] : 0));
	return res;
}



*/