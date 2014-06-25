#include "LaplacianOperator.h"

LaplacianOperator::LaplacianOperator():kernelSize(3){

}

LaplacianOperator::~LaplacianOperator(){

}

int LaplacianOperator::process(Mat & m, bool isGaussianBlurUsed){
	if(!isGaussianBlurUsed){
		GaussianBlur( m, m, Size(3,3), 0, 0, BORDER_DEFAULT );
	}

	Mat m_gray;
	cvtColor(m,m_gray,CV_RGB2GRAY);
	
	Mat dst, abs_dst;
	
	int ddepth = CV_16S;
	int scale = 1;
	int delta = 0;
	
	Laplacian(m_gray, dst, ddepth, kernelSize, scale, delta, BORDER_DEFAULT);
	convertScaleAbs( dst, abs_dst );

	m = abs_dst;

	return 0;
}

void LaplacianOperator::show(Mat m, string name){
	namedWindow(name, CV_WINDOW_AUTOSIZE );
	imshow(name,m);
	waitKey();
	return;
}

void LaplacianOperator::setKernelSize(int _kernelSize){
	kernelSize = _kernelSize;
}

int LaplacianOperator::getKernelSize(){
	return kernelSize;
}