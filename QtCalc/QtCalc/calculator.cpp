#include "calculator.h"
#include <stdio.h>
#include <windows.h>

template<typename ElemType>
Calculator<ElemType>::Calculator()
{
	s.base = new ElemType[STACK_INIT_SIZE];//ջ��ָ������ռ���׵�ַ
	if (s.base == NULL)//����ʧ��
		exit(0);
	s.top = s.base;//top����ָ����ЧԪ�ص���һ���ռ䣨ջ������top��û������
	s.stackSize = STACK_INIT_SIZE;
}

//����ջ�����ڴ�ռ��ͷ�
template<typename ElemType>
Calculator<ElemType>::~Calculator()
{
	delete[]s.base;
}

template<typename ElemType>
void Calculator<ElemType>::Push(ElemType e)
{
	if (s.top - s.base >= s.stackSize)
	{
		s.base = (ElemType *)realloc(s.base, (s.stackSize + STACKINCREMENT) * sizeof(ElemType));
		//        realloc������һ���µĿռ䣬�����ɵ����ݿ������µĿռ䣬�����ͷ���ǰ�Ŀռ�
		if (s.base == NULL)
			exit(0);
		s.top = s.base + s.stackSize;//��Ϊ���·����˿ռ䣬������������ջ��
		s.stackSize = s.stackSize + STACKINCREMENT;//��ǰջ��������������
	}
	*(s.top) = e;
	s.top++;
}

template<typename ElemType>
bool Calculator<ElemType>::Pop(ElemType &e)
{
	if (s.top == s.base)
		return false;//��ջ
	e = *(--(s.top));
	return true;
}

//���ջ�����ı�����ռ�
template<typename ElemType>
void Calculator<ElemType>::clearStack()
{
	s.top = s.base;
}

//����ջ�ĵ�ǰ�������洢������������Ԫ�ظ�����
template<typename ElemType>
int Calculator<ElemType>::StackLen()
{
	return s.top - s.base;
}

template<typename ElemType>
double Calculator<ElemType>::Calculation(char Postfix[])
{
	int i = 0, j;
	char c;
	char str[MAXBUFFER];
	double a = 0, b = 0;

	for (j = 0; Postfix[j] != '\0'; j++)
	{
		//        c=Postfix[j];
		while ((Postfix[j] >= 48) && (Postfix[j] <= 57) || Postfix[j] == '.') //�����������
		{
			str[i] = Postfix[j];
			//            printf("str[%d]=%c\n",i,c);
			i++;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("������������ݳ��ȹ���!\n");
				return -1;
			}

			//            scanf("%c",&c);
			j++;
			if ((Postfix[j] == ' '))
			{
				//                str[i]='\0';
//                printf("str[%d]=%c\n",i,Postfix[j]);
				a = atof(str);
				//                printf("%f \n",a);
				Push(a);
				i = 0;
			}

		}

		switch (Postfix[j])
		{
		case '+':
			Pop(a);
			if (!Pop(b))//��ֹ���Ƿ���λ����Ŀ�������
			{
				Push(a);
				break;
			}
			Pop(b);
			//            printf("%f+%f=%f\n",b,a,b+a);
			Push(b + a);
			break;
		case '-':
			Pop(a);
			if (!Pop(b))//
			{
				Push(-a);
				break;
			}
			//            printf("%f-%f=%f\n",b,a,b-a);
			Push(b - a);
			break;
		case '*':
			Pop(a);
			Pop(b);
			//            printf("%f*%f=%f\n",b,a,b*a);
			Push(b*a);
			break;
		case '/':
			Pop(a);
			if (a == 0)
			{
				printf("��������Ϊ�� ��\n");
				return -1;
			}
			Pop(b);
			Push(b / a);

			break;
		default:
			break;
		}
	}
	Pop(a);
	return a;

}

template<typename ElemType>
bool Calculator<ElemType>::Infix2Postfix(char Infix[], char Postfix[])
{
	Calculator<char> s;
	int i = 0, j = 0;
	char e;

	printf("��׺���ʽΪ��");
	while (Infix[j] != '\0')
	{
		while (Infix[j] >= '0' && Infix[j] <= '9')
		{
			printf("%c", Infix[j]);
			Postfix[i++] = Infix[j];
			j++;
			if (Infix[j]<'0' || Infix[j]>'9')
			{
				Postfix[i++] = ' ';
				printf(" ");
			}
		}

		switch (Infix[j])
		{

		case ')':
			s.Pop(e);
			while ('(' != e)
			{
				printf("%c ", e);
				Postfix[i++] = e;
				Postfix[i++] = ' ';
				s.Pop(e);
			}
			break;

		case '+':
		case '-':
			if (0 == s.StackLen())
				s.Push(Infix[j]);
			else
			{
				do
				{
					s.Pop(e);
					if ('(' == e)
					{
						s.Push(e);
					}
					else
					{
						printf("%c ", e);
						Postfix[i++] = e;
						Postfix[i++] = ' ';
					}
				} while (s.StackLen() && '(' != e);
				s.Push(Infix[j]);
			}
			break;

		case '*':
		case '/':
		case '(':
			s.Push(Infix[j]);
			break;

		case '\0':
			break;

		default:
			printf("\n�����ʽ����\n");
			return -1;
		}

		if ('\0' == Infix[j])
			break;
		j++;
	}

	while (s.StackLen())
	{
		s.Pop(e);
		printf("%c ", e);
		Postfix[i++] = e;
		Postfix[i++] = ' ';
	}
	Postfix[i] = '\0';
	printf("\n");
	return true;
}
