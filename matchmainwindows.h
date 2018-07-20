#ifndef MATCHMAINWINDOWS_H
#define MATCHMAINWINDOWS_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <QString>
#include <QQuickWindow>
#include <QImage>
#include <QTime>
#include <QUrl>
#include <QVariantMap>
#include <QStandardPaths>
#include <QMessageBox>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>


#include "imageprovider.h"
#include "videoprovider.h"

class MatchMainWindows : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap IconPath READ IconPath WRITE setIconPath NOTIFY IconPathChanged)
public:

    explicit MatchMainWindows(QObject *parent = nullptr);

    void setIconPath(QVariantMap value){};
    QVariantMap IconPath(){
        return IconVariant;
    }

    QImage cvMat2QImage(const cv::Mat& mat);

    ImageProvider *m_pImgProvider;
    VideoProvider *m_VideoProvider;

signals:
    void callQmlRefeshImg();
    void IconPathChanged();
    void newInfo(QString str);

public slots:
    void btClicked(int numberBT,QString path);

private:
    QQmlApplicationEngine engine;
    QVariantMap IconVariant;
    QString DeskPath;

    cv::Mat src;

};

#endif // MATCHMAINWINDOWS_H
