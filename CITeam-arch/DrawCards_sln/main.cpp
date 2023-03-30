#include "common.h"
#include "drawCards.h"

int main(){
    RoleInfo *roleInfo;
    initRoleInformation(roleInfo);      //初始化人物数据
    initSource();       //初始化原石

    int i = startDraw();
    if (!i){
        printf("startDraw error!\n");
        getchar();
        return -1;
    }
    if (i == BACK){
        return 0;
    }
    if (i == COME_IN){
        drawCardView();
    }
}