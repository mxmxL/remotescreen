#ifndef SIMULATOR_WINDOW_H
#define SIMULATOR_WINDOW_H

#include <QMainWindow>
#include <QMenu>

#include "common.h"

#include "remotescreenwidget.h"
#include "outputwidget.h"


class RemoteScreenWindow : public QMainWindow
{
	Q_OBJECT

public:
	RemoteScreenWindow(QWidget *parent = Q_NULLPTR);

private slots:
	void load();

    void scan();
    void open();
    void close();

    void updateLogMsg(const QString& message);

private:
	void setupUi();

    void createActions();
    void createDockWindows();
    void createStatusBar();

    void updateStatusBar(const QString& message);

private:
    RemoteScreenWidget* m_remoteScreenWidget;
    QMenu *m_viewMenu;
    OutputWidget* m_outputWidget;
};

#endif // SIMULATOR_WINDOW_H