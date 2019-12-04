//класс диалога

#include <afxwin.h>
#include "resource.h"

class CMyDialog : public CDialog
{
public:
	CMyDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void edit_KdReflection();
	afx_msg void edit_LightIntensive();
	afx_msg void edit_LightX();
	afx_msg void edit_LightY();
	afx_msg void edit_LightZ();
	afx_msg void OnBnClickedCheckPixelinvertex();
	afx_msg void OnBnClickedCheckDrawrebra();
	afx_msg void OnBnClickedCheckPaint();
	void OnBnClickedCheckKrest();

	double get_KdReflection();
	int get_LightX();
	int get_LightY();
	int get_LightZ();
	double get_LightI();
	bool get_check_Vertex();
	bool get_check_Rebra();
	bool get_check_Paint();
	bool get_check_Krest();
	int get_FColorR();
	int get_FColorG();
	int get_FColorB();
	void set_Light(int x, int y, int z, double I, bool Krest);
	void set_Figure(double kd, bool V, bool R, bool P, int ClrR, int ClrG, int ClrB);
	void edit_FColorR();
	void edit_FColorG();
	void edit_FColorB();
	void Figure_ButtonColor();

private:
	DECLARE_MESSAGE_MAP();
	char ch1[10];
	int x, y, z, ClrR, ClrG, ClrB;
	double I, kd;
	bool V, R, P, KREST;

	int mytype;
};