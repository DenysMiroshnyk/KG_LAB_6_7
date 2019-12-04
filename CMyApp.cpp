#include "CMyApp.h"

CMyApp::CMyApp() // конструктор главного класса приложения
{}

BOOL CMyApp::InitInstance() // стандартная инициализация
{
	m_pMainWnd = new CMyMainWnd();
	ASSERT(m_pMainWnd);
	m_pMainWnd->ShowWindow(SW_SHOW); // Показать окно
	m_pMainWnd->UpdateWindow(); // Обновить окно
	return TRUE; // Вернуть что все нормально 
};

CMyApp theApp; // запуск приложения