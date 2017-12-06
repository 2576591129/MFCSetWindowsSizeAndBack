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
		m_brBk.DeleteObject();
	}


	void SetWindowSize(int height ,int wight)
	{
		//set the hight and the width
			myWidth = wight;
			myHight = height;
		::MoveWindow(hwnd,200,200,myWidth,myHight,TRUE);
	}

	void SetWindowSize(LPCTSTR picture_path)
	{
		this->picture_path = picture_path;
		img.Load(picture_path);
		myWidth = img.GetWidth();	
		myHight = img.GetHeight();
		::MoveWindow(hwnd,200,200,myWidth,myHight,TRUE);
	}

	void SetBackPicture(LPCTSTR picture_path =0 )
	{	
		CRect rc;
		::GetWindowRect(hwnd,&rc);
		CImage image;
		if(!picture_path &&  this->picture_path)
			image.Load(this->picture_path) ;
		else	if  ( !picture_path &&  !this->picture_path)
			return ;
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

