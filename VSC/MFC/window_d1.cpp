#include <windows.h>

//声明窗口函数原型
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//主函数
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE PreInstance,LPSTR lpCmdLine,int nCmdShow)
{
    HWND hwnd;  //定义窗口句柄
    MSG msg;    //定义一个用来存储消息的变量
    char lpszClassName[]="窗口";
    WNDCLASS wc;    //定义一个窗口类变量
    wc.style=0;
    wc.lpfnWndProc=WndProc;		//函数指针
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hInstance=hInstance;
    wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName=NULL;
    wc.lpszClassName=lpszClassName;

    RegisterClass(&wc);     //注册窗口类
    hwnd=CreateWindow(lpszClassName,"Windows",WS_OVERLAPPEDWINDOW,120,50,800,600,NULL,NULL,hInstance,NULL); //创建窗口类
    ShowWindow(hwnd,nCmdShow);  //显示窗口
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0))   //消息循环
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

//处理消息的窗口函数
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    switch(message)
    {
        case WM_LBUTTONDOWN:
        {
            MessageBeep(0);
    
        }
			break;
        case WM_DESTROY:
        {
            PostQuitMessage(0);
        }
			break;
        default:
			return DefWindowProc(hwnd,message,wParam,lParam);

    }
    return 0;
}
