#ifdef OPENCV
#endif OPENCV
#include "opencv2/opencv.hpp"

#include "darknet.h"

#include "QDebug"

using namespace cv;

extern "C" Mat image_to_mat(image im);
extern "C" image mat_to_image(Mat m);

Mat test(Mat img)
{
    image im = mat_to_image(img);

    fprintf(stderr,"lll\n");

    return image_to_mat(im);
}

char **getNames(char *datacfg)
{
        list *options = read_data_cfg(datacfg);

        char *name_list = option_find_str(options, "names", "data/names.list");
        char **names = get_labels(name_list);

        return names;
}

void test_detector2(network *net,char **names, char *cfgfile, char *weightfile, Mat img, float thresh, float hier_thresh, char *outfile, int fullscreen,image **alphabet)
{
    printf("asdf1");

    srand(2222222);
    double time;
    char buff[256];
    char *input = buff;
    float nms=.45;
    image im;
    image sized;


    printf("asdf2");
    im = mat_to_image(img);
    sized = letterbox_image(im, net->w, net->h);
    //image sized = resize_image(im, net->w, net->h);
    //image sized2 = resize_max(im, net->w);
    //image sized = crop_image(sized2, -((net->w - sized2.w)/2), -((net->h - sized2.h)/2), net->w, net->h);
    //resize_network(net, sized.w, sized.h);
    layer l = net->layers[net->n-2];

    qDebug()<<"net n"<<":"<<net->layers[net->n-2].classes;

    float *X = sized.data;
    time=what_time_is_it_now();
    network_predict(net, X);
    printf("%s: Predicted in %f seconds.\n", input, what_time_is_it_now()-time);
    int nboxes = 0;
    detection *dets = get_network_boxes(net, im.w, im.h, thresh, hier_thresh, 0, 1, &nboxes);

    //printf("%d\n", nboxes);
    //if (nms) do_nms_obj(boxes, probs, l.w*l.h*l.n, l.classes, nms);
//    if (nms) do_nms_sort(dets, nboxes, l.classes, nms);
//    draw_detections(im, dets, nboxes, thresh, names, alphabet, l.classes);
    free_detections(dets, nboxes);
    if(outfile){
        save_image(im, outfile);
    }
    else{
        save_image(im, "predictions");
#ifdef OPENCV
        //  make_window("predictions", 512, 512, 0);
        //  show_image(im, "predictions", 0);
#endif
    }

     printf("asdf3");

    // cv::imshow("asdf",image_to_mat(im));


    //free_layer(l);
    free_image(sized);
    free_image(im);
    //return image_to_mat(im);
}

Mat test_detector(char **names, char *cfgfile, char *weightfile, Mat img, image **alphabet, network *net , layer l, float thresh, float hier_thresh, char *outfile, int fullscreen)
{
    srand(2222222);
    double time;
    char buff[256];
    char *input = buff;
    float nms=.45;
    image im;
    image sized;


    printf("asdf2");
    im = mat_to_image(img);
    sized = letterbox_image(im, net->w, net->h);
    //image sized = resize_image(im, net->w, net->h);
    //image sized2 = resize_max(im, net->w);
    //image sized = crop_image(sized2, -((net->w - sized2.w)/2), -((net->h - sized2.h)/2), net->w, net->h);
    //resize_network(net, sized.w, sized.h);


    qDebug()<<"net n"<<":"<<net->layers[net->n-2].classes;

    float *X = sized.data;
    time=what_time_is_it_now();
    network_predict(net, X);
    printf("%s: Predicted in %f seconds.\n", input, what_time_is_it_now()-time);
    int nboxes = 0;
    detection *dets = get_network_boxes(net, im.w, im.h, thresh, hier_thresh, 0, 1, &nboxes);

    //printf("%d\n", nboxes);
    //if (nms) do_nms_obj(boxes, probs, l.w*l.h*l.n, l.classes, nms);
    if (nms) do_nms_sort(dets, nboxes, l.classes, nms);
    draw_detections(im, dets, nboxes, thresh, names, alphabet, l.classes);
    free_detections(dets, nboxes);
    if(outfile){
        save_image(im, outfile);
    }
    else{
        save_image(im, "predictions");
#ifdef OPENCV
        //  make_window("predictions", 512, 512, 0);
        //  show_image(im, "predictions", 0);
#endif
    }

    Mat m_mat = image_to_mat(im);
    free_image(im);
    free_image(sized);

    return m_mat;
}
