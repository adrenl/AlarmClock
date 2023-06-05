#pragma once
#include "afxdialogex.h"


// SetColorDlg 对话框

class SetColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SetColorDlg)

public:
	SetColorDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetColorDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETSHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFCColorButton m_textcolor;
	CMFCColorButton m_backgroundcolor;
	CButton m_autosetsize;
	CButton m_setfont;
	afx_msg void OnBnClickedSetfont();
	afx_msg void OnBnClickedCancalbtn();
	afx_msg void OnBnClickedOkbtn();
};
