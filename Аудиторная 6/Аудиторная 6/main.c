#include<stdio.h>
#include<locale.h>

#include"Pass.h"

void main()
{
	setlocale(0, "ru");
	system("cls");

	int k;
	printf("������� ����� �������: ");
	scanf_s("%d", &k);

	switch (k)
	{
	case 1:
		Password();
		break;
	default:
		printf("������ ������������ ����� �������");
		exit(k);
	}
}