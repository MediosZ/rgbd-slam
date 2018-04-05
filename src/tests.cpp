#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <XnCppWrapper.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void print(){
  std::cout<<"Hello World."<<std::endl;

  XnStatus result = XN_STATUS_OK;
  xn::DepthMetaData depthMD;
  xn::ImageMetaData imageMD;

  IplImage*  imgDepth16u=cvCreateImage(cvSize(640,480),IPL_DEPTH_16U,1);
  IplImage* imgRGB8u=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,3);
  IplImage*  depthShow=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,1);
  IplImage* imageShow=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,3);

}
