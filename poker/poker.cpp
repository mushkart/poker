#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
#include <time.h>
#include <stdlib.h>

#include "Source.h"

#define cards_num 52
#define table_players_max 9


/*
todo:
 - ������� ������ ���������� ���-�� ������ � ���������� ������� �� ���
 - ������� ������� ������� ������       ---\ ����� 
 - ������� ������� ������������ ������  ---/ ����������
 - ������� ������� ������������ ������ ����� ��������
 - ������� ������� ���������� ������������ ����� �� �� ������
 - ������� ������� ������� ��� �� �����
 -
 

��:
 - ����
������� ����
 - ���������
 - ���������������

�� ����:
���-�� �������

�� �����:
���� ������ � �� ���� (�������)
*/



struct hand {
	char num;
	int card1;
	int card2;
};



int main() {
	//��������� ������� ��� ��������� ����
	srand(time(NULL));

	//��������� ������� ��������
	int players_num;
	scanf("%d", &players_num);
	printf("\n");

	//������������ ������, ������ ������� �������� - ���-�� ������ ��� ������, 
	//� ����������� - ���-�� ������� ������� �� ������ �� ���
	int * tables = Tables_Num_And_Table_Players_Num(players_num);

	for (int i = 1; i < tables[0] + 1; i++) {

		//�������� � ��������� ������
		int* deck = Create_And_Shuffle_Deck();

		//������������� ���� �� �����
		struct hand* players = Distribute_Cards_To_Hands(tables[i],deck);
		
		//�����
		printf("                  ---   Table  %d   ---   \n\n", i);
		Result(players);

		

	} 

	//��������� ���������
	return 0;
}