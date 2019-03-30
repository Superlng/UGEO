#ifndef BASEFUNCTION_h__
#define BASEFUNCTION_h__
#include"Gridstruct.h"
#include"Constants.h"
#include"Qstring.h"
using namespace std;
#define GPGzero(x) (((x)>0?(x):-(x))<InfSmall)
namespace UMSM {

	const char * QString2Char(QString std);
	void GetCornerBounds(point t1, point t2, double *Bounds);

	vector<string> split(const string &s, const string &seperator);
	bool intersection(const point& u1, const point& u2, const point& v1, const point& v2, point &ret);
	int parallel(const point& u1, const point& u2, const point& v1, const point& v2);

	bool Intercept(const point L1, const point L2, const double Z, point& e);
	bool Intercept(const point L1, const point L2, point &Z);

	point operator+(const point& v1, const point& v2);
	point operator-(const point& v1, const point& v2);
	point operator*(point & v1, const double d);
	point operator/(point & v1, const double d);
	point operator^(const point& v1, const point& v2);
	point OutProd(const point& v1, const point& v2);

	double operator*(point& v1, point& v2);
	double VxNorm(const point& v);
	point TriProj(const point& v1, const point& v2, const point& v3);
	point PolygProj(const int N, const point* vs, point& c);
	double PolygArea(const int N, const point* vs, point& c);
	point PolygProj(const int N, const point* vs);

	double FCenter(const point &s1, const point &s2, const point &s3, const point &s4, point& fc);
	inline void LOC_IJK(const int LOC, const int NX, const int NY, int& I, int& J, int& K)
	{
		K = LOC / (NX*NY);
		J = (LOC % (NX*NY)) / NX;
		I = LOC%NX;
	};

	double TetraVol(const point& P, const point& a, const point& b, const point& c);
	double HexVol(const point* corners, point& Centroid);

	point ArithmCenter(const point &a, const point &b, const point &c, const point &d);
	void ThrowErr(const char *format, ...);
	bool is_zero(const double x, const double tol);

	void Center(point *v, point &center);

	bool Intersect_3d_lines(point pt1, point pt2, point pt3, point pt4, point &crossPt);
	bool get_plane_crossPts(point v2, point v1, point u1, point u2, point u3, point &crossPt);
	bool In_planes(point pt1, point pt2, point pt3, point pt4);
};
#endif;