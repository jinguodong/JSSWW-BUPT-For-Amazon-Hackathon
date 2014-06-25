#include "CannyEdgeDetector.h"

CannyEdgeDetector::CannyEdgeDetector():ratio(3),kernelSize(3),lowThreshold(10){

}

CannyEdgeDetector::~CannyEdgeDetector(){

}

int CannyEdgeDetector::process(Mat & m){
	Mat m_gray,detected_edges,dst;
	dst.create(m.size(),m.type());
	cvtColor(m,m_gray,CV_BGR2GRAY);
	blur( m_gray, detected_edges, Size(3,3) );
	Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernelSize );
	dst = Scalar::all(0);
	m.copyTo( dst, detected_edges);
	m = dst;

	return 0;
}

void CannyEdgeDetector::show(Mat m, string name){
	namedWindow(name, CV_WINDOW_AUTOSIZE );
	imshow(name,m);
	waitKey();
	return;
}

void CannyEdgeDetector::setRatio(int _ratio){
	ratio = _ratio;
}

int CannyEdgeDetector::getRatio(){
	return ratio;
}

void CannyEdgeDetector::setKernelSize(int _kernelSize){
	kernelSize = _kernelSize;
}

int CannyEdgeDetector::getKernelSize(){
	return kernelSize;
}

void CannyEdgeDetector::setlowThreshold(int _lowThreshold){
	lowThreshold = _lowThreshold;
}

int CannyEdgeDetector::getlowThreshold(){
	return lowThreshold;
}