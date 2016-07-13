#include "head.h"
void main (){
	int i=0;//循环变量
	Menu();
	int choose=0;
	printf("请输入您的选择：");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:	system("cls");
				main_1();
				system("cls");
				main();
				break;

		case 2:	system("cls");
				main_2();
				Returnmain();
				main();
				break;
				
		case 3:	system("cls");
				main_3();
				Returnmain();
				main();
				break;

		case 4:	system("cls");
				main_4();
				system("cls");
				main();	
				break;

		case 5:	exit(0);
				break;

		default:system("CLS");
				printf("警告：\a\a\a\a\a\a\a\a\n");
				printf("您的输入有误，请重新输入!\n");
				Sleep(3000);
				system("CLS");
				main();
	}
}
