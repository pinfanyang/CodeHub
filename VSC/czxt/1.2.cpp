//�嵥1-2 ����̬���к��û�̬����ʱ��ȼ���
// proclist��Ŀ
#include <windows.h>
#include <tlhelp32.h>
#include <iostream.h>

// �����û�ģʽ���ں�ģʽ�¶��ṩ����ʱ��ʱ�����ں�ģʽ�½�������ʱ���64λ����İ�������
DWORD GetKernelModePercentage(const FILETIME& ftKernel,
							  const FILETIME& ftUser)
{
    // ��FILETIME�ṹת��Ϊ64λ����
    ULONGLONG qwKernel=(((ULONGLONG)ftKernel.dwHighDateTime)
		<<32)+ftKernel.dwLowDateTime;
    ULONGLONG qwUser=(((ULONGLONG)ftUser.dwHighDateTime)
		<<32)+ftUser.dwLowDateTime;

    // ������ʱ����ӣ�Ȼ������������ں�ģʽ�µ�ʱ��ٷֱ�
    ULONGLONG qwTotal=qwKernel+qwUser;
    DWORD dwPct=(DWORD)(((ULONGLONG)100*qwKernel)/qwTotal);
    return(dwPct);
}

// �����ǽ���ǰ���й��������������ں�ģʽ�µ�ʱ��ٷ�������ʾ������Ӧ�ó���
void main(int argc,char *argv[])
{
    
	if(argc<2) 
	{
		cout<<"�������Ҫ��ѯ�ĳ�����"<<endl;
		exit(0);
	}
	
	// �Ե�ǰϵͳ�����еĹ�����ȡ"����"	
	HANDLE hSnapshot=::CreateToolhelp32Snapshot(
	   TH32CS_SNAPPROCESS,				// ��ȡ��ǰ����
	   0);								// ����ǵ�ǰ���̣��ͽ������

    // ��ʼ���������   
	PROCESSENTRY32 pe;
	::ZeroMemory(&pe,sizeof(pe));
	pe.dwSize=sizeof(pe);
	BOOL bMore=::Process32First(hSnapshot,&pe);
	BOOL found = FALSE;
	while(bMore)
	{
        // �����ڶ�ȡ�Ĺ���		
	
		if(!strcmp(pe.szExeFile,argv[1])) 
		{
			found = TRUE;
			HANDLE hProcess=::OpenProcess(
				PROCESS_QUERY_INFORMATION,		// ָ��Ҫ�õ���Ϣ
				FALSE,							// ���ؼ̳���һ���
				pe.th32ProcessID);				// Ҫ�򿪵Ľ���
			if (hProcess!=NULL)
			{
			    // �ҳ����̵�ʱ��
				FILETIME ftCreation,ftKernelMode,ftUserMode,ftExit;
				::GetProcessTimes(
					hProcess,					// ������Ȥ�Ľ���
					&ftCreation,				// ���̵�����ʱ�� 
					&ftExit,					// ����ʱ�� (����еĻ�)
					&ftKernelMode,				// ���ں�ģʽ�����ĵ�ʱ��
					&ftUserMode);				// ���û�ģʽ�����ĵ�ʱ��

				// �����ں�ģʽ���ĵ�ʱ��ٷֱ�
				DWORD dwPctKernel=::GetKernelModePercentage(
					ftKernelMode,				// ���ں�ģʽ�����ĵ�ʱ��
					ftUserMode);				// ���û�ģʽ�����ĵ�ʱ��

            // ���û���ʾ���̵�ĳЩ��Ϣ
			cout<< "process ID: " << pe.th32ProcessID
				<< ",EXE file:" << pe.szExeFile
				<< ",%d in Kernel mode: " << dwPctKernel << endl;

            // �������
			::CloseHandle(hProcess);
			}
		}
        // ת����һ������
		bMore=::Process32Next(hSnapshot,&pe);
	}
	if(found==FALSE)
	{
		cout<<"��ǰϵͳû�������ִ�г�����������"<<endl;
		exit(0);
	}
}

