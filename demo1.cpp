#include "demo1.h"

demo1::demo1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initConnection();
}
void demo1::initConnection()
{
	connect(ui.rotateEdit, SIGNAL(textChanged(const QString &)), this, SLOT(rotateEditChangedSlot(const QString &)));
	connect(ui.xOffsetEdit, SIGNAL(textChanged(const QString &)), this, SLOT(xoffsetEditChangedSlot(const QString &)));
	connect(ui.yOffsetEdit, SIGNAL(textChanged(const QString &)), this, SLOT(yoffsetEditChangedSlot(const QString &)));
	connect(ui.zOffsetEdit, SIGNAL(textChanged(const QString &)), this, SLOT(zoffsetEditChangedSlot(const QString &)));
}
void demo1::rotateEditChangedSlot(const QString &text)
{
	if(text == "")
		ui.openGLWidget->setAngle(0);
	float data = text.toFloat();
	ui.openGLWidget->setAngle(data);
	ui.openGLWidget->update();
}
void demo1::xoffsetEditChangedSlot(const QString &text)
{
	if (text == "")
		ui.openGLWidget->setXoffset(0);
	float data = text.toFloat();
	ui.openGLWidget->setXoffset(data);
	ui.openGLWidget->update();
}
void demo1::yoffsetEditChangedSlot(const QString &text)
{
	if (text == "")
		ui.openGLWidget->setYoffset(0);
	float data = text.toFloat();
	ui.openGLWidget->setYoffset(data);
	ui.openGLWidget->update();
}
void demo1::zoffsetEditChangedSlot(const QString &text)
{
	if (text == "")
		ui.openGLWidget->setZoffset(0);
	float data = text.toFloat();
	ui.openGLWidget->setZoffset(data);
	ui.openGLWidget->update();
}