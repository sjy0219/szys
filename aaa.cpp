#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int getchoice();
void menu();
void doExercise(int);
int test(int);
int exnum=0; //��Ŀ����
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
				printf("��������");
			else break;
		}
		if(choice==0)
		{
			break;//�û�ѡ��0���Ƴ�ѭ�����Ƴ�ϵͳ��
		}
		doExercise(choice);//����ϵͳ
	}while(choice!=0);
	printf("��ӭʹ�ñ�������ټ���\n");
	return 0;
}
int getchoice()
{
	printf("���������ѡ��0--4����");
	int choice;
	scanf("%d",&choice);
	return choice;
}
void menu()
{
	printf("****************************************\n");
	printf("**    ��ӭʹ��Сѧ������������ϰ���  **\n");
	printf("*          1.�ӷ���ϰ                  *\n");
	printf("*          2.������ϰ                  *\n");
	printf("*          3.�˷���ϰ                  *\n");
	printf("*          4.������ϰ                  *\n");
	printf("*          0.�˳�                      *\n");
	printf("****************************************\n");
}
void doExercise(int n)
{
	int score=0;  //��ϰ�÷֣���ʼ��Ϊ0
	int i=0;     //��ϰ�����ļ�����
	printf("���������ٵ��⣿");
	scanf("%d",&exnum);
	for(i=0;i<exnum;i++)
	{
		score=score+test(n);
	}
	printf("\n��ȷ�ʣ�%d/%d\n\n\n",score,exnum);
}
int test(int n)
{
	int rightanswer=0; //��ȷ��
	int useranswer=0; //�û�����Ĵ�
	int t=0;          //��ʱ����
	char operation;   //�������
	int  num1=0;      //������1
	int  num2=0;      //������2
	srand(time(NULL));
	num1=rand()%10;  //ȡ0-9֮��������
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
//�ж�֤��
	int errornum=0;
	printf("%d%c%d=",num1,operation,num2);
	while(1)
	{
		scanf("%d",&useranswer);
		if(useranswer==rightanswer)
		{
			if(errornum>0)
			{
				printf("�����ˣ�\n\n");
				return 0;
			}
			else
			{
				printf("�����ˣ�\n\n");
				return 1;
			}
		}
		else 
		{
		  errornum++;
		  if(errornum==3)
		  {
			  printf("����3�Σ���ȷ��Ϊ��%d\n\n",rightanswer);
			  return 0;
		  }
		  else
		  {
			  printf("�����ˣ�����������𰸣�");
		  }
		}
	}
}


