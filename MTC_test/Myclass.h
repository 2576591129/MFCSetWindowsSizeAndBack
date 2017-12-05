#include "stdafx.h"

class InitDialog
{
public:
	InitDialog(HWND hwnd,int height,int wight,LPCTSTR picture_path)
	{
		//set the hight and the width

		myWidth = height;	
		myHight = wight;

		//set the background
		this->picture_path = picture_path;	
		img.Load (picture_path);
		bitmap.Attach(img.Detach());
		m_brBk.CreatePatternBrush(&bitmap);

		::MoveWindow(hwnd,200,200,myWidth,myHight,TRUE);
	}

	~InitDialog()
	{
		bitmap.DeleteObject();
		img.Destroy();
	}


public:
	int myWidth;	
	CBrush m_brBk;
	LPCTSTR picture_path;
	int myHight;
	CBitmap bitmap;
	CImage img;
};
