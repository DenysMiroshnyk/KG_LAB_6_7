#include "CMyMainWnd.h"

//имена файлов
wchar_t FileNames[][2][30] = {
	{L"Figures\\Figure1.txt",L"Figures\\Figure1m.txt"},
	{L"Figures\\Figure2.txt",L"Figures\\Figure2m.txt"},
	{L"Figures\\Figure3.txt",L"Figures\\Figure3m.txt"},
	{L"Figures\\Figure4.txt",L"Figures\\Figure4m.txt"},
	{L"Figures\\Figure5.txt",L"Figures\\Figure5m.txt"},
	{L"Figures\\Figure6.txt",L"Figures\\Figure6m.txt"}
};
const double ONE_GR = 0.017453293;
//const int numof_figures = 6;
CMyMainWnd::CMyMainWnd()
{
	Create(NULL, L"КГ №6.7", WS_OVERLAPPEDWINDOW, rectDefault, NULL, NULL); // Создать окно программы
	m_wndMenu.LoadMenu(IDR_MENU1); // Загрузить меню из файла ресурса
	SetMenu(&m_wndMenu);      // Установить меню
	
	figureActive = -1;
	CMyMainWnd::MenuTetr();
}

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_KEYDOWN()
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
	ON_COMMAND(ID_EXIT, MenuEXIT)
END_MESSAGE_MAP()


void CMyMainWnd::MenuTetr()
{
	figureActive = 0;
	figures[figureActive].Clear();
	if (figures[figureActive].loadFigureFromFile(FileNames[figureActive][0], FileNames[figureActive][1]))
	{
		figureActive = -1;
		MessageBox(L"не получилось загрузить",NULL,MB_OK);
		return;
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
	figures[figureActive].ifLightKrest = about.IsCrossChecked();
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
	figures[figureActive].ColorR = about.GetColorR();
	figures[figureActive].ColorG = about.GetColorG();
	figures[figureActive].ColorB = about.GetColorB();

	InvalidateRect(false);
}

afx_msg void CMyMainWnd::OnKeyDown(UINT a, UINT b, UINT c)
{
	switch (a) {
		//перемещения
	case VK_LEFT:
	{
		figures[figureActive].Transposition2(-10, 0, 0);
		break;
	}
	case VK_RIGHT:
	{
		figures[figureActive].Transposition2(10, 0, 0);
		break;
	}
	case VK_UP:
	{
		figures[figureActive].Transposition2(0, -10, 0);
		break;
	}
	case VK_DOWN:
	{
		figures[figureActive].Transposition2(0, 10, 0);
		break;
	}
	case '1':
	{
		figures[figureActive].Transposition2(0, 0, -10);
		break;
	}
	case '2':
	{
		figures[figureActive].Transposition2(0, 0, 10);
		break;
	}
	//растяжение/сжатие
	case 33: //PgUp 
	{
		figures[figureActive].Dilatation(1.02, 1.02, 1.02);
		break;
	}
	//PgDwn
	case 34:
	{
		figures[figureActive].Dilatation(0.98, 0.98, 0.98);
		break;
	}

	//вращения
	case 65:	//'a'
	{
		figures[figureActive].Rotation(0, 5 * ONE_GR, 0);
		break;
	}
	case 68:	//'d'
	{
		figures[figureActive].Rotation(0, -5 * ONE_GR, 0);
		break;
	}
	case 83:	//'s'
	{
		figures[figureActive].Rotation(-5 * ONE_GR, 0, 0);
		break;
	}
	case 87:	//'w'
	{
		figures[figureActive].Rotation(5 * ONE_GR, 0, 0);
		break;
	}
	case 81:	//'q'
	{
		figures[figureActive].Rotation(0, 0, 5 * ONE_GR);
		break;
	}
	case 69:	//'e'
	{
		figures[figureActive].Rotation(0, 0, -5 * ONE_GR);
		break;
	}
	//отражения
	case 88:	//'x'
	{
		figures[figureActive].Reflection(-1);
		break;
	}

	case 89:	//'y'
	{
		figures[figureActive].Reflection(1, -1);
		break;
	}
	case 90:	//'z'
	{
		figures[figureActive].Reflection(1, 1, -1);
		break;
	}
	case 116: //'F5'
	{
		CMyMainWnd::MenuDod();
		break;
	}
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