#include "windows.h"


LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);


//WIN32程序入口点  -- 消息循环
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int nCmdShow)
{
	WNDCLASS wc;  //窗口
	HWND	hwnd; //窗口句柄
	MSG		msg;

	//设置窗口属性
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); //背景
	wc.hCursor = LoadCursor(NULL, IDI_WINLOGO);  //光标
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);		 //图标
	wc.hInstance = hInstance;
	wc.lpszClassName = L"ZZZ";	
	wc.lpszMenuName = NULL;

	//注册窗口
	RegisterClass(&wc);

	//创建窗口
	hwnd = CreateWindow(
		L"ZZZ",						//根据窗口类名生成窗口
		L"写个窗口类",				//窗口标题
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		HWND_DESKTOP,
		NULL,
		hInstance,
		NULL
	);

	//显示窗口
	ShowWindow(hwnd, nCmdShow);

	//更新窗口
	UpdateWindow(hwnd);

	//消息循环
	while (GetMessage(&msg,hwnd,0,0))
	{
		TranslateMessage(&msg);   //消息ID转化为字符消息
		DispatchMessage(&msg);    //消息分离
	}

	return msg.wParam;

}


//消息处理回调函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT message , WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT: //重新绘制窗口
		
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 0, 0, 100, 200);
		EndPaint(hwnd, &ps);

		return 0;

	case WM_DESTROY://撤销窗口

		PostQuitMessage(0);

		return 0;

	}

	return DefWindowProc(hwnd, message, wParam, lParam); //调用默认窗口消息处理函数，确保应用程序没有处理的消息能够被处理
}