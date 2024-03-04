#include <Windows.h>
#include "resource.h"

HINSTANCE hInstance;

INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	::hInstance = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}


INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		
		
		
		

		break;
	}
	case WM_MOUSEMOVE: {
        POINT cursorPos;
        GetCursorPos(&cursorPos);

        
        HWND hStatic = GetDlgItem(hwnd, IDC_STATIC1);

        
        RECT rect;
        RECT WinRect;
        GetWindowRect(hStatic, &rect);
        GetWindowRect(hwnd, &WinRect);

        int testX;
        int testY;
        int newX = 0;
        int newY = 0;

       
        if (cursorPos.x > rect.left - 50 && cursorPos.x < rect.right + 50 &&
            cursorPos.y > rect.top - 50 && cursorPos.y < rect.bottom + 50)
        {
           
            testX = rect.left + (rand() % 50) * (rand() % 2 == 0 ? 1 : -1);
            testY = rect.top + (rand() % 50) * (rand() % 2 == 0 ? 1 : -1);

            if ((testX > WinRect.left) && (testX < WinRect.right) && (testY > WinRect.top) && (testY < WinRect.bottom)) {
                newX = testX;
                newY = testY;
            }

           
            SetWindowPos(hStatic, NULL, newX, newY, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
        }
        break;
	}

	


	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return TRUE;
		
	}

	return FALSE;
}