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

	char string[sizeof(str) * TOTAL_LINE] = "";
	char buffer[sizeof(str) * TOTAL_LINE] = "";

	string[0] = '\0'; 
	while (fgets(str, sizeof(str), stdin)) {

		//現在表示
		if (atoi(str) == 0)
		{
			printf("%s\n", string);
		}
		//先頭削除
		else if (atoi(str) == -1)
		{
			//カンマが含まれていなかった場合は先頭を\0
			char *rp = retComma(string);
			if (string == rp)
			{
				string[0] = '\0';
			}
			//以外の場合はカンマ以降をstringへコピーする
			else
			{
				strcpy_s(string, ++rp);
			}

		}
		//先頭に追加
		else
		{
			trim(str);
			//文字列が空じゃないときは str, を追加する
			if (string[0] != '\0')
			{
				strcpy_s(buffer, str);
				strcat_s(buffer, ",");
				strcat_s(buffer, string);
				strcpy_s(string, buffer);
			}
			else
			{
				strcpy_s(string, str);
			}
		}
		buffer[0] = '\0';
	}

	return 0;
}