# QTOpenCVMatch  
##Download OpenCV source  
##1、Download OpenCV source (Github) V3.4.1 : https://github.com/opencv/opencv/tree/3.4.1  
##2、Download OpenCV contrib source (Github) V3.4.1 : https://github.com/opencv/  
opencv_contrib/archive/3.4.1.zip  
  
##Build OpenCV  
1、cd <OpenCV Source directory>  
2、mkdir build  
3、cd build  
4、cmake -D CMAKE_BUILD_TYPE=RELEASE \
                    -D CMAKE_INSTALL_PREFIX=/usr/local \
                    -D WITH_TBB=ON \
                    -D BUILD_NEW_PYTHON_SUPPORT=ON \
                    -D WITH_V4L=ON \
                    -D WITH_OPENGL=ON \
                    -D INSTALL_C_EXAMPLES=OFF \
                    -D OPENCV_EXTRA_MODULES_PATH=<opencv contrib directory>/modules <opencv source directory>  
5、make -j4  
6、make install  
## QT5 + OpenCV 圖片比對位置  
QTOpenCVmatch.pro 加入  
INCLUDEPATH +=/usr/local/include  
LIBS += -L/usr/local/lib -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_features2d  -lopencv_objdetect -lopencv_xfeatures2d

