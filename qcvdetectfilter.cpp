#include "qcvdetectfilter.h"
#include "opencvhelper.h"
#include "rgbframehelper.h"


extern "C" Mat image_to_mat(image im);
extern "C" image mat_to_image(Mat m);

using namespace cv;

extern void test_detector2(network *net ,char **datacfg, char *cfgfile, char *weightfile, Mat img, float thresh, float hier_thresh, char *outfile, int fullscreen,image **alphabet);
extern Mat test_detector(char **datacfg, char *cfgfile, char *weightfile, Mat img, image **alphabet, network *net,layer l, float thresh, float hier_thresh, char *outfile, int fullscreen);
extern char **getNames(char *datacfg);

QVideoFilterRunnable* QCvDetectFilter::createFilterRunnable()
{
    return new QCvDetectFilterRunnable(this);
}

QCvDetectFilterRunnable::QCvDetectFilterRunnable(QCvDetectFilter *creator)
{
    filter = creator;

    char *cfg = "yolov3.cfg";
    char *weights = "yolov3.weights";
    net = load_network(cfg, weights, 0);
    alphabet = load_alphabet();
    set_batch_network(net, 1);
    l = net->layers[net->n-2];
    names = getNames("coco.data");
}

QCvDetectFilterRunnable::~QCvDetectFilterRunnable()
{
    free_network(net);
    free_image(**alphabet);
}

QVideoFrame QCvDetectFilterRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags)
{
    Q_UNUSED(flags);
    input->map(QAbstractVideoBuffer::ReadOnly); // 메모리에 맵핑하여 다른 값이 들어오지 않게 하기 위함



    if(surfaceFormat.handleType() == QAbstractVideoBuffer::NoHandle)
    {
        if (input->pixelFormat() == QVideoFrame::Format_YUV420P || input->pixelFormat() == QVideoFrame::Format_NV12) {
            m_yuv = true;
            m_mat = yuvFrameToMat8(*input);
        } else {
            m_yuv = false;
            QImage wrapper = imageWrapper(*input);
            if (wrapper.isNull()) {
                if (input->handleType() == QAbstractVideoBuffer::NoHandle)
                    input->unmap();
                return *input;
            }
            m_mat = imageToMat8(wrapper);
        }

        // YOLO START
        int dont_show = 'd';
        int letter_box = 0;
        float thresh = 0.25;
        char *outfile = nullptr;
        float hier_thresh = 0.5;
        int ext_output = 0;
        int save_labels = 0;

        char *datacfg = (char*)"coco.data";
        char *cfg = (char*)"yolov3.cfg";
        char *weights = (char*)"yolov3.weights";
        if (weights)
            if (strlen(weights) > 0)
                if (weights[strlen(weights) - 1] == 0x0d) weights[strlen(weights) - 1] = 0;
        char *filename = "data/temp.jpg";

//        printf("ddd : %f\n", thresh);
//        printf("sss : %f\n", hier_thresh);
//        printf("dont : \d\n", dont_show);
//        printf("ext : %d\n", ext_output);
//        printf("save : %d\n", save_labels);
//        printf("outfile : %s\n", outfile);
//        printf("letter : %d\n", letter_box);

        int fullscreen = 0;

        if (m_mat.type() == CV_8UC1)
            cvtColor(m_mat, m_mat, CV_GRAY2BGR);

        Mat tmp_mat;
        try{
//            test_detector2(net , names, cfg, weights, m_mat, thresh, hier_thresh, outfile, fullscreen,alphabet);
            tmp_mat =test_detector(names, cfg, weights, m_mat,alphabet,net,l, thresh, hier_thresh, outfile, fullscreen);

        }
        catch(int exception){
            qDebug()<<"ERROR"<<exception;
        }

        //YOLO END

        m_mat = tmp_mat;
        tmp_mat.release();

            // Classifier 방식 start
//        if(classifier.empty())
//        {
//            QFile xml(":/faceclassifier.xml");
//            if(xml.open(QFile::ReadOnly | QFile::Text))
//            {
//                QTemporaryFile temp;
//                if(temp.open())
//                {
//                    temp.write(xml.readAll());
//                    temp.close();
//                    if(classifier.load(temp.fileName().toStdString()))
//                    {
//                        qDebug() << "Successfully loaded classifier!";
//                    }
//                    else
//                    {
//                        qDebug() << "Could not load classifier.";
//                    }
//                }
//                else
//                {
//                    qDebug() << "Can't open temp file.";
//                }
//            }
//            else
//            {
//                qDebug() << "Can't open XML.";
//            }
//        }
//        else
//        {

//            classifier.detectMultiScale(m_mat, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));


//            //char str[128];

//            //std::cerr << "Exception occurred. Ignoring frame... " << std::endl;
//            // Draw circles on the detected faces
//            for (int i = 0; i < faces.size(); i++)
//            {
//                Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
//                rectangle(m_mat, Point(faces[i].x,faces[i].y),Point(faces[i].x+faces[i].width, faces[i].y+faces[i].height),Scalar(255,0,255),2,8,0);
//                //Mat cutImg = originalMat(faces[i]);
//                //sprintf(str, "%d.jpg", i);
//                //AfxMessageBox(str);
//                //imwrite(str, cutImg);
//            }


//        }



    }
//    else
//    {
//        qDebug() << "Other surface formats are not supported yet!";
//    }

        //Classifier 방식 end

    input->unmap(); // 메모리에서 언매핑

    // Output is an RGB video frame.

    return QVideoFrame(mat8ToImage(m_mat));
    //return *input;
}

