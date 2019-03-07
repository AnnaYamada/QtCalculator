#include "calculator.h"
#include <stdio.h>
#include <windows.h>

template<typename ElemType>
Calculator<ElemType>::Calculator()
{
	s.base = new ElemType[STACK_INIT_SIZE];//栈底指向申请空间的首地址
	if (s.base == NULL)//申请失败
		exit(0);
	s.top = s.base;//top总是指向有效元素的下一个空间（栈顶），top中没有数据
	s.stackSize = STACK_INIT_SIZE;
}

//销毁栈，将内存空间释放
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
		//        realloc是申请一个新的空间，并将旧的内容拷贝到新的空间，还会释放以前的空间
		if (s.base == NULL)
			exit(0);
		s.top = s.base + s.stackSize;//因为重新分配了空间，所以重新设置栈顶
		s.stackSize = s.stackSize + STACKINCREMENT;//当前栈的最大容量变大了
	}
	*(s.top) = e;
	s.top++;
}

template<typename ElemType>
bool Calculator<ElemType>::Pop(ElemType &e)
{
	if (s.top == s.base)
		return false;//空栈
	e = *(--(s.top));
	return true;
}

//清空栈，不改变物理空间
template<typename ElemType>
void Calculator<ElemType>::clearStack()
{
	s.top = s.base;
}

//计算栈的当前容量（存储的数据量或者元素个数）
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
		while ((Postfix[j] >= 48) && (Postfix[j] <= 57) || Postfix[j] == '.') //输入的是数字
		{
			str[i] = Postfix[j];
			//            printf("str[%d]=%c\n",i,c);
			i++;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("出错，输入的数据长度过大!\n");
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
			if (!Pop(b))//防止这是符号位（单目运算符）
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
				printf("除数不能为零 ！\n");
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

	printf("中缀表达式为：");
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
			printf("\n输入格式错误！\n");
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
