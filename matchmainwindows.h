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

#include <opencv2/opencv.hpp>
#include "imageprovider.h"

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
};

#endif // MATCHMAINWINDOWS_H
