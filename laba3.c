#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int j, len_str;
	char d[4];
	printf("Введите 3 числа без пробелов:");
	scanf("%s", d);
	len_str = strlen(d);
	if (len_str != 3)
	{
		fprintf(stderr, "неверная длина строки :\n"); return 1;
	}
	for (j = 0; j < len_str; j++)
	{
		if (!isdigit(d[j]))
		{
			fprintf(stderr, "Test is not digit!\n"); return 1;
		}
	}
	printf("%s становится ", d);
	__asm
	{
		mov al, d[0]; //запись первой цифры
		mov ah, d[1]; //запись второй цифры
		mov cl, d[2]; //запись третьей цифры
		cmp al, ah; // сравнение первой и второй цифры
		jge CHANGE; // если первая меньше второй
		cmp ah, cl; // сравнение второй и третьей цифры

		3

			jge INCR; // если вторая цифра больше или равна второй
		jl CHANGE; // если вторая цифра меньше третьей
	CHANGE:// смена первой и второй цифры местами
		mov d[0], ah;
		mov d[1], al;
		jmp EXIT;
	INCR:// дополнение до 7
		mov al, d[0];
		sub al, '0';
		cmp al, 7;
		ja EXIT;
		mov ch, 7;
		sub ch, al;
		add ch, '0';
		mov d[0], ch;
	EXIT: // выход из ассемблерной вставки
		nop;
	}
	printf("%s\n", d);
	return 0;
}