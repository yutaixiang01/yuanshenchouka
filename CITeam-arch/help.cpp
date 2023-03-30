#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <easyx.h>
#include <ctime>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

//---------------------------------------
// 传入坐标, 将光标移动到指定坐标
void gotoXY(int x, int y)
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


//使用案例
//清理指定矩形区域(从(x,y)到(x+w,y+h)的矩形
void clear(int x, int y, int w, int h)
{
    for (int i = 0; i < h; i++) {
        gotoXY(x, y + i);
        for (int j = 0;j < w;j++) putchar(' ');
    }
}

//--------------------------------------------
#include <windows.h>
/*
	设置打印字体的颜色
	0x24: 低位4表示字体红色 高位2表示背景绿色

	0: 黑
	1: 蓝
	2: 绿
	3: 蓝绿
	4: 红
	5: 紫
	6: 黄
	7: 白
	+8表示高亮
*/
void setPrintColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


//----------------------------------------------------

#define music_background 0
#define music_over 1
#define music_score 2
#define music_title 3
// 是否播放音乐 0表示不播放, 1表示播放
extern int isMusic=1;

//音乐文件的路径
const wchar_t musicPath[4][128] = {
        L"./background.wav",
        L"./music/over.wav",
        L"./music/score.wav",
        L"./music/title.wav"
};



