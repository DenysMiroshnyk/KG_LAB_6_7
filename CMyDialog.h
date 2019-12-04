//класс диалога

#include <afxwin.h>
#include "resource.h"

class CMyDialog : public CDialog
{
public:
	CMyDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void SetReflection();
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
	bool IsCrossChecked();
	int GetColorR();
	int GetColorG();
	int GetColorB();
	void set_Light(int x, int y, int z, double I, bool Krest);
	void set_Figure(double kd, bool V, bool R, bool P, int ClrR, int ClrG, int ClrB);
	void SetColorR();
	void SetColorG();
	void SetColorB();
	void Figure_ButtonColor();

private:
	DECLARE_MESSAGE_MAP();
	wchar_t ch1[10];
	int x, y, z, R, G, B;
	double I, kd;
	bool vertex, rebra, paint, cross;

	int mytype;
};