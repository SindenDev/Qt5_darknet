#ifndef QCVDETECTFILTER_H
#define QCVDETECTFILTER_H

#include "opencv2/opencv.hpp"
#include "darknet.h"

#include <QAbstractVideoFilter>
#include <QDebug>
#include <QTemporaryFile>
#include <QMutex>
#include <vector>

using namespace std;
using namespace cv;


class QCvDetectFilter : public QAbstractVideoFilter
{
    Q_OBJECT
public:
    QVideoFilterRunnable *createFilterRunnable();

signals:
    void objectDetected(float x, float y, float w, float h);

public slots:

};

class QCvDetectFilterRunnable : public QVideoFilterRunnable
{
public:

    QCvDetectFilterRunnable(QCvDetectFilter *creator);
    ~QCvDetectFilterRunnable();
    QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);

private:
    image **alphabet;
    network *net;
    layer l;
    QCvDetectFilter *m_filter;
    cv::Mat m_mat;
    bool m_yuv;
    char **names;

    cv::CascadeClassifier classifier;
    vector<Rect> faces;
    void dft(cv::InputArray input, cv::OutputArray output);
    QCvDetectFilter *filter;
};

#endif // QCVDETECTFILTER_H
