#include <stdio.h>
#include <string.h>
#include <Windows.h>

// 콘솔 글자색 변경 코드
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

// 콘솔창 설정
void Initializing()
{
	system("title ANSI color enable");				//CMD 제목
	system("mode con cols=100 lines=35");			// 가로 110, 세로 40

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);	//코드가 길어서 핸들을 밖으로 빼줌
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);		//콘솔창 화면 버퍼정보 받아옴
	COORD new_size =
	{
		info.srWindow.Right + 1,
		info.srWindow.Bottom + 5000
	};
	SetConsoleScreenBufferSize(handle, new_size);		//콘솔창 화면 버퍼 크기 지정
}


int main()
{
	Initializing();
	char input[1024];

	printf("\n");
	textcolor(11);
	puts("이 프로그램은 ANSI escape sequence를 활성화합니다.");
	textcolor(14);
	puts("java에서는 ANSI escape sequence로만 콘솔 글자에 색을 입힐 수 있습니다.");
	textcolor(12);
	printf("Windows10 에서만 작동");
	textcolor(7);
	puts("되며 그 이하 버전은 OS에서 ANSI color를 지원하지 않습니다.");
	puts("이진값(DWORD) 1개가 추가되며 추가적인 영향은 없습니다.");
	puts("");
	textcolor(14);
	printf("레지스트리를 추가하시겠습니까? (Y/N) ");
	textcolor(7);
	gets_s(input, sizeof(input));	// 사용자 입력 받기

	while (1)
	{
		if ( (strcmp(input, "Y") == 0) || (strcmp(input, "y") == 0) )
		{
			printf("\n");
			system("ANSI_color_enable.reg");	// cmd 명령어 실행 (레지스트리 등록)
			textcolor(10);
			printf("완료되었습니다. ");
			textcolor(11);
			puts("***컴퓨터를 재부팅 해주세요.***");
			textcolor(14);
			puts("프로그램을 종료합니다.");
			textcolor(7);
			puts("");
			system("pause");
			return 0;	// 종료
		}
		else if ( (strcmp(input, "N") == 0) || (strcmp(input, "n") == 0) )
		{
			printf("\n");
			textcolor(12);
			puts("레지스트리를 추가하지 않습니다.");
			textcolor(7);
			puts("프로그램을 종료합니다.");
			puts("");
			system("pause");
			return 0;	// 종료
		}
		else
		{
			textcolor(14);
			printf("다시 입력해주세요: ");
			textcolor(7);
			gets_s(input, sizeof(input));
		}
	}
}