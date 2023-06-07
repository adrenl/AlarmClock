#pragma once
#include "afxdialogex.h"


// SetFormatDlg 对话框

class SetFormatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SetFormatDlg)

public:
	SetFormatDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetFormatDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETFORMAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCanbtn();
	afx_msg void OnBnClickedOkbtn();
	CEdit m_example;
	afx_msg void OnBnClickedDefaultbtn();
	CEdit m_fmt;
};
