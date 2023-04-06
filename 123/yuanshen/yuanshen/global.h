#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//定义字符数组，， 存放，，，所有的物品
//按照角色和武器的星级进行分组，数据来源于常驻池说明

//常驻13把三星武器
extern const char weapon_3star[][200];
//常驻16四星角色
extern const char char_4star[][200];
//18个四星武器
extern const char weapon_4star[][200];
//常驻10 五星武器
extern const char weapon_char_5star[][200];
//定义纠缠数
extern int jiuchan_num;
//抽出的物品星级
extern int xingji;
//存放随机数
extern int r;
//连续ssr-1抽没有五星物品
extern int ssr;
//连续sr-1抽没有四星物品
extern int sr;
//定义一个字符数组存储结果
extern char results[100];
//总权重为10000
extern int Wceil;
//三星物品权重
extern int wr;
//写一个选择池子的判断函数
extern void xuanzechizi();
//卡池函数
extern void chanzgzhuchouka();
//确定星级之后的输出函数
extern void queding_xingji();
//打印输出结果函数
extern char* result(int xingji);
//生成一个均匀分布在[1,max]上的随机数
extern int RF1(int max);
//取两个数之间的最小值
extern int min(int a, int b);
//五星角色权重  随着ssr增加（暨随着没有抽中的数量变多）权重变多   
//ssr为0是权重为 60   ssr大于等于74之后权值每次增加600  权值最高时大于10000
extern int wssr(int ssr);
//四星角色与武器权重
//sr为0时权重为510    sr大于等于8之后权重每次增加5100   权重最高是大于10000
extern int wsr(int sr);
//定义一个保底
extern int baodi;
//定义池子
extern int chizi;