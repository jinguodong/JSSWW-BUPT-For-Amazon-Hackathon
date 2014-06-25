#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class ScharrOperator{
public:
	ScharrOperator();
	~ScharrOperator();

	int process(Mat & m,bool isGaussianBlurUsed);
	void show(Mat m, string name);

private:

};