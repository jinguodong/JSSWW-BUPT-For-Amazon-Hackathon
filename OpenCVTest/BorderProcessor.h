#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class BorderProcessor{
public:
	BorderProcessor();
	~BorderProcessor();
	
	int addBorderByConstant(Mat & m, Scalar color);
	int addBorderByReplicate(Mat & m);
	int delBorder(Mat & m);

	void show(Mat m, string name);

	void setPercent(double _percent);
	double getPercent();
private:
	// Define how many percentage pixels used for padding
	double percent;//0.05 by default

	//pixels that added to the origin Mat
	int top;
	int bottom;
	int left;
	int right;
};