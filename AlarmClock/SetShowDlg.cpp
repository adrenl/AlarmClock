// SetShowDlg.cpp: 实现文件
//

#include "pch.h"
#include "AlarmClock.h"
#include "afxdialogex.h"
#include "SetShowDlg.h"
LOGFONT SetShowDlg::slf;
// SetShowDlg 对话框

IMPLEMENT_DYNAMIC(SetShowDlg, CDialogEx)

SetShowDlg::SetShowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETSHOW, pParent)
{

}

SetShowDlg::~SetShowDlg()
{
}

void SetShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BGCOLOR, m_bgcolor);
	DDX_Control(pDX, IDC_AUTOAJUSTCHK, m_autoajust);
	DDX_Control(pDX, IDC_TEXTCOLOR, m_textcolor);
}


BEGIN_MESSAGE_MAP(SetShowDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CANBTN, &SetShowDlg::OnBnClickedCanbtn)
	ON_BN_CLICKED(IDC_OKBTN, &SetShowDlg::OnBnClickedOkbtn)
	ON_BN_CLICKED(IDC_SETFONTBTN, &SetShowDlg::OnBnClickedSetfontbtn)
END_MESSAGE_MAP()
// SetShowDlg 消息处理程序
BOOL SetShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	memset(&SetShowDlg::slf, 0, sizeof(LOGFONT));
	_tcscpy_s(SetShowDlg::slf.lfFaceName, LF_FACESIZE, CGlobal::font_name);
	SetShowDlg::slf.lfHeight = _ttoi(CGlobal::font_size);
	SetShowDlg::slf.lfItalic = CGlobal::font_italic;
	SetShowDlg::slf.lfUnderline = CGlobal::font_unline;
	SetShowDlg::slf.lfStrikeOut = CGlobal::font_delline;
	SetShowDlg::slf.lfWeight = CGlobal::font_bold == TRUE ? FW_BOLD : 0;
	m_bgcolor.SetColor(CGlobal::background_color);
	m_textcolor.SetColor(CGlobal::text_color);
	m_autoajust.SetCheck(CGlobal::font_autoajust);
	return TRUE;
}


void SetShowDlg::OnBnClickedCanbtn()
{
	EndDialog(0);
}


void SetShowDlg::OnBnClickedOkbtn()
{
	CString Size;
	Size.Format(L"%d", SetShowDlg::slf.lfHeight);
	theApp.WriteProfileStringW(_T("font"), _T("size"),Size);
	theApp.WriteProfileInt(_T("font"), _T("bold"), CGlobal::BoolToInt(SetShowDlg::slf.lfWeight == 700 ? TRUE : FALSE));
	theApp.WriteProfileInt(_T("font"), _T("italic"), CGlobal::BoolToInt(SetShowDlg::slf.lfItalic));
	theApp.WriteProfileInt(_T("font"), _T("unline"), CGlobal::BoolToInt(SetShowDlg::slf.lfUnderline));
	theApp.WriteProfileInt(_T("font"), _T("delline"), CGlobal::BoolToInt(SetShowDlg::slf.lfStrikeOut));
	theApp.WriteProfileInt(_T("font"), _T("autoajust"), CGlobal::BoolToInt(m_autoajust.GetCheck()));
	theApp.WriteProfileInt(_T("color"), _T("text"),m_textcolor.GetColor());
	theApp.WriteProfileInt(_T("color"), _T("background"), m_bgcolor.GetColor());
	theApp.WriteProfileStringW(_T("font"), _T("name"), SetShowDlg::slf.lfFaceName);
	EndDialog(1);
}


void SetShowDlg::OnBnClickedSetfontbtn()
{
	CFontDialog FontDlg(&SetShowDlg::slf);
	FontDlg.DoModal();
	//if (IDOK == FontDlg.DoModal()) {
	//}
}
