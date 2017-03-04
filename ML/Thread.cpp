
#include "stdafx.h"
#include "Thread.h"

tThreadInfo threadInfo[MAX_TIMERS_COUNT];
int threadInfoSize = 0;


DWORD WINAPI ThreadsProc(LPVOID lpParameter)
{
	ptThreadInfo pthreadInfo = (ptThreadInfo) (lpParameter);
	pthreadInfo->threadWork = TRUE;
	pthreadInfo->proc();
	pthreadInfo->threadWork = FALSE;
	return 0;
}

void CALLBACK TimersProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	if (!threadInfo[idEvent - 1].threadWork) {
		KillTimer(hWnd, idEvent);
		CloseHandle(threadInfo[idEvent].hthread);
		threadInfo[idEvent - 1].afproc();
	}
}

HANDLE CreateWaitThread(HWND hWnd, WaitThreadProc proc, WaitThreadProc afproc)
{
	int dwThreadId;

	threadInfo[threadInfoSize].threadWork = FALSE;
	threadInfo[threadInfoSize].proc = proc;
	threadInfo[threadInfoSize].afproc = afproc;

	threadInfo[threadInfoSize].hthread = CreateThread(NULL, 0, ThreadsProc, (LPVOID)&(threadInfo[threadInfoSize]), 0, (LPDWORD)&dwThreadId);
	threadInfo[threadInfoSize].htimer = SetTimer(hWnd, threadInfoSize + 1, USER_TIMER_MINIMUM, (TIMERPROC)TimersProc);

	threadInfoSize++;

	return threadInfo[threadInfoSize].hthread;
}

HANDLE CreateSingleThread(LPTHREAD_START_ROUTINE proc)
{
	int dwThreadId;

	return CreateThread(NULL, 0, proc, NULL, 0, (LPDWORD)&dwThreadId);
}