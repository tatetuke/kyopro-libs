/*

;https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B


struct Point { // �_�̍\����
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

typedef Point Vector; // �_�ƃx�N�g���͓����悤�ɕ\����

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; } // ����
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // �O��

double arg(Vector p) { return atan2(p.y, p.x); } // �Ίp
Point polar(double r, double a) { return Point(cos(a) * r, sin(a) * r); } // �ɍ��W���璼�����W�ւ̕ϊ�

bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); } // ���s����
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); } // ���𔻒�

struct EndPoint { // �[�_�̍\����(�}���n�b�^����)
	Point p;
	int seg, st; // �_��id, �_�̎��

	EndPoint() {}
	EndPoint(Point p, int seg, int st) :p(p), seg(seg), st(st) {}

	bool operator<(const EndPoint& ep) const {
		if (p.y == ep.p.y) return st < ep.st;
		return p.y < ep.p.y;
	}
};

struct Segment { // �����̍\����
	Point p1, p2; // 2�[�_

	Segment() {}
	Segment(Point p1, Point p2) :p1(p1), p2(p2) {}

	friend istream& operator>>(istream& is, Segment& s) {
		is >> s.p1 >> s.p2;
		return is;
	}
};

typedef Segment Line; // �����͐����ɒ����𖳂����������̂���

Point project(Segment s, Point p) { // �_�̎ˉe
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}

Point reflect(Segment s, Point p) { // �_�̔���
	return p + (project(s, p) - p) * 2.0;
}

struct Circle { // �~�̍\����
	Point c; // ���S�_
	double r; // ���a

	Circle() {}
	Circle(Point c, double r) :c(c), r(r) {}
};

typedef vector<Point> Polygon; // ���p�`(�����t���̓_�̏W��)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (a.norm() < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}


//������g��
//��ڂ�4�_��^����A��ڂ͒�����^����
//��������Ȃ�true �����łȂ��Ȃ�false
bool intersectSS(Point p1, Point p2, Point p3, Point p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersectSS(Segment s1, Segment s2) {
	return intersectSS(s1.p1, s1.p2, s2.p1, s2.p2);
}




*/