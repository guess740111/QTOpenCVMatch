#include "videoprovider.h"
VideoProvider::VideoProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
    capture_ = cvCaptureFromCAM(0);
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n");  };
//    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n");  };

}
QPixmap VideoProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Mat img = cvarrToMat(cvQueryFrame(capture_));
//    Mat img = cvQueryFrame(capture_);

    // resize
    *size = QSize(img.cols, img.rows);
    int width  = requestedSize.width()  > 0 ? requestedSize.width()  : img.rows;
    int height = requestedSize.height() > 0 ? requestedSize.height() : img.cols;
    Mat resized_img(width, height, img.type());
    resize(img, resized_img, resized_img.size(), INTER_CUBIC);

    // BGR -> ARGB
    cvtColor(resized_img, resized_img, CV_BGR2BGRA);
    vector<Mat> bgra;
    split(resized_img, bgra);
    swap(bgra[0], bgra[3]);
    swap(bgra[1], bgra[2]);

    //SURF
//    vector<KeyPoint> keypoints;
//    int minHessian = 4500;
//    Ptr<SURF>detector = SURF::create(minHessian);
//    detector->detect( resized_img, keypoints );
//    Scalar color(100, 255, 50);
//    for (const auto& point : keypoints) {
//        circle(resized_img, point.pt, 1, color, -1);
//        circle(resized_img, point.pt, point.size, color, 1, CV_AA);
//    }

    //人臉辨識
    resized_img = detectAndDisplay( resized_img );

    //找圓形
//    Mat edges;
//    cvtColor(resized_img, edges, CV_BGR2GRAY);
//    //高斯滤波
//    GaussianBlur(edges, edges, Size(7, 7), 2, 2);
//    vector<Vec3f> circles;
//    //霍夫圆
//    HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.3, 100, 150, 100, 0, 0);
//    for (size_t i = 0; i < circles.size(); i++)
//    {
//        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//        int radius = cvRound(circles[i][2]);
//        circle(resized_img, center, radius, Scalar(155, 50, 255,255), 3, 8, 0);
//    }




    QImage video_img(resized_img.data, resized_img.cols, resized_img.rows, QImage::Format_ARGB32);

    return QPixmap::fromImage(video_img);
}

Mat VideoProvider::detectAndDisplay(Mat frame)
{

    std::vector<Rect> faces;
//    Mat frame_gray;

//    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
//    equalizeHist( frame_gray, frame_gray );

//    //-- Detect faces
//    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
    face_cascade.detectMultiScale( frame, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for( size_t i = 0; i < faces.size(); i++ )
    {
        //畫橢圓
//        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
//        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 0, 255, 0 ,255), 4, 8, 0 );

        Point startPoint(faces[i].x,faces[i].y);
        Point ednPoint (faces[i].x+faces[i].width,faces[i].y+faces[i].height);
        //畫正方形
        rectangle(frame, startPoint, ednPoint, Scalar( 0, 255, 0 ,255), 2, 8, 0);

//        Mat faceROI = frame_gray( faces[i] );
//        std::vector<Rect> eyes;

        //-- In each face, detect eyes
//        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

//        for( size_t j = 0; j < eyes.size(); j++ )
//        {
//            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
//            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
//            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
//        }
    }
    return frame;
}

