#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}

char* retComma(char* string)
{
	char *p;
	p = strchr(string, ',');
	if (p != NULL) {
		//カンマがあるポインタを返却
		return p;
	}
	//カンマ含まれてない場合は文字列先頭ポインタを返却
	return string;
}

int main(int argc, char *argv[])
{
	static const int TOTAL_LINE = 100;

	char str[5];

	char string[512];
	char buffer[512];

	string[0] = '\0';
	while (fgets(str, sizeof(str), stdin)) {

		//現在表示
		if (atoi(str) == 0)
		{
			printf("%s\n", string);
		}

		//先頭削除(削除した際に消したものを呟く)
		else if (atoi(str) == -1)
		{

			//カンマがどこにあるか探査
			char *rp = retComma(string);
			buffer[0] = '\0';
			//カンマが含まれていない場合は先頭を\0
			if (string == rp)
			{
				strcpy(buffer, string);
				string[0] = '\0';
			}
			//カンマが含まれている場合はカンマ以前をstringへコピーする
			else
			{
				strncpy(buffer, string, (unsigned)(rp - string));
				strcpy(string, buffer);
			}

			printf("%s\n", buffer);
		}

		//先頭に追加
		else
		{
			trim(str);
			//文字列が空じゃないときは str, を追加する
			if (string[0] != '\0')
			{
				strcpy(buffer, str);
				strcat(buffer, ",");
				strcat(buffer, string);
				strcpy(string, buffer);
			}
			else
			{
				strcpy(string, str);
			}
		}
		buffer[0] = '\0';
	}

	return 0;
}