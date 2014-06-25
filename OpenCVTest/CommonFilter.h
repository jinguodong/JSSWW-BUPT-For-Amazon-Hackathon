#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class CommonFilter{
public:
	CommonFilter();
	~CommonFilter();
	
	int process(Mat & src, Mat kernel, Mat & dst);
	void show(Mat m, string name);
	
	void setAllOnesKernel(Mat & kern, int size);

	void setAnchor(int a,int b);
	Point getAnchor();
	void setDelta(double d);
	double getDelta();
	void setDdepth(int depth);
	int getDdepth();

private:
	// The position of the anchor relative to its kernel.
	Point anchor;// (-1,-1) by default

	//A value to be added to each pixel during the convolution
	double delta;// 0 by default

	//The depth of dst.
	int ddepth; // -1 by default(the same as src)
};