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
	printf("������� 3 ����� ��� ��������:");
	scanf("%s", d);
	len_str = strlen(d);
	if (len_str != 3)
	{
		fprintf(stderr, "�������� ����� ������ :\n"); return 1;
	}
	for (j = 0; j < len_str; j++)
	{
		if (!isdigit(d[j]))
		{
			fprintf(stderr, "Test is not digit!\n"); return 1;
		}
	}
	printf("%s ���������� ", d);
	__asm
	{
		mov al, d[0]; //������ ������ �����
		mov ah, d[1]; //������ ������ �����
		mov cl, d[2]; //������ ������� �����
		cmp al, ah; // ��������� ������ � ������ �����
		jge CHANGE; // ���� ������ ������ ������
		cmp ah, cl; // ��������� ������ � ������� �����

		3

			jge INCR; // ���� ������ ����� ������ ��� ����� ������
		jl CHANGE; // ���� ������ ����� ������ �������
	CHANGE:// ����� ������ � ������ ����� �������
		mov d[0], ah;
		mov d[1], al;
		jmp EXIT;
	INCR:// ���������� �� 7
		mov al, d[0];
		sub al, '0';
		cmp al, 7;
		ja EXIT;
		mov ch, 7;
		sub ch, al;
		add ch, '0';
		mov d[0], ch;
	EXIT: // ����� �� ������������ �������
		nop;
	}
	printf("%s\n", d);
	return 0;
}