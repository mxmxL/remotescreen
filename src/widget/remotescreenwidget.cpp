#include "remotescreenwidget.h"

#include "common.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

RemoteScreenWidget::RemoteScreenWidget(QWidget *parent) 
    : QWidget(parent) {
    setupUi();
}



void RemoteScreenWidget::setupUi()
{
	QHBoxLayout* main_layout = new QHBoxLayout(this);



	setLayout(main_layout);
}
