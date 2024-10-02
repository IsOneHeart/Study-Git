/*����ѧ���ṹ��Student(��ѧ�š��������ɼ����ȼ�������)��ͳ�ƺ���Static��
�ú����������õȼ����������Ρ�ͳ�Ƹ��ȼ������ͷ���ƽ���ɼ��Ĺ��ܡ�
��������������3��ѧ����ѧ�š������ͳɼ�������Static�������ͳ�ƹ��ܣ�������ѧ��ȫ����Ϣ��
�ɼ��ȼ����򣺴��ڵ���90��A�����ڵ���80��B�����ڵ���70��C�����ڵ���60��D��60���¡�E��*/
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 64
#define NumStudent 10
#include <stdio.h>
struct Student {
	long long No;
	char Name[MaxSize];
	float Mark;
	char Grade;
	int List;
}student[NumStudent];

void Static(struct Student students[]) {
	int count[5] = { 0,0,0,0,0 };
	float sum = 0, aver = 0;
	for (int i = 0;i < NumStudent;i++) {
		switch ((int)students[i].Mark / 10) {
		case 10:
		case 9:
			count[0]++;
			students[i].Grade = 'A';
			break;
		case 8:
			count[1]++;
			students[i].Grade = 'B';
			break;
		case 7:
			count[2]++;
			students[i].Grade = 'C';
			break;
		case 6:
			count[3]++;
			students[i].Grade = 'D';
			break;
		default:
			count[4]++;
			students[i].Grade = 'E';
			break;
		}
	}
	printf("A�ȼ�%d�ˣ�B�ȼ�%d�ˣ�C�ȼ�%d�ˣ�D�ȼ�%d�ˣ�E�ȼ�%d��\n", count[0], count[1], count[2], count[3], count[4]);

	struct Student temp;
	for (int i = 0;i < NumStudent;i++) {
		for (int j = 0;j < NumStudent - i;j++) {
			if (students[j].Mark < students[j + 1].Mark) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	//����������
	for (int i = 0;i < NumStudent;i++) {
		students[i].List = i + 1;
		if (i > 0 && students[i].Mark == students[i - 1].Mark) 
			students[i].List = students[i - 1].List;
	}

	printf("����\t����\tѧ��\t����\t�ȼ�\n");
	for (int i = 0;i < NumStudent;i++) {
		printf("��%d��\t%s\t%lld\t%.2f\t%c\n", students[i].List, students[i].Name, students[i].No, students[i].Mark, students[i].Grade);
		sum += students[i].Mark;
	}

	aver = sum / NumStudent;
	printf("\nƽ���֣�%.2f\n", aver);
}

void main() {
	printf("������%d��ѧ������Ϣ��\n", NumStudent);
	for (int i = 0;i < NumStudent;i++) {
		printf("��%d��ѧ����\n", i+1);
		printf("ѧ�ţ�");
		scanf("%lld", &student[i].No);
		printf("������");
		getchar();//С����һ������Ļس���
		gets(student[i].Name);
		printf("�ɼ���");
		scanf("%f", &student[i].Mark);
	}
	Static(student);
}