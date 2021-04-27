#include <stdio.h>
#include <locale.h>
short int asm(char y, char z, short int x)
{
	short v = 0;
	__asm
	{
		mov al, z;
		cbw;
		sub ax, 2;
		mov bx, ax;
		mov al, y;
		cbw;
		imul x;
		sub ax, 4;
		sbb dx, 0;
		idiv bx;
		sub ax, 2;
		mov v, ax;
	}
	return v;
}
int main()
{
	setlocale(LC_ALL, "rus");
	char y, z;
	int i;
	short int v_c1, v_c2;
	short int x, v_as1, v_as2;
	short int v1 = -0x4, v2 = -0x45B;
	printf("Введите номер теста 1 или 2:\n");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		x = 0x2;

		3

			y = -0x3;
		z = 0x7;
		v_as1 = asm(y, z, x);
		v_c1 = ((0x2 * -0x3 - 4) / (0x7 - 2)) - 2;
		printf("Значение из asm:\nдесятичное %d, шестнадцатеричное %x\n", v_as1, v_as1);
		printf("Значение из C:\nдесятичное %d, шестнадцатеричное %x\n", v_c1, v_c1);
		printf("Оригинальный ответ:\nдесятичное %d, шестнадцатеричное %x\n", v1, v1);
		break;
	case 2:
		x = 0x5AE;
		y = 0x62;
		z = -0x7E;
		v_as2 = asm(y, z, x);
		v_c2 = ((0x5AE * 0x62 - 4) / (-0x7E - 2)) - 2;
		printf("Значение из asm:\nдесятичное %d, шестнадцатеричное %x\n", v_as2, v_as2);
		printf("Значение из C:\nдесятичное %d, шестнадцатеричное %x\n", v_c2, v_c2);
		printf("Оригинальный ответ:\nдесятичное %d, шестнадцатеричное %x\n", v2, v2);
		break;
	}
}