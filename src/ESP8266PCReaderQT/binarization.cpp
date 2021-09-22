#include "binarization.h"

CBinarization::CBinarization( QString imgPath )
    : threshold(0)
{
    // 加载图片
    _img = new QImage();
    if (NULL != _img)
    {
        _img->load(imgPath);
    }
}

// 生成灰度图像
QImage* CBinarization::grayScaleImg()
{
    if (NULL == _img)
    {
        return NULL;
    }
    int nWidth = _img->width();
    int nHeight = _img->height();

    // 这里留意，我使用了QImage::Format_Grayscale8格式的图片，这种图片每个像素只用了8bit存储灰度颜色值
    QImage* grayImg = new QImage(nWidth, nHeight, QImage::Format_Grayscale8);
    QRgb rgbVal = 0;
    int grayVal = 0;

    for (int x = 0; x < nWidth; ++x)
    {
        for (int y = 0; y < nHeight; ++y)
        {
            rgbVal = _img->pixel(x, y);

            grayVal = qGray(rgbVal);    // 这里调用Qt的函数，使用(R * 11 + G * 16 + B * 5)/32的方法计算

            grayImg->setPixel(x, y, QColor(grayVal, grayVal, grayVal).rgb());
        }
    }

    return grayImg;
}

int CBinarization::Otsu(QImage* img)
{
    if (NULL == img)
    {
        return -1;
    }
    vector<int> histogram = Histogram(img);
    int total = 0;
    for (int i = 0; i != histogram.size(); ++i)
    {
        total += histogram[i];
    }

    double sum = 0.0;
    for (unsigned int i = 1; i < histogram.size(); ++i)
        sum += i * histogram[i];
    double sumB = 0.0;
    double wB = 0.0;
    double wF = 0.0;
    double mB = 0.0;
    double mF = 0.0;
    double max = 0.0;
    double between = 0.0;
    double threshold = 0.0;
    for (int i = 0; i != 256; ++i)
    {
        wB += histogram[i];
        if (wB == 0)
            continue;
        wF = total - wB;
        if (wF == 0)
            break;
        sumB += i * histogram[i];
        mB = sumB / wB;
        mF = (sum - sumB) / wF;
        between = wB * wF * (mB - mF) * (mB - mF);
        if ( between > max )
        {
            threshold = i;
            max = between;
        }
    }
    return threshold;
}

QImage* CBinarization::process(QImage* img,uchar* binarydata, QByteArray& binDATA)
{
    if (NULL == img)
    {
        return NULL;
    }
    int width = img->width();
    int height = img->height();
    int bytePerLine = img->bytesPerLine();    // 每一行的字节数
    unsigned char *data = img->bits();
    //QByteArray binDATA;
    //binDATA.resize(1024);
    //binarydata = new unsigned char[bytePerLine * height];

    unsigned char g = 0;

    if(alterImage==false){
        int time=0,k=0;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {

                if(time==0){
                    binDATA[k]=0x00;
                }
                g = *(data + i * bytePerLine + j);
                if(int(g) > threshold){
                    binarydata[ i * bytePerLine + j] = 0xFF;
                    //char temp=0x01;
                    binDATA[k]=binDATA[k]>>1;
                    binDATA[k]=binDATA[k]|0x80;
                }
                else{
                    binarydata[ i * bytePerLine + j] = 0x00;
                    //unsigned char temp=0x00;
                    binDATA[k]=(binDATA[k]>>1);
                    binDATA[k]=binDATA[k]&0x7f;
                }
                time++;
                if(time==8){
                    k++;
                    time=0;
                }
            }
        }

    }else{
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                g = *(data + i * bytePerLine + j);

                if(int(g) >= threshold)
                    binarydata[ i * bytePerLine + j] = 0x00;
                else
                    binarydata[ i * bytePerLine + j] = 0xFF;
            }
        }
    }

    //imgData=binarydata;
    QImage *ret = new QImage(binarydata, width, height, bytePerLine, QImage::Format_Grayscale8);
//    for(int gg=0;gg<1024;gg++){
//        qDebug()<<hex<<uchar(binDATA[gg]);
//        //ui->textEdit->append()
//    }
//    XBMData=&binDATA;
    return ret;
}

std::vector<int> CBinarization::Histogram( QImage* img )
{
    unsigned char* graydata = img->bits();
    vector<int> hist(256);    // 256色
    for (int i = 0; i != img->width(); ++i)
    {
        for (int j = 0; j != img->height(); ++j)
        {
            int index = int(*graydata);
            hist[index] += 1;
            graydata += 1;    // step
        }
    }
    graydata = NULL;
    return hist;
}
