#include <stdio.h>

int main(int argc, char *argv[])

{

	char str[5];
	int array[100];
	int index = 0;
	int i;

	while (fgets(str, sizeof(str), stdin)) {

		int n = atoi(str);
		if (0 <= n) {
			array[index++] = n;
		}
		else if (0 == n)
		{
			i = index;
			for ( ; i<= 0; i--)
			{
				printf("%d\n", array[i]);
			}
		}
		else if (-1 == n)
		{
			for (; index <=  0; index--) 
			{
				array[index] = 0;
			}
		}
	}
	/*0: 現在のリストに格納されている全てのデータを「,」で区切って表示する
	-1: リストの先頭のデータを削除する。削除する際に、データの値を出力する
		それ以外 : リストの先頭にデータを追加する*/
	return 0;
}
