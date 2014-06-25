#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class LaplacianOperator{
public:
	LaplacianOperator();
	~LaplacianOperator();

	int process(Mat & m,bool isGaussianBlurUsed);
	void show(Mat m, string name);

	void setKernelSize(int _kernelSize);
	int getKernelSize();
private:
	//The kernel size of the Sobel operator to be applied internally.
	int kernelSize; // 3 by default
};