//класс главного окна
//#include <afxwin.h>
#include "resource.h"
#include "CMyFigure.h"
#include "CMyDialog.h"

class CMyMainWnd : public CFrameWnd
{
public:
	CMyMainWnd(); // Конструктор по умочанию
	DECLARE_MESSAGE_MAP();
	afx_msg void OnKeyDown(UINT, UINT, UINT);
	//команды меню
	void MenuTetr();
	void MenuHex();
	void MenuOct();
	void MenuIcos();
	void MenuDod();
	void MenuHelp();
	void MenuEsso();
	void MenuEXIT();
	void MenuPrLight();
	void MenuPrFig();

	BOOL OnEraseBkgnd(CDC* pDC);
	void OnPaint();

private:
	int figureActive;
	CMyFigure figures[10];
	CMenu m_wndMenu;

};