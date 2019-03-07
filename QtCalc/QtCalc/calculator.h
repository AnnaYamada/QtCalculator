#ifndef CALCULATOR_H
#define CALCULATOR_H

enum MAXSIZE
{
	STACK_INIT_SIZE = 20,//定义初始最大容量
	STACKINCREMENT = 10,//栈满的时候，动态增加容量，每次增加10个元素空间
	MAXBUFFER = 10,//最大缓冲区
	MAX_EXP_LEN = 100//表达式最长为100
};

template<typename ElemType>
class Calculator
{
public:
	struct sqStack
	{
		ElemType *base;//指向栈顶
		ElemType *top;
		int stackSize;//当前栈的最大容量
	};
	Calculator();
	~Calculator();
	void Push(ElemType e);
	bool Pop(ElemType &e);
	void clearStack();
	int StackLen();

	double Calculation(char Postfix[]);//后缀表达式的计算
	bool Infix2Postfix(char Infix[], char Postfix[]);//中缀表达式变为后缀表达式

private:
	sqStack s;

};

#endif // CALCULATOR_H
