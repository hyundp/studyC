#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	FILE* ipa, *ipb, *opc;
	char str1[10][21];
	char str2[10][21];
	int i;
	int sav;
	int decl;

	ipa = fopen("a.txt", "rt");
	if (ipa == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}
	ipb = fopen("b.txt", "rt");
	if (ipb == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	opc = fopen("c.txt", "at");
	if (opc == NULL)
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	for (i = 0; i < 10; i++)
	{
		fscanf(ipa, "%s", str1[i]);
		if (feof(ipa)) break;
	}
	sav = i;

	for (i = 0; i < 10; i++)
	{
		decl = 0;
		fscanf(ipb, "%s", str2[i]);
		for (int j = 0; j <= sav; j++)
		{
			if (strcmp(str2[i], str1[j]) == 0)
			{
				decl = 1;
				break;
			}
		}
		if (decl == 0)
		{
			fprintf(opc, "%s\n", str2[i]);
		}
		if (feof(ipb)) break;
	}


	fclose(ipa);
	fclose(ipb);
	fclose(opc);

	return 0;
}