#include <afxwin.h>
#include "CMyPaint.h"
//#include "CPoint.h"

//плоскость в трёхмерном пространстве. Задана каноническом уравнением. 
class plane
{
public:
	double Nx;
	double Ny;
	double Nz;
	double D;

	plane();
	void PlaneFromThreePoints(point a, point b, point c);
	bool operator == (const plane& M);
	int ifPointInPlane(point a);
};

//класс трёхмерной фигуры 
class CMyFigure
{
	point center;//центр фигуры.
	CFile file;//класс для работы с файлами...отдельно бы его, ну да ладно.
	int numofVertex;//количество вершин
	point* vertex;//вершины фигуры
	int** connectionMatrix;//матрица связей вершин(как вершины соединены рёбрами)
	plane sides[1000];//грани
	int numof_sides; //
	point* scene; //проекция на экран

	void calcCenter();//посчитать центр фигуры
	void moveToCenter();//переместить координатные оси в центр фигуры
	void moveBackFromCenter();//вернуть координатные оси в обычное положение

public:
	//афинные преобразования
	void Rotation(double fix, double fiy = 0, double fiz = 0);//поворот вокруг оси на угол фи
	void Dilatation(double x, double y = 1, double z = 1);//растяжение/сжатие по осям на коэфициэнты
	void Reflection(int XOZ, int XOY = 1, int YOZ = 1);//отражение от плоскостей
	void Transposition(double x, double y = 0, double z = 0);//перемещение по вектору
	void Transposition2(double x, double y = 0, double z = 0);//перемещение по вектору


	//проекции
	int typeofProection;//как сейчас проецировать
   /*1 - ортографическая проекция
	 2 - изометрическая
	 3 - диметрия
	 4 - триметрия
	 5 - свободная
	 6 - кабинетная
	 7 - одноточечная
	 8 - двухточечная
	 9 - трёхточечная
   */
	void OrtograficView();
	void AcsonometricView(double fi, double sg);
	void ScewView(double px, double py);
	void CentralView(double cx = 0, double cy = 0, double cz = 0);

	light lampa;
	bool ifLightKrest;
	double kD; //коэфициэнт диффузного отражения 0<=kd<=1
	int ifdrawVertex;
	int ifdrawRebra;
	int ifdrawGuro;
	int ColorR;
	int ColorG;
	int ColorB;
	//для удаления невидимых линий
	//int ifNewPlane(plane T);//проверка есть ли уже в списке плоскость T
	int ifNewPlaneFromPoints(point a, point b, point c);
	int ifSide_NotSection(plane T);
	int MakePlanes();//задать плоскости тела, используя список вершин

public:
	CMyFigure(); //
	~CMyFigure();
	void CMyFigure::Clear();//деструктор + конструктор, который можно вызвать
	int loadFigureFromFile(wchar_t filename[], wchar_t filenameM[]);//см. имя функции:)
	int drawFigure(CDC* dc);
};