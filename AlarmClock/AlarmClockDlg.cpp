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
	m_big = AfxGetApp()->LoadIcon(IDI_BIG);
	m_small = AfxGetApp()->LoadIcon(IDI_SMALL);
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
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_32773, &CAlarmClockDlg::On32773)
	ON_COMMAND(ID_32776, &CAlarmClockDlg::On32776)
	ON_COMMAND(ID_32771, &CAlarmClockDlg::On32771)
END_MESSAGE_MAP()
// CAlarmClockDlg 消息处理程序
void CAlarmClockDlg::LoadIni() {
	CGlobal::format = theApp.GetProfileStringW(_T("time"), _T("format"), _T("%H : %M : %S"));
	CGlobal::font_name=theApp.GetProfileStringW(_T("font"),_T("name"),_T("宋体"));
	CGlobal::font_size=theApp.GetProfileStringW(_T("font"), _T("size"), _T("12"));
	CGlobal::font_autoajust = CGlobal::IntToBool(theApp.GetProfileIntW(_T("font"), _T("autoajust"), 1));
	CGlobal::font_bold = CGlobal::IntToBool(theApp.GetProfileIntW(_T("font"), _T("bold"), 0));
	CGlobal::font_italic = CGlobal::IntToBool(theApp.GetProfileIntW(_T("font"), _T("italic"), 0));
	CGlobal::font_unline = CGlobal::IntToBool(theApp.GetProfileIntW(_T("font"), _T("unline"), 0));
	CGlobal::font_delline = CGlobal::IntToBool(theApp.GetProfileIntW(_T("font"), _T("delline"), 0));
	CGlobal::text_color = theApp.GetProfileIntW(_T("color"), _T("text"), 0);
	CGlobal::background_color = theApp.GetProfileIntW(_T("color"), _T("background"), 16776960);
	CGlobal::clarm_at_hour = CGlobal::IntToBool(theApp.GetProfileIntW(_T("time"), _T("clarm_at_hour"), 0));
	CGlobal::clarm_at_half_hour = CGlobal::IntToBool(theApp.GetProfileIntW(_T("time"), _T("clarm_at_half_hour"), 0));
	CString Now;
	int Thish;
	int Thism;
	for (int j = 0; j< 4; j++) {
		Now.Format(_T("%d"), j);
		Thish=theApp.GetProfileIntW(_T("time"), _T("alarm_h_"+Now), 0);
		Thism = theApp.GetProfileIntW(_T("time"), _T("alarm_m_" + Now), 0);
		CGlobal::AlarmTime[j] = CTime(2020,1,1,Thish,Thism,0);
		CGlobal::AlarmTimeEnable[j] = CGlobal::IntToBool(theApp.GetProfileIntW(_T("time"), _T("alarm_enable_"+Now), 0));
	}
	int height= theApp.GetProfileIntW(_T("window"), _T("height"), 300);
	int width= theApp.GetProfileIntW(_T("window"), _T("width"), 300);
	int top = theApp.GetProfileIntW(_T("window"), _T("top"), 100);
	int left = theApp.GetProfileIntW(_T("window"), _T("left"), 100);
	::SetWindowPos(this->m_hWnd, NULL, left,top, width, height, NULL);
	SetTimer(ID_TIMER, 1000, 0);
	if (CGlobal::font_autoajust == true) {
		SetTimer(99999, 1005, NULL);
	} else {
		m_font.CreateFontW(_ttoi(CGlobal::font_size), 0, 0, 0, (CGlobal::font_bold == TRUE ? FW_BOLD : 0), CGlobal::font_italic, CGlobal::font_unline, CGlobal::font_delline, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, CGlobal::font_name);
		m_time.SetFont(&m_font, true);
	}
	GetDlgItem(IDC_TIME)->InvalidateRect(NULL);
}
void CAlarmClockDlg::savewin() {
	CRect rect;
	GetClientRect(rect);
	GetWindowRect(rect);
	if (!this->IsIconic()) {
		theApp.WriteProfileInt(_T("window"), _T("top"), rect.top);
		theApp.WriteProfileInt(_T("window"), _T("left"), rect.left);
		theApp.WriteProfileInt(_T("window"), _T("width"), rect.Width());
		theApp.WriteProfileInt(_T("window"), _T("height"), rect.Height());
	}
}
void CAlarmClockDlg::AjustTimeStatic(int cx,int cy) {
	if (GetDlgItem(IDC_TIME) != NULL && CGlobal::font_autoajust == TRUE) {
		if (m_font.m_hObject) m_font.DeleteObject();
		int Length;
		CString con;
		m_time.GetWindowTextW(con);
		Length = con.GetLength();
		if (Length == 0) return;
		m_font.CreateFontW((cx+cy)/Length, 0 , 0, 0, (CGlobal::font_bold == TRUE ? FW_BOLD : 0), CGlobal::font_italic, CGlobal::font_unline, CGlobal::font_delline, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, CGlobal::font_name);
		m_time.SetFont(&m_font, TRUE);
	}
}
BOOL CAlarmClockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_big, TRUE);
	SetIcon(m_small, FALSE);

	// TODO: 在此添加额外的初始化代码

	LoadIni();
	return TRUE;
}

void CAlarmClockDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

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
	AjustTimeStatic(cx, cy);
}

void CAlarmClockDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 99999) {
		CRect rect;
		GetClientRect(rect);
		ChangeSize(IDC_TIME, rect.Height(), rect.Width());
		CAlarmClockDlg::OnSize(0, rect.Width(), rect.Height());
		AjustTimeStatic(rect.Width(), rect.Height());
		KillTimer(99999);
	}
	m_times=CTime::GetCurrentTime();
	m_time.SetWindowTextW(m_times.Format(CGlobal::format));
	for (int a = 0; a < 4; a++) {
		if (CGlobal::AlarmTime[a].GetHour() == m_times.GetHour() && CGlobal::AlarmTime[a].GetMinute() == m_times.GetMinute() && m_times.GetSecond() == 0 && CGlobal::AlarmTimeEnable[a]==TRUE) {
			MessageBeep(MB_ICONINFORMATION);
		}
	}
	if(((m_times.GetMinute()==0 && CGlobal::clarm_at_hour == TRUE) || (m_times.GetMinute() == 30 && CGlobal::clarm_at_half_hour == TRUE)) && m_times.GetSecond() == 0) MessageBeep(MB_ICONINFORMATION);
	CDialogEx::OnTimer(nIDEvent);
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

HBRUSH CAlarmClockDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	HBRUSH hbrBk;
	if (pWnd->GetDlgCtrlID() == IDC_TIME)
	{
		pDC->SetTextColor(CGlobal::text_color);
		hbrBk = ::CreateSolidBrush(CGlobal::background_color);
		pDC->SetBkColor(CGlobal::background_color);
		return hbrBk;
	}
	return hbr;
}

void CAlarmClockDlg::OnClose()
{
	savewin();
	CDialogEx::OnClose();
}

void CAlarmClockDlg::On32773()
{
	SetFormatDlg Mode;
	if(Mode.DoModal()==1){
		savewin();
		LoadIni();
	}
}

void CAlarmClockDlg::On32772()
{
	SetShowDlg Mode;
	if (Mode.DoModal() == 1) {
		savewin();
		LoadIni();
	}
}

void CAlarmClockDlg::On32776()
{
	MessageBeep(MB_ICONINFORMATION);
	MSGBOXPARAMS msgBox;
	msgBox.cbSize = sizeof(MSGBOXPARAMS);
	msgBox.dwStyle = MB_USERICON;
	msgBox.hInstance = AfxGetApp()->m_hInstance;
	msgBox.hwndOwner = NULL;
	msgBox.lpszCaption = _T("关于");
	msgBox.lpszIcon = MAKEINTRESOURCE(IDR_MAINFRAME);
	msgBox.lpszText = _T("AlarmClock");
	MessageBoxIndirect(&msgBox);
}

void CAlarmClockDlg::On32771()
{
	SetCAADlg Mode;
	if (Mode.DoModal() == 1) {
		savewin();
		LoadIni();
	}
}
