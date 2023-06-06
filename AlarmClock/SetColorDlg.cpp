// SetColorDlg.cpp: 实现文件
//

#include "pch.h"
#include "AlarmClock.h"
#include "afxdialogex.h"
#include "SetColorDlg.h"
extern bool WinOK = FALSE;

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
	DDX_Control(pDX, IDC_FONTNAME, m_fontname);
	DDX_Control(pDX, IDC_PREVIEW, m_preview);
	DDX_Control(pDX, IDC_FONTSIZE, m_fontsize);
	DDX_Control(pDX, IDC_BOLDCHK, m_bold);
	DDX_Control(pDX, IDC_ITALICCHK, m_italic);
	DDX_Control(pDX, IDC_UNLINECHK, m_unline);
	DDX_Control(pDX, IDC_DELLINKCHK, m_delline);
}


BEGIN_MESSAGE_MAP(SetColorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CANCALBTN, &SetColorDlg::OnBnClickedCancalbtn)
	ON_BN_CLICKED(IDC_OKBTN, &SetColorDlg::OnBnClickedOkbtn)
	ON_CBN_SELCHANGE(IDC_FONTNAME, &SetColorDlg::OnCbnSelchangeMfcfontcombo1)
	ON_BN_CLICKED(IDC_TEXTCOLOR, &SetColorDlg::OnBnClickedTextcolor)
	ON_BN_CLICKED(IDC_BACKGROUNDCOLOR, &SetColorDlg::OnBnClickedBackgroundcolor)
	ON_EN_CHANGE(IDC_FONTSIZE, &SetColorDlg::OnEnChangeFontsize)
	ON_BN_CLICKED(IDC_BOLDCHK, &SetColorDlg::OnBnClickedBoldchk)
	ON_BN_CLICKED(IDC_ITALICCHK, &SetColorDlg::OnBnClickedItalicchk)
	ON_BN_CLICKED(IDC_UNLINECHK, &SetColorDlg::OnBnClickedUnlinechk)
	ON_BN_CLICKED(IDC_DELLINKCHK, &SetColorDlg::OnBnClickedDellinkchk)
	ON_BN_CLICKED(IDC_AUTOSETSIZE, &SetColorDlg::OnBnClickedAutosetsize)
END_MESSAGE_MAP()


void SetColorDlg::OnPreview() {
	if (WinOK == FALSE) return;
	CFont prefont;
	CMFCFontInfo* pInfoFont = m_fontname.GetSelFont();
	CString fontsize;
	COLORREF textcolor = m_textcolor.GetColor();
	COLORREF bgcolor = m_backgroundcolor.GetColor();
	if (m_autosetsize.GetCheck() == TRUE) {
		fontsize = "12";
		m_fontsize.EnableWindow(FALSE);
	} else {
		GetDlgItem(IDC_FONTSIZE)->GetWindowText(fontsize);
		m_fontsize.EnableWindow(TRUE);
	}
	//prefont.CreateFontW(_ttoi(fontsize), 0, 0, 0, (m_bold.GetCheck() == TRUE ? FW_BOLD : 0), m_italic.GetCheck(), m_unline.GetCheck(), m_delline.GetCheck(), ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, pInfoFont->m_strName);
	//m_preview.SetFont(&prefont, true);
}

void SetColorDlg::OnBnClickedCancalbtn()
{
	EndDialog(0);
}


void SetColorDlg::OnBnClickedOkbtn()
{
	WinOK = FALSE;
	CString fontsize;
	CString bold;
	CString italic;
	CString unline;
	CString delline;
	CString autosize;
	bold.Format(_T("%d"), CGlobal::BoolToInt(m_bold.GetCheck()));
	italic.Format(_T("%d"), CGlobal::BoolToInt(m_italic.GetCheck()));
	unline.Format(_T("%d"), CGlobal::BoolToInt(m_unline.GetCheck()));
	delline.Format(_T("%d"), CGlobal::BoolToInt(m_delline.GetCheck()));
	autosize.Format(_T("%d"), CGlobal::BoolToInt(m_autosetsize.GetCheck()));
	if (m_autosetsize.GetCheck() == TRUE) {
		fontsize = "12";
	}
	else {
		GetDlgItem(IDC_FONTSIZE)->GetWindowText(fontsize);
	}
	CMFCFontInfo* pInfoFont = m_fontname.GetSelFont();
	WritePrivateProfileString(_T("font"), _T("name"), pInfoFont->m_strName,CGlobal::inipath);
	WritePrivateProfileString(_T("font"), _T("size"), fontsize, CGlobal::inipath);
	WritePrivateProfileString(_T("font"), _T("autosize"), autosize, CGlobal::inipath);
	WritePrivateProfileString(_T("font"), _T("bold"), bold, CGlobal::inipath);
	WritePrivateProfileString(_T("font"), _T("italic"), italic, CGlobal::inipath);
	WritePrivateProfileString(_T("font"), _T("unline"), unline, CGlobal::inipath);
	WritePrivateProfileString(_T("font"), _T("delline"), delline, CGlobal::inipath);
	//EndDialog(1);
}


void SetColorDlg::OnCbnSelchangeMfcfontcombo1()
{
	OnPreview();
}

void SetColorDlg::OnBnClickedTextcolor()
{
	// TODO: 在此添加控件通知处理程序代码
}


void SetColorDlg::OnBnClickedBackgroundcolor()
{
	// TODO: 在此添加控件通知处理程序代码
}


void SetColorDlg::OnEnChangeFontsize()
{
	OnPreview();
}


void SetColorDlg::OnBnClickedBoldchk()
{
	OnPreview();
}


void SetColorDlg::OnBnClickedItalicchk()
{
	OnPreview();
}


void SetColorDlg::OnBnClickedUnlinechk()
{
	OnPreview();
}


void SetColorDlg::OnBnClickedDellinkchk()
{
	OnPreview();
}


void SetColorDlg::OnBnClickedAutosetsize()
{
	OnPreview();
}

BOOL SetColorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_fontname.SetWindowTextW(CGlobal::font_name);
	m_fontsize.SetWindowTextW(CGlobal::font_size);
	m_autosetsize.SetCheck(CGlobal::font_sizeauto);
	m_bold.SetCheck(CGlobal::font_sizeauto);
	m_italic.SetCheck(CGlobal::font_italic);
	m_unline.SetCheck(CGlobal::font_unline);
	m_delline.SetCheck(CGlobal::font_delline);
	WinOK = TRUE;
	OnPreview();
	return TRUE;  // return TRUE unless you set the focus to a control
}
