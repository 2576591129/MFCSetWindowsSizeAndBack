
// MTC_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMTC_testApp:
// �йش����ʵ�֣������ MTC_test.cpp
//

class CMTC_testApp : public CWinApp
{
public:
	CMTC_testApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMTC_testApp theApp;