// SetCAADlg.cpp: 实现文件
//

#include "pch.h"
#include "AlarmClock.h"
#include "afxdialogex.h"
#include "SetCAADlg.h"


// SetCAADlg 对话框

IMPLEMENT_DYNAMIC(SetCAADlg, CDialogEx)

SetCAADlg::SetCAADlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETCAA, pParent)
{

}

SetCAADlg::~SetCAADlg()
{
}

void SetCAADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAH, m_CAH);
	DDX_Control(pDX, IDC_CAHH, m_CAHH);
}


BEGIN_MESSAGE_MAP(SetCAADlg, CDialogEx)
	ON_BN_CLICKED(IDC_OKBTN, &SetCAADlg::OnBnClickedOkbtn)
	ON_BN_CLICKED(IDC_CANBTN, &SetCAADlg::OnBnClickedCanbtn)
END_MESSAGE_MAP()


// SetCAADlg 消息处理程序


void SetCAADlg::OnBnClickedOkbtn()
{
	CString Now;
	CTime This;
	theApp.WriteProfileInt(_T("time"), _T("clarm_at_hour"), CGlobal::BoolToInt(m_CAH.GetCheck()));
	theApp.WriteProfileInt(_T("time"), _T("clarm_at_half_hour"), CGlobal::BoolToInt(m_CAHH.GetCheck()));
	for (unsigned int i = 0; i < 4; i++) {
		Now.Format(_T("%d"), i);
		CDateTimeCtrl* pDateTimeCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1 + i);
		CButton* pCheckBox = (CButton*)GetDlgItem(IDC_CHECK1 + i);
		pDateTimeCtrl->GetTime(This);
		theApp.WriteProfileInt(_T("time"), _T("alarm_h_"+Now),This.GetHour());
		theApp.WriteProfileInt(_T("time"), _T("alarm_m_" + Now), This.GetMinute());
		theApp.WriteProfileInt(_T("time"), _T("alarm_enable_"+Now), CGlobal::BoolToInt(pCheckBox->GetCheck()));
	}
	EndDialog(1);
}


void SetCAADlg::OnBnClickedCanbtn()
{
	EndDialog(0);
}


BOOL SetCAADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_CAH.SetCheck(CGlobal::clarm_at_hour);
	m_CAHH.SetCheck(CGlobal::clarm_at_half_hour);
	for (unsigned int i = 0; i < 4; i++) {
		CDateTimeCtrl* pDateTimeCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1 + i);
		CButton* pCheckBox = (CButton*)GetDlgItem(IDC_CHECK1 + i);
		pDateTimeCtrl->SetFormat(_T("HH:mm"));
		pDateTimeCtrl->SetTime(&CGlobal::AlarmTime[i]);
		pCheckBox->SetCheck(CGlobal::AlarmTimeEnable[i]);
	}
	return TRUE;
}
