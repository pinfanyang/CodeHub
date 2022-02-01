#include <windows.h>

//�������ں���ԭ��
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//������
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE PreInstance,LPSTR lpCmdLine,int nCmdShow)
{
    HWND hwnd;  //���崰�ھ��
    MSG msg;    //����һ�������洢��Ϣ�ı���
    char lpszClassName[]="����";
    WNDCLASS wc;    //����һ�����������
    wc.style=0;
    wc.lpfnWndProc=WndProc;		//����ָ��
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hInstance=hInstance;
    wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName=NULL;
    wc.lpszClassName=lpszClassName;

    RegisterClass(&wc);     //ע�ᴰ����
    hwnd=CreateWindow(lpszClassName,"Windows",WS_OVERLAPPEDWINDOW,120,50,800,600,NULL,NULL,hInstance,NULL); //����������
    ShowWindow(hwnd,nCmdShow);  //��ʾ����
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0))   //��Ϣѭ��
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

//������Ϣ�Ĵ��ں���
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
