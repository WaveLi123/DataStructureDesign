#include "head.h"
void main (){
	int i=0;//ѭ������
	Menu();
	int choose=0;
	printf("����������ѡ��");
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
				printf("���棺\a\a\a\a\a\a\a\a\n");
				printf("����������������������!\n");
				Sleep(3000);
				system("CLS");
				main();
	}
}
