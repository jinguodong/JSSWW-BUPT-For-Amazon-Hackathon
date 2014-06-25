#include "NoiseGenerator.h"

NoiseGenerator::NoiseGenerator():delta(20.0){

}

NoiseGenerator::~NoiseGenerator(){

}

int NoiseGenerator::addNoise(Mat & src){
	IplImage *srcImage,*noise,*dstImage;
	srcImage = &(IplImage(src));
	noise = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	dstImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
	CvRNG rng = cvRNG(-1);
	cvRandArr(&rng,noise,CV_RAND_NORMAL,cvScalarAll(0),cvScalarAll(delta));
	cvAdd(srcImage,noise,dstImage);
	src = Mat(dstImage);
	return 0;
}

void NoiseGenerator::show(Mat m,string name){
	namedWindow(name, CV_WINDOW_AUTOSIZE );
	imshow(name,m);
	waitKey();
	return;
}

void NoiseGenerator::setDelta(float _delta){
	delta = _delta;
}

float NoiseGenerator::getDelta(){
	return delta;
}