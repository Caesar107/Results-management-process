#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct student				//ѧ����Ϣ 
{
	char name[25];			//����
	int age;				//����
	int stu_num;			//ѧ��
	float score[3];			//���Ƴɼ�
	float total;			//�ܷ�
	float Ave;				//ƽ����
};
 
int num;				//ѧ������

//�ļ����� 
int f_output(struct student *info, int len)
{
    FILE *fp = fopen("data.txt", "r");
    int i=0,j;

    if(fp == NULL)		//�ж��ļ��Ƿ���� 
    {
        printf("û�и��ļ�!\n");
        exit(0);
    }
    
    while(fscanf(fp,"%s%d%d%f%f%f%f%f",info[i].name, &info[i].age, &info[i].stu_num, &info[i].score[0], 
	&info[i].score[1], &info[i].score[2], &info[i].total, &info[i].Ave)!=EOF)
	{
		i++;			//���� 
	}
    fclose(fp);
    return i;
 } 

//�ļ�д��
void f_input(struct student *info, int len){
	FILE *fp; 
	fp = fopen("data.txt", "w");
	int i;
    for(i=0; i < len; i++)
    {
        if(info[i].name != 0)
            {
                fprintf(fp,"%s %d %d %f %f %f %f %f\n",info[i].name, info[i].age, info[i].stu_num, info[i].score[0], 
								info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);
            }
    }
    getchar();
	fclose(fp);    
} 
 
//ѧ������
int stu_num(void)
{
	printf("������ѧ��������\n");
	scanf("%d", &num);
	return num;
}
  
//ѧ������Ϣ�Ľ���
struct student* Input(struct student *info, int len)	
{
	int i;
	for (i = 0; i <len; i++)
	{
		printf("�������%d��ѧ��������:\n", i+1);
		scanf("%s", info[i].name);
 
		printf("�������%d��ѧ��������:\n", i+1);
		scanf("%d", &info[i].age);
 
		printf("�������%d��ѧ����ѧ��:\n",i+1);
		scanf("%d", &info[i].stu_num);
 
		printf("�������%d��ѧ�������ĳɼ�:\n", i+1);
		scanf("%f", &info[i].score[0]);
 
		printf("�������%d��ѧ������ѧ�ɼ�:\n", i+1);
		scanf("%f", &info[i].score[1]);
 
		printf("�������%d��ѧ����Ӣ��ɼ�:\n", i+1);
		scanf("%f", &info[i].score[2]);
		
		info[i].total = info[i].score[0] + info[i].score[1] + info[i].score[2];	//�ܷ�
 
		info[i].Ave = info[i].total /  3.0f;		//ƽ����
 
	}
 	f_input(info, num);		//д���ļ� 
	return info;   
}
 
//���ѧ������Ϣ
void Output(struct student *info, int len)
{
	printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
 	int i;
 	len=f_output(info,num);
	for (i = 0; i < len; i++)
	{
		printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", info[i].name, info[i].age, info[i].stu_num, info[i].score[0], info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);
	}
}
 
//ɾ��ѧ����Ϣ
void Delete(struct student *info, int len)
{
	int i, num;
	char name[10];
 
	printf("��������Ҫɾ�����ݵ�����:\n");
	scanf("%s", name);//�õ�ɾ��ѧ��������
 	len=f_output(info, num);
	for (i = 0; i < len; i++)//����ɾ����ѧ���ı��
	{
		if (0 == strcmp(info[i].name, name))
		{
			num = i;
			break;
		}
		else num=-1;
	}
 	if(num!=-1){
		for (i = num; i < len; i++)//ɾ��ѧ��
		{
			info[i] = info[i+1];
		}
		printf("\n\nɾ����Ϊ\n"); 
	 	f_input(info, len - 1);
		Output(info, len - 1);//���ɾ����Ľ��
				}
	else printf("���޴���\n"); 
}
	
//����ѧ����Ϣ 
void Search(struct student *info, int len)
{
	int i;
	char name[10];
	printf("����������Ҫ���ҵ�ѧ��������\n");
	scanf("%s", name);
 	len=f_output(info, num);
	for (i = 0; i < len; i++)		//����ѧ�����
	{
		if (0 == strcmp(info[i].name, name))
		{
			num = i;
			break;
		}
		else num=-1;
	}
	if(num!=-1) {
		printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
		printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", info[i].name, info[i].age, info[i].stu_num, info[i].score[0],
						 info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);		//����ҵ���ѧ������Ϣ
	}
	else  printf("���޴���\n"); 
}
 
//�޸�ѧ����Ϣ 
void Change(struct student *info, int len)
{
	char name[10];
 
	printf("����������Ҫ�޸ĵ�ѧ��������:\n");
	scanf("%s", name);
 	len=f_output(info, num);
	int i, num;
 
	for (i = 0; i < len; i++)
	{
		if (0 == strcmp(info[i].name, name))//����ѧ�����
		{
			num = i;
			break;
		}
		else num=-1;
	}
	if (num!=-1){
		printf("������ѧ��������:\n");
		scanf("%s", info[num].name);
	 
		printf("������ѧ��������:\n");
		scanf("%d", &info[num].age);
	 
		printf("������ѧ����ѧ��:\n");
		scanf("%d", &info[num].stu_num);
	 
		printf("������ѧ�������ĳɼ�:\n");
		scanf("%f", &info[num].score[0]);
	 
		printf("������ѧ������ѧ�ɼ�:\n");
		scanf("%f", &info[num].score[1]);
	 
		printf("������ѧ����Ӣ��ɼ�:\n");
		scanf("%f", &info[num].score[2]);
 
		info[num].total = info[num].score[0] + info[num].score[1] + info[num].score[2];		//	�ܷ� 
	 
		info[num].Ave = info[num].total / 3.0f;				//ƽ����
	 	f_input(info, len);		//д���ļ��У��浵�� 
		Output(info, len);		//���ѧ����Ϣ
}
	else printf("���޴�����Ϣ\n");
}

//���ѧ����Ϣ
void Add(struct student *info, int len)
{
	int peo,i;
 	len=f_output(info, num);
	printf("��������ӵ�ѧ��������:\n");
	scanf("%d", &peo);
 
	struct student *p = NULL;
 
	for (i = 0; i < peo; i++)
	{
		printf("�������%d��ѧ��������:\n", i + 1);
		scanf("%s", info[i+len].name);
		printf("�������%d��ѧ��������:\n", i + 1);
		scanf("%d", &info[i+len].age);
		printf("�������%d��ѧ����ѧ��:\n", i + 1);
		scanf("%d", &info[i+len].stu_num);
		printf("�������%d��ѧ�������ĳɼ�:\n", i + 1);
		scanf("%f",&info[i+len].score[0]);
		printf("�������%d��ѧ������ѧ�ɼ�:\n", i + 1);
		scanf("%f", &info[i+len].score[1]);
		printf("�������%d��ѧ����Ӣ��ɼ�:\n", i + 1);
		scanf("%f", &info[i+len].score[2]);
 
		info[i+len].total = info[i+len].score[0] + info[i+len].score[1] + info[i+len].score[2];		
		info[i+len].Ave = info[i+len].total / 3.0f;
	}
 	f_input(info, peo+len);		//�浵 
	Output(info, peo+len);		//���ѧ����Ϣ
}

//���ܳɼ�����
void scoretotal(struct student *info, int len)
{
	struct student temp;//�м����
	int max;//���ֵ���±�
 	int i,j;
 	f_output(info, num);
	for (i = 0; i < len - 1; i++)
	{
		max = i;//�ٶ��ܳɼ������ֵ���±���i
 
		for (j = i + 1; j < len; j++)
		{
			if (info[j].total  > info[max].total)//�����ܳɼ����ֵ���±�
			{
				max = j;
			}
		}
 
		if (max != i)//����
		{
			temp = info[max];
			info[max] = info[i];
			info[i] = temp;
		}
	}
 
	Output(info, len);//��������Ľ��
}

//ͳ�� 
void stat(struct student *info, int len)
{
len=f_output(info, num);
int i,j;			//��i+1��ѧ������j+1�Ƴɼ� 
int stage[12][3]={0};
	for(i=0;i<len;i++){
		for(j=0;j<3;j++){
			int judge=info[i].score[j]/10;
				switch(judge) {
				case 0:	stage[0][j]++	; break;			//0-9 
				case 1:	stage[1][j]++	; break;			//10-19
				case 2:	stage[2][j]++	; break; 			//20-29
				case 3:	stage[3][j]++	; break;			//30-39
				case 4:	stage[4][j]++	; break;			//40-49
				case 5:	stage[5][j]++	; break;			//50-59
				case 6:	stage[6][j]++	; break;			//60-69
				case 7:	stage[7][j]++	; break;			//70-79
				case 8:	stage[8][j]++	; break;			//80-89
				case 9:	stage[9][j]++	; break;			//90-99
				case 10: stage[10][j]++	; break;			//���� 	
		}
	} 
}
float A[3]={0},E[3]={0},a[3]={0},e[3]={0};			//�����ʡ������� 
int sum1,sum2;
for(j=0;j<3;j++){
	for(i=9;i<11;i++){
		a[j]+=stage[i][j];
	}
	for(i=6;i<11;i++){
		e[j]+=stage[i][j];
	}
	A[j]=a[j]/len;
	E[j]=e[j]/len;
}
printf("������           ����       ��ѧ        Ӣ��\n");
printf(" 0-9              %d         %d          %d\n",stage[0][0],stage[0][1],stage[0][2]);
printf(" 10-19            %d         %d          %d\n",stage[1][0],stage[1][1],stage[1][2]);
printf(" 20-29            %d         %d          %d\n",stage[2][0],stage[2][1],stage[2][2]);
printf(" 30-39            %d         %d          %d\n",stage[3][0],stage[3][1],stage[3][2]);
printf(" 40-49            %d         %d          %d\n",stage[4][0],stage[4][1],stage[4][2]);
printf(" 50-59            %d         %d          %d\n",stage[5][0],stage[5][1],stage[5][2]);
printf(" 60-69            %d         %d          %d\n",stage[6][0],stage[6][1],stage[6][2]);
printf(" 70-79            %d         %d          %d\n",stage[7][0],stage[7][1],stage[7][2]);
printf(" 80-89            %d         %d          %d\n",stage[8][0],stage[8][1],stage[8][2]);
printf(" 90-99            %d         %d          %d\n",stage[9][0],stage[9][1],stage[9][2]);
printf(" 100              %d         %d          %d\n",stage[10][0],stage[10][1],stage[10][2]);
printf("������            %g         %g          %g\n",A[0],A[1],A[2]);
printf("������            %g         %g          %g\n",E[0],E[1],E[2]);
}

//��ϲ�ѯ 
void mul_search(struct student *info, int len)
{
	int i,ch, ma ,en;
	len=f_output(info, num);
	printf("����������Ҫ���ҵ�ѧ�������ġ���ѧ��Ӣ��ɼ�\n");
	scanf("%d%d%d", &ch, &ma, &en);
 
	for (i = 0; i < len; i++)		//����ѧ�����
	{
		if (info[i].score[0] == ch && info[i].score[1] == ma && info[i].score[2] == en)
		{
			num = i;
			break;
		}
		else num=-1;
	}
	if(num!=-1)  {
		printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
		printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", info[i].name, info[i].age, info[i].stu_num, info[i].score[0],
						 info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);		//����ҵ���ѧ������Ϣ
				}		
	else  printf("û��ѧ�������ṩ��Ϣ���\n"); 	
}

//��ӭҳ����ʾ
void page(){
	
	printf("================================================================================\n\n");
	printf("================================================================================\n\n");
	printf("*************************��ӭʹ��ѧ���ɼ�����ϵͳ*******************************\n\n");
	printf("********************************************************************************\n\n");
	printf("================================================================================\n\n");
	printf("================================================================================\n\n");
 
 
	printf("�밴���⽫����ѧ������ϵͳ:\n");
	getchar();
	system("cls");
} 

//�û�ѡ����� 
void Choice(){
	int num, Item;
	struct student *info = NULL;
	struct student *p = NULL;
 	printf("================================================================================\n\n");
	printf("*----------------------- ��ѡ��Ҫ���������----------------------------------*\n\n");
	printf("*------------------------- 1 ����ѧ����Ϣ--------------------------------------*\n\n");
	printf("*------------------------- 2 ���ѧ����Ϣ--------------------------------------*\n\n");
	printf("*------------------------- 3 ɾ��ѧ����Ϣ--------------------------------------*\n\n");
	printf("*------------------------- 4 ����ѧ����Ϣ--------------------------------------*\n\n");
	printf("*------------------------- 5 �޸�ѧ����Ϣ--------------------------------------*\n\n");
	printf("*------------------------- 6 ����ѧ����Ϣ--------------------------------------*\n\n");
	printf("*------------------------- 7 ͳ�ƣ������ʣ������ʣ�----------------------------*\n\n");
	printf("*------------------------- 8 ��ϲ�ѯ------------------------------------------*\n\n");
	printf("*------------------------- 9 ��ѧ�����ܳɼ����Ӵ�С��------------------------*\n\n");
    printf("*------------------------- 10 �˳�---------------------------------------------*\n\n");
	printf("================================================================================\n\n");
 	int judge=1;
 	info = (struct student*)malloc(1000*sizeof(struct student));
	p = (struct student*)malloc(1000*sizeof(struct student)); 
 	while(judge!=0)
	{
		printf("\n��ѡ���������;\n");
		scanf("%d", &Item);
 
		switch (Item)
		{
		     case 1://����ѧ����Ϣ
			{
				num = stu_num();
				p = Input(info, num);
			}
			break;
 
		    case 2://���ѧ����Ϣ
			{
				Output(p, num);
			}
			break;
 
		     case 3://ɾ��ѧ����Ϣ
			{
				Delete(p, num);
			}
			break;
 
		     case 4://����ѧ����Ϣ
			{
				Search(p, num);
			}
			break;
 
		     case 5://�޸�ѧ����Ϣ
			{
				Change(p, num);
			}
			break;
 
		     case 6://���ѧ����Ϣ
			{
				Add(p, num);
			}
			break;
 
		    case 7://ͳ��
			{
				stat(p, num);
			}
			break;
 
			case 8://��ϲ�ѯ 
				{
				mul_search(p, num);
				}
				break;
 
			case 9://��ѧ�����ܳɼ����Ӵ�С����
				{
					scoretotal(p, num); 
				}
				break;
 
			case 10://�˳� 
				{
					system("cls");
					judge=0; 
				}
				break;
			default: printf("������������ȷ�����");	
		}
} 
}
//������ 
int main()
{
	page();
 	Choice();
 	return 0;
}
