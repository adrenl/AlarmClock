// SetFormatDlg.cpp: 实现文件
//

#include "pch.h"
#include "AlarmClock.h"
#include "afxdialogex.h"
#include "SetFormatDlg.h"


// SetFormatDlg 对话框

IMPLEMENT_DYNAMIC(SetFormatDlg, CDialogEx)

SetFormatDlg::SetFormatDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETFORMAT, pParent)
{

}

SetFormatDlg::~SetFormatDlg()
{
}

void SetFormatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXAMPLE, m_example);
	DDX_Control(pDX, IDC_FMT, m_fmt);
}


BEGIN_MESSAGE_MAP(SetFormatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CANBTN, &SetFormatDlg::OnBnClickedCanbtn)
	ON_BN_CLICKED(IDC_OKBTN, &SetFormatDlg::OnBnClickedOkbtn)
	ON_BN_CLICKED(IDC_DEFAULTBTN, &SetFormatDlg::OnBnClickedDefaultbtn)
END_MESSAGE_MAP()


// SetFormatDlg 消息处理程序


BOOL SetFormatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_fmt.SetWindowTextW(CGlobal::format);
	m_example.SetWindowTextW(L"格式说明：（区分大小写）\r\n%a 星期几的简写\r\n%A 星期几的全称\r\n%b 月分的简写\r\n%B 月份的全称\r\n%c 标准的日期的时间串\r\n%C 年份的后两位数字\r\n%d 十进制表示的每月的第几天\r\n%D 月/天/年\r\n%e 在两字符域中，十进制表示的每月的第几天\r\n%F 年-月-日\r\n%g 年份的后两位数字，使用基于周的年\r\n%G 年分，使用基于周的年\r\n%h 简写的月份名\r\n%H 24小时制的小时\r\n%I 12小时制的小时\r\n%j 十进制表示的每年的第几天\r\n%m 十进制表示的月份\r\n%M 十时制表示的分钟数\r\n%n 新行符\r\n%p 本地的AM或PM的等价显示\r\n%r 12小时的时间\r\n%R 显示小时和分钟：hh:mm\r\n%S 十进制的秒数\r\n%t 水平制表符\r\n%T 显示时分秒：hh:mm:ss\r\n%u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）\r\n%U 第年的第几周，把星期日做为第一天（值从0到53）\r\n%V 每年的第几周，使用基于周的年\r\n%w 十进制表示的星期几（值从0到6，星期天为0）\r\n%W 每年的第几周，把星期一做为第一天（值从0到53）\r\n%x 标准的日期串\r\n%X 标准的时间串\r\n%y 不带世纪的十进制年份（值从0到99）\r\n%Y 带世纪部分的十制年份\r\n%z，%Z 时区名称，如果不能得到时区名称则返回空字符。\r\n%% 百分号");
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void SetFormatDlg::OnBnClickedCanbtn()
{
	EndDialog(0);
}


void SetFormatDlg::OnBnClickedOkbtn()
{
	CString Fmt;
	m_fmt.GetWindowTextW(Fmt);
	theApp.WriteProfileStringW(_T("time"), _T("format"), Fmt);
	EndDialog(1);
}


void SetFormatDlg::OnBnClickedDefaultbtn()
{
	m_fmt.SetWindowTextW(_T("%H : %M : %S"));
}
