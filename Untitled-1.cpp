// WindowsProject3.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "WindowsProject5.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define MAX_LOADSTRING 100
#define DEF_TIMER1 1
using namespace std;



// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance(hInstance, nCmdShow))
    {

        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT5));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

int xu = 0;//贯穿全段代码的确定方块类型的 变量锁
int ci = 0;//初始赋值使用的FFyici中的变量
int ff1 = 2;//判断变形的次数
int ff2 = 0;//判断变形的次数
int pan = 1;//暂停功能使用到的变量锁
int ikun = 800;//定时器的快慢值
int awei = 1;//判断是否处于加速或不加速的变量锁
int nb = 1;//方块每次下落的距离
int suo = 0;//判断是否落到底部，判断是否能加速 变形 左右移的变量锁
int elo = 0;//每次生成一个随机方块的单次变量锁
int chudi = 0;//触底则增加的变量锁

//变形时用上的变量
int a1 = 0;int a2 = 0;
int a3 = 0;int a4 = 0;
int a5 = 0;int a6 = 0;
int a7 = 0;int a8 = 0;

int arrweizi[45][20] = { 0 };//位置数组 底部保存作用

int x = 0; int y = 0;//方块转入dibu函数转存时用到的中转变量


//只调用一次的赋值函数，FFzijian函数运行后再次调用赋值
void FFyici1() {
    if (ci < 1) {
        a1 = 1; a2 = 2; a3 = 3; a4 = 0;
        a5 = 0; a6 = 0; a7 = 0; a8 = 0;
        ci++;
    }
}
void FFyici2() {
    if (ci < 1) {
        a1 = -1; a4 = -1; a2 = 0; a5 = -1;  
        a7 = 0; a8 = 0; a3 = 1; a6 = -1;
        ci++;
    }
}
void FFyici3() {
    if (ci < 1) {
        a3 = 1; a6 = 0; a1 = 0; a4 = -1;
        a2 = 0; a5 = -2; a7 = 0; a8 = 0;
        ci++;
    }
}
void FFyici4() {
    if (ci < 1) {
        a7 = 0; a8 = 0; a1 = 1; a4 = 0;
        a2 = 0; a5 = -1; a3 = -1; a6 = -1;
        ci++;
    }
}
void FFyici6() {
    if (ci < 1) {
        a7 = 0; a8 = 0; a1 = -1; a4 = 0;
        a2 = 0; a5 = -1; a3 = 1; a6 = -1;
         ci++;
    }
}
void FFyici0() {
    if (ci < 1) {
        a1 = -1; a4 = 0; a7 = 0; a8 = 0;
        a2 = 0; a5 = -1; a3 = 0; a6 = -2;
        ci++;
    }
}



class QIUYU {//父类
public:


    //构造
    QIUYU() {};


    //主要绘图
    void FFhui(HDC hdc) {
        //靠变量锁 xu 来确定该一直画那一方块
        Rectangle(hdc, 0, 0, 360, 800);
        
        if (xu == 6 && suo == 0) {
                FFyici6();
                //取下面（x6+a7）（y6+a8)做解释，a7 a8是后续变形所需要做增减值的变量  如：FFshan
                //x6 y7是做基本左右移动 下落的变量 如：FFxia FFzuo FFyou

                HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
                HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                Rectangle(hdc, (x6 + a7) * 20 + 1, (y6 + a8) * 20 + 1, (x6 + a7) * 20 + 20, (y6 + a8) * 20 + 20);
                Rectangle(hdc, (x6 + a1) * 20 + 1, (y6 + a4) * 20 + 1, (x6 + a1) * 20 + 20, (y6 + a4) * 20 + 20);
                Rectangle(hdc, (x6 + a2) * 20 + 1, (y6 + a5) * 20 + 1, (x6 + a2) * 20 + 20, (y6 + a5) * 20 + 20);
                Rectangle(hdc, (x6 + a3) * 20 + 1, (y6 + a6) * 20 + 1, (x6 + a3) * 20 + 20, (y6 + a6) * 20 + 20);
                SelectObject(hdc, oldBrush);
        }
        else if (xu == 0 && suo == 0) {
                FFyici0();
                HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
                HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                Rectangle(hdc, (x7 + a7) * 20 + 1, (y7 + a8) * 20 + 1, (x7 + a7) * 20 + 20, (y7 + a8) * 20 + 20);
                Rectangle(hdc, (x7 + a1) * 20 + 1, (y7 + a4) * 20 + 1, (x7 + a1) * 20 + 20, (y7 + a4) * 20 + 20);
                Rectangle(hdc, (x7 + a2) * 20 + 1, (y7 + a5) * 20 + 1, (x7 + a2) * 20 + 20, (y7 + a5) * 20 + 20);
                Rectangle(hdc, (x7 + a3) * 20 + 1, (y7 + a6) * 20 + 1, (x7 + a3) * 20 + 20, (y7 + a6) * 20 + 20);
                SelectObject(hdc, oldBrush);
                y = y7;
            }
        else if (xu == 1 && suo == 0) {
                FFyici1();
                HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
                HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                Rectangle(hdc, (x1 + a7) * 20 + 1, (y1 + a8) * 20 + 1, (x1 + a7) * 20 + 20, (y1 + a8) * 20 + 20);
                Rectangle(hdc, (x1 + a1) * 20 + 1, (y1 + a4) * 20 + 1, (x1 + a1) * 20 + 20, (y1 + a4) * 20 + 20);
                Rectangle(hdc, (x1 + a2) * 20 + 1, (y1 + a5) * 20 + 1, (x1 + a2) * 20 + 20, (y1 + a5) * 20 + 20);
                Rectangle(hdc, (x1 + a3) * 20 + 1, (y1 + a6) * 20 + 1, (x1 + a3) * 20 + 20, (y1 + a6) * 20 + 20);
                SelectObject(hdc, oldBrush);   
        }
        else if (xu == 2 && suo == 0) {
            FFyici2();
            HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
            Rectangle(hdc, (x2 + a7) * 20 + 1, (y2 + a8) * 20 + 1, (x2 + a7) * 20 + 20, (y2 + a8) * 20 + 20);
            Rectangle(hdc, (x2 + a1) * 20 + 1, (y2 + a4) * 20 + 1, (x2 + a1) * 20 + 20, (y2 + a4) * 20 + 20);
            Rectangle(hdc, (x2 + a2) * 20 + 1, (y2 + a5) * 20 + 1, (x2 + a2) * 20 + 20, (y2 + a5) * 20 + 20);
            Rectangle(hdc, (x2 + a3) * 20 + 1, (y2 + a6) * 20 + 1, (x2 + a3) * 20 + 20, (y2 + a6) * 20 + 20);
            SelectObject(hdc, oldBrush);
        }
        else if (xu == 3 && suo == 0) {
                FFyici3();
                HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
                HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                Rectangle(hdc, (x3 + a7) * 20 + 1, (y3 + a8) * 20 + 1, (x3 + a7) * 20 + 20, (y3 + a8) * 20 + 20);
                Rectangle(hdc, (x3 + a1) * 20 + 1, (y3 + a4) * 20 + 1, (x3 + a1) * 20 + 20, (y3 + a4) * 20 + 20);
                Rectangle(hdc, (x3 + a2) * 20 + 1, (y3 + a5) * 20 + 1, (x3 + a2) * 20 + 20, (y3 + a5) * 20 + 20);
                Rectangle(hdc, (x3 + a3) * 20 + 1, (y3 + a6) * 20 + 1, (x3 + a3) * 20 + 20, (y3 + a6) * 20 + 20);
                SelectObject(hdc, oldBrush);
        }
        else if (xu == 4&&suo==0) {
            FFyici4();
            HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
            Rectangle(hdc, (x4 + a7) * 20 + 1, (y4 + a8) * 20 + 1, (x4 + a7) * 20 + 20, (y4 + a8) * 20 + 20);
            Rectangle(hdc, (x4 + a1) * 20 + 1, (y4 + a4) * 20 + 1, (x4 + a1) * 20 + 20, (y4 + a4) * 20 + 20);
            Rectangle(hdc, (x4 + a2) * 20 + 1, (y4 + a5) * 20 + 1, (x4 + a2) * 20 + 20, (y4 + a5) * 20 + 20);
            Rectangle(hdc, (x4 + a3) * 20 + 1, (y4 + a6) * 20 + 1, (x4 + a3) * 20 + 20, (y4 + a6) * 20 + 20);
            SelectObject(hdc, oldBrush);
        }
        else if (xu == 5 && suo == 0) {
            HBRUSH hBrush = CreateSolidBrush(RGB(220, 20, 60));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
            Rectangle(hdc,  x5 * 20 + 1, y5 * 20 + 1, x5 * 20 + 20, y5 * 20 + 20);
            Rectangle(hdc, (x5 + 1) * 20 + 1, (y5) * 20 + 1, (x5 + 1) * 20 + 20, ( y5 ) * 20 + 20);
            Rectangle(hdc, ( x5) * 20 + 1, (y5 - 1) * 20 + 1, (x5 ) * 20 + 20, (y5 - 1) * 20 + 20);
            Rectangle(hdc, (x5+1) * 20 + 1,(y5 - 1) * 20 + 1, (x5+1) * 20 + 20,(y5 - 1) * 20 + 20);
            SelectObject(hdc, oldBrush);
        }
       
        
        
    }
    //下落
    void FFxia() {
        if (pan % 2 == 1&&suo==0) {
          y1+=nb; y2+=nb; y3+=nb; y4+=nb; y5+=nb; y6+=nb; y7+=nb;
        }
    }
    //左移
    void FFzuo() {
        if (pan % 2 == 1){
            x1--; x2--; x3--; x4--; x5--; x6--; x7--;
        }
        
    }
    //右移
    void FFyou() {
        if (pan % 2 == 1) {
            x1++; x2++; x3++; x4++; x5++; x6++; x7++;       
        }
    }
    //变形
    void FFshan() {
        switch (xu) {
            
        case 1:
            
            if (ff1 % 2 == 0) {
                a1 = 1; a2 = 1; a3 = 1; a4 = 1;
                a5 = 2; a6 = 3; a7 = 1; a8 = 0;
            }
            else if(ff1%2==1) {
                a1 = 1; a2 = 2; a3 = 3; a7 = 0;
                a4 = 0; a5 = 0; a6 = 0; a8 = 0;
            }
            ff1++;
            break;
        case 2:
            
            if (ff2 % 4 == 0) {
                a1 = -1; a4 = 0; a2 = -1; a5 = 1;
                a7 = 0; a8 = 0; a3 = -1; a6 = -1;
            }
            else if (ff2 % 4 == 1) {
                a7 = 0; a8 = 0; a1 = -1; a4 = 1;
                a2 = 0; a5 = 1; a3 = 1; a6 = 1;
            }
            else if (ff2 % 4 == 2) {
                a1 = 1; a4 = 0; a2 = 1; a5 = 1;
                a7 = 0; a8 = 0; a3 = 1; a6 = -1;
            }
            else if(ff2%4==3) {
                a1 = -1; a4 = -1; a2 = 0; a5 = -1;
                a7 = 0; a8 = 0; a3 = 1; a6 = -1;
            }
       
            ff2++;
            break;
        case 3:
            if (ff2 % 4 == 0) {
                a1 = -1; a4 = 0; a2 = -1; a5 = 1;
                a7 = 0; a8 = 0; a3 = 1; a6 = 0;
            }
            else if (ff2 % 4 == 1) {
                a1 = -1; a4 = 0; a7 = 0; a8 = 0;
                a2 = 0; a5 = 1; a3 = 0; a6 = 2;
            }
            else if (ff2 % 4 == 2) {
                a1 = -1; a4 = 0; a7 = 0; a8 = 0;
                a2 = -2; a5 = 0; a3 = 0; a6 = -1;
            }
            else if (ff2 % 4 == 3) {
                a3 = 1; a6 = 0; a1 = 0; a4 = -1;
                a2 = 0; a5 = -2; a7 = 0; a8 = 0;
            }
            ff2++;
            break;
        case 4:
            if (ff2 % 4 == 0) {
                a2 = 0; a5 = -1; a7 = 0; a8 = 0;
                a1 = -1; a4 = 0; a3 = -1; a6 = 1;
            }
            else if (ff2 % 4 == 1) {
                a1 = -1; a4 = 0; a7 = 0; a8 = 0;
                a2 = 0; a5 = 1; a3 = 1; a6 = 1;
            }
            else if (ff2 % 4 == 2) {
                a2 = 0; a5 = 1; a7 = 0; a8 = 0;
                a1 = 1; a4 = 0; a3 = 1; a6 = -1;
            }
            else if (ff2 % 4 == 3) {
                a7 = 0; a8 = 0; a1 = 1; a4 = 0;
                a2 = 0; a5 = -1; a3 = -1; a6 = -1;
            }
            ff2++;
            break;
        case 6:
            if (ff2 % 4 == 0||ff2%4==2) {
                a2 = -1; a5 = 0; a7 = 0; a8 = 0;
                a1 = -1; a4 = -1; a3 = 0; a6 = 1;
            }
            else if (ff2 % 4 == 1||ff2%4==3) {
                a1 = -1; a4 = 1; a7 = 0; a8 = 0;
                a2 = 1; a5 = 0; a3 = 0; a6 = 1;
            }
            ff2++;
            break;
        case 0:
            if (ff2 % 4 == 0) {
                a2 = -1; a5 = 0; a7 = 0; a8 = 0;
                a1 = -2; a4 = 0; a3 = 0; a6 = 1;
            }
            else if (ff2 % 4 == 1) {
                a1 = 0; a4 = 2; a7 = 0; a8 = 0;
                a2 = 1; a5 = 0; a3 = 0; a6 = 1;
            }
            else if (ff2 % 4 == 2) {
                a7 = 0; a8 = 0; a1 = 1; a4 = 0;
                a2 = 0; a5 = -1; a3 = 2; a6 = 0;
            }
            else if (ff2 % 4 == 3) {
                a1 = -1; a4 = 0; a7 = 0; a8 = 0;
                a2 = 0; a5 = -1; a3 = 0; a6 = -2;
            }
            ff2++;
            break;
        }
    }
    //判断边界
    //每一个方块变形后形状边界不一，故需要重新编写边界
    void FFbian() {
        switch (xu) {
        case 1:
            switch (ff1 % 2) {
            case 0:
                if (x1 > 14) { x1 = 13; }if (x1 < 0) { x1 = 1; } if (y1 >= 39) { y1 = 39; chudi++; }
                break;
            case 1:
                if (x1 > 16) { x1 = 15; }if (x1 < -1) { x1 = 0; }if (y1 >= 39) { y1 = 39; chudi++;}
                
                break;
            }
            break;
        case 2:
            if (ff2 % 4 == 0 || ff2 % 4 == 2) {
                if (x2 < 1) { x2 = 2; } if (x2 > 16) { x2 = 15; }if (y2 >= 39) { y2 = 39; chudi++;
                }
            }
            if (ff2 % 4 == 1) { if (x2 > 17) { x2 = 16; } if (x2 < 1) { x2 = 2; } if (y2 >= 39) { y2 = 39; chudi++;
            } }
            if (ff2 % 4 == 3) { if (x2 < 0) { x2 = 1; }if (x2 > 16) { x2 = 15; }if (y2 >= 39) { y2 = 39; chudi++;
            } }
            break;
        case 3:
            if (ff2 % 4 == 3) { if (x3 < 2) { x3 = 3; }if (x3 > 17) { x3 = 16; }if (y3 >= 39) { y3 = 39; chudi++;
            } }
            else if (ff2 % 4 == 2) { if (x3 > 17) { x3 = 16; }if (x3 < 1) { x3 = 2; }if (y3 >= 39) { y3 = 39; chudi++;
            } }
            else if (ff2 % 4 == 1) { if (x3 > 16) { x3 = 15; }if (x3 < 1) { x3 = 2; }if (y3 >= 39) { y3 = 39; chudi++;
            } }
            else { if (x3 > 16) { x3 = 15; }if (x3 < 0) { x3 = 1; } if (y3 >= 39) { y3 = 39; chudi++;
            } }
            break;
        case 4:
            if (ff2 % 4 == 3) { if (x4 < 0) { x4 = 1; }if (x4 > 16) { x4 = 15; } if (y4 >= 39) { chudi++; y4 = 39; } }
            else if (ff2 % 4 == 0) { if (x4 < 1) { x4 = 2; }if (x4 > 16) { x4 = 15; } if (y4 >= 39) { chudi++; y4 = 39; } }
            else if (ff2 % 4 == 2) { if (x4 < 1) { x4 = 2; }if (x4 > 16) { x4 = 15; } if (y4 >= 39) { chudi++; y4 = 39; } }
            else if (ff2 % 4 == 1) { if (x4 < 1) { x4 = 2; }if (x4 > 17) { x4 = 16; } if (y4 >= 39) { chudi++; y4 = 39; } }
            break;
        case 5:
            if (x5 < 0) { x5 = 1; }
            if (x5 > 16) { x5 = 15; }
            if (y5 >= 39) { chudi++; y5 = 39; }
            break;
        case 6:
            if (ff2 % 4 == 0 || ff2 % 4 == 2) { if (x6 < 1) { x6 = 2; }if (x6 > 16) { x6 = 15; }if (y6 >= 39) { chudi++; y6 = 39; } }
            else { if (x6 < 1) { x6 = 2; }if (x6 > 17) { x6 = 16; }if (y6 >= 39) { chudi++; y6 = 39; } }
            break;
        case 0:
            if (ff2 % 4 == 0) { if (x7 < 1) { x7 = 2; }if (x7 > 17) { x7 = 16; }if (y7 >= 39) { chudi++; y7 = 39; } }
            else if (ff2 % 4 == 1) { if (x7 < 2) { x7 = 3; }if (x7 > 17) { x7 = 16; }if (y7 >= 39) { chudi++; y7 = 39; } }
            else if (ff2 % 4 == 2) { if (x7 < 0) { x7 = 1; }if (x7 > 16) { x7 = 15; }if (y7 >= 39) { chudi++; y7 = 39; } }
            else { if (x7 < 0) { x7 = 1; }if (x7 > 15) { x7 = 14; }if (y7 >= 39) { chudi++; y7 = 39; } }
            break;

        }
    }
    
   
    //加速状态则将nb变为5  意为每次下落5块
    void FFjiasu() {
        if (awei % 2 == 1) {
            nb = 5;
            awei++;
        }
        else if(awei % 2 == 0){
            nb = 1;
            awei++;
        }
    }
    void FFdibu() {
        if (chudi>0|| arrweizi[y+1][x] == 1) {
            suo++;
            FFdihua1();
            chudi = 0;
        }
        
    }
    //将方块所处的基本位置赋值给x y
    void FFsuo() {
        switch (xu) {
                case 0:
                    x = x7; y = y7;
                    break;
                case 1:
                    x = x1; y = y1;
                    break;
                case 2:
                    x = x2; y = y2;
                    break;
                case 3:
                    x = x3; y = y3;
                    break;
                case 4:
                    x = x4; y = y4;
                    break;
                case 5:
                    x = x5; y = y5;
                    break;
                case 6:
                    x = x6; y = y6;
                    break;
                }
    }
    //将方块的位置赋值给底部数组arrweizi
    void FFdihua1() {
        switch (xu) {
        case 0:
            arrweizi[y7 + a8][x7 + a7]++; arrweizi[y7 + a4][x7 + a1]++; arrweizi[y7 + a5][x7 + a2]++; arrweizi[y7 + a6][x7 + a3]++;
            break;
        case 1:
            arrweizi[y1 + a8][x1 + a7]++; arrweizi[y1 + a4][x1 + a1]++; arrweizi[y1 + a5][x1 + a2]++; arrweizi[y1 + a6][x1 + a3]++;
            break;
        case 2:
            arrweizi[y2 + a8][x2 + a7]++; arrweizi[y2 + a4][x2 + a1]++; arrweizi[y2 + a5][x2 + a2]++; arrweizi[y2 + a6][x2 + a3]++;
            break;
        case 3:
            arrweizi[y3 + a8][x3 + a7]++; arrweizi[y3 + a4][x3 + a1]++; arrweizi[y3 + a5][x3 + a2]++; arrweizi[y3 + a6][x3 + a3]++;
            break;
        case 4:
            arrweizi[y4 + a8][x4 + a7]++; arrweizi[y4 + a4][x4 + a1]++; arrweizi[y4 + a5][x4 + a2]++; arrweizi[y4 + a6][x4 + a3]++;
            break;
        case 6:
            arrweizi[y6 + a8][x6 + a7]++; arrweizi[y6 + a4][x6 + a1]++; arrweizi[y6 + a5][x6 + a2]++; arrweizi[y6 + a6][x6 + a3]++;
            break;
        case 5:
            arrweizi[y5][x5]++; arrweizi[y5][x5 + 1]++; arrweizi[y5 - 1][x5]++; arrweizi[y5 - 1][x5 + 1]++;
            break;
        }   
   }
    //画出底部数组arrwezi中的方块
    void FFdihua2(HDC hdc) {
        for (int az = 40; az > 0; az--) {
            for (int sx = 0; sx < 20; sx++) {
                if (arrweizi[az][sx] >= 1) {

                    HBRUSH hBrush = CreateSolidBrush(RGB(160, 20, 60));
                    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                    Rectangle(hdc, sx * 20 + 1, (az-1) * 20 + 1, sx * 20 + 20, (az - 1) * 20 + 20);
                    SelectObject(hdc, oldBrush);
                }
            }
        }
   }
    //重新产生方块 使elo等变为零
    void FFzijian() {
        if (suo > 0) {
            ci = 0;
            suo = 0;
            elo = 0;
            chudi = 0;
        }
    }
    //消除底部堆积好的一排完整方块
    void FFxiaochu() {
        int w3 = 0; int w7 = 0;
        for (int w1 = 40; w1 > 0; w1--) {
            for (int w2 = 0; w2 < 20; w2++) {
                if (arrweizi[w1][w2] >= 1) {
                    w3++;
                }
                else if (arrweizi[w1][w2] < 1) {
                    w3 = 0;
                    break;
                }
                if (w3 == 19) {
                    for (int w4 = 0; w4 < 20; w4++) {
                        arrweizi[w1][w4] = 0; w7 = w1;
                   }
                }
            }
        }
        for (int w5 = w7; w5 > 0; w5--) {
            for (int w6 = 0; w6 < 20; w6++) {
                if (arrweizi[w5][w6] >= 1) {
                    arrweizi[w5 + 1][w6] = arrweizi[w5][w6];
                    arrweizi[w5][w6] = 0;
                }
            }
        }


    }
    virtual void di1() = 0; //纯虚函数1.0
    virtual void di2() = 0; //纯虚函数2.0
    int x1 = 7, y1 = 0, x2 = 8, y2 = 1, x3 = 8, y3 = 2, x4 = 9, y4 = 1, x5 = 8, y5 = 1, x6 = 9, y6 = 1, x7 = 9, y7 = 2;

    //虚析构
    ~QIUYU() {};

};

//左移


class FFQIUYU1 :public QIUYU {//长方条


public:


    void di1() {
        arrweizi[0][0] = 1, arrweizi[0][1] = 1, arrweizi[0][2] = 1, arrweizi[0][3] = 1;

    }
    void di2() {
        arrweizi[0][0] = 1, arrweizi[0][1] = 1, arrweizi[0][2] = 1, arrweizi[0][3] = 1;

    }


};
class FFQIUYU2 :public FFQIUYU1 {//T形


public:


    void di1() {
        arrweizi[0][5] = 1, arrweizi[0][6] = 1, arrweizi[0][7] = 1, arrweizi[1][6] = 1;
        FFQIUYU1::di1();
    }
    void di2() {
        arrweizi[0][5] = 1, arrweizi[0][6] = 1, arrweizi[0][7] = 1, arrweizi[1][6] = 1;

    }

};
class FFQIUYU3 :public FFQIUYU2 {//L形


public:


    void di1() {
        arrweizi[0][9] = 1, arrweizi[1][9] = 1, arrweizi[2][9] = 1, arrweizi[2][10] = 1;
        FFQIUYU1::di1();
        FFQIUYU2::di1();
    }
    void di2() {
        arrweizi[0][9] = 1, arrweizi[1][9] = 1, arrweizi[2][9] = 1, arrweizi[2][10] = 1;

    }

};
class FFQIUYU4 :public FFQIUYU3 {//不规则形


public:


    void di1() {
        arrweizi[2][1] = 1, arrweizi[2][0] = 1, arrweizi[3][1] = 1, arrweizi[3][2] = 1;
        FFQIUYU1::di1();
        FFQIUYU2::di1();
        FFQIUYU3::di1();
    }
    void di2() {
        arrweizi[2][1] = 1, arrweizi[2][0] = 1, arrweizi[3][1] = 1, arrweizi[3][2] = 1;

    }

};
class FFQIUYU5 :public FFQIUYU4 {//正方形


public:


    void di1() {
        arrweizi[3][5] = 1, arrweizi[3][6] = 1, arrweizi[4][5] = 1, arrweizi[4][6] = 1;
        FFQIUYU1::di1();
        FFQIUYU2::di1();
        FFQIUYU3::di1();
        FFQIUYU4::di1();
    }
    void di2() {
        arrweizi[3][5] = 1, arrweizi[3][6] = 1, arrweizi[4][5] = 1, arrweizi[4][6] = 1;

    }
    ~FFQIUYU5() {};
};
class FFQIUYU6 :public FFQIUYU5 {//反不规则形


public:


    void di1() {
        arrweizi[5][1] = 1, arrweizi[5][2] = 1, arrweizi[6][0] = 1, arrweizi[6][1] = 1;
        FFQIUYU1::di1();
        FFQIUYU2::di1();
        FFQIUYU3::di1();
        FFQIUYU4::di1();
        FFQIUYU5::di1();
    }
    void di2() {
        arrweizi[5][1] = 1, arrweizi[5][2] = 1, arrweizi[6][0] = 1, arrweizi[6][1] = 1;

    }

};
class FFQIUYU7 :public FFQIUYU6 {//反L形


public:


    void di1() {
        arrweizi[4][10] = 1, arrweizi[5][10] = 1, arrweizi[6][10] = 1, arrweizi[6][9] = 1;
        FFQIUYU1::di1();
        FFQIUYU2::di1();
        FFQIUYU3::di1();
        FFQIUYU4::di1();
        FFQIUYU5::di1();
        FFQIUYU6::di1();
    }
    void di2() {
        arrweizi[4][10] = 1, arrweizi[5][10] = 1, arrweizi[6][10] = 1, arrweizi[6][9] = 1;

    }

};

void FFqiu(HDC hdc)//黑框函数
{
    HDC hMemeDC = CreateCompatibleDC(hdc);
    HBITMAP hbackbmp = CreateCompatibleBitmap(hdc, 500, 800);
    SelectObject(hMemeDC, hbackbmp);
    BitBlt(hdc, 0, 0, 500, 800, hMemeDC, 0, 0, SRCCOPY);
    DeleteObject(hbackbmp);
    DeleteDC(hMemeDC);
}

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT5));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT5);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中

    HWND hWnd = CreateWindowW(szWindowClass,                          //窗口类型名
        TEXT("阿伟俄罗斯"),                           //窗口的标题
        WS_OVERLAPPEDWINDOW,                    //窗口的风格
        200, 100,                               //窗口左上角坐标(像素:px)
        500, 800,                               //窗口的宽和高
        nullptr,                                //父窗口句柄
        nullptr,                                //菜单句柄
        hInstance,                              //应用程序实例句柄
        nullptr);


    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//

FFQIUYU1 te1; FFQIUYU2 te2; FFQIUYU3 te3; FFQIUYU4 te4; FFQIUYU5 te5; FFQIUYU6 te6; FFQIUYU7 te7;




void FFxuan() {
    if (elo < 1) {
        srand((unsigned int)time(NULL));

        xu = rand() % 7;
    }
    elo++;
}
 QIUYU* p21 = &te1;
 FFQIUYU1* p1 = new FFQIUYU1;
 FFQIUYU2* p2 = new FFQIUYU2;
 FFQIUYU3* p3 = new FFQIUYU3;
 FFQIUYU4* p4 = new FFQIUYU4;
 FFQIUYU5* p5 = new FFQIUYU5;
 FFQIUYU6* p6 = new FFQIUYU6;
 FFQIUYU7* p7 = new FFQIUYU7;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    switch (message)
    {

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 分析菜单选择:
        switch (wmId)
        {
        case IDM_ABOUT:

            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;



    case WM_PAINT:
    {
        p21->FFzijian();
        p21->FFxiaochu();
        FFqiu(hdc);//画黑框
        FFxuan();
       
        
        switch (xu) {
        case 1:
            p21 = p1;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        case 2:
            p21 = p2;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        case 3:
            p21 = p3;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        case 4:
            p21 = p4;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        case 5:
            p21 = p5;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        case 6:
            p21 = p6;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        case 0:
            p21 = p7;
            p21->FFhui(hdc); p21->FFdihua2(hdc);
            break;
        }


    }
    break;


    case WM_CREATE:


        break;
    case WM_KEYDOWN:
        switch (wParam)
        { 
        case VK_RETURN://按回车开始下落方块

            SetTimer(hWnd, 5000, ikun, NULL);

            break;
        case VK_LEFT://左移
            if(suo==0){
            switch (xu) {
            case 1:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 2:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 3:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 4:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 5:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 6:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 0:
                p21->FFzuo();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            }}
            break;
        case VK_RIGHT://右移
            if (suo == 0) {       
            switch(xu) {
            case 1:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 2:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 3:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 4:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 5:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 6:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            case 0:
                p21->FFyou();
                p21->FFbian();
                p21->FFhui(hdc);
                break;
            }}
            break;
        case VK_UP://变形
            if(suo==0){
            switch (xu) {
            case 1:
                p21->FFshan();
                break;
            case 2:
                p21->FFshan();
                break;
            case 3:
                p21->FFshan();
                break;
            case 4:
                p21->FFshan();
                break;
            case 6:
                p21->FFshan();
                break;
            case 0:
                p21->FFshan();
                break;

            }}
            break;
        case VK_SPACE://暂停
            pan++;
            break;
        case VK_DOWN://加速

            if (suo == 0) {
              p21->FFjiasu();
            }
            break;
        }
        break;
    case WM_TIMER:


        switch (xu) {
        case 1:
            p21->FFxia(); p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        case 2:
            p21->FFxia(); p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        case 3:
            p21->FFxia(); p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        case 4:
            p21->FFxia();p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        case 5:
            p21->FFxia(); p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        case 6:
            p21->FFxia(); p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        case 0:
            p21->FFxia(); p21->FFdibu();
            p21->FFbian(); p21->FFdihua2(hdc);
            break;
        }
        
        ReleaseDC(hWnd, hdc);

        /*   te1.FFhui(hdc);*/
         //  GetClientRect(hWnd, NULL);

        InvalidateRect(hWnd, NULL, 0);
        UpdateWindow(hWnd);
        break;




    case WM_DESTROY://窗口销毁消息
        KillTimer(hWnd, DEF_TIMER1);
        PostQuitMessage(0);
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete p5;
        delete p6;
        delete p7;
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
 
    

    return 0;
}



// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
