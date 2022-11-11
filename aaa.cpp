#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int getchoice();
void menu();
void doExercise(int);
int test(int);
int exnum=0; //题目数量
int main(void)
{
	int choice=0;
	do
	{
		menu();
		while(1)
		{
			choice=getchoice();
			if(choice<0||choice>4)
				printf("输入有误，");
			else break;
		}
		if(choice==0)
		{
			break;//用户选择0，推出循环（推出系统）
		}
		doExercise(choice);//测试系统
	}while(choice!=0);
	printf("欢迎使用本软件，再见！\n");
	return 0;
}
int getchoice()
{
	printf("请输入你的选择（0--4）：");
	int choice;
	scanf("%d",&choice);
	return choice;
}
void menu()
{
	printf("****************************************\n");
	printf("**    欢迎使用小学生四则运算练习软件  **\n");
	printf("*          1.加法练习                  *\n");
	printf("*          2.减法练习                  *\n");
	printf("*          3.乘法练习                  *\n");
	printf("*          4.除法练习                  *\n");
	printf("*          0.退出                      *\n");
	printf("****************************************\n");
}
void doExercise(int n)
{
	int score=0;  //练习得分，初始化为0
	int i=0;     //练习题数的计数器
	printf("你想做多少道题？");
	scanf("%d",&exnum);
	for(i=0;i<exnum;i++)
	{
		score=score+test(n);
	}
	printf("\n正确率：%d/%d\n\n\n",score,exnum);
}
int test(int n)
{
	int rightanswer=0; //正确答案
	int useranswer=0; //用户输入的答案
	int t=0;          //临时变量
	char operation;   //运算类别
	int  num1=0;      //操作数1
	int  num2=0;      //操作数2
	srand(time(NULL));
	num1=rand()%10;  //取0-9之间的随机数
	num2=rand()%10;

	switch(n)
	{
	case 1:operation='+';break;
	case 2:operation='-';break;
	case 3:operation='*';break;
	case 4:operation='/';break;
	}
	if((operation=='-')&&(num1<num2))
	{
		t=num1;
		num1=num2;
		num2=t;
	}
	if((operation=='/')&&(num2==0))
	{
		t=num1;
		num1=num2;
		num2=t;
	}
	switch(operation)
	{
	case '+':rightanswer=num1+num2;break;
	case '-':rightanswer=num1-num2;break;
	case '*':rightanswer=num1*num2;break;
	case '/':rightanswer=num1/num2;break;
	}
//判断证误
	int errornum=0;
	printf("%d%c%d=",num1,operation,num2);
	while(1)
	{
		scanf("%d",&useranswer);
		if(useranswer==rightanswer)
		{
			if(errornum>0)
			{
				printf("做对了！\n\n");
				return 0;
			}
			else
			{
				printf("做对了！\n\n");
				return 1;
			}
		}
		else 
		{
		  errornum++;
		  if(errornum==3)
		  {
			  printf("错误3次，正确答案为：%d\n\n",rightanswer);
			  return 0;
		  }
		  else
		  {
			  printf("做错了！请重新输入答案：");
		  }
		}
	}
}


