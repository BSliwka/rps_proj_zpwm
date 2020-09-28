#include <Windows.h>
#include "res.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>

using namespace std;
HINSTANCE g_hInstance;
// 1 - papier // 2 - kamien // 3 - nozyce //

int player_score = 0;
int computer_score = 0;
int players_choice = 0;
int computers_choice = 0;

char buff[100];

void clear_choice() {
    players_choice = 0;
    computers_choice = 0;
}

void clear_score(HWND hwndDlg) {
    player_score = 0;
    computer_score = 0;
    HWND textBox1 = GetDlgItem(hwndDlg, IDC_STATIC1);
    HWND textBox2 = GetDlgItem(hwndDlg, IDC_STATIC2);
    SetWindowText((HWND)textBox1, "Ty: 0");
    SetWindowText((HWND)textBox2, "Komputer: 0");
}

// 1 - papier // 2 - kamien // 3 - nozyce //

void decide(HWND hwndDlg) {
    HWND textBox1 = GetDlgItem(hwndDlg, IDC_STATIC1);
    HWND textBox2 = GetDlgItem(hwndDlg, IDC_STATIC2);
    HWND textBox3 = GetDlgItem(hwndDlg, IDC_ST);
    HWND textBox4 = GetDlgItem(hwndDlg, IDC_STATIC6);
    HBITMAP bmp1 = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    HBITMAP bmp2 = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    HBITMAP bmp3 = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    HBITMAP bmp4 = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);


    if (computers_choice == 1)
    {
      SetWindowText((HWND)textBox4, "Papier");
      SendDlgItemMessage(hwndDlg, IDC_PIC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp1);
        if (players_choice == 3)
        {
            ++player_score;
            sprintf_s(buff, "Ty: %d", player_score);
            SetWindowText((HWND)textBox1, buff);
            SetWindowText((HWND)textBox3, "Wygra³eœ - no¿yce przecinaj¹ papier!");
        }
        if (players_choice == 2)
        {
            ++computer_score;
            sprintf_s(buff, "Komputer: %d", computer_score);
            SetWindowText((HWND)textBox2, buff);
            SetWindowText((HWND)textBox3, "Przegra³eœ - papier zawija kamieñ!");
        }
        if (players_choice == 1)
        {
            SetWindowText((HWND)textBox3, "Remis!");
        }
    }
    if (computers_choice == 2)
    {
      SetWindowText((HWND)textBox4, "Kamieñ");
      SendDlgItemMessage(hwndDlg, IDC_PIC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp2);
        if (players_choice == 3)
        {
            ++computer_score;
            sprintf_s(buff, "Komputer: %d", computer_score);
            SetWindowText((HWND)textBox2, buff);
            SetWindowText((HWND)textBox3, "Przegra³eœ - kamieñ têpi no¿yce!");
        }
        if (players_choice == 1)
        {
            ++player_score;
            sprintf_s(buff, "Ty: %d", player_score);
            SetWindowText((HWND)textBox1, buff);
            SetWindowText((HWND)textBox3, "Wygra³eœ - papier zawija kamieñ!");
        }
        if (players_choice == 2)
        {
            SetWindowText((HWND)textBox3, "Remis!");
        }
    }
    if (computers_choice == 3)
    {
      SetWindowText((HWND)textBox4, "No¿yce");
      SendDlgItemMessage(hwndDlg, IDC_PIC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp3);
        if (players_choice == 1)
        {
            ++computer_score;
            sprintf_s(buff, "Komputer: %d", computer_score);
            SetWindowText((HWND)textBox2, buff);
            SetWindowText((HWND)textBox3, "Przegra³eœ - no¿yce przecinaj¹ papier!");
        }
        if (players_choice == 2)
        {
            ++player_score;
            sprintf_s(buff, "Ty: %d", player_score);
            SetWindowText((HWND)textBox1, buff);
            SetWindowText((HWND)textBox3, "Wygra³eœ - kamieñ têpi no¿yce!");
        }
        if (players_choice == 3)
        {
            SetWindowText((HWND)textBox3, "Remis!");
        }
    }

    if (player_score == 5)
    {
        sprintf_s(buff, "Wygra³eœ! (Ty %d : %d Komputer) Chcesz zagraæ ponownie?", player_score, computer_score);
        if (MessageBox(hwndDlg, buff, "Gratulacje", MB_YESNO) == IDYES)
        {
            clear_score(hwndDlg);
            SetWindowText((HWND)textBox3, "Start gry - dokonaj pierwszego wyboru!");
            SetWindowText((HWND)textBox4, "...");
            SendDlgItemMessage(hwndDlg, IDC_PIC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp4);
        }
        else
        {
            DestroyWindow(hwndDlg);
            PostQuitMessage(0);
        }
    }

    if (computer_score == 5)
    {
        sprintf_s(buff, "Przegra³eœ! (Ty %d : %d Komputer) Chcesz zagraæ ponownie?", player_score, computer_score);
        if (MessageBox(hwndDlg, buff, "Mo¿e nastêpnym razem...", MB_YESNO) == IDYES)
        {
            clear_score(hwndDlg);
            SetWindowText((HWND)textBox3, "Start gry - dokonaj pierwszego wyboru!");
            SetWindowText((HWND)textBox4, "...");
            SendDlgItemMessage(hwndDlg, IDC_PIC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp4);
        }
        else
        {
            DestroyWindow(hwndDlg);
            PostQuitMessage(0);
        }
    }
}

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    
  switch (uMsg)
  {
  case WM_INITDIALOG:
  {
    HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));
    SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    return false; 
  }

  case WM_CLOSE:
      DestroyWindow(hwndDlg);
      PostQuitMessage(0);
      return true;

  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
        case IDC_BUTTON1:
            players_choice = 2;
            computers_choice = ((rand() % 3) + 1);
            decide(hwndDlg);
            clear_choice();
            return true;

        case IDC_BUTTON2:
            players_choice = 1;
            computers_choice = ((rand() % 3) + 1);
            decide(hwndDlg);
            clear_choice();
            return true;

        case IDC_BUTTON3:
            players_choice = 3;
            computers_choice = ((rand() % 3) + 1);
            decide(hwndDlg);
            clear_choice();
            return true;
            
      }
    }
    return false;
  }
      
  return false;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    srand(time(NULL));
    g_hInstance = hInstance;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}
