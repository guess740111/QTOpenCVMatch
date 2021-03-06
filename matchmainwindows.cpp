#include "matchmainwindows.h"
MatchMainWindows::MatchMainWindows(QObject *parent) : QObject(parent){

    DeskPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    IconVariant["DeskPath"] = DeskPath;
    IconVariant["source"] = DeskPath+"/image/source.jpg";

    src = cv::imread((DeskPath+"/image/source.jpg").toUtf8().constData());

    m_pImgProvider = new ImageProvider();
    m_VideoProvider = new VideoProvider();
    engine.rootContext()->setContextProperty("mainui",this);
    engine.addImageProvider(QLatin1String("CodeImg"), m_pImgProvider);
    engine.addImageProvider(QLatin1String("videoCapture"), m_VideoProvider);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    emit IconPathChanged();

    QObject* topLevel     = engine.rootObjects().first();
    QQuickWindow* rootWin = qobject_cast<QQuickWindow *>( topLevel );

    QObject::connect( rootWin, SIGNAL( btClicked(int,QString)), this, SLOT( btClicked(int,QString)) );
    QObject::connect( this, SIGNAL( newInfo(QString)), rootWin, SIGNAL( newInfo(QString)) );




}

void MatchMainWindows::btClicked(int numberBT, QString path){

    QTime current_time;
    int msec,msec2;
    current_time = QTime::currentTime();
    msec = (current_time.second()*1000)+current_time.msec();

    cv::Mat roiImg = cv::imread((DeskPath+"/image/"+QString::number(numberBT)+".jpg").toUtf8().constData());
    cv::Mat displayImg = src.clone();

    cv::Mat result;
    result.create(src.rows-roiImg.rows+1, src.cols-roiImg.cols+1, CV_32FC1);
    cv::matchTemplate(src, roiImg, result, cv::TM_SQDIFF_NORMED);
    double minVal,maxVal;
    cv::Point minLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, 0);
    cv::rectangle(displayImg, minLoc, cv::Point(minLoc.x+roiImg.cols , minLoc.y+roiImg.rows), cv::Scalar(0,0,255)/*Blue,Green,Red*/, 3);

    //指定插入的大小和位置
//    cv::Mat imgROI = displayImg(Rect((displayImg.cols/2)-(roiImg.cols/2),30,roiImg.cols,roiImg.rows));
//    cv::addWeighted(imgROI,0,roiImg,1,0,imgROI);


    QImage tempimage = cvMat2QImage(displayImg);
    m_pImgProvider->img = tempimage;
    emit callQmlRefeshImg();

    current_time = QTime::currentTime();
    msec2 = (current_time.second()*1000)+current_time.msec();
    if(minVal < 0.1 || minVal >2){
        QString tempStr;
        tempStr = "mainVal : "+ QString::number(minVal) + " Match Time : " + QString::number(msec2 - msec) + "\n";
        tempStr =tempStr + " x : " + QString::number(minLoc.x) + " y : " + QString::number(minLoc.y);
        emit newInfo(tempStr);
    }
}


QImage MatchMainWindows::cvMat2QImage(const cv::Mat& mat)
{
    if(mat.type() == CV_8UC1){
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for(int i = 0; i < 256; i++){
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++){
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }else if(mat.type() == CV_8UC3){
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }else if(mat.type() == CV_8UC4){
        qDebug() << "CV_8UC4";
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }else{
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

