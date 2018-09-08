#pragma once

#include <QtWidgets/QWidget>
#include "ui_demo1.h"
#include "RenderCls.h"

class demo1 : public QWidget
{
	Q_OBJECT

public:
	demo1(QWidget *parent = Q_NULLPTR);
	void initConnection();
public slots:
	void rotateEditChangedSlot(const QString &);
	void xoffsetEditChangedSlot(const QString &);
	void yoffsetEditChangedSlot(const QString &);
	void zoffsetEditChangedSlot(const QString &);
private:
	Ui::demo1Class ui;
};
