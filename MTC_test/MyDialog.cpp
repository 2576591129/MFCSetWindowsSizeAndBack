// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MTC_test.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

	MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
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
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MyDialog 消息处理程序







BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	init.hwnd= this->m_hWnd;

	init.SetWindowSize(1000,500);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}




void MyDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	init.SetBackPicture(_T("res\\aaa.jpg"));
	
}


HBRUSH MyDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);


		return NULL;


}
