#include "../mycaffe/mycaffe.h"
#include "iostream"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

#ifdef _DEBUG
#pragma comment(lib, "E:/slns/caffe/Build/x64/Debug/mycaffed")
#else
#pragma comment(lib, "E:/slns/caffe/Build/x64/Release/mycaffe")
#endif

int main() {
	CCaffeCfr cfr("lenet.prototxt", "lenet_iter_10000.caffemodel", "mean.binaryproto", "labels.txt");

	Mat img;
	
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j < 16; ++j) {
			string s = format("img_num/%d_%04d.jpg", i, j);
			img = ~imread(s);
			cout << s << ": " << cfr.cfr(img) << "\n";
		}
	}
	
	return 0;
}
