#include <stdio.h>
#include <string.h>
#include <Windows.h>

// �ܼ� ���ڻ� ���� �ڵ�
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

// �ܼ�â ����
void Initializing()
{
	system("title ANSI color enable");				//CMD ����
	system("mode con cols=100 lines=35");			// ���� 110, ���� 40

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	//�ڵ尡 �� �ڵ��� ������ ����
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);		//�ܼ�â ȭ�� �������� �޾ƿ�
	COORD new_size =
	{
		info.srWindow.Right + 1,
		info.srWindow.Bottom + 5000
	};
	SetConsoleScreenBufferSize(handle, new_size);		//�ܼ�â ȭ�� ���� ũ�� ����
}


int main()
{
	Initializing();
	char input[1024];

	printf("\n");
	textcolor(11);
	puts("�� ���α׷��� ANSI escape sequence�� Ȱ��ȭ�մϴ�.");
	textcolor(14);
	puts("java������ ANSI escape sequence�θ� �ܼ� ���ڿ� ���� ���� �� �ֽ��ϴ�.");
	textcolor(12);
	printf("Windows10 ������ �۵�");
	textcolor(7);
	puts("�Ǹ� �� ���� ������ OS���� ANSI color�� �������� �ʽ��ϴ�.");
	puts("������(DWORD) 1���� �߰��Ǹ� �߰����� ������ �����ϴ�.");
	puts("");
	textcolor(14);
	printf("������Ʈ���� �߰��Ͻðڽ��ϱ�? (Y/N) ");
	textcolor(7);
	gets_s(input, sizeof(input));	// ����� �Է� �ޱ�

	while (1)
	{
		if ( (strcmp(input, "Y") == 0) || (strcmp(input, "y") == 0) )
		{
			printf("\n");
			system("ANSI_color_enable.reg");	// cmd ��ɾ� ���� (������Ʈ�� ���)
			textcolor(10);
			printf("�Ϸ�Ǿ����ϴ�. ");
			textcolor(11);
			puts("***��ǻ�͸� ����� ���ּ���.***");
			textcolor(14);
			puts("���α׷��� �����մϴ�.");
			textcolor(7);
			puts("");
			system("pause");
			return 0;	// ����
		}
		else if ( (strcmp(input, "N") == 0) || (strcmp(input, "n") == 0) )
		{
			printf("\n");
			textcolor(12);
			puts("������Ʈ���� �߰����� �ʽ��ϴ�.");
			textcolor(7);
			puts("���α׷��� �����մϴ�.");
			puts("");
			system("pause");
			return 0;	// ����
		}
		else
		{
			textcolor(14);
			printf("�ٽ� �Է����ּ���: ");
			textcolor(7);
			gets_s(input, sizeof(input));
		}
	}
}