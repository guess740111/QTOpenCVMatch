#ifndef VIDEOPROVIDER_H
#define VIDEOPROVIDER_H
#include <QQuickImageProvider>
#include <QImage>
#include <QPixmap>
#include <QString>
#include <QSize>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;
//using namespace xfeatures2d;

class VideoProvider : public QQuickImageProvider
{
public:
    VideoProvider();
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    QString fileName;
private:
    Mat detectAndDisplay( Mat frame );
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    String face_cascade_name = "haarcascade_frontalface_alt.xml";
    String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

    CvCapture* capture_;

};

#endif // VIDEOPROVIDER_H

