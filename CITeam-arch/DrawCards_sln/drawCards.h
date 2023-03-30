#ifndef DRAWCARDS_H
#define DRAWCARDS_H
/* 抽卡
 * */
#include "common.h"
#define BACK 0
#define COME_IN 1
#define DRAW 2


/* 人物用结构定义,包含：
 *  ·人物编号
 *  ·人物名称
 * */
typedef struct {
    int no;
    char *name;
}RoleInfo;

int initWindow();
/* 初始化窗口，窗口大小用宏(商讨定义)
 * 首界面设计
 * */

int initRoleInformation(RoleInfo *roleDataSet);
/* 初始化人物数据，malloc一块空间存放各人物属性
 * */

int initSource();
/* 初始化资源数据
 * 原石数、资源名称为“原石”
 * */

int startDraw();
/* 进入程序
 * 调用初始化窗口*/

int drawCardView();
/* 贴图工作，设置抽卡界面
 * */

int Animation();
/* 设置抽卡时的动画效果，以及抽卡结果的界面展示*/

#endif //DRAWCARDS_H
