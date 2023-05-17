#ifndef APP_SIGNAL_H
#define APP_SIGNAL_H

#include <QObject>

#include "common.h"

class AppSignal : public QObject {
    Q_OBJECT
public:
    static AppSignal* getInstance() {
        static AppSignal* instance = nullptr;
        if(instance == nullptr) {
            instance = new AppSignal;
        }
        return instance;
    }

private:
    AppSignal();

public:
  
    void emitUpdateLogMsg(const QString& message);

signals:
    
    void updateLogMsg(const QString& message);
};

#define gSignal AppSignal::getInstance()

#endif // APP_SIGNAL_H

