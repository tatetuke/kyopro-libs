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

vector<Point> getCrossPointCC(Circle c1, Circle c2) {
	double d = abs(c1.c - c2.c);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.c - c1.c);
	vector<Point> ps;
	ps.push_back(c1.c + polar(c1.r, t + a)); ps.push_back(c1.c + polar(c1.r, t - a));
	return ps;
}



//任意の点を通る円の接線の接点
vector<Point> tangentCP(Circle c, Point p) {
	return getCrossPointCC(c, Circle(p, sqrt(norm(c.c - p) - c.r * c.r)));
}

//二つの円の共通接線の接点
vector<Line> tangentCC(Circle c1, Circle c2) {
	vector<Line> ls;
	if (c1.r < c2.r) swap(c1, c2);
	double g = abs(c1.c - c2.c);
	if (equals(g, 0)) return ls;
	Point u = (c2.c - c1.c) / g;
	Point v = Point(-u.y, u.x);
	for (int s = 1; s >= -1; s -= 2) {
		double h = (c1.r + s * c2.r) / g;
		if (equals(1, h * h)) ls.push_back(Line(c1.c + u * c1.r, c1.c + (u + v) * c1.r));
		else if (1 - h * h > 0) {
			Point uu = u * h, vv = v * sqrt(1 - h * h);
			ls.push_back(Line(c1.c + (uu + vv) * c1.r, c2.c - (uu + vv) * c2.r * s));
			ls.push_back(Line(c1.c + (uu - vv) * c1.r, c2.c - (uu - vv) * c2.r * s));
		}
	}
	return ls;
}
*/