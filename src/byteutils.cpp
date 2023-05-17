#include "byteutils.h"

uchar ByteUtils::byteArrayToByte(QByteArray arr){
    uchar v=0;
    if(arr.size() > 8){
        return v;
    }
    for(int i=0; i < arr.size(); i++){
        v = v |(((uchar)arr[i] == 0) ? 0 : (1<<i));
    }
    return v;
}