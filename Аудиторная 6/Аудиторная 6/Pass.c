#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>

#include"Pass.h"

void Password()
{
	setlocale(0, "ru");
	system("cls");

    char password[100];
    int i = 0, n = 0;//i - �������, n - ���������� ������ ������

    printf("������� ������: ");
    while (i < 99)//���� ������
    {
        char c = getch();
        if (c == 13)
        {
            break;
        }
        if (c == 8)
        {
            if (i == 1)
            {
                system("cls");
                printf("������� ������: ");
                continue;
            }
            if (i == 0)
                continue;
            i--;
            password[i - 1] = 0;
            system("cls");
            printf("������� ������: ");
            for (int j = 0; j < i; j++)
            {      
                printf("*");
            }
            n--;
            continue;
        }
        password[i] = c;
        i++;
        n++;
        printf("*");
    }

    int check = 0, count_numbers = 0, count_bigger = 0, count_simv = 0;//check - ������� ���������� ������, count_numbers - ������� ���� � �����e
    //count_bigger - ������� ��������� ���� � ������, count_simv - ���������� ����������� �������� � ������
    char* eng_bigger = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (n >= 8)//�������� ������ �� ���������
    {
        check++;

        for (i = 0; i < n; i++)//�������� ���������� ���� � ������
        {
            if ((password[i] - 48 >= 0) && (password[i] - 48 <= 9))
                count_numbers++;
        }
        if (count_numbers >= (n/5))
            check++;

        for (i = 0; i < n; i++)//�������� ���������� ������� ����
            for (int x = 0; x < 27; x++) 
                if (password[i] == eng_bigger[x])
                    count_bigger++;
        if (count_bigger >= (n / 4))
            check++;

        for (i = 0; i < n; i++)//�������� ��������� ����������� ��������
        {
            if (password[i] == '_' || password[i] == '-' || password[i] == '/')
                count_simv++;
        }
        if (count_simv >= 2)
            check++;

        switch (check)
        {
        case 1:
            printf("\n������ ������");
            break;
        case 2:
            printf("\n������� ������");
            break;
        case 3:
            printf("\n���������� ������");
            break;
        case 4:
            printf("\n�������� ������");
            break;
        }
    }
    else
        printf("\n���������� ������");

    printf("\n��� ������:");

    for (i = 0; i < n; i++)
    {
        printf("%c", password[i]);
    }
}