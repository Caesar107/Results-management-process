#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct student				//学生信息 
{
	char name[25];			//姓名
	int age;				//年龄
	int stu_num;			//学号
	float score[3];			//三科成绩
	float total;			//总分
	float Ave;				//平均分
};
 
int num;				//学生人数

//文件读出 
int f_output(struct student *info, int len)
{
    FILE *fp = fopen("data.txt", "r");
    int i=0,j;

    if(fp == NULL)		//判断文件是否存在 
    {
        printf("没有该文件!\n");
        exit(0);
    }
    
    while(fscanf(fp,"%s%d%d%f%f%f%f%f",info[i].name, &info[i].age, &info[i].stu_num, &info[i].score[0], 
	&info[i].score[1], &info[i].score[2], &info[i].total, &info[i].Ave)!=EOF)
	{
		i++;			//人数 
	}
    fclose(fp);
    return i;
 } 

//文件写入
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
 
//学生人数
int stu_num(void)
{
	printf("请输入学生的人数\n");
	scanf("%d", &num);
	return num;
}
  
//学生的信息的接收
struct student* Input(struct student *info, int len)	
{
	int i;
	for (i = 0; i <len; i++)
	{
		printf("请输入第%d个学生的姓名:\n", i+1);
		scanf("%s", info[i].name);
 
		printf("请输入第%d个学生的年龄:\n", i+1);
		scanf("%d", &info[i].age);
 
		printf("请输入第%d个学生的学号:\n",i+1);
		scanf("%d", &info[i].stu_num);
 
		printf("请输入第%d个学生的语文成绩:\n", i+1);
		scanf("%f", &info[i].score[0]);
 
		printf("请输入第%d个学生的数学成绩:\n", i+1);
		scanf("%f", &info[i].score[1]);
 
		printf("请输入第%d个学生的英语成绩:\n", i+1);
		scanf("%f", &info[i].score[2]);
		
		info[i].total = info[i].score[0] + info[i].score[1] + info[i].score[2];	//总分
 
		info[i].Ave = info[i].total /  3.0f;		//平均分
 
	}
 	f_input(info, num);		//写入文件 
	return info;   
}
 
//输出学生的信息
void Output(struct student *info, int len)
{
	printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t平均分\n");
 	int i;
 	len=f_output(info,num);
	for (i = 0; i < len; i++)
	{
		printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", info[i].name, info[i].age, info[i].stu_num, info[i].score[0], info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);
	}
}
 
//删除学生信息
void Delete(struct student *info, int len)
{
	int i, num;
	char name[10];
 
	printf("请输入你要删除数据的姓名:\n");
	scanf("%s", name);//得到删除学生的姓名
 	len=f_output(info, num);
	for (i = 0; i < len; i++)//查找删除的学生的编号
	{
		if (0 == strcmp(info[i].name, name))
		{
			num = i;
			break;
		}
		else num=-1;
	}
 	if(num!=-1){
		for (i = num; i < len; i++)//删除学生
		{
			info[i] = info[i+1];
		}
		printf("\n\n删除后为\n"); 
	 	f_input(info, len - 1);
		Output(info, len - 1);//输出删除后的结果
				}
	else printf("查无此人\n"); 
}
	
//查找学生信息 
void Search(struct student *info, int len)
{
	int i;
	char name[10];
	printf("请输入你需要查找的学生的姓名\n");
	scanf("%s", name);
 	len=f_output(info, num);
	for (i = 0; i < len; i++)		//查找学生编号
	{
		if (0 == strcmp(info[i].name, name))
		{
			num = i;
			break;
		}
		else num=-1;
	}
	if(num!=-1) {
		printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t平均分\n");
		printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", info[i].name, info[i].age, info[i].stu_num, info[i].score[0],
						 info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);		//输出找到的学生的信息
	}
	else  printf("查无此人\n"); 
}
 
//修改学生信息 
void Change(struct student *info, int len)
{
	char name[10];
 
	printf("请输入你需要修改的学生的姓名:\n");
	scanf("%s", name);
 	len=f_output(info, num);
	int i, num;
 
	for (i = 0; i < len; i++)
	{
		if (0 == strcmp(info[i].name, name))//查找学生编号
		{
			num = i;
			break;
		}
		else num=-1;
	}
	if (num!=-1){
		printf("请输入学生的姓名:\n");
		scanf("%s", info[num].name);
	 
		printf("请输入学生的年龄:\n");
		scanf("%d", &info[num].age);
	 
		printf("请输入学生的学号:\n");
		scanf("%d", &info[num].stu_num);
	 
		printf("请输入学生的语文成绩:\n");
		scanf("%f", &info[num].score[0]);
	 
		printf("请输入学生的数学成绩:\n");
		scanf("%f", &info[num].score[1]);
	 
		printf("请输入学生的英语成绩:\n");
		scanf("%f", &info[num].score[2]);
 
		info[num].total = info[num].score[0] + info[num].score[1] + info[num].score[2];		//	总分 
	 
		info[num].Ave = info[num].total / 3.0f;				//平均分
	 	f_input(info, len);		//写入文件中（存档） 
		Output(info, len);		//输出学生信息
}
	else printf("查无此人信息\n");
}

//添加学生信息
void Add(struct student *info, int len)
{
	int peo,i;
 	len=f_output(info, num);
	printf("请输入添加的学生的人数:\n");
	scanf("%d", &peo);
 
	struct student *p = NULL;
 
	for (i = 0; i < peo; i++)
	{
		printf("请输入第%d个学生的姓名:\n", i + 1);
		scanf("%s", info[i+len].name);
		printf("请输入第%d个学生的年龄:\n", i + 1);
		scanf("%d", &info[i+len].age);
		printf("请输入第%d个学生的学号:\n", i + 1);
		scanf("%d", &info[i+len].stu_num);
		printf("请输入第%d个学生的语文成绩:\n", i + 1);
		scanf("%f",&info[i+len].score[0]);
		printf("请输入第%d个学生的数学成绩:\n", i + 1);
		scanf("%f", &info[i+len].score[1]);
		printf("请输入第%d个学生的英语成绩:\n", i + 1);
		scanf("%f", &info[i+len].score[2]);
 
		info[i+len].total = info[i+len].score[0] + info[i+len].score[1] + info[i+len].score[2];		
		info[i+len].Ave = info[i+len].total / 3.0f;
	}
 	f_input(info, peo+len);		//存档 
	Output(info, peo+len);		//输出学生信息
}

//对总成绩排序
void scoretotal(struct student *info, int len)
{
	struct student temp;//中间变量
	int max;//最大值的下标
 	int i,j;
 	f_output(info, num);
	for (i = 0; i < len - 1; i++)
	{
		max = i;//假定总成绩的最大值的下标是i
 
		for (j = i + 1; j < len; j++)
		{
			if (info[j].total  > info[max].total)//查找总成绩最大值的下标
			{
				max = j;
			}
		}
 
		if (max != i)//排序
		{
			temp = info[max];
			info[max] = info[i];
			info[i] = temp;
		}
	}
 
	Output(info, len);//输出排序后的结果
}

//统计 
void stat(struct student *info, int len)
{
len=f_output(info, num);
int i,j;			//第i+1个学生，第j+1科成绩 
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
				case 10: stage[10][j]++	; break;			//满分 	
		}
	} 
}
float A[3]={0},E[3]={0},a[3]={0},e[3]={0};			//优秀率、及格率 
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
printf("分数段           语文       数学        英语\n");
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
printf("及格率            %g         %g          %g\n",A[0],A[1],A[2]);
printf("优秀率            %g         %g          %g\n",E[0],E[1],E[2]);
}

//组合查询 
void mul_search(struct student *info, int len)
{
	int i,ch, ma ,en;
	len=f_output(info, num);
	printf("请输入你需要查找的学生的语文、数学、英语成绩\n");
	scanf("%d%d%d", &ch, &ma, &en);
 
	for (i = 0; i < len; i++)		//查找学生编号
	{
		if (info[i].score[0] == ch && info[i].score[1] == ma && info[i].score[2] == en)
		{
			num = i;
			break;
		}
		else num=-1;
	}
	if(num!=-1)  {
		printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t平均分\n");
		printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", info[i].name, info[i].age, info[i].stu_num, info[i].score[0],
						 info[i].score[1], info[i].score[2], info[i].total, info[i].Ave);		//输出找到的学生的信息
				}		
	else  printf("没有学生与您提供信息相符\n"); 	
}

//欢迎页面显示
void page(){
	
	printf("================================================================================\n\n");
	printf("================================================================================\n\n");
	printf("*************************欢迎使用学生成绩管理系统*******************************\n\n");
	printf("********************************************************************************\n\n");
	printf("================================================================================\n\n");
	printf("================================================================================\n\n");
 
 
	printf("请按任意将进入学生管理系统:\n");
	getchar();
	system("cls");
} 

//用户选择界面 
void Choice(){
	int num, Item;
	struct student *info = NULL;
	struct student *p = NULL;
 	printf("================================================================================\n\n");
	printf("*----------------------- 请选择要操作的命令：----------------------------------*\n\n");
	printf("*------------------------- 1 输入学生信息--------------------------------------*\n\n");
	printf("*------------------------- 2 输出学生信息--------------------------------------*\n\n");
	printf("*------------------------- 3 删除学生信息--------------------------------------*\n\n");
	printf("*------------------------- 4 查找学生信息--------------------------------------*\n\n");
	printf("*------------------------- 5 修改学生信息--------------------------------------*\n\n");
	printf("*------------------------- 6 增加学生信息--------------------------------------*\n\n");
	printf("*------------------------- 7 统计（优秀率，及格率）----------------------------*\n\n");
	printf("*------------------------- 8 组合查询------------------------------------------*\n\n");
	printf("*------------------------- 9 将学生的总成绩按从大到小排------------------------*\n\n");
    printf("*------------------------- 10 退出---------------------------------------------*\n\n");
	printf("================================================================================\n\n");
 	int judge=1;
 	info = (struct student*)malloc(1000*sizeof(struct student));
	p = (struct student*)malloc(1000*sizeof(struct student)); 
 	while(judge!=0)
	{
		printf("\n请选择操作命令;\n");
		scanf("%d", &Item);
 
		switch (Item)
		{
		     case 1://输入学生信息
			{
				num = stu_num();
				p = Input(info, num);
			}
			break;
 
		    case 2://输出学生信息
			{
				Output(p, num);
			}
			break;
 
		     case 3://删除学生信息
			{
				Delete(p, num);
			}
			break;
 
		     case 4://查找学生信息
			{
				Search(p, num);
			}
			break;
 
		     case 5://修改学生信息
			{
				Change(p, num);
			}
			break;
 
		     case 6://添加学生信息
			{
				Add(p, num);
			}
			break;
 
		    case 7://统计
			{
				stat(p, num);
			}
			break;
 
			case 8://组合查询 
				{
				mul_search(p, num);
				}
				break;
 
			case 9://将学生的总成绩按从大到小排序
				{
					scoretotal(p, num); 
				}
				break;
 
			case 10://退出 
				{
					system("cls");
					judge=0; 
				}
				break;
			default: printf("请重新输入正确的序号");	
		}
} 
}
//主函数 
int main()
{
	page();
 	Choice();
 	return 0;
}
