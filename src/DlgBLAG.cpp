#include "DlgBLAG.h"
#include <aygshell.h>
//#include "Sysinfo.h"
//#include "utf8.hpp"
#include "../vs2005/ui/resourceppc.h"

extern HINSTANCE g_hInst; // current instance

// Message handler for about box.
INT_PTR CALLBACK Blag(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
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

            

            SetDlgItemText(hDlg, IDC_EDIT1, L"WMID 361790411398");
			SetDlgItemText(hDlg, IDC_EDIT2, L"E479008419378");
			SetDlgItemText(hDlg, IDC_EDIT3, L"Z374971411509");
			SetDlgItemText(hDlg, IDC_EDIT4, L"R212134056228");
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


void DlgBLAG(HINSTANCE hInst, HWND parentWnd) {
    DialogBox(hInst, (LPCTSTR)IDD_BLAGO, parentWnd, Blag);
}
