
// AlarmClockDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AlarmClock.h"
#include "AlarmClockDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAlarmClockDlg 对话框



CAlarmClockDlg::CAlarmClockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ALARMCLOCK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAlarmClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TIME, m_time);
}

BEGIN_MESSAGE_MAP(CAlarmClockDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_COMMAND(ID_32772, &CAlarmClockDlg::On32772)
	ON_STN_DBLCLK(IDC_TIME, &CAlarmClockDlg::OnStnDblclickTime)
END_MESSAGE_MAP()


// CAlarmClockDlg 消息处理程序

void CAlarmClockDlg::LoadIni() {
	GetPrivateProfileString(_T("font"),_T("name"),_T("Digital"),CGlobal::font_name.GetBuffer(MAX_PATH), MAX_PATH, CGlobal::inipath);
	GetPrivateProfileString(_T("font"), _T("size"), _T("12"), CGlobal::font_size.GetBuffer(MAX_PATH), MAX_PATH, CGlobal::inipath);
	CGlobal::font_sizeauto = CGlobal::IntToBool(GetPrivateProfileInt(_T("font"), _T("autosize"), 1, CGlobal::inipath));
	CGlobal::font_bold = CGlobal::IntToBool(GetPrivateProfileInt(_T("font"), _T("bold"), 0, CGlobal::inipath));
	CGlobal::font_italic = CGlobal::IntToBool(GetPrivateProfileInt(_T("font"), _T("italic"), 0, CGlobal::inipath));
	CGlobal::font_unline = CGlobal::IntToBool(GetPrivateProfileInt(_T("font"), _T("unline"), 0, CGlobal::inipath));
	CGlobal::font_delline = CGlobal::IntToBool(GetPrivateProfileInt(_T("font"), _T("delline"), 0, CGlobal::inipath));
	SetTimer(ID_TIMER, 1000, 0);
	GetClientRect(&m_rect);
	if (CGlobal::font_sizeauto == true) {
		//CAlarmClockDlg::OnSize(SIZE_RESTORED,200,200);
	} else {
		m_font.CreateFontW(_ttoi(CGlobal::font_size), 0, 0, 0, (CGlobal::font_bold == TRUE ? FW_BOLD : 0), CGlobal::font_italic, CGlobal::font_unline, CGlobal::font_delline, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, CGlobal::font_name);
		m_time.SetFont(&m_font, true);
	}
}

BOOL CAlarmClockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	LoadIni();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAlarmClockDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAlarmClockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAlarmClockDlg::ChangeSize(UINT nID, int x, int y) {
	CWnd* pWnd;
	CRect rect;
	CString Cont;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL)
	{
		pWnd->GetWindowTextW(Cont);
		pWnd->SetWindowPos(NULL,0,0,x,y,SWP_NOMOVE);
		pWnd->SetWindowTextW(Cont);
	}
}

void CAlarmClockDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if (nType == SIZE_MINIMIZED) return;
	ChangeSize(IDC_TIME, cx, cy);
	if (GetDlgItem(IDC_TIME) != NULL && CGlobal::font_sizeauto==TRUE) {
		if (m_font.m_hObject) m_font.DeleteObject();
		m_font.CreateFontW(((cx+cy)*0.13), 0, 0, 0, (CGlobal::font_bold == TRUE ? FW_BOLD : 0), CGlobal::font_italic, CGlobal::font_unline, CGlobal::font_delline, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, CGlobal::font_name);
		m_time.SetFont(&m_font, TRUE);
	}
	/*if (GetDlgItem(IDC_TIME) != NULL) {
		if(m_font.m_hObject) m_font.DeleteObject();
		m_font.CreatePointFont(((cx+cy) * 0.5), _T("Digital"), NULL);
		m_time.SetFont(&m_font, true);
	}*/
}

void CAlarmClockDlg::OnTimer(UINT_PTR nIDEvent)
{
	m_times=CTime::GetCurrentTime();
	m_time.SetWindowTextW(m_times.Format("%H : %M : %S"));
	CDialogEx::OnTimer(nIDEvent);
}

void CAlarmClockDlg::On32772()
{
	SetColorDlg doMode;
	if (doMode.DoModal() == 1) {
		LoadIni();
	}
}

void CAlarmClockDlg::OnStnDblclickTime()
{
	CGlobal::showtitle = !CGlobal::showtitle;
	if (CGlobal::showtitle) {
		LONG IStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
		::SetWindowLong(this->m_hWnd, GWL_STYLE, IStyle | WS_CAPTION);
		::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE| SWP_NOMOVE| SWP_NOZORDER| SWP_NOACTIVATE| SWP_FRAMECHANGED | SWP_FRAMECHANGED);
	}else {
		LONG IStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
		::SetWindowLong(this->m_hWnd, GWL_STYLE, IStyle & ~WS_CAPTION);
		::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE| SWP_NOMOVE| SWP_NOZORDER| SWP_NOACTIVATE| SWP_FRAMECHANGED);
	}
}