#include<stdio.h>

//개선된 선택정렬(내림차순)

int main(void)
{
	int a[5] = { 4, 2, 5, 1, 3 };
	int i, j, temp;
	int max = 0;

	for (i = 0; i < 4; i++)
	{
		max = i;
		for (j = i + 1; j < 5; j++)
		{
			if (a[max] < a[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("순서대로 : %d\n", a[i]);
	}
	return 0;
}