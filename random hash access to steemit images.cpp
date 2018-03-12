/* 이것은 바보같은 뻘짓거리였다 */
/* 2018 01 09 3:00 AM           */

#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main()
{
	FILE *file;
	char output[1000];
	int n, r;

	// valid test case
	char test[93] = " /C wget64 C:\ https://steemitimages.com/DQmaCMZjV8bCSvYGS3FmSfhnNSeWNKQqHj9bQBzLjDRDftF";
	char filenamee[48] = "DQmaCMZjV8bCSvYGS3FmSfhnNSeWNKQqHj9bQBzLjDRDftF";
	char cmd[93] = { 0 }, yn, filename[48] = { 0 };
	strcpy(cmd, " /C wget64 D:\app\ https://steemitimages.com/");
	srand(time(NULL));

	while (1) {
		printf("open random page...\n");

		yn = 'y';
		if (yn == 'y') {
			for (int i = 43; i < 90; ) {
				n = rand() % 128;
				if ((n >= '0'&&n <= '9') || (n >= 'A'&&n <= 'Z') || (n >= 'a'&&n <= 'z')) {
					*(filename + i - 43) = n;
					*(cmd + i++) = n;
				}
			}
			// test code
//			r = (int)ShellExecuteA(GetDesktopWindow(), "open", "cmd.exe", test, "C:W", SW_SHOW);
			r = (int)ShellExecuteA(GetDesktopWindow(), "open", "cmd.exe", cmd, "C:W", SW_SHOW);

			Sleep(6000);
			file = fopen(filenamee, "rb");
			if (!file) {
				printf("try again...\n");
			}
			else {
				printf("success\n");

				// project folder
//				ShellExecuteA(GetDesktopWindow(), "open", "explorer.exe", "C:\\Users\\Administrator\\Documents\\Visual Studio 2017\\Projects", NULL, SW_SHOW);
				break;
			}
		}
		else break;
	}
	return 0;
}