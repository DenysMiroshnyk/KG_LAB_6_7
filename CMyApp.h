//класс приложения
#include "CMyMainWnd.h"

class CMyApp : public CWinApp
{
public:
	CMyApp(); // конструктор по умолчанию
	virtual BOOL InitInstance(); // стандартная инициализация
};