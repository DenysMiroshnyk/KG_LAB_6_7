#include "CMyDialog.h"
#include <afxdlgs.h>
#include <afxwin.h>

BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_EN_CHANGE(IDC_EDIT_KDREFLECTION, SetReflection)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_X, edit_LightX)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_Y, edit_LightY)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_Z, edit_LightZ)
	ON_EN_CHANGE(IDC_EDIT_LIGHT_INTENSIVE, edit_LightIntensive)
	ON_BN_CLICKED(IDC_CHECK_PIXELINVERTEX, OnBnClickedCheckPixelinvertex)
	ON_BN_CLICKED(IDC_CHECK_DRAWREBRA, OnBnClickedCheckDrawrebra)
	ON_BN_CLICKED(IDC_CHECK_CHECK_FPAINT, OnBnClickedCheckPaint)
	ON_BN_CLICKED(IDC_CHECK_KREST, OnBnClickedCheckKrest)
	ON_EN_CHANGE(IDC_EDIT_FCOLOR_R, SetColorR)
	ON_EN_CHANGE(IDC_EDIT_FCOLOR_G, SetColorG)
	ON_EN_CHANGE(IDC_EDIT_FCOLOR_B, SetColorB)
	ON_BN_CLICKED(IDC_BUTTON_FCOLOR, Figure_ButtonColor)
END_MESSAGE_MAP()

afx_msg void CMyDialog::SetReflection()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_KDREFLECTION);
	pWnd->GetWindowText(ch1, 10);
	kd = _wtof(ch1);
}

afx_msg void CMyDialog::edit_LightIntensive()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_INTENSIVE);
	pWnd->GetWindowText(ch1, 10);
	I = _wtof(ch1);
}

afx_msg void CMyDialog::edit_LightX()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_X);
	pWnd->GetWindowText(ch1, 10);
	x = _wtoi(ch1);
}

afx_msg void CMyDialog::edit_LightY()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_Y);
	pWnd->GetWindowText(ch1, 10);
	y = _wtoi(ch1);
}

afx_msg void CMyDialog::edit_LightZ()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_Z);
	pWnd->GetWindowText(ch1, 10);
	z = _wtoi(ch1);
}

void CMyDialog::OnBnClickedCheckPixelinvertex()
{
	vertex = !vertex;
}

void CMyDialog::OnBnClickedCheckDrawrebra()
{
	rebra = !rebra;
}

void CMyDialog::OnBnClickedCheckPaint()
{
	paint = !paint;
}

void CMyDialog::OnBnClickedCheckKrest()
{
	cross = !cross;
}

double CMyDialog::get_KdReflection()
{
	return kd;
}

int CMyDialog::get_LightX()
{
	return x;
}

int CMyDialog::get_LightY()
{
	return y;
}

int CMyDialog::get_LightZ()
{
	return z;
}

double CMyDialog::get_LightI()
{
	return I;
}

bool CMyDialog::get_check_Vertex()
{
	return vertex;
}

bool CMyDialog::get_check_Rebra()
{
	return rebra;
}
bool CMyDialog::get_check_Paint()
{
	return paint;
}
bool CMyDialog::IsCrossChecked()
{
	return cross;
}
int CMyDialog::GetColorR()
{
	return R;
}
int CMyDialog::GetColorG()
{
	return G;
}
int CMyDialog::GetColorB()
{
	return B;
}
void CMyDialog::SetColorR()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_FCOLOR_R);
	pWnd->GetWindowText(ch1, 10);
	R = _wtoi(ch1);
}
void CMyDialog::SetColorG()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_FCOLOR_G);
	pWnd->GetWindowText(ch1, 10);
	G = _wtoi(ch1);
}
void CMyDialog::SetColorB()
{
	CWnd* pWnd = GetDlgItem(IDC_EDIT_FCOLOR_B);
	pWnd->GetWindowText(ch1, 10);
	B = _wtoi(ch1);
}
void CMyDialog::Figure_ButtonColor()
{
	COLORREF c;
	CColorDialog cDlg(RGB(R, G, B), CC_FULLOPEN, this);
	cDlg.DoModal();
	c = cDlg.GetColor();

	R = GetRValue(c);
	G = GetGValue(c);
	B = GetBValue(c);

	CWnd* pWnd;

	pWnd = GetDlgItem(IDC_EDIT_FCOLOR_R);
	_itow(R, ch1, 10);
	pWnd->SetWindowText(ch1);

	pWnd = GetDlgItem(IDC_EDIT_FCOLOR_G);
	_itow(G, ch1, 10);
	pWnd->SetWindowText(ch1);

	pWnd = GetDlgItem(IDC_EDIT_FCOLOR_B);
	_itow(B, ch1, 10);
	pWnd->SetWindowText(ch1);
}

void CMyDialog::set_Light(int xx, int yy, int zz, double II, bool K)
{
	I = II;
	x = xx;
	y = yy;
	z = zz;
	mytype = 1;
	cross = K;
}

void CMyDialog::set_Figure(double kkd, bool vv, bool rr, bool pp, int ClrRR, int ClrGG, int ClrBB)
{
	kd = kkd;
	vertex = vv;
	rebra = rr;
	paint = pp;
	R = ClrRR;
	G = ClrGG;
	B = ClrBB;
	mytype = 2;
}

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

BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();
	wchar_t nul[] = L"0.        ";
	double hr;
	int i;

	if (mytype == 1)
	{
		CWnd* pWnd = GetDlgItem(IDC_EDIT_LIGHT_INTENSIVE);
		if (I < 1)
		{
			_itow(I * 100, ch1, 10);
			nul[2] = ch1[0];
			nul[3] = ch1[1];
			nul[4] = ch1[2];
		}
		else {
			//....нужно найти функцию перевода из double в *char и вставить сюда вместо этой... ерунды
			_itow(I, ch1, 10);
			for (i = 0; ch1[i] && i < 10; i++)
			{
				nul[i] = ch1[i];
			}
			hr = I - int(I);
			if (hr) {
				_itow(hr * 100, ch1, 10);
				nul[i++] = '.';
				nul[i++] = ch1[0];
				nul[i++] = ch1[1];
				nul[i++] = ch1[2];
				nul[i++] = ch1[3];
			}
		}
		pWnd->SetWindowText(nul);

		CWnd* pWnd1 = GetDlgItem(IDC_EDIT_LIGHT_X);
		_itow(x, ch1, 10);
		pWnd1->SetWindowText(ch1);

		CWnd* pWnd2 = GetDlgItem(IDC_EDIT_LIGHT_Y);
		_itow(y, ch1, 10);
		pWnd2->SetWindowText(ch1);

		CWnd* pWnd3 = GetDlgItem(IDC_EDIT_LIGHT_Z);
		_itow(z, ch1, 10);
		pWnd3->SetWindowText(ch1);

		if (cross)
			this->CheckDlgButton(IDC_CHECK_KREST, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_KREST, BST_UNCHECKED);
	}
	if (mytype == 2)
	{
		CWnd* pWnd = GetDlgItem(IDC_EDIT_KDREFLECTION);
		if (kd < 1)
		{
			_itow(kd * 100, ch1, 10);
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
		_itow(R, ch1, 10);
		pWnd->SetWindowText(ch1);

		pWnd = GetDlgItem(IDC_EDIT_FCOLOR_G);
		_itow(G, ch1, 10);
		pWnd->SetWindowText(ch1);

		pWnd = GetDlgItem(IDC_EDIT_FCOLOR_B);
		_itow(B, ch1, 10);
		pWnd->SetWindowText(ch1);

		//CDlg* pB2 = GetDlgItem(IDC_CHECK_PIXELINVERTEX);
		if (vertex)
			this->CheckDlgButton(IDC_CHECK_PIXELINVERTEX, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_PIXELINVERTEX, BST_UNCHECKED);

		//	CDlg* pB2(this);// = GetDlgItem(IDC_CHECK_DRAWREBRA);
		if (rebra)
			this->CheckDlgButton(IDC_CHECK_DRAWREBRA, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_DRAWREBRA, BST_UNCHECKED);

		if (paint)
			this->CheckDlgButton(IDC_CHECK_CHECK_FPAINT, BST_CHECKED);
		else
			this->CheckDlgButton(IDC_CHECK_CHECK_FPAINT, BST_UNCHECKED);
	}
	return TRUE;
}
