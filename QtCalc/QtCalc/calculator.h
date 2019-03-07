#ifndef CALCULATOR_H
#define CALCULATOR_H

enum MAXSIZE
{
	STACK_INIT_SIZE = 20,//�����ʼ�������
	STACKINCREMENT = 10,//ջ����ʱ�򣬶�̬����������ÿ������10��Ԫ�ؿռ�
	MAXBUFFER = 10,//��󻺳���
	MAX_EXP_LEN = 100//���ʽ�Ϊ100
};

template<typename ElemType>
class Calculator
{
public:
	struct sqStack
	{
		ElemType *base;//ָ��ջ��
		ElemType *top;
		int stackSize;//��ǰջ���������
	};
	Calculator();
	~Calculator();
	void Push(ElemType e);
	bool Pop(ElemType &e);
	void clearStack();
	int StackLen();

	double Calculation(char Postfix[]);//��׺���ʽ�ļ���
	bool Infix2Postfix(char Infix[], char Postfix[]);//��׺���ʽ��Ϊ��׺���ʽ

private:
	sqStack s;

};

#endif // CALCULATOR_H
