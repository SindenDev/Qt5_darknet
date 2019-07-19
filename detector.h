#ifndef DETECTOR_H
#define DETECTOR_H

#include "darknet.h"

void goodbye();
void train_detector(char *datacfg, char *cfgfile, char *weightfile, int *gpus, int ngpus, int clear);
void print_detector_detections(FILE **fps, char *id, detection *dets, int total, int classes, int w, int h);

#endif // DETECTOR_H
