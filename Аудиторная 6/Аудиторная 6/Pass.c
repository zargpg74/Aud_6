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
    int i = 0, n = 0;//i - индексы, n - количество знаков пароля

    printf("Введите пароль: ");
    while (i < 99)//ввод пароля
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
                printf("Введите пароль: ");
                continue;
            }
            if (i == 0)
                continue;
            i--;
            password[i - 1] = 0;
            system("cls");
            printf("Введите пароль: ");
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

    int check = 0, count_numbers = 0, count_bigger = 0, count_simv = 0;//check - счетчик надежности пароля, count_numbers - счетчик цифр в паролe
    //count_bigger - счетчик заглавных букв в пароле, count_simv - количество специальных символов в пароле
    char* eng_bigger = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (n >= 8)//проверка пароля на прочность
    {
        check++;

        for (i = 0; i < n; i++)//проверка количества цифр в пароле
        {
            if ((password[i] - 48 >= 0) && (password[i] - 48 <= 9))
                count_numbers++;
        }
        if (count_numbers >= (n/5))
            check++;

        for (i = 0; i < n; i++)//проверка количества больших букв
            for (int x = 0; x < 27; x++) 
                if (password[i] == eng_bigger[x])
                    count_bigger++;
        if (count_bigger >= (n / 4))
            check++;

        for (i = 0; i < n; i++)//проверка количетва специальных символов
        {
            if (password[i] == '_' || password[i] == '-' || password[i] == '/')
                count_simv++;
        }
        if (count_simv >= 2)
            check++;

        switch (check)
        {
        case 1:
            printf("\nСлабый пароль");
            break;
        case 2:
            printf("\nСредний пароль");
            break;
        case 3:
            printf("\nНормальный пароль");
            break;
        case 4:
            printf("\nНадежный пароль");
            break;
        }
    }
    else
        printf("\nНенадежный пароль");

    printf("\nВаш пароль:");

    for (i = 0; i < n; i++)
    {
        printf("%c", password[i]);
    }
}