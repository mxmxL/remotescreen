#include "remotescreenwindow.h"

#include <QCoreApplication>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QDockWidget>


#include "appsignal.h"

RemoteScreenWindow::RemoteScreenWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi();

    connect(gSignal, &AppSignal::updateLogMsg, this, &RemoteScreenWindow::updateLogMsg);
}


void RemoteScreenWindow::setupUi()
{
    setWindowTitle("远程控制系统");
    setMinimumSize(1080, 800);
	setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);

    auto w = takeCentralWidget();
    if(w != nullptr) {
        delete w;
        w = nullptr;
    }

    m_remoteScreenWidget = new RemoteScreenWidget(this);
    setCentralWidget(m_remoteScreenWidget);

    createActions();
    createStatusBar();
    createDockWindows();
}


void RemoteScreenWindow::load() {
}

void RemoteScreenWindow::scan() {
   
}

void RemoteScreenWindow::open() {
    
}

void RemoteScreenWindow::close() {
   
}

void RemoteScreenWindow::updateLogMsg(const QString& message) {
    m_outputWidget->appendOutput(message);
}

void RemoteScreenWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu("文件(&F)");
    QAction *loadAct = new QAction("加载(&L)", this);
    connect(loadAct, &QAction::triggered, this, &RemoteScreenWindow::load);
    fileMenu->addAction(loadAct);

    fileMenu->addSeparator();
    QAction *quitAct = fileMenu->addAction("退出(&Q)", qApp, &QCoreApplication::quit);
    quitAct->setShortcuts(QKeySequence::Quit);

    menuBar()->addSeparator();
    m_viewMenu = menuBar()->addMenu("视图(&V)");

    QToolBar *mainToolBar = addToolBar("Device");
    QIcon scanIcon(":/images/scan.png");
    QAction *scanAct = new QAction(scanIcon, "扫描", this);
    mainToolBar->addAction(scanAct);

    QIcon openIcon(":/images/open.png");
    QAction *openAct = new QAction(openIcon, "打开", this);
    mainToolBar->addAction(openAct);

    QIcon closeIcon(":/images/close.png");
    QAction *closeAct = new QAction(closeIcon, "关闭", this);
    mainToolBar->addAction(closeAct);

    connect(scanAct, &QAction::triggered, this, &RemoteScreenWindow::scan);
    connect(openAct, &QAction::triggered, this, &RemoteScreenWindow::open);
    connect(closeAct, &QAction::triggered, this, &RemoteScreenWindow::close);
}

void RemoteScreenWindow::createStatusBar()
{
}

void RemoteScreenWindow::updateStatusBar(const QString& message)
{
    statusBar()->showMessage(message, 3000);
}

void RemoteScreenWindow::createDockWindows()
{
    auto outputDock = new QDockWidget("输出", this);
    m_outputWidget = new OutputWidget(outputDock);
    outputDock->setWidget(m_outputWidget);
    addDockWidget(Qt::BottomDockWidgetArea, outputDock);
    m_viewMenu->addAction(outputDock->toggleViewAction());
}