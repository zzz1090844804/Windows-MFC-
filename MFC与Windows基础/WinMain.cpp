#include "windows.h"


LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);


//WIN32������ڵ�  -- ��Ϣѭ��
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int nCmdShow)
{
	WNDCLASS wc;  //����
	HWND	hwnd; //���ھ��
	MSG		msg;

	//���ô�������
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); //����
	wc.hCursor = LoadCursor(NULL, IDI_WINLOGO);  //���
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);		 //ͼ��
	wc.hInstance = hInstance;
	wc.lpszClassName = L"ZZZ";	
	wc.lpszMenuName = NULL;

	//ע�ᴰ��
	RegisterClass(&wc);

	//��������
	hwnd = CreateWindow(
		L"ZZZ",						//���ݴ����������ɴ���
		L"д��������",				//���ڱ���
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

	//��ʾ����
	ShowWindow(hwnd, nCmdShow);

	//���´���
	UpdateWindow(hwnd);

	//��Ϣѭ��
	while (GetMessage(&msg,hwnd,0,0))
	{
		TranslateMessage(&msg);   //��ϢIDת��Ϊ�ַ���Ϣ
		DispatchMessage(&msg);    //��Ϣ����
	}

	return msg.wParam;

}


//��Ϣ����ص�����
LRESULT CALLBACK WndProc(HWND hwnd, UINT message , WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT: //���»��ƴ���
		
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 0, 0, 100, 200);
		EndPaint(hwnd, &ps);

		return 0;

	case WM_DESTROY://��������

		PostQuitMessage(0);

		return 0;

	}

	return DefWindowProc(hwnd, message, wParam, lParam); //����Ĭ�ϴ�����Ϣ��������ȷ��Ӧ�ó���û�д������Ϣ�ܹ�������
}