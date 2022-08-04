/*
https://qiita.com/ageprocpp/items/34121c58e571ea8c4023

//小さいものを優先してtrueにする。
int M;  //分割するひとつひとつの区間サイズ
bool func(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first / M < rhs.first / M)return true;
    if (lhs.first / M == rhs.first / M && lhs.second < rhs.second)return true;
    return false;
}
*/