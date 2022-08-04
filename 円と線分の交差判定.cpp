/*

struct Point { // 点の構造体
	double x, y; // (x, y)

	Point() {}
	Point(double x, double y) :x(x), y(y) {}

	Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
	Point operator*(const double& k) const { return Point(x * k, y * k); }
	Point operator/(const double& k) const { return Point(x / k, y / k); }

	friend istream& operator>>(istream& is, Point& p) {
		is >> p.x >> p.y;
		return is;
	}

	bool operator==(const Point& p) const { return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS); }
	bool operator<(const Point& p) const { return (x != p.x ? x < p.x : y < p.y); }

	double norm() { return x * x + y * y; }
	double abs() { return sqrt(norm()); }
};

typedef Point Vector; // 点とベクトルは同じように表せる

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; } // 内積
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 外積

double arg(Vector p) { return atan2(p.y, p.x); } // 偏角
Point polar(double r, double a) { return Point(cos(a) * r, sin(a) * r); } // 極座標から直交座標への変換

bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); } // 平行判定
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); } // 直交判定

struct EndPoint { // 端点の構造体(マンハッタン幾何)
	Point p;
	int seg, st; // 点のid, 点の種別

	EndPoint() {}
	EndPoint(Point p, int seg, int st) :p(p), seg(seg), st(st) {}

	bool operator<(const EndPoint& ep) const {
		if (p.y == ep.p.y) return st < ep.st;
		return p.y < ep.p.y;
	}
};

struct Segment { // 線分の構造体
	Point p1, p2; // 2端点

	Segment() {}
	Segment(Point p1, Point p2) :p1(p1), p2(p2) {}

	friend istream& operator>>(istream& is, Segment& s) {
		is >> s.p1 >> s.p2;
		return is;
	}
};

typedef Segment Line; // 直線は線分に長さを無くしただけのもの

Point project(Segment s, Point p) { // 点の射影
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}

Point reflect(Segment s, Point p) { // 点の反射
	return p + (project(s, p) - p) * 2.0;
}

struct Circle { // 円の構造体
	Point c; // 中心点
	double r; // 半径

	Circle() {}
	Circle(Point c, double r) :c(c), r(r) {}
};

typedef vector<Point> Polygon; // 多角形(順序付きの点の集合)


//0の時交点を持たない。1の時交点をひとつ持つ。2の時交点を二つ持つ。
int intersectCS(Circle c, Segment s) {
	if (norm(project(s, c.c) - c.c) - c.r * c.r > EPS) return 0;
	double d1 = abs(c.c - s.p1), d2 = abs(c.c - s.p2);
	if (d1 < c.r + EPS && d2 < c.r + EPS) return 0;
	if ((d1 < c.r - EPS && d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;
	Point h = project(s, c.c);
	if (dot(s.p1 - h, s.p2 - h) < 0) return 2;
	return 0;
}


*/