#include "HelloWorld.h"


CWinApp myapp;
/*CMyApp*/
BOOL CMyApp::InitInstace()
{
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

/*CMainWindow*/

//œ˚œ¢”≥…‰
BEGIN_MESSAGE_MAP(CMainWindow,CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



CMainWindow::CMainWindow()
{
	Create(NULL, _T("The Hello App"));

}

void CMainWindow::OnPaint()
{
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	dc.DrawText(L"Hello World", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
