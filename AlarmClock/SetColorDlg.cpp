// SetColorDlg.cpp: 实现文件
//

#include "pch.h"
#include "AlarmClock.h"
#include "afxdialogex.h"
#include "SetColorDlg.h"


// SetColorDlg 对话框

IMPLEMENT_DYNAMIC(SetColorDlg, CDialogEx)

SetColorDlg::SetColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETSHOW, pParent)
{

}

SetColorDlg::~SetColorDlg()
{
}

void SetColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXTCOLOR, m_textcolor);
	DDX_Control(pDX, IDC_BACKGROUNDCOLOR, m_backgroundcolor);
	DDX_Control(pDX, IDC_AUTOSETSIZE, m_autosetsize);
	DDX_Control(pDX, IDC_SETFONT, m_setfont);
}


BEGIN_MESSAGE_MAP(SetColorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SETFONT, &SetColorDlg::OnBnClickedSetfont)
	ON_BN_CLICKED(IDC_CANCALBTN, &SetColorDlg::OnBnClickedCancalbtn)
	ON_BN_CLICKED(IDC_OKBTN, &SetColorDlg::OnBnClickedOkbtn)
END_MESSAGE_MAP()


// SetColorDlg 消息处理程序


void SetColorDlg::OnBnClickedSetfont(){
	CString FontName;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T(""));
	CFontDialog FontDlg(&lf);
	if (IDOK == FontDlg.DoModal()) {

	}
}

void SetColorDlg::OnBnClickedCancalbtn()
{
	EndDialog(0);
}


void SetColorDlg::OnBnClickedOkbtn()
{
	
}
