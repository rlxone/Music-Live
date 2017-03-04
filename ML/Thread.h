
#define MAX_TIMERS_COUNT 100

typedef int (*WaitThreadProc)(void);
typedef int(*SingleThreadProc)(LPVOID lpParameter);

typedef struct _tagThread {
	WaitThreadProc proc;
	WaitThreadProc afproc;
	BOOL threadWork;
	HANDLE hthread;
	UINT_PTR htimer;
} tThreadInfo, *ptThreadInfo;

HANDLE CreateWaitThread(HWND hWnd, WaitThreadProc proc, WaitThreadProc afproc);
HANDLE CreateSingleThread(LPTHREAD_START_ROUTINE proc);