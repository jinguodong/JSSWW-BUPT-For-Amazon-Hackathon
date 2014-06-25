// OpenCVTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "opencv.hpp"
#include <string>
#include "CommonFilter.h"
#include "BorderProcessor.h"
#include "SobelOperator.h"
#include "ScharrOperator.h"
#include "LaplacianOperator.h"
#include "NoiseGenerator.h"
#include "CannyEdgeDetector.h"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	string fileName("D:\\origin_small.png");
	assert(fileName.size()!=0);
	Mat src, ret, kernel;
	src = imread(fileName);
	if(!src.data){
		return -1;
	}

	//CannyEdgeDetector
	CannyEdgeDetector cannyEdgeDetector;
	cannyEdgeDetector.process(src);
	cannyEdgeDetector.show(src,"CannyEdgeDetector");

	/*
	//NoiseGenerator
	NoiseGenerator noiseGenerator;
	noiseGenerator.setDelta(100.0);
	noiseGenerator.addNoise(src);
	noiseGenerator.show(src,"NoiseGenerator");
	*/

	/*
	//LaplacianOperator
	LaplacianOperator laplacianOperator;
	laplacianOperator.setKernelSize(9);
	laplacianOperator.process(src,false);
	//GaussianBlur( src, src, Size(7,7), 0, 0, BORDER_DEFAULT );
	laplacianOperator.show(src,"LaplacianOperator");
	*/

	/*
	//ScharrOperator
	ScharrOperator scharrOperator;
	scharrOperator.process(src,false);
	scharrOperator.show(src,"ScharrOperator");
	*/
	
	/*
	//SobelOperator
	SobelOperator sobelOperator;
	sobelOperator.process(src,false);
	sobelOperator.show(src,"SobelOperator");
	*/

	/*
	//BorderProcessor
	BorderProcessor borderProcess;
	borderProcess.addBorderByReplicate(src);
	borderProcess.setPercent(0.1);
	Scalar s = Scalar(30,30,34);
	//borderProcess.addBorderByConstant(src,s);
	borderProcess.show(src,"BorderProcessor");
	borderProcess.delBorder(src);
	borderProcess.show(src,"BorderProcessor");
	*/

	/*
	//CommonFilter
	CommonFilter filter;
	filter.setAllOnesKernel(kernel,11);
	//filter.setDelta(10);
	filter.process(src,kernel,ret);
	filter.show(ret,"CommonFilter");
	*/
	return 0; 
}

