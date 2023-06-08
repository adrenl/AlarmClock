#pragma once
#include "afxdialogex.h"


// SetCAADlg 对话框

class SetCAADlg : public CDialogEx
{
	DECLARE_DYNAMIC(SetCAADlg)

public:
	SetCAADlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetCAADlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETCAA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOkbtn();
	afx_msg void OnBnClickedCanbtn();
	virtual BOOL OnInitDialog();
	CButton m_CAH;
	CButton m_CAHH;
};
