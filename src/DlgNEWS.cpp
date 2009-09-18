#include "DlgNEWS.h"
#include <aygshell.h>
#include <string>
//#include "Sysinfo.h"
#include "utf8.hpp"
#include "../vs2005/ui/resourceppc.h"
extern std::string newsstring;
extern HINSTANCE g_hInst; // current instance

// Message handler for about box.
INT_PTR CALLBACK news(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{std::wstring  n;
    switch (message)
    {
    case WM_INITDIALOG:
        {
            // Create a Done button and size it.  
            SHINITDLGINFO shidi;
            shidi.dwMask = SHIDIM_FLAGS;
            shidi.dwFlags = SHIDIF_DONEBUTTON | SHIDIF_SIPDOWN | SHIDIF_SIZEDLGFULLSCREEN | SHIDIF_EMPTYMENU;
            shidi.hDlg = hDlg;
            SHInitDialog(&shidi);

            n=utf8::utf8_wchar(newsstring);

				SetDlgItemText(hDlg, IDC_NEWS_EDIT,n.c_str() );
			
            //SetDlgItemText(hDlg, IDC_AVERSION, MAKEINTRESOURCE(IDS_VERSION));
        }
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return TRUE;
        }
        break;

    case WM_CLOSE:
        EndDialog(hDlg, message);
        return TRUE;

        /*#ifdef _DEVICE_RESOLUTION_AWARE
        case WM_SIZE:
        {
        DRA::RelayoutDialog(
        g_hInst, 
        hDlg, 
        DRA::GetDisplayMode() != DRA::Portrait ? MAKEINTRESOURCE(IDD_ABOUTBOX_WIDE) : MAKEINTRESOURCE(IDD_ABOUTBOX));
        }
        break;
        #endif*/
    }
    return (INT_PTR)FALSE;
}


void  DlgNEWS(HINSTANCE hInst, HWND parentWnd) {
    DialogBox(hInst, (LPCTSTR)IDD_HISTOR, parentWnd, news);
}
