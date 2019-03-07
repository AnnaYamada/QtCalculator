#include "QtCalc.h"
#include "calculator.cpp"
#include <string>

int i = 0;
long value=0;
//char express[100] = { 0 };

Calculator<double> cal;
char express[100], Postfix[100];

QtCalc::QtCalc(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//ʹ�ùٷ���������ʽ�� on_XXX_clicked��ʽ����Ҫ�ٴΰ�
	//connect(ui.pushButton_0, SIGNAL(clicked()), this, SLOT(on_pushButton_0_clicked()));
	//connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(on_pushButton_1_clicked()));
	//connect(ui.pushButton_plus, SIGNAL(clicked()), this, SLOT(on_pushButton_plus_clicked()));
	//connect(ui.pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
	//connect(ui.label, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));

}


void QtCalc::on_pushButton_0_clicked()
{
	express[i] = '0'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("0");

}

void QtCalc::on_pushButton_1_clicked()
{
	express[i] = '1'; i++;
ui.textEdit->moveCursor(QTextCursor::End);
ui.textEdit->insertPlainText("1");
}
void QtCalc::on_pushButton_2_clicked()
{
	express[i] = '2'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("2");
}
void QtCalc::on_pushButton_3_clicked()
{
	express[i] = '3'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("3");
}
void QtCalc::on_pushButton_4_clicked()
{
	express[i] = '4'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("4");
}
void QtCalc::on_pushButton_5_clicked()
{
	express[i] = '5'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("5");
}
void QtCalc::on_pushButton_6_clicked()
{
	express[i] = '6'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("6");
}
void QtCalc::on_pushButton_7_clicked()
{
	express[i] = '7'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("7");
}
void QtCalc::on_pushButton_8_clicked()
{
	express[i] = '8'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("8");
}
void QtCalc::on_pushButton_9_clicked()
{
	express[i] = '9'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("9");
}

void QtCalc::on_pushButton_plus_clicked()
{
	express[i] = '+'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("+");

}

void QtCalc::on_pushButton_sub_clicked()
{
	express[i] = '-'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("-");

}

void QtCalc::on_pushButton_mul_clicked()
{
	express[i] = '*'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("*");
}

void QtCalc::on_pushButton_div_clicked()
{
	express[i] = '/'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("/");

}

//����
void QtCalc::on_pushButton_parL_clicked()
{
	express[i] = '('; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("(");
}

void QtCalc::on_pushButton_parR_clicked()
{
	express[i] = ')'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText(")");
}

void QtCalc::on_pushButton_C_clicked()
{
	ui.textEdit->clear();
	//�������
	for (i = 0; i < 100; i++)
	{
		express[i] = 0;
	}
	i = 0;
}

void QtCalc::on_pushButton_CE_clicked()
{
	ui.textEdit->clear();
	//�������
	for (i = 0; i < 100; i++)
	{
		express[i] = 0;
	}
	i = 0;
}

void QtCalc::on_pushButton_back_clicked()
{
	int length_express = 0;

	if (i != 0)
	{
		//����������һλ
		i--;
		express[i] = '\0';
		//��ʾ
		ui.textEdit->clear();
		ui.textEdit->moveCursor(QTextCursor::End);
		ui.textEdit->insertPlainText(express);
	}

}

void QtCalc::on_pushButton_equal_clicked()
{

	//clear
	ui.textEdit->clear();
	//��ӡ�ַ�
	ui.textEdit->append(express);
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("=");
	//expressתΪ���ֱ��ʽ
	//0:48 9:57
	//+:43           -:45            *:42          /:47

	//һ�μ���
	double sum;
	cal.Infix2Postfix(express, Postfix);
	sum = cal.Calculation(Postfix);
	printf("���ռ�����Ϊ��%f\n\n", sum);
	QString sum_string = QString::number(sum, 'g', 5); //5 С������
	//string sum_string = to_string(sum);//X����ʹint float double ������

	//��ʾ
	ui.textEdit->clear();
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText(sum_string);
	//�������
	for (i = 0; i < 100; i++)
	{
		express[i] = 0;
	}
	i = 0;

}
