/*
* 

cout <<setprecision();
�����l�֐؂�グ
ceil(),cillf(),ceill()
double ceil(double x);
float ceil(float x);
float ceilf(float x);
long double ceill(long double x);

https://www.madopro.net/entry/2016/09/08/091348
�����ɂ��Ȃ�map�Bmap��葁���Ȃ�B�g������map�Ɠ��l
unordered_map


fixed << setprecision(2)


//str[1�`]���o�͂���
string str = "atcoder";
cout << str.substr(1)<< endl;

//str[1,1+2)(str[1]��擪�Ƃ���2�����o��
cout << str.substr(1, 2)<< std::endl;

10ms�����Ȃ�B
ios::sync_with_stdio(false);


next_permutation
https://qiita.com/siser/items/a91022071b24952d27d9
		do {
		 }while (next_permutation(a.begin(), a.end()));


�����_�ċA
auto dfs = [&](auto& f,...)-> void{

};

set�̒l���Ȃ����A�Ԃ�l��end()
set.find()!=set.end()


map�~��(�ł��Ȃ�)
for(auto &&[x,y]:mp|reversed){

}

//�󔒂��܂ޕ�������擾����D
string S;
getline(cin,S);

priority_queue����
priority_queue<
      int,                // �v�f�̌^��int
      vector<int>,   // �����R���e�i��std::vector (�f�t�H���g�̂܂�)
      greater<int>   // ���� (�f�t�H���g��std::less<T>)
    >

set��lower_bound
https://cpprefjp.github.io/reference/set/set/lower_bound.html
�Ō�̗v�f���ǂ����́Ait!=set.end()������΂킩��

    //snuke����̃��C�u����
    https://github.com/atcoder/live_library




//argsort https://gist.github.com/HViktorTsoi/58eabb4f7c5a303ced400bcfa816f6f5
//�Ԃ�l��0-indexed
template<typename T>
std::vector<size_t> argsort(const std::vector<T>& array) {
	std::vector<size_t> indices(array.size());
	std::iota(indices.begin(), indices.end(), 0);
	std::sort(indices.begin(), indices.end(),
		[&array](int left, int right) -> bool {
		// sort indices according to corresponding array element
		return array[left] < array[right];
	});

	return indices;
}


multiset
set.erase�͗v�f�����ׂč폜����
������폜�������ꍇ��set.erase(set.find(�l))�Ƃ���
set.count�͌v�Z�ʂ�O(set�̗v�f��+log(set.size()))
find���g���H�v���邱�ƂŌv�Z�ʂ𗎂Ƃ��B


bitset
������set�����̂��������Ɏg��
bit��64bit���傫���Ă����v
���t�@�����X
https://cpprefjp.github.io/reference/set/set.html
�g�p���
https://atcoder.jp/contests/abc152/tasks/abc152_f


to_string(a)
https://cpprefjp.github.io/reference/string/to_string.html
�����^��string�^��


// y != 0
template <typename T>
constexpr T floor_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return x / y;
    } else {
        return -((-x + y - 1) / y);
    }
}

// y != 0
template <typename T>
constexpr T ceil_div(T x, T y) {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    if (x >= 0) {
        return (x + y - 1) / y;
    } else {
        return -(-x / y);
    }
}


https://codechacha.com/ja/cpp-isdigit/
isdigit �^����ASCII���������l�ł��邩�ǂ���
isdigit('a') :0
isdigit('1') :0�ȊO


*/