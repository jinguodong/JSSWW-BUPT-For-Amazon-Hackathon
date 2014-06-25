#include "opencv.hpp"
#include <string>

using namespace std;
using namespace cv;

class NoiseGenerator{
public:
	NoiseGenerator();
	~NoiseGenerator();
	
	int addNoise(Mat & src);
	void show(Mat m, string name);
	
	void setDelta(float _delta);
	float getDelta();

private:
	// delta
	float delta; // 20 by default
};