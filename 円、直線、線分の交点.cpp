/*

//https://sizk.hatenablog.com/entry/2020/04/02/002147


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


double getDistanceLP(Line l, Point p) {
	return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}


int intersectCS(Circle c, Segment s) {
	if (norm(project(s, c.c) - c.c) - c.r * c.r > EPS) return 0;
	double d1 = abs(c.c - s.p1), d2 = abs(c.c - s.p2);
	if (d1 < c.r + EPS && d2 < c.r + EPS) return 0;
	if ((d1 < c.r - EPS && d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;
	Point h = project(s, c.c);
	if (dot(s.p1 - h, s.p2 - h) < 0) return 2;
	return 0;
}


//直線と直線の交点
Point getCrossPointLL(Line l1, Line l2) {
	double a = cross(l1.p2 - l1.p1, l2.p2 - l2.p1);
	double b = cross(l1.p2 - l1.p1, l1.p2 - l2.p1);
	if (abs(a) < EPS && abs(b) < EPS) return l2.p1;
	return l2.p1 + (l2.p2 - l2.p1) * (b / a);
}
//線分と線分の交点
Point getCrossPointSS(Segment s1, Segment s2) {
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base, s1.p1 - s2.p1));
	double d2 = abs(cross(base, s1.p2 - s2.p1));
	return s1.p1 + (s1.p2 - s1.p1) * (d1 / (d1 + d2));
}
//円と直線の交点、返り値は必ず2点になる。
vector<Point> getCrossPointCL(Circle c, Line l) {
	vector<Point> ps;
	Vector pr = project(l, c.c);
	Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	if (equals(getDistanceLP(l, c.c), c.r)) return vector<Point>{pr, pr};
	double base = sqrt(c.r * c.r - norm(pr - c.c));
	ps.push_back(pr + e * base); ps.push_back(pr - e * base);
	return ps;
}
//円と線分の交点
vector<Point> getCrossPointCS(Circle c, Segment s) {
	Line l(s);
	vector<Point> ps = getCrossPointCL(c, l);
	if (intersectCS(c, s) == 2) return ps;
	if (dot(l.p1 - ps[0], l.p2 - ps[0]) < 0) ps[1] = ps[0];
	else ps[0] = ps[1];
	return ps;
}

//円と円の交点
vector<Point> getCrossPointCC(Circle c1, Circle c2) {
	double d = abs(c1.c - c2.c);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.c - c1.c);
	vector<Point> ps;
	ps.push_back(c1.c + polar(c1.r, t + a)); ps.push_back(c1.c + polar(c1.r, t - a));
	return ps;
}


*/