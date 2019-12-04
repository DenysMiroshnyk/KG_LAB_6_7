//класс приложения
#include "CMyMainWnd.h"

class CMyApp : public CWinApp
{
public:
	CMyApp()= default; // конструктор по умолчанию
	virtual BOOL InitInstance(); // стандартная инициализация
};