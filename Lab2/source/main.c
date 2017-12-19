#include <stdio.h>
#include <stdlib.h>
#pragma warning( disable : 4996 )
struct clientdata
{
	int acctnum;
	char lastname[15];
	char firstname[10];
	double balance;
};
int main(void)
{
	FILE *pread, *pwrite;
	FILE *cfptr;
	int cnt = 0;
	struct clientdata client = { 0,"","",0.0 };
	pread = fopen("D://credit.txt", "r");
	if (NULL == pread)
	{
		return 0;
	}
	pwrite = fopen("D://credit_bin.txt", "wb");
	if (NULL == pwrite)
	{
		fclose(pread);
		return 0;
	}
	while (!feof(pread))
	{
		fscanf(pread, "%d%s%s%lf", &client.acctnum, client.lastname, client.firstname, &client.balance);
		fwrite(&client, sizeof(struct clientdata), 1, pwrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.acctnum, client.lastname, client.firstname, client.balance);
	}
	fclose(pread);
	fclose(pwrite);
	printf("以讀取文字檔的ACSII資料，並轉存為二進制資料檔案\n\n");
	system("pause");
	printf("\n讀取二進制資料檔案，並格式化輸出如下:\n");
	if ((cfptr = fopen("D://credit_bin.txt", "rb")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last name", "First name", "Balance");
		cnt = fread(&client, sizeof(struct clientdata), 1, cfptr);
		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.acctnum, client.lastname, client.firstname, client.balance);
			cnt = fread(&client, sizeof(struct clientdata), 1, cfptr);
		}
		fclose(cfptr);
	}
	system("pause");
	return 0;
}