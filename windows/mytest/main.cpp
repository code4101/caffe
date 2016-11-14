#include "../mycaffe/mycaffe.h"
#include "iostream"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

/*
#ifdef _DEBUG
#pragma comment(lib, "E:/slns/caffe/Build/x64/Debug/mycaffed")
#else
#pragma comment(lib, "E:/slns/caffe/Build/x64/Release/mycaffe")
#endif
*/

int main() {
	CCaffeCfr cfr("lenet.prototxt", "lenet_iter_5000.caffemodel", "mean.binaryproto", "labels.txt");

	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < 10; ++i) {
		for (int j = 1; j < 26; ++j) {
			//读取图片
			Mat img = imread(format("mynum/%d/%d_%02d.png", i, i, j));
			//转为CvMat类
			CvMat a = img;
			//获取识别结果
			string ans = cfr.cfr(a);
			//统计正确数
			if (ans[0] - '0' == i) ++cnt1;
			++cnt2;
		}
	}

	printf("正确数/总数: %d / %d ≈ %.2f%%\n", cnt1, cnt2, cnt1*100.0 / cnt2);
	
	return 0;
}
