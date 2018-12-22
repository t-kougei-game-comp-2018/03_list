#define _CRT_SECURE_NO_WARNINGS

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
	char str[5];

	char string[512];
	char buffer[512];

	string[0] = '\0';
	while (fgets(str, sizeof(str), stdin)) {

		//-----------------------------------------------------
		//	表示
		//-----------------------------------------------------
		if (atoi(str) == 0)
		{
			printf("%s\n", string);
		}

		//-----------------------------------------------------
		//	削除
		//-----------------------------------------------------
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
			//カンマが含まれている場合はカンマ以降をstringへコピーする
			else
			{
				unsigned int len = (unsigned)(rp - string);
				int i = 0;
				for (; i < len; i++)
				{
					buffer[i] = string[i];
				}
				buffer[i] = '\0';

				strcpy(string, ++rp);
			}

			printf("%s\n", buffer);
		}

		//-----------------------------------------------------
		//	追加
		//-----------------------------------------------------
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