#include "outputwidget.h"

#include <QDateTime>
#include <QScrollBar>

OutputWidget::OutputWidget(QWidget *parent)
    : QTextEdit(parent) {
    setReadOnly(true);
}

void OutputWidget::appendOutput(const QString& message) {
    auto now = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    append(QString("%1 %2").arg(now).arg(message));
    verticalScrollBar()->setValue(verticalScrollBar()->maximum());
}