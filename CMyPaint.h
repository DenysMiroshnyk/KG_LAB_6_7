#include <afxwin.h>
#include <math.h>
#include "CPoint.h"

struct light
{
	point C;
	double I;
};
class CMyPaintDC
{
	CDC* mydc;
public:
	CMyPaintDC(CDC* cdc) { mydc = cdc; };

	void PaintSideGuro(point side[], int n, light L, double kd, int Cr, int Cg, int Cb);
	void AreaGuro(light L, double kd, point a, point b, point c, int Cr, int Cg, int Cb);
};