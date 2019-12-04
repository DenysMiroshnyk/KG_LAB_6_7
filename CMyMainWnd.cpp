#include "CMyMainWnd.h"

//имена файлов
char FileNames[][2][30] = {
	{"Figures\\Figure1.txt","Figures\\Figure1m.txt"},
	{"Figures\\Figure2.txt","Figures\\Figure2m.txt"},
	{"Figures\\Figure3.txt","Figures\\Figure3m.txt"},
	{"Figures\\Figure4.txt","Figures\\Figure4m.txt"},
	{"Figures\\Figure5.txt","Figures\\Figure5m.txt"},
	{"Figures\\Figure6.txt","Figures\\Figure6m.txt"}
};
const double ONE_GR = 0.017453293;
//const int numof_figures = 6;
CMyMainWnd::CMyMainWnd()
{
	Create(NULL, "КГ лабраб №6.", WS_OVERLAPPEDWINDOW, rectDefault, NULL, NULL); // Создать окно программы
	m_wndMenu.LoadMenu(IDR_MENU1); // Загрузить меню из файла ресурса
	SetMenu(&m_wndMenu);      // Установить меню

   // figures[0].loadFigureFromFile(FileNames[0][0],FileNames[0][1]);
   // figures[1].loadFigureFromFile(FileNames[1][0],FileNames[1][1]);
	//figures[1].typeofProection=8;
   // figures[2].loadFigureFromFile(FileNames[2][0],FileNames[2][1]);
	//figures[3].loadFigureFromFile(FileNames[3][0],FileNames[3][1]);
	//figures[4].loadFigureFromFile(FileNames[4][0],FileNames[4][1]);

	MoveOn = false;
	figureActive = -1;
	CMyMainWnd::MenuTetr();
}

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_TETR, MenuTetr)
	ON_COMMAND(ID_HEX, MenuHex)
	ON_COMMAND(ID_OCT, MenuOct)
	ON_COMMAND(ID_ICOS, MenuIcos)
	ON_COMMAND(ID_DOD, MenuDod)
	ON_COMMAND(ID_ESSO, MenuEsso)
	ON_COMMAND(ID_HELP, MenuHelp)
	ON_COMMAND(ID_PROPERTIES_LIGHT, MenuPrLight)
	ON_COMMAND(ID_PROPERTIES_FIGURE, MenuPrFig)
	ON_COMMAND(ID_PROEC_ORT, MenuPROEC_ORT)
	ON_COMMAND(ID_PROEC_ISO, MenuPROEC_ISO)
	ON_COMMAND(ID_PROEC_DI, MenuPROEC_DI)
	ON_COMMAND(ID_PROEC_TRI, MenuPROEC_TRI)
	ON_COMMAND(ID_PROEC_FREE, MenuPROEC_FREE)
	ON_COMMAND(ID_PROEC_KAB, MenuPROEC_KAB)
	ON_COMMAND(ID_PROEC_ONEPOINT, MenuPROEC_ONEPOINT)
	ON_COMMAND(ID_PROEC_TWOPOINT, MenuPROEC_TWOPOINT)
	ON_COMMAND(ID_PROEC_THREEPOINT, MenuPROEC_THREEPOINT)
	ON_COMMAND(ID_TOWEB, MenuTosait)
	ON_COMMAND(ID_EXIT, MenuEXIT)
END_MESSAGE_MAP()


void CMyMainWnd::MenuTetr()
{
	figureActive = 0;
	figures[figureActive].Clear();
	if (figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]))
	{
		figureActive = -1;
		//MessageBox("не получилось загрузить",NULL,MB_OK);
	}
	figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
	InvalidateRect(false);
}
void CMyMainWnd::MenuHex()
{
	figureActive = 1;
	figures[figureActive].Clear();
	figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]);
	figures[figureActive].Rotation(-5 * ONE_GR, -5 * ONE_GR, -5 * ONE_GR);
	InvalidateRect(false);
}
void CMyMainWnd::MenuOct()
{
	figureActive = 2;
	figures[figureActive].Clear();
	figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]);
	figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
	InvalidateRect(false);
}
void CMyMainWnd::MenuIcos()
{
	figureActive = 3;
	figures[figureActive].Clear();
	figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]);
	figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
	InvalidateRect(false);
}
void CMyMainWnd::MenuDod()
{
	figureActive = 4;
	figures[figureActive].Clear();
	figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]);
	figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
	InvalidateRect(false);
}
void CMyMainWnd::MenuEsso()
{
	figureActive = 5;
	figures[figureActive].Clear();
	figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]);
	figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
	InvalidateRect(false);
}
void CMyMainWnd::MenuEXIT()
{
	DestroyWindow();
}
void CMyMainWnd::MenuHelp()
{
	CDialog about(IDD_DIALOG1);
	about.DoModal();
}
void CMyMainWnd::MenuTosait()
{
	ShellExecute(NULL, "open", "http://aa-shi.narod.ru/graphics/roberts/", "", "c:\\", SW_SHOWNORMAL);
}
void CMyMainWnd::MenuPROEC_ORT()
{
	figures[figureActive].typeofProection = 1;
	InvalidateRect(false);

}
void CMyMainWnd::MenuPROEC_ISO()
{
	figures[figureActive].typeofProection = 2;

	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_DI()
{
	figures[figureActive].typeofProection = 3;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_TRI()
{
	figures[figureActive].typeofProection = 4;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_FREE()
{
	figures[figureActive].typeofProection = 5;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_KAB()
{
	figures[figureActive].typeofProection = 6;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_ONEPOINT()
{
	figures[figureActive].typeofProection = 7;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_TWOPOINT()
{
	figures[figureActive].typeofProection = 8;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPROEC_THREEPOINT()
{
	figures[figureActive].typeofProection = 9;
	InvalidateRect(false);
}
void CMyMainWnd::MenuPrLight()
{
	if (figureActive < 0)return;
	CMyDialog about(IDD_DIALOG_LIGHT, this);
	about.set_Light((int)figures[figureActive].lampa.C.x, (int)figures[figureActive].lampa.C.y, (int)figures[figureActive].lampa.C.z, figures[figureActive].lampa.I, figures[figureActive].ifLightKrest);
	about.DoModal();

	figures[figureActive].lampa.C.x = (double)about.get_LightX();
	figures[figureActive].lampa.C.y = (double)about.get_LightY();
	figures[figureActive].lampa.C.z = (double)about.get_LightZ();
	figures[figureActive].lampa.I = about.get_LightI();
	figures[figureActive].ifLightKrest = about.get_check_Krest();
	InvalidateRect(false);
}
void CMyMainWnd::MenuPrFig()
{
	if (figureActive < 0)return;
	CMyDialog about(IDD_DIALOG_FIGURE, this);
	about.set_Figure(figures[figureActive].kD, int(figures[figureActive].ifdrawVertex), (int)figures[figureActive].ifdrawRebra, (int)figures[figureActive].ifdrawGuro, figures[figureActive].ColorR, figures[figureActive].ColorG, figures[figureActive].ColorB);
	about.DoModal();

	figures[figureActive].ifdrawVertex = about.get_check_Vertex();
	figures[figureActive].ifdrawRebra = about.get_check_Rebra();
	figures[figureActive].ifdrawGuro = about.get_check_Paint();
	figures[figureActive].kD = about.get_KdReflection();
	figures[figureActive].ColorR = about.get_FColorR();
	figures[figureActive].ColorG = about.get_FColorG();
	figures[figureActive].ColorB = about.get_FColorB();

	InvalidateRect(false);
}
afx_msg void  CMyMainWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	//if(point.x <100 && point.y <100) ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
}
int k = 0;
afx_msg void CMyMainWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	//if(point.x <100 && point.y <100)
	//{::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));

	if (!MoveOn)
	{
		MoveOn = true;
		k = 0;
		SetTimer(ID_TIMER_1, 1, NULL);
	}
	else
	{
		MoveOn = false;
		KillTimer(ID_TIMER_1);
	}
	//}

}
afx_msg void CMyMainWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
	//if(point.x <100 && point.y <100)
	//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
}
void CMyMainWnd::OnTimer(UINT uTime)
{
	if (k < 100)figures[figureActive].Rotation(0.1);
	else if (k < 200) {
		figures[figureActive].Rotation(0, 0.1);
		figures[figureActive].Transposition2(1, 1);
	}
	else if (k < 300) {
		figures[figureActive].Rotation(0, 0, 0.1);
		figures[figureActive].Transposition2(0, 1, 1);
	}
	else if (k < 400) {
		figures[figureActive].Rotation(0.3, 0.5, 0.5);
		figures[figureActive].Transposition2(3, -1);
	}
	else {
		figures[figureActive].Rotation(0.3, 0.2, 0.1);
		figures[figureActive].Transposition2(-1, -1);
	}
	k++;
	InvalidateRect(false);
}
afx_msg void CMyMainWnd::OnKeyDown(UINT a, UINT b, UINT c)
{
	switch (a) {
		//перемещения
	case VK_LEFT: figures[figureActive].Transposition2(-10, 0, 0);
		break;
	case VK_RIGHT: figures[figureActive].Transposition2(10, 0, 0);
		break;
	case VK_UP: figures[figureActive].Transposition2(0, -10, 0);
		break;
	case VK_DOWN: figures[figureActive].Transposition2(0, 10, 0);
		break;
	case '1': figures[figureActive].Transposition2(0, 0, -10);
		break;
	case '2': figures[figureActive].Transposition2(0, 0, 10);
		break;
		//растяжение/сжатие
		  //PgUp
	case 33: figures[figureActive].Dilatation(1.02, 1.02, 1.02);
		break;
		//PgDwn
	case 34: figures[figureActive].Dilatation(0.98, 0.98, 0.98);
		break;
		//вращения
		  //'a'
	case 65: figures[figureActive].Rotation(0, 5 * ONE_GR, 0);
		break;
		//'d'
	case 68: figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
		break;
		//'s'
	case 83: figures[figureActive].Rotation(-5 * ONE_GR, 0, 0);
		break;
		//'w'
	case 87: figures[figureActive].Rotation(5 * ONE_GR, 0, 0);
		break;
		//'q'
	case 81: figures[figureActive].Rotation(0, 0, 5 * ONE_GR);
		break;
		//'e'
	case 69: figures[figureActive].Rotation(0, 0, -5 * ONE_GR);
		break;
		//отражения
		  //'x'
	case 88: figures[figureActive].Reflection(-1);
		break;
		//'y'
	case 89: figures[figureActive].Reflection(1, -1);
		break;
		//'z'
	case 90: figures[figureActive].Reflection(1, 1, -1);
		break;
		//'F5'
	case 116: CMyMainWnd::MenuDod();
		break;
	}
	InvalidateRect(false);
}
BOOL CMyMainWnd::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CMyMainWnd::OnPaint()
{
	if (figureActive < 0) return;

	CRect rect;
	this->GetClientRect(&rect);

	CPaintDC dc(this);
	CDC tdc;
	tdc.CreateCompatibleDC(&dc);

	CBitmap tdcbmp;
	tdcbmp.CreateCompatibleBitmap(&dc, rect.right, rect.bottom);
	CBitmap* tbmp = tdc.SelectObject(&tdcbmp);

	CBrush brush_bkg(0xFFFFFF);
	tdc.FillRect(&rect, &brush_bkg);
	tdc.SetBkMode(TRANSPARENT);

	/**/figures[figureActive].drawFigure(&tdc);

	dc.BitBlt(0, 0, rect.right, rect.bottom, &tdc, 0, 0, SRCCOPY);


	if (tbmp) tdc.SelectObject(tbmp);
	tdc.DeleteDC();

}