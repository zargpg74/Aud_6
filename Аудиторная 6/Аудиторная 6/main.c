#include<stdio.h>
#include<locale.h>
#include<Windows.h>

#include"Pass.h"
#include"netUser.h"

void Option(int number, int argc, wchar_t* argv[])
{
	system("cls");
	printf("Aud 6\n");
	printf("Error. Такого задания не существует, попробуйте еще раз.\n");

	printf("Введите номер задания: ");
	scanf_s("%d", &number);

	switch (number)
	{
	case 1:
		Password();
		break;
	case 2:
		wmain(argc, argv);
		break;
	default:
		Option(number, argc, argv);
		break;
	}
}

void main(int argc, wchar_t* argv[])
{
	setlocale(0, "ru");
	system("cls");
	printf("Aud 6\n");

	int number;
	printf("Введите номер задания: ");
	scanf_s("%d", &number);

	switch (number)
	{
	case 1:
		Password();
		break;
	case 2:
		wmain(argc, argv);
		break;
	default:
		Option(number, argc, argv);
		break;
	}
}