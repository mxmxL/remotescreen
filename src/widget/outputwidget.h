#ifndef OUTPUT_WIDGET_H
#define OUTPUT_WIDGET_H

#include <QObject>
#include <QTextEdit>

class OutputWidget : public QTextEdit {
    Q_OBJECT
public:
    OutputWidget(QWidget *parent = nullptr);

public:
    void appendOutput(const QString& message);

private: 

};

#endif // OUTPUT_WIDGET_H