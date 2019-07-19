#include "opencvhelper.h"

/**
 * @brief imageToMat8
 * @param image
 * @return
 */
cv::Mat imageToMat8(const QImage &image)
{
    QImage img = image.convertToFormat(QImage::Format_RGB32).rgbSwapped();
    cv::Mat tmp(img.height(), img.width(), CV_8UC4, (void *) img.bits(), img.bytesPerLine());
    return tmp.clone();
}

/**
 * @brief ensureC3
 * @param mat
 */
void ensureC3(cv::Mat *mat)
{
    Q_ASSERT(mat->type() == CV_8UC3 || mat->type() == CV_8UC4);
    if (mat->type() != CV_8UC3) {
        cv::Mat tmp;
        cvtColor(*mat, tmp, CV_BGRA2BGR);
        *mat = tmp;
    }
}

QImage mat8ToImage(const cv::Mat &mat)
{
    switch (mat.type()) {
    case CV_8UC1:
    {
        QVector<QRgb> ct;
        for (int i = 0; i < 256; ++i)
            ct.append(qRgb(i, i, i));
        QImage result(mat.data, mat.cols, mat.rows, (int) mat.step, QImage::Format_Indexed8);
        result.setColorTable(ct);
        return result.copy();
    }
    case CV_8UC3:
    {
        cv::Mat tmp;
        cvtColor(mat, tmp, CV_BGR2BGRA);
        return mat8ToImage(tmp);
    }
    case CV_8UC4:
    {
        QImage result(mat.data, mat.cols, mat.rows, (int) mat.step, QImage::Format_RGB32);
        return result.rgbSwapped();
    }
    default:
        qWarning("Unhandled Mat format %d", mat.type());
        return QImage();
    }
}

cv::Mat yuvFrameToMat8(const QVideoFrame &frame)
{
    Q_ASSERT(frame.handleType() == QAbstractVideoBuffer::NoHandle && frame.isReadable());
    Q_ASSERT(frame.pixelFormat() == QVideoFrame::Format_YUV420P || frame.pixelFormat() == QVideoFrame::Format_NV12);

    cv::Mat tmp(frame.height() + frame.height() / 2, frame.width(), CV_8UC1, (uchar *) frame.bits());
    cv::Mat result(frame.height(), frame.width(), CV_8UC3);
    cvtColor(tmp, result, frame.pixelFormat() == QVideoFrame::Format_YUV420P ? CV_YUV2BGR_YV12 : CV_YUV2BGR_NV12);
    return result;
}

class YUVBuffer : public QAbstractVideoBuffer
{
public:
    YUVBuffer(cv::Mat *mat) : QAbstractVideoBuffer(NoHandle), m_mode(NotMapped) {
        m_yuvMat.reset(mat);
    }
    MapMode mapMode() const Q_DECL_OVERRIDE { return m_mode; }
    uchar *map(MapMode mode, int *numBytes, int *bytesPerLine) Q_DECL_OVERRIDE {
        if (mode != NotMapped && m_mode == NotMapped) {
            if (numBytes)
                *numBytes = m_yuvMat->rows * m_yuvMat->cols;
            if (bytesPerLine)
                *bytesPerLine = m_yuvMat->cols;
            m_mode = mode;
            return m_yuvMat->data;
        }
        return 0;
    }
    void unmap() Q_DECL_OVERRIDE { m_mode = NotMapped; }
    QVariant handle() const Q_DECL_OVERRIDE { return 0; }

private:
    MapMode m_mode;
    QScopedPointer<cv::Mat> m_yuvMat;
};

QVideoFrame mat8ToYuvFrame(const cv::Mat &mat)
{
    Q_ASSERT(mat.type() == CV_8UC3 || mat.type() == CV_8UC4);

    cv::Mat *m = new cv::Mat;
    cvtColor(mat, *m, mat.type() == CV_8UC4 ? CV_BGRA2YUV_YV12 : CV_BGR2YUV_YV12);
    return QVideoFrame(new YUVBuffer(m), QSize(mat.cols, mat.rows), QVideoFrame::Format_YUV420P);
}

void mat8ToYuvFrame(const cv::Mat &mat, uchar *dst)
{
    cv::Mat m(mat.rows + mat.rows / 2, mat.cols, CV_8UC1, dst);
    cvtColor(mat, m, mat.type() == CV_8UC4 ? CV_BGRA2YUV_YV12 : CV_BGR2YUV_YV12);
}
