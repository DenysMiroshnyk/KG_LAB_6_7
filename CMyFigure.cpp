#include "CMyFigure.h"
#include <math.h>
CMyFigure::CMyFigure()
{
	vertex = 0;
	connectionMatrix = 0;
	numofVertex = 0;
	//	CMyFigure::numofArrises = 0;
	numof_sides = 0;
	scene = 0;
	typeofProection = 1;
	center.p = 1; center.x = center.y = center.z = 0;

	lampa.I = 0.9; lampa.C.x = 150; lampa.C.y = 150; lampa.C.z = 70;
	kD = 0.9;
	ifdrawVertex = 0;
	ifdrawRebra = 0;
	ifdrawGuro = 1;
	ifLightKrest = 1;

	ColorR = 0;
	ColorG = 255;
	ColorB = 0;
}
void CMyFigure::Clear()
{
	if (vertex) delete[] vertex;
	if (connectionMatrix) delete[] connectionMatrix;
	if (scene) delete[] scene;

	vertex = 0;
	connectionMatrix = 0;
	numofVertex = 0;
	numof_sides = 0;
	CMyFigure::scene = 0;
	typeofProection = 1;
	center.p = 1; center.x = center.y = center.z = 0;
}
CMyFigure::~CMyFigure()
{
	if (vertex) delete[] vertex;
	if (connectionMatrix) delete[] connectionMatrix;
	if (scene) delete[] scene;

}
/*загрузить фигуру из файла. возвращает 0 если удалось загрузить.*/
int CMyFigure::loadFigureFromFile(wchar_t filename[], wchar_t filenameM[])
{
	char bufer[1000], bbuf[10];
	int n, i, j, c;

	if (!filename || !filenameM)
	{
		return 1;
	}
	//читаем файл с вершинами
	if (!file.Open(filename, CFile::modeRead))
	{
		return 1;
	}
	file.Read(bufer, sizeof(bufer));
	file.Close();

	//считаем количество вершин...
	for (i = 0, n = 0; bufer[i] != 'x'; i++)
	{
		if (bufer[i] == '\n' || bufer[i] == '\0')n++;
	}
	numofVertex = n;

	//создаём массив вершин
	vertex = new point[n];

	//создаём матрицу смежности
	connectionMatrix = new int* [n];
	for (i = 0; i < n; i++)
		connectionMatrix[i] = new int[n];

	//заполняем массив вершин
	for (i = 0, j = 0, n = 0, c = 0; bufer[i] != 'x'; i++, j++)
	{
		if (bufer[i] == '	' || bufer[i] == ' ' || bufer[i] == '\0' || bufer[i] == '\n')
		{
			if (c == 0)
			{
				vertex[n].x = atoi(bbuf);
			}
			else if (c == 1) vertex[n].y = atoi(bbuf);
			else if (c == 2) vertex[n].z = atoi(bbuf);
			else
			{
				vertex[n].p = atoi(bbuf);
				c = -1; n++;
			}
			c++;
			for (j = 0; j < 10; j++)bbuf[j] = 0;
			j = -1;
			continue;
		}
		bbuf[j] = bufer[i];
	}

	for (i = 0; i < 1000; i++) bufer[i] = 0;//обнулить буфер... на всякий)

	scene = new point[numofVertex];
	for (i = 0; i < numofVertex; i++)
	{
		scene[i].x = vertex[i].x;
		scene[i].y = vertex[i].y;
		scene[i].z = vertex[i].z;
		scene[i].p = vertex[i].p;
	}

	//читаем файл с матрицей смежности
	if (!file.Open(filenameM, CFile::modeRead))return 2;
	file.Read(bufer, sizeof(bufer));
	file.Close();

	//заполняем матрицу смежности
	for (i = 0, n = 0; i < numofVertex; i++)
		for (j = 0; j < numofVertex; n++)
		{
			if (bufer[n] - 48 != 1 && bufer[n] - 48 != 0) continue;
			connectionMatrix[i][j] = bufer[n] - 48;
			//		 if(connectionMatrix[i][j] == 1) numofArrises++;
			j++;
		}
	calcCenter();

	MakePlanes();
	return 0;
}
//посчитать центр фигуры
void CMyFigure::calcCenter()
{
	double sumX = 0,
		sumY = 0,
		sumZ = 0;
	for (int i = 0; i < numofVertex; i++)
	{
		sumX = sumX + vertex[i].x;
		sumY = sumY + vertex[i].y;
		sumZ = sumZ + vertex[i].z;
	}
	center.x = sumX / numofVertex;
	center.y = sumY / numofVertex;
	center.z = sumZ / numofVertex;
}
//переместить центр системы координат в центр фигуры
void CMyFigure::moveToCenter()
{
	Transposition(-1 * center.x, -1 * center.y, -1 * center.z);
}
//переместить обратно
void CMyFigure::moveBackFromCenter()
{
	Transposition(center.x, center.y, center.z);
}



double SkalarProiz(point a1, point b1)
{
	return (a1.x * b1.x + a1.y * b1.y + a1.z * b1.z);
}
//нарисовать в 
int CMyFigure::drawFigure(CDC* dc)
{
	if (!vertex || !connectionMatrix) return 1;
	int i, ti, tj, z, num;
	point gran[100]; //одна грань. количество вершин можно увеличить.
	point be, temp;
	CMyPaintDC mydc(dc);

	be.x = 0;	be.y = 0; be.z = 1;
	/*1 - ортографическая проекция
	  2 - изометрическая
	  3 - диметрия
	  4 - триметрия
	  5 - свободная
	  6 - кабинетная
	  7 - одноточечная
	  8 - двухточечная
	  9 - трёхточечная*/
	switch (typeofProection) {
	case 1:	OrtograficView(); break;
	case 2:	AcsonometricView(0.78539816, 0.61547971); break;//sin(fi)=1/sqr(2) sin(sg)=1/sqr(3)
	case 3:	AcsonometricView(0.52359878, 0.46364761); break;//sin(fi)=tg(sg)
	case 4: AcsonometricView(0.5, 0.1); break;//коэфициэнты любые
	case 5: ScewView(0.70710678, 0.70710678); break;//px = py = 1/sqr(2)
	case 6:	ScewView(0.35355339, 0.35355339); break;//px = py = 0.5*cos(pi/4)
	case 7:	CentralView(0, 0, 0.01); break;
	case 8:	CentralView(0, 0.01, 0.01); break;
	case 9:	CentralView(0.01, 0.01, 0.01); break;
	};

	numof_sides = 0;
	MakePlanes();
	for (i = 0; i < numof_sides; i++)
	{
		temp.x = sides[i].Nx;
		temp.y = sides[i].Ny;
		temp.z = sides[i].Nz;
		temp.p = 1;
		if (SkalarProiz(temp, be) > 0)
		{
			num = 0;

			for (ti = 0; ti < numofVertex; ti++)
			{
				if (!(sides[i].ifPointInPlane(scene[ti])))
				{
					for (tj = 0; tj < num; tj++)
						if (gran[tj] == scene[ti])
							break;
					if (tj == num)
					{
						gran[num] = scene[ti];
						gran[num].i = ti;//
						num++;
					}

				}//if(!(...
			}//for(ti=0;...
			for (z = 1; z < num; z++)
				for (tj = z; tj < num; tj++)
				{
					if (connectionMatrix[gran[z - 1].i][gran[tj].i] == 1)
					{
						temp = gran[z];
						gran[z] = gran[tj];
						gran[tj] = temp;
						break;
					}
				}
			if (num && ifdrawGuro)
			{
				mydc.PaintSideGuro(gran, num, lampa, kD, ColorR, ColorG, ColorB);
			}
			if (ifdrawRebra)
			{
				for (z = 0; z < num - 1; z++)
				{
					dc->MoveTo((int)gran[z].x, (int)gran[z].y);
					dc->LineTo((int)gran[z + 1].x, (int)gran[z + 1].y);
					//Sleep(500);
				}
				dc->MoveTo((int)gran[0].x, (int)gran[0].y);
				dc->LineTo((int)gran[num - 1].x, (int)gran[num - 1].y);
			}
			if (ifdrawVertex)
			{
				for (z = 0; z < num; z++)
					dc->SetPixel((int)gran[z].x, (int)gran[z].y, RGB(0, 0, 0));
			}
		}//if(SkalarProiz
	}//	for(i=0;i<numof_sides;i++)
	if (ifLightKrest)
	{
		dc->MoveTo((int)lampa.C.x - 4, (int)lampa.C.y);
		dc->LineTo((int)lampa.C.x + 5, (int)lampa.C.y);
		dc->MoveTo((int)lampa.C.x, (int)lampa.C.y - 4);
		dc->LineTo((int)lampa.C.x, (int)lampa.C.y + 5);
	}
	return 0;
}
//преобразования
//поворот на угол fi(x/y/z) вокруг оси O(X/Y/Z)
void CMyFigure::Rotation(double fix, double fiy, double fiz)
{
	int i;
	double tx, ty;
	moveToCenter();

	if (fix) {
		for (i = 0; i < numofVertex; i++)
		{
			vertex[i].x = vertex[i].x * 1;
			ty = vertex[i].y * cos(fix) - vertex[i].z * sin(fix);
			tx = vertex[i].y * sin(fix) + vertex[i].z * cos(fix);
			vertex[i].z = tx;
			vertex[i].y = ty;
		}
	}
	if (fiy) {
		for (i = 0; i < numofVertex; i++)
		{
			tx = vertex[i].x * cos(fiy) + vertex[i].z * sin(fiy);
			vertex[i].y = vertex[i].y * 1;
			ty = vertex[i].z * cos(fiy) - vertex[i].x * sin(fiy);
			vertex[i].x = tx;
			vertex[i].z = ty;
		}
	}
	if (fiz) {
		for (i = 0; i < numofVertex; i++)
		{
			tx = vertex[i].x * cos(fiz) - vertex[i].y * sin(fiz);
			ty = vertex[i].x * sin(fiz) + vertex[i].y * cos(fiz);
			vertex[i].z = vertex[i].z * 1;
			vertex[i].y = ty;
			vertex[i].x = tx;
		}
	}
	moveBackFromCenter();
}
//растяжение/сжатие по осям
void CMyFigure::Dilatation(double x, double y, double z)
{
	moveToCenter();
	for (int i = 0; i < numofVertex; i++)
	{
		vertex[i].x = (vertex[i].x * x);
		vertex[i].y = (vertex[i].y * y);
		vertex[i].z = (vertex[i].z * z);
	}
	moveBackFromCenter();
}
//отражение от плоскостей. -1 - надо отразить
void CMyFigure::Reflection(int XOZ, int XOY, int YOZ)
{
	moveToCenter();

	for (int i = 0; i < numofVertex; i++)
	{
		vertex[i].x = vertex[i].x * XOZ;
		vertex[i].y = vertex[i].y * XOY;
		vertex[i].z = vertex[i].z * YOZ;
	}
	moveBackFromCenter();
}
//перемещение для 
void CMyFigure::Transposition(double x, double y, double z)
{
	for (int i = 0; i < numofVertex; i++)
	{
		vertex[i].x = vertex[i].x + x;
		vertex[i].y = vertex[i].y + y;
		vertex[i].z = vertex[i].z + z;
	}
}
//перемещение по вектору. x, y, z - направляющие вектора вместе с центром
void CMyFigure::Transposition2(double x, double y, double z)
{
	for (int i = 0; i < numofVertex; i++)
	{
		vertex[i].x = vertex[i].x + x;
		vertex[i].y = vertex[i].y + y;
		vertex[i].z = vertex[i].z + z;
	}
	calcCenter();
}
//проекции
void CMyFigure::OrtograficView()
{
	moveToCenter();
	for (int i = 0; i < numofVertex; i++)
	{
		scene[i].x = vertex[i].x;
		scene[i].y = vertex[i].y;
		scene[i].z = vertex[i].z;
		scene[i].p = vertex[i].p;
		scene[i] = scene[i] + center;
	}
	moveBackFromCenter();
}
void CMyFigure::AcsonometricView(double fi, double sg)
{
	moveToCenter();

	for (int i = 0; i < numofVertex; i++)
	{
		scene[i].x = vertex[i].x * cos(sg) + vertex[i].y * sin(fi) * sin(sg) + vertex[i].z * sin(sg) * cos(fi);
		scene[i].y = vertex[i].y * cos(fi) - vertex[i].z * sin(fi);
		scene[i].z = vertex[i].z;
		scene[i].p = vertex[i].p;
		scene[i] = scene[i] + center;
	}
	moveBackFromCenter();
}
void CMyFigure::ScewView(double px, double py)
{
	moveToCenter();
	for (int i = 0; i < numofVertex; i++)
	{
		scene[i].x = vertex[i].x + px * vertex[i].z;
		scene[i].y = vertex[i].y + py * vertex[i].z;
		scene[i].z = vertex[i].z;
		scene[i].p = vertex[i].p;
		scene[i] = scene[i] + center;
	}
	moveBackFromCenter();
}
void CMyFigure::CentralView(double cx, double cy, double cz)
{
	moveToCenter();
	for (int i = 0; i < numofVertex; i++)
	{
		scene[i].p = vertex[i].p + vertex[i].x * cx + vertex[i].y * cy + vertex[i].z * cz;
		scene[i].x = vertex[i].x / scene[i].p;
		scene[i].y = vertex[i].y / scene[i].p;
		scene[i].z = vertex[i].z / scene[i].p;
		scene[i] = scene[i] + center;
	}
	moveBackFromCenter();
}

/*для удаления невидимых граней*/
//
int CMyFigure::ifNewPlaneFromPoints(point a, point b, point c)
{
	int i;
	for (i = 0; i < numof_sides; i++)
	{
		if (!(sides[i].ifPointInPlane(a) || sides[i].ifPointInPlane(b) || sides[i].ifPointInPlane(c)))
			return 0;
	}
	return 1;
}
int CMyFigure::ifSide_NotSection(plane T)
{
	int i, dir = 0, t;
	for (i = 0; i < numofVertex; i++)
	{
		t = T.ifPointInPlane(scene[i]);
		if (!t)continue;
		if (!dir) { dir = t; continue; }
		if (dir * t > 0) continue;
		return 0;
	}
	return 1;
}
int CMyFigure::MakePlanes()
{
	int i, j, z;
	plane T;
	point a, b, c;
	//перебрать все тройки вершин
	for (i = 0; i < numofVertex; i++)
		for (j = i + 1; j < numofVertex; j++)
			for (z = j + 1; z < numofVertex; z++)
			{
				a = scene[i];// a.z = vertex[i].z;
				b = scene[j];// b.z = vertex[j].z;
				c = scene[z];// c.z = vertex[z].z;
				if (ifNewPlaneFromPoints(a, b, c))
				{
					T.PlaneFromThreePoints(a, b, c);
					if (ifSide_NotSection(T))
					{
						if (T.ifPointInPlane(center) < 0)
						{
							T.Nx = -T.Nx;
							T.Ny = -T.Ny;
							T.Nz = -T.Nz;
							T.D = -T.D;
						}
						sides[numof_sides] = T;
						numof_sides++;
					}
				}
			}

	return 1;
}
//плоскость
plane::plane()
{
	Nx = 0;
	Ny = 0;
	Nz = 0;
	D = 0;
}
void plane::PlaneFromThreePoints(point a, point b, point c)
{
	point v1, v2;

	v1.x = b.x - a.x;  v1.y = b.y - a.y;  v1.z = b.z - a.z;//b-a
	v2.x = c.x - a.x;  v2.y = c.y - a.y;  v2.z = c.z - a.z;//c-a

	//поскольку векторы v1 и v2 лежат в искомой плоскости, то вектор, полученный в результате их векторного произведения, будет ортогонален этой плоскости.
	Nx = v1.y * v2.z - v1.z * v2.y;
	Ny = v1.z * v2.x - v1.x * v2.z;
	Nz = v1.x * v2.y - v1.y * v2.x;
	//остаётся найти D. Так как точка 'a' принадлежит этой плоскости, то ее координаты должны удовлетворять уравнению Nx*x + Ny*y + Nz*z + D =0.
	D = -Nx * a.x - Ny * a.y - Nz * a.z;

	return;
}
bool plane::operator == (const plane& M)
{
	double x, y, z, d;

	if (M.D)  d = D / M.D;
	else if (D)  return false;
	else d = 0;
	if (M.Nx) x = Nx / M.Nx;
	else if (Nx) return false;
	else x = 0;
	if (M.Ny) y = Ny / M.Ny;
	else if (Ny) return false;
	else y = 0;
	if (M.Nz) z = Nz / M.Nz;
	else if (Nz) return false;
	else z = 0;

	if (((d == x) || !d || !x) && ((x == y) || !x || !y) && ((y == z) || !y || !z))
		return true;
	else return false;

}
int plane::ifPointInPlane(point a)
{
	int u = (int)(Nx * a.x + Ny * a.y + Nz * a.z + D);
	if (!u)	return u;
	else return (u / abs(u));
}