#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtCalc.h"

class QtCalc : public QWidget
{
	Q_OBJECT

public:
	QtCalc(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtCalcClass ui;

private slots:
	void on_pushButton_0_clicked();
	void on_pushButton_1_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();

	void on_pushButton_plus_clicked();
	void on_pushButton_sub_clicked();
	void on_pushButton_mul_clicked();
	void on_pushButton_div_clicked();

	void on_pushButton_parL_clicked();
	void on_pushButton_parR_clicked();

	void on_pushButton_nn_clicked();//n!

	void on_pushButton_C_clicked();
	void on_pushButton_CE_clicked();
	void on_pushButton_back_clicked();

	void on_pushButton_equal_clicked();


};
