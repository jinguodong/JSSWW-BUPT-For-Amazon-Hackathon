#include "ScharrOperator.h"

ScharrOperator::ScharrOperator(){

}

ScharrOperator::~ScharrOperator(){

}

int ScharrOperator::process(Mat & m, bool isGaussianBlurUsed){
	if(!isGaussianBlurUsed){
		GaussianBlur( m, m, Size(3,3), 0, 0, BORDER_DEFAULT );
	}
	Mat m_gray;
	cvtColor(m,m_gray,CV_RGB2GRAY);
	
	Mat grad, grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	
	int ddepth = CV_16S;
	int scale = 1;
	int delta = 0;

	Scharr(m_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT);
	convertScaleAbs( grad_x, abs_grad_x );
	
	Scharr(m_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT);
	convertScaleAbs( grad_y, abs_grad_y );

	addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

	m = grad;

	return 0;
}

void ScharrOperator::show(Mat m, string name){
	namedWindow(name, CV_WINDOW_AUTOSIZE );
	imshow(name,m);
	waitKey();
	return;
}