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

	//使用官方的命名方式： on_XXX_clicked方式不需要再次绑定
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

//括号
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

//---------------------------------------------------------------------------------
//n!直接计算//计算阶乘
void QtCalc::on_pushButton_nn_clicked()
{
	express[i] = '!'; i++;
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("!");

}

void QtCalc::on_pushButton_C_clicked()
{
	ui.textEdit->clear();
	//清空数组
	for (i = 0; i < 100; i++)
	{
		express[i] = 0;
	}
	i = 0;
}

void QtCalc::on_pushButton_CE_clicked()
{
	ui.textEdit->clear();
	//清空数组
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
		//清除数组最后一位
		i--;
		express[i] = '\0';
		//显示
		ui.textEdit->clear();
		ui.textEdit->moveCursor(QTextCursor::End);
		ui.textEdit->insertPlainText(express);
	}

}

//----------------------------------------------------------------------------
void QtCalc::on_pushButton_equal_clicked()
{

	//clear
	ui.textEdit->clear();
	//打印字符
	ui.textEdit->append(express);
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText("=");

	double sum;
	//阶乘
	char nn_express[100] = { 0 };
	if(express[i-1] == '!')
	{ 
		//去掉!号
		for (int k = 0; k < i-1; k++)
		{
			nn_express[k]= express[k];
		}
		long a = atoi(nn_express);
		sum = 1;
		//计算阶乘
		for (int k = 1; k <= a; k++)
		{
			sum = sum * k;
		}
		//QString sum_string = QString::number(sum, 'g', 5); //5 小数精度
	}
	else
	{
		//一次计算
		cal.Infix2Postfix(express, Postfix);
		sum = cal.Calculation(Postfix);
		//printf("最终计算结果为：%f\n\n", sum);
		
	}

	QString sum_string = QString::number(sum, 'g', 5); //5 小数精度
	//显示
	ui.textEdit->clear();
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText(sum_string);
	//清空数组
	for (i = 0; i < 100; i++)
	{
		express[i] = 0;
	}
	i = 0;

}
