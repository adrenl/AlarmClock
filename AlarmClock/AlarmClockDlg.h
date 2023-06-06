
// AlarmClockDlg.h: 头文件
//

#pragma once
#include "SetColorDlg.h"
// CAlarmClockDlg 对话框
class CAlarmClockDlg : public CDialogEx
{
// 构造
public:
	CAlarmClockDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALARMCLOCK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_time;
	CFont m_font;
	CRect m_rect;
	CTime m_times;
	bool isMouseDown;    //鼠标是否按下  

	void ChangeSize(UINT nID, int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32772();
	afx_msg void OnStnDblclickTime();
	void LoadIni();
};
