#include <stdio.h>
#include <stdlib.h>
#pragma warning( disable : 4996 )
typedef struct _student 
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	float avg;
}student;
int main(void)
{
	student data[5];
	FILE *stream1;
	FILE *stream2;
	int i;
	stream1 = fopen("D://gradedata.txt", "r");
	stream2 = fopen("D://gradeoutput.txt", "w");
	if (stream1 == NULL || stream2 == NULL)
	{
		printf("�ɮ׶}�ҥ���\n");
	}
	else
	{
		fprintf(stream2, "�m�W\t���\t�^��\t�ƾ�\t�`�M\t����\n");
		for (i = 0; i < 5; i++)
		{
			fscanf(stream1, "%s", data[i].name);
			fscanf(stream1, "%d", &data[i].chinese);
			fscanf(stream1, "%d", &data[i].english);
			fscanf(stream1, "%d", &data[i].math);

			data[i].sum = data[i].chinese + data[i].math + data[i].english;
			data[i].avg = data[i].sum / 3.0;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", data[i].name, data[i].chinese, data[i].english, data[i].math, data[i].sum, data[i].avg);
		}
		fclose(stream1);
		fclose(stream2);
	}
	system("pause");
	return 0;

}