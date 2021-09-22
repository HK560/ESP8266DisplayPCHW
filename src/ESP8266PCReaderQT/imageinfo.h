#ifndef IMAGEINFO_H
#define IMAGEINFO_H

#include <QString>
#include <QByteArray>

class imageInfo
{
public:
    imageInfo();

    QString fileName;
    unsigned char * binData;
    QByteArray XBM_DATA;

private:

};


extern imageInfo *imgInfoList;
extern int imgListSize;
#endif // IMAGEINFO_H
