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
//	afx_msg void OnBnClickedSetfont();
	afx_msg void OnBnClickedCancalbtn();
	afx_msg void OnBnClickedOkbtn();
	afx_msg void OnCbnSelchangeMfcfontcombo1();
	CMFCFontComboBox m_fontname;
	CStatic m_preview;
	CEdit m_fontsize;
	CButton m_bold;
	CButton m_italic;
	CButton m_unline;
	void OnPreview();
	afx_msg void OnBnClickedTextcolor();
	afx_msg void OnBnClickedBackgroundcolor();
	afx_msg void OnEnChangeFontsize();
	afx_msg void OnBnClickedBoldchk();
	afx_msg void OnBnClickedItalicchk();
	afx_msg void OnBnClickedUnlinechk();
	afx_msg void OnBnClickedDellinkchk();
	afx_msg void OnBnClickedAutosetsize();
	CButton m_delline;
	virtual BOOL OnInitDialog();
};
