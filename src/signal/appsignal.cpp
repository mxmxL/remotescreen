#include "appsignal.h"

AppSignal::AppSignal() {

}

void AppSignal::emitUpdateLogMsg(const QString& message) {
    emit updateLogMsg(message);
}
