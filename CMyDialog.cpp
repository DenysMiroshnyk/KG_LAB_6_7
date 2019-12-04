#include "CMyDialog.h"
#include <afxdlgs.h>
//--------------------------------------------------------------------------
BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_EN_CHANGE(IDC_EDIT_KDREFLECTION, edit_KdReflection)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_X, edit_LightX)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_Y, edit_LightY)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_Z, edit_LightZ)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_INTENSIVE, edit_LightIntensive)
	ON_BN_CLICKED(IDC_CHECK_PIXELINVERTEX, OnBnClickedCheckPixelinvertex)
	ON_BN_CLICKED(IDC_CHECK_DRAWREBRA, OnBnClickedCheckDrawrebra)
	ON_BN_CLICKED(IDC_CHECK_CHECK_FPAINT, OnBnClickedCheckPaint)
	ON_BN_CLICKED(IDC_CHECK_KREST, OnBnClickedCheckKrest)
	ON_EN_CHANGE(IDC_EDIT_FCOLOR_R, edit_FColorR)
	ON_EN_CHANGE(IDC_EDIT_FCOLOR_G, edit_FColorG)
	ON_EN_CHANGE(IDC_EDIT_FCOLOR_B, edit_FColorB)
	ON_BN_CLICKED(IDC_BUTTON_FCOLOR, Figure_ButtonColor)
END_MESSAGE_MAP()
//--------------------------------------------------------------------------
afx_msg void CMyDialog::edit_KdReflection()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_KDREFLECTION);
	pWnd->GetWindowText(ch1, 10);
	kd = atof(ch1);
}
//--------------------------------------------------------------------------
afx_msg void CMyDialog::edit_LightIntensive()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_INTENSIVE);
	pWnd->GetWindowText(ch1, 10);
	I = atof(ch1);
}
//--------------------------------------------------------------------------
afx_msg void CMyDialog::edit_LightX()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_X);
	pWnd->GetWindowText(ch1, 10);
	x = atoi(ch1);
}
//--------------------------------------------------------------------------
afx_msg void CMyDialog::edit_LightY()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_Y);
	pWnd->GetWindowText(ch1, 10);
	y = atoi(ch1);
}
//--------------------------------------------------------------------------
afx_msg void CMyDialog::edit_LightZ()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_Z);
	pWnd->GetWindowText(ch1, 10);
	z = atoi(ch1);
}
//--------------------------------------------------------------------------
void CMyDialog::OnBnClickedCheckPixelinvertex()
{
	V = !V;
}
//--------------------------------------------------------------------------
void CMyDialog::OnBnClickedCheckDrawrebra()
{
	R = !R;
}
//--------------------------------------------------------------------------
void CMyDialog::OnBnClickedCheckPaint()
{
	P = !P;
}
//--------------------------------------------------------------------------
void CMyDialog::OnBnClickedCheckKrest()
{
	KREST = !KREST;
}
//--------------------------------------------------------------------------
double CMyDialog::get_KdReflection()
{
	return kd;
}
//--------------------------------------------------------------------------
int CMyDialog::get_LightX()
{
	return x;
}
//--------------------------------------------------------------------------
int CMyDialog::get_LightY()
{
	return y;
}
//--------------------------------------------------------------------------
int CMyDialog::get_LightZ()
{
	return z;
}
//--------------------------------------------------------------------------
double CMyDialog::get_LightI()
{
	return I;
}
//--------------------------------------------------------------------------
bool CMyDialog::get_check_Vertex()
{
	return V;
}
//--------------------------------------------------------------------------
bool CMyDialog::get_check_Rebra()
{
	return R;
}
bool CMyDialog::get_check_Paint()
{
	return P;
}
bool CMyDialog::get_check_Krest()
{
	return KREST;
}
int CMyDialog::get_FColorR()
{
	return ClrR;
}
int CMyDialog::get_FColorG()
{
	return ClrG;
}
int CMyDialog::get_FColorB()
{
	return ClrB;
}
void CMyDialog::edit_FColorR()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_FCOLOR_R);
	pWnd->GetWindowText(ch1, 10);
	ClrR = atoi(ch1);
}
void CMyDialog::edit_FColorG()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_FCOLOR_G);
	pWnd->GetWindowText(ch1, 10);
	ClrG = atoi(ch1);
}
void CMyDialog::edit_FColorB()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_FCOLOR_B);
	pWnd->GetWindowText(ch1, 10);
	ClrB = atoi(ch1);
}
void CMyDialog::Figure_ButtonColor()
{
	COLORREF c;
	CColorDialog cDlg(RGB(ClrR, ClrG, ClrB), CC_FULLOPEN, this);
	cDlg.DoModal();
	c = cDlg.GetColor();

	ClrR = GetRValue(c);
	ClrG = GetGValue(c);
	ClrB = GetBValue(c);

	CWnd* pWnd;

	pWnd = GetDlgItem(IDC_EDIT_FCOLOR_R);
	itoa(ClrR, ch1, 10);
	pWnd->SetWindowText(ch1);

	pWnd = GetDlgItem(IDC_EDIT_FCOLOR_G);
	itoa(ClrG, ch1, 10);
	pWnd->SetWindowText(ch1);

	pWnd = GetDlgItem(IDC_EDIT_FCOLOR_B);
	itoa(ClrB, ch1, 10);
	pWnd->SetWindowText(ch1);
}
//--------------------------------------------------------------------------
void CMyDialog::set_Light(int xx, int yy, int zz, double II, bool K)
{
	I = II;
	x = xx;
	y = yy;
	z = zz;
	mytype = 1;
	KREST = K;
}
//--------------------------------------------------------------------------
void CMyDialog::set_Figure(double kkd, bool vv, bool rr, bool pp, int ClrRR, int ClrGG, int ClrBB)
{
	kd = kkd;
	V = vv;
	R = rr;
	P = pp;
	ClrR = ClrRR;
	ClrG = ClrGG;
	ClrB = ClrBB;
	mytype = 2;
}
//--------------------------------------------------------------------------
void CMyDialog::OnOK()
{
	CDialog::OnOK();
}
//------------------------------------------------------------------------
CMyDialog::CMyDialog(UINT nIDTemplate, CWnd* pParentWnd)
	:CDialog(nIDTemplate, pParentWnd)
{
	mytype = 0;
	ch1[1] = '\0';

}
//--------------------------------------------------------------------------
BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();
	char nul[] = "0.        ";
	double hr;
	int i;

	if (mytype == 1)
	{
		CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_INTENSIVE);
		if (I < 1)
		{
			itoa(I * 100, ch1, 10);
			nul[2] = ch1[0];
			nul[3] = ch1[1];
			nul[4] = ch1[2];
		}
		else {
			//....нужно найти функцию перевода из double в *char и вставить сюда вместо этой... ерунды
			itoa(I, ch1, 10);
			for (i = 0; ch1[i] && i < 10; i++)
			{
				nul[i] = ch1[i];
			}
			hr = I - int(I);
			if (hr) {
				itoa(hr * 100, ch1, 10);
				nul[i++] = '.';
				nul[i++] = ch1[0];
				nul[i++] = ch1[1];
				nul[i++] = ch1[2];
				nul[i++] = ch1[3];
			}
		}
		pWnd->SetWindowText(nul);

		CWnd* pWnd1 = GetDlgItem(IDC_EDIT_LIGHT_X);
		itoa(x, ch1, 10);
		pWnd1->SetWindowText(ch1);

		CWnd* pWnd2 = GetDlgItem(IDC_EDIT_LIGHT_Y);
		itoa(y, ch1, 10);
		pWnd2->SetWindowText(ch1);

		CWnd* pWnd3 = GetDlgItem(IDC_EDIT_LIGHT_Z);
		itoa(z, ch1, 10);
		pWnd3->SetWindowText(ch1);

		if (KREST)
			this->CheckDlgButton(IDC_CHECK_KREST, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_KREST, BST_UNCHECKED);
	}
	if (mytype == 2)
	{
		CWnd* pWnd = GetDlgItem(IDC_EDIT_KDREFLECTION);
		if (kd < 1)
		{
			itoa(kd * 100, ch1, 10);
			nul[2] = ch1[0];
			nul[3] = ch1[1];
			nul[4] = ch1[2];
		}
		else {
			nul[0] = '1';
			nul[1] = 0;
		}
		pWnd->SetWindowText(nul);

		pWnd = GetDlgItem(IDC_EDIT_FCOLOR_R);
		itoa(ClrR, ch1, 10);
		pWnd->SetWindowText(ch1);

		pWnd = GetDlgItem(IDC_EDIT_FCOLOR_G);
		itoa(ClrG, ch1, 10);
		pWnd->SetWindowText(ch1);

		pWnd = GetDlgItem(IDC_EDIT_FCOLOR_B);
		itoa(ClrB, ch1, 10);
		pWnd->SetWindowText(ch1);

		//CDlg* pB2 = GetDlgItem(IDC_CHECK_PIXELINVERTEX);
		if (V)
			this->CheckDlgButton(IDC_CHECK_PIXELINVERTEX, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_PIXELINVERTEX, BST_UNCHECKED);

		//	CDlg* pB2(this);// = GetDlgItem(IDC_CHECK_DRAWREBRA);
		if (R)
			this->CheckDlgButton(IDC_CHECK_DRAWREBRA, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_DRAWREBRA, BST_UNCHECKED);

		if (P)
			this->CheckDlgButton(IDC_CHECK_CHECK_FPAINT, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_CHECK_FPAINT, BST_UNCHECKED);
	}
	return TRUE;
}
//--------------------------------------------------------------------------