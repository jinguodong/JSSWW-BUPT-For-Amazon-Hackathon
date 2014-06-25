#include "BorderProcessor.h"

BorderProcessor::BorderProcessor():percent(0.05),top(0),bottom(0),left(0),right(0){

}

BorderProcessor::~BorderProcessor(){

}

int BorderProcessor::addBorderByConstant(Mat & m, Scalar color){
	Mat temp;
	top = (int) (percent * m.rows);
	bottom = (int) (percent * m.rows);
	left = (int) (percent * m.cols);
	right = (int) (percent * m.cols);
	copyMakeBorder( m, temp, top, bottom, left, right, BORDER_CONSTANT, color);
	m = temp;
	return 0;
}

int BorderProcessor::addBorderByReplicate(Mat & m){
	Mat temp;
	Scalar_<double> color = Scalar(255, 255, 255);
	top = (int) (percent * m.rows);
	bottom = (int) (percent * m.rows);
	left = (int) (percent * m.cols);
	right = (int) (percent * m.cols);
	copyMakeBorder( m, temp, top, bottom, left, right, BORDER_REPLICATE, color);
	m = temp;
	return 0;
}

int BorderProcessor::delBorder(Mat & m){
	Mat temp;
	Size_<int> s(m.cols-left-right,m.rows-top-bottom);
	Point2f p = Point2f(m.cols/2, m.rows/2);
	getRectSubPix(m, s, p, temp);
	m = temp;
	return 0;
}

void BorderProcessor::show(Mat m, string name){
	namedWindow(name, CV_WINDOW_AUTOSIZE );
	imshow(name,m);
	waitKey();
	return;
}

void BorderProcessor::setPercent(double _percent){
	percent = _percent;
}

double BorderProcessor::getPercent(){
	return percent;
}