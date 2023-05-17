#ifndef BYTE_UTILS_H
#define BYTE_UTILS_H

#include <QByteArray>

class ByteUtils {
public:
    static uchar byteArrayToByte(QByteArray arr);

    static inline QByteArray shortToByteArray(short i)
    {
        QByteArray result;
        result.resize(2);
        result[0] = (uchar)(0x000000ff & i);
        result[1] = (uchar)((0x0000ff00 & i) >> 8);
        return result;
    }
};

#endif // BYTE_UTILS_H