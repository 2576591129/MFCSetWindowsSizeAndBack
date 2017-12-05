// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MTC_test.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

	MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent),init(this->m_hWnd,1000,200,_T("D:\\aaa.jpg"))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MyDialog 消息处理程序


BOOL MyDialog::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类

	// TODO: Modify the Window class or styles here bymodifying
	//  the CREATESTRUCTcs

	cs.dwExStyle&= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	cs.style |= WS_CLIPCHILDREN|WS_CLIPSIBLINGS;
	cs.cx = 50;//窗口宽度
	cs.cy = 50;//窗口高度

	return TRUE;

}


void MyDialog::PreInitDialog()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::PreInitDialog();
}


BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	::MoveWindow(this->m_hWnd,200,200,init.myWidth,init.myHight,TRUE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH MyDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd == this)
	{
		return init.m_brBk;
	}
	return hbr;
}
