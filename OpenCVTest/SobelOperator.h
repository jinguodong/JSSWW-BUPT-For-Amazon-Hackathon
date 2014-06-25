#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class SobelOperator{
public:
	SobelOperator();
	~SobelOperator();

	int process(Mat & m,bool isGaussianBlurUsed);
	void show(Mat m, string name);

private:

};