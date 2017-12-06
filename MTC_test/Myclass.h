#include "stdafx.h"

class InitDialog
{
public:
	InitDialog()
	{		
		
	}

	~InitDialog()
	{
		bitmap.DeleteObject();
		img.Destroy();
	}


	void SetWindowSize(int height,int wight)
	{
		//set the hight and the width
		myWidth = height;	
		myHight = wight;
		::MoveWindow(hwnd,200,200,myWidth,myHight,TRUE);
	}
	void SetBackPicture(LPCTSTR picture_path)
	{	
		CRect rc;
		::GetWindowRect(hwnd,&rc);
		CImage image;
		image.Load(picture_path) ;
		image.Draw(::GetDC(hwnd), CRect(0,0,rc.Width(),rc.Height()));
	}
	void Set(LPCTSTR picture_path,int height,int wight)
	{
		myWidth = height;	
		myHight = wight;
		::MoveWindow(hwnd,200,200,myWidth,myHight,TRUE);

		//set the background
		this->picture_path = picture_path;	
		img.Load (picture_path);
		bitmap.Attach(img.Detach());
		m_brBk.CreatePatternBrush(&bitmap);
	}



public:
	int myWidth;	
	CBrush m_brBk;
	LPCTSTR picture_path;
	int myHight;
	CBitmap bitmap;
	CImage img;
	HWND hwnd;
};

