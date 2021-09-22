
#ifndef CBINARIZATION_H
#define CBINARIZATION_H

#include <QImage>
#include <QColor>
#include <QByteArray>
#include <QtDebug>

using namespace std;

class CBinarization
{
public:
    CBinarization(QString imgPath);
    //~CBinarization();
    QImage* grayScaleImg();
    int Otsu(QImage* img);
    QImage* process(QImage* img,uchar* imgData,QByteArray& binDATA);
    int     threshold;
    bool alterImage=false;

private:
    QImage* _img;

    vector<int> Histogram(QImage* img);
};

#endif // CBINARIZATION_H
