#include"global.h"

//常驻13把三星武器
const char weapon_3star[][200] = { "弹弓", "神射手之誓","鸦羽弓","翡玉法球","讨龙英杰谭","魔导绪论","黑缨枪",
								"以理服人","沐浴龙血的剑","铁影阔剑","飞天御剑","黎明神剑","冷刃" };


//常驻16四星角色
const char char_4star[][200] = { "辛焱", "砂糖", "迪奥娜", "重云", "诺艾尔", "班尼特", "菲谢尔", "凝光",
								"行秋", "北斗", "香菱", "安柏", "雷泽", "凯亚", "芭芭拉", "丽莎" };


//18个四星武器
const char weapon_4star[][200] = { "弓藏", "祭礼弓", "绝弦", "西风猎弓", "昭心", "祭礼残章", "流浪乐章", "西风秘典", "西风长枪",
								"匣里灭辰", "雨裁", "祭礼大剑", "钟剑", "西风大剑", "匣里龙吟", "祭礼剑", "笛剑", "西风剑" };

//常驻15 五星
const char weapon_char_5star[][200] = { "刻晴" ,"莫娜" ,"七七" ,"迪卢克" ,"琴","阿莫斯之弓", "天空之翼", "四风原典", "天空之卷", "和璞鸢",
								"天空之脊", "狼的末路", "天空之傲", "天空之刃", "风鹰剑" };

//定义纠缠数
int jiuchan_num = 0;

//抽出的物品星级
int xingji = 0;

//存放随机数
int r = 0;

//连续ssr-1抽没有五星物品
int ssr = 0;

//连续sr-1抽没有四星物品
int sr = 1;
//定义一个字符数组存储结果
char results[100];
//总权重为10000
int Wceil = 10000;
//三星物品权重
static int wr = 9430;

int chizi = 0;
int baodi = 0;

//生成一个均匀分布在[1,max]上的随机数
int RF1(int max) {
	return 1 + (int)max * rand() / (RAND_MAX + 1);
}

//取两个数之间的最小值
int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}


//五星角色权重  随着ssr增加（暨随着没有抽中的数量变多）权重变多   
//ssr为0是权重为 60   ssr大于等于74之后权值每次增加600  权值最高时大于10000
int wssr(int ssr) {
	if (ssr <= 73) {
		return 60;
	}
	else if (ssr >= 74) {
		return (60 + 600 * (ssr - 73));
	}
}


//四星角色与武器权重
//sr为0时权重为510    sr大于等于8之后权重每次增加5100   权重最高是大于10000
int wsr(int sr) {
	if (sr <= 8) {
		return 510;
	}
	else if (sr >= 9) {
		return 510 + 5100 * (sr - 8);
	}
}

//写一个选择池子的判断函数
void xuanzechizi() {
	printf_s("\n选择(卡池)\n 1.常驻池\n 2.神里绫华up \n 3.胡桃up\n");
	scanf_s("%d", &chizi);
}


//定义抽卡的函数  
void chanzgzhuchouka() {
	//定义修改纠缠数量
	printf_s("输入一共抽几次:");
	scanf_s("%d", &jiuchan_num);

	xuanzechizi();


	//循环确定每次的星级  三  四   五
	//用过修改jiuchan_num 来判断循环
	for (int i = 0; i < jiuchan_num; ) {

		//定义选择哪种抽取方式  抽一抽还是10抽
		int xuanze = 0;

		//选择池子的函数

		printf_s("\n选择（1 or 2）\n 1.抽一发。\n 2.抽10发\n");
		scanf_s("%d", &xuanze);

		if (xuanze == 1) {

			//纠缠数减一
			jiuchan_num -= 1;

			//如果纠缠不够  退出
			if (jiuchan_num == 0) {
				break;
			}

			//确定抽卡等级的函数
			queding_xingji();
		}
		else {

			//纠缠数不够10 退出
			if (jiuchan_num < 10) {
				printf_s("纠缠不足");
				break;

			}
			else {
				jiuchan_num -= 10;

				//循环十次   确定每次星级
				for (int j = 1; j <= 10; j++) {
					queding_xingji();
				}
			}
		}
	}
}

void queding_xingji() {


	//产生随机数
	r = RF1(min(Wceil, wssr(ssr) + wsr(sr) + wr));


	//抽出五星     随机数在【1，wssr(ssr)】中
	if (r >= 1 && r <= wssr(ssr)) {
		xingji = 5;
		printf_s("\n%d\n", xingji);   //打印星级
		ssr = 0;
		sr += 1;
		result(xingji);       //输出结果
	}
	//抽出四星      随机数在【wssr(ssr+1),wssr(ssr)+wsr(sr)】中
	else if (r >= wssr(ssr + 1) && r <= wssr(ssr) + wsr(sr)) {
		xingji = 4;
		printf_s("\n%d\n", xingji);
		ssr += 1;
		sr = 1;
		result(xingji);
	}
	//抽出三星   随机数在【wssr(ssr)+wsr(sr),max】中
	else {
		xingji = 3;
		printf_s("\n%d\n", xingji);
		ssr += 1;
		sr += 1;
		result(xingji);

	}
}

char* result(int xingji)
{

	//产生一个随机数种子
	//srand((unsigned)time(NULL));

	if (xingji == 3) {

		//产生一个  最大值等同于三星武器数量的 随机数 然后从数组中取值   只有武器  		//  产生[1,13]
		int n1 = rand() % 13;

		//存储 抽到的 三星武器
		//printf_s("%s", weapon_3star[n1]);
		//复制到结果数组中
		strcpy_s(results, weapon_3star[n1]);
		printf_s("%s\n", results);
		//返回结果
		return results;

	}
	else if (xingji == 4) {

		//产生一个    随机数（0  1  ）   判断是武器还是角色   假设0是武器池，，1是角色池
		int boolen = rand() % 2;   //[0,1]

		if (boolen == 0) {
			//武器池
			//产生一个  最大值等同于四星武器数量的 随机数 然后从数组中取值
			int n2 = rand() % 18;
			//printf_s("%s", weapon_4star[n2]);
			strcpy_s(results, weapon_4star[n2]);
			printf_s("%s\n", results);
			return results;
		}
		else {
			//角色池
			//产生一个  最大值等同于四星角色数量的 随机数 然后从数组中取值
			int n3 = rand() % 16;
			//printf_s("%s", char_4star[n3]);
			strcpy_s(results, weapon_4star[n3]);
			printf_s("%s\n", results);
			return results;
		}

	}
	else {
		//五星判断   是否歪了？？/  up池  
		//歪了   是武器还是角色？？//  或者这个不判断   将  角色  武器 合为一起(之后同上)
		//产生一个    随机数（0  1  ）   判断是否歪了

		int boolen = rand() % 2;   //[0,1]


		//如果是常驻池   只能从第一个里面抽  //？？？up池子中   存在   大保底    定义参数后  参数歪了+1   根据参数值判定下一次必不歪
		if (chizi == 1) {
			boolen = 0;
		}

		if (chizi != 1 && baodi == 0 && boolen == 0) {
			boolen = 0;
		}
		else if (chizi != 1 && baodi == 1) {
			boolen = 1;
			baodi = 0;
		}



		if (boolen == 0) {   //歪了   倘若   歪了  
			// 定义新的 一个 参数  可以判断 下一次 必定会出up  比如  在里面增加一个 bool  下一次 直接跳过歪的可能
			//产生随机数     随机一个五星物品

			if (chizi != 1) {
				baodi += 1;
			}


			int n4 = rand() % 15;   //[0,14]

			printf_s("\n-----------------------------\n");
			//printf_s("%s\n", weapon_char_5star[n4]);
			strcpy_s(results, weapon_char_5star[n4]);
			printf_s("%s\n", results);
			return results;

		}
		else {   //没歪    根据池子判断    如果是胡桃池子   为  胡桃    如果是   绫华池子   绫华   进行  传参操作
			if (chizi == 2) {
				strcpy_s(results, "神里绫华");
				printf_s("\n-----------------------------\n");
				printf_s("%s\n", results);

				return results;
			}
			else {
				strcpy_s(results, "胡桃");
				printf_s("\n-----------------------------\n");
				printf_s("%s\n", results);
				return results;
			}
		}

	}

}

