/*
https://github.com/E869120/kyopro_educational_90/blob/main/sol/041-03.cpp


struct Point {
	long long px, py;
};

Point operator+(const Point& a1, const Point& a2) {
	return Point{ a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

// “_ p1 ‚Æ p2 ‚ÌŠOÏ‚ð‹‚ß‚é
long long crs(Point p1, Point p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

//‘½ŠpŒ`‚Ì–ÊÏ O(N)
long long area(vector<Point>& G) {
	if (G.size() < 3)return 0;
	ll res = 0;
	repi(i, 1, G.size() - 1) {
		res += abs(crs(G[i] - G[0], G[i + 1] - G[0]));
	}
	return res;

}





*/