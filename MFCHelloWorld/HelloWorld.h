#pragma once
#include "afxwin.h"

class CMyApp : public CWinApp
{
public:

	virtual BOOL InitInstace();
};

class CMainWindow : public CFrameWnd
{
public:
	CMainWindow();

private:

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
};




