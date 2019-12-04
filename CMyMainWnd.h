//класс главного окна
//#include <afxwin.h>
#include "resource.h"
#include "CMyFigure.h"
#include "CMyDialog.h"

class CMyMainWnd : public CFrameWnd
{

	int figureActive;
	bool MoveOn;
	CMyFigure figures[10];
	CMenu m_wndMenu;

public:
	CMyMainWnd(); // Конструктор по умочанию
	DECLARE_MESSAGE_MAP();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnLButtonUp(UINT, CPoint);
	afx_msg void OnKeyDown(UINT, UINT, UINT);
	afx_msg void OnTimer(UINT);
	//команды меню
	void MenuTetr();
	void MenuHex();
	void MenuOct();
	void MenuIcos();
	void MenuDod();
	void MenuHelp();
	void MenuEsso();
	void MenuEXIT();
	void MenuPROEC_ORT();
	void MenuPROEC_ISO();
	void MenuPROEC_DI();
	void MenuPROEC_TRI();
	void MenuPROEC_FREE();
	void MenuPROEC_KAB();
	void MenuPROEC_ONEPOINT();
	void MenuPROEC_TWOPOINT();
	void MenuPROEC_THREEPOINT();
	void MenuPrLight();
	void MenuPrFig();
	void MenuTosait();

	BOOL OnEraseBkgnd(CDC* pDC);
	void OnPaint();
};