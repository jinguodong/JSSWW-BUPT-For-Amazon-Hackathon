#include "CommonFilter.h"

CommonFilter::CommonFilter():anchor(Point(-1,-1)),delta(0),ddepth(-1){

}

CommonFilter::~CommonFilter(){

}

int CommonFilter::process(Mat & src, Mat kernel, Mat & dst){
	filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
	return 0;
}

void CommonFilter::show(Mat m,string name){
	namedWindow(name, CV_WINDOW_AUTOSIZE );
	imshow(name,m);
	waitKey();
	return;
}

void CommonFilter::setAllOnesKernel(Mat & kern, int size){
	assert(size >= 1);
	kern = Mat::ones(size, size, CV_32F )/ (float)(size*size);
	return;
}

void CommonFilter::setAnchor(int a,int b){
	anchor = Point(a,b);
	return;
}

Point CommonFilter::getAnchor(){
	return anchor;
}

void CommonFilter::setDelta(double d){
	delta = d;
}

double CommonFilter::getDelta(){
	return delta;
}

void CommonFilter::setDdepth(int depth){
	ddepth = depth;
}

int CommonFilter::getDdepth(){
	return ddepth;
}