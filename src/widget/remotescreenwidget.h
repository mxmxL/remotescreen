#ifndef REMOTE_SCREEN_WIDGET_H
#define REMOTE_SCREEN_WIDGET_H

#include <QWidget>


class RemoteScreenWidget : public QWidget {
    Q_OBJECT

public:
    RemoteScreenWidget(QWidget *parent = Q_NULLPTR);

private:
    void setupUi();

private slots:
	

private:
	
};

#endif // REMOTE_SCREEN_WIDGET_H