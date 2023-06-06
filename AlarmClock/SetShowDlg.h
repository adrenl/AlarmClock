#pragma once
#include "afxdialogex.h"


// SetShowDlg 对话框

class SetShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SetShowDlg)

public:
	SetShowDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetShowDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETSHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	static LOGFONT slf;
	virtual BOOL OnInitDialog();
	CMFCColorButton m_bgcolor;
	CButton m_autoajust;
	afx_msg void OnBnClickedCanbtn();
	afx_msg void OnBnClickedOkbtn();
	afx_msg void OnBnClickedSetfontbtn();
	CMFCColorButton m_textcolor;
};
