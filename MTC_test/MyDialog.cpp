// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MTC_test.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog �Ի���

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


// MyDialog ��Ϣ�������


BOOL MyDialog::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���

	// TODO: Modify the Window class or styles here bymodifying
	//  the CREATESTRUCTcs

	cs.dwExStyle&= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	cs.style |= WS_CLIPCHILDREN|WS_CLIPSIBLINGS;
	cs.cx = 50;//���ڿ��
	cs.cy = 50;//���ڸ߶�

	return TRUE;

}


void MyDialog::PreInitDialog()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::PreInitDialog();
}


BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	::MoveWindow(this->m_hWnd,200,200,init.myWidth,init.myHight,TRUE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
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
