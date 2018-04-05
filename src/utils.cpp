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

using namespace std;
using namespace cv;

void CheckOpenNIError( XnStatus result, string status )
{
	if( result != XN_STATUS_OK )
		cerr << status << " Error: " << xnGetStatusString( result ) << endl;
}

int Capture(){
  	XnStatus result = XN_STATUS_OK;
  	xn::DepthMetaData depthMD;
  	xn::ImageMetaData imageMD;

  	IplImage*  imgDepth16u=cvCreateImage(cvSize(640,480),IPL_DEPTH_16U,1);
  	IplImage* imgRGB8u=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,3);
  	IplImage*  depthShow=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,1);
  	IplImage* imageShow=cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,3);
  	//namedWindow("depth",1);
  	//namedWindow("image",1);
  	char key=0;

  	xn::Context context;
  	result = context.Init();
  	CheckOpenNIError( result, "initialize context" );

  	xn::DepthGenerator depthGenerator;
  	result = depthGenerator.Create( context );
  	CheckOpenNIError( result, "Create depth generator" );
  	xn::ImageGenerator imageGenerator;
  	result = imageGenerator.Create( context );
  	CheckOpenNIError( result, "Create image generator" );

  	XnMapOutputMode mapMode;
  	mapMode.nXRes = 640;
  	mapMode.nYRes = 480;
  	mapMode.nFPS = 30;
  	result = depthGenerator.SetMapOutputMode( mapMode );
  	result = imageGenerator.SetMapOutputMode( mapMode );

  	depthGenerator.GetAlternativeViewPointCap().SetViewPoint( imageGenerator );

  	result = context.StartGeneratingAll();
  	result = context.WaitNoneUpdateAll();

    int index = 1;
    stringstream ss;
    string rgb_dir = "./data/rgb_png/";
    string depth_dir = "./data/depth_png/";
    string png = ".png";
    string rgb_path = "";
    string depth_path = "";

  	while( (key!=27) && !(result = context.WaitNoneUpdateAll( ))  )
  	{
  		depthGenerator.GetMetaData(depthMD);
  		imageGenerator.GetMetaData(imageMD);

  		memcpy(imgDepth16u->imageData,depthMD.Data(),640*480*2);
  		cvConvertScale(imgDepth16u,depthShow,255/4096.0,0);
  		memcpy(imgRGB8u->imageData,imageMD.Data(),640*480*3);
  		cvCvtColor(imgRGB8u,imageShow,CV_RGB2BGR);
  		//cvShowImage("depth", depthShow);
  		//cvShowImage("image",imageShow);
  		key=cvWaitKey(20);

  		Mat rgb = cvarrToMat(imageShow);
  		Mat depth = cvarrToMat(depthShow);
  		imshow("rgb", rgb);
  		imshow("depth", depth);

      ss<<rgb_dir<<index<<png;
      ss>>rgb_path;
      imwrite(rgb_path, rgb);
      ss.clear();
      ss<<depth_dir<<index<<png;
      ss>>depth_path;
      imwrite(depth_path, depth);
      ss.clear();
      cout<<"saving image"<<endl;
      index++;
  	}

    cout<<"saved "<<index<<" pics"<<endl;

  	//destroy
  	//cvDestroyWindow("depth");
  	//cvDestroyWindow("image");
  	cvReleaseImage(&imgDepth16u);
  	cvReleaseImage(&imgRGB8u);
  	cvReleaseImage(&depthShow);
  	cvReleaseImage(&imageShow);
  	context.StopGeneratingAll();
  	context.Release();
  	return 0;
}
