#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class CannyEdgeDetector{
public:
	CannyEdgeDetector();
	~CannyEdgeDetector();
	
	int process(Mat & m);
	void show(Mat m, string name);

	void setRatio(int _ratio);
	int getRatio();
	void setKernelSize(int _kernelSize);
	int getKernelSize();
	void setlowThreshold(int _lowThreshold);
	int getlowThreshold();
private:
	//Canny recommended a upper:lower ratio between 2:1 and 3:1.
	int ratio; // 3 by default

	//The kernel size of the Sobel operator to be applied internally.
	int kernelSize; // 3 by default

	// pixel gradient lowThreshold
	int lowThreshold; // 10 by default
};