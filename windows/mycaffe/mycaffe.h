#pragma once
#include <string>
#include <opencv2/opencv.hpp>
using std::string;

class CCaffeCfr {
public: //构造函数
	_declspec(dllexport) CCaffeCfr();
	_declspec(dllexport) CCaffeCfr(string deploy_prototxt, string network_caffemodel, string mean_binaryproto, string labels_txt);
	_declspec(dllexport) void reset(string deploy_prototxt, string network_caffemodel, string mean_binaryproto, string labels_txt);

	_declspec(dllexport) ~CCaffeCfr();

public: //分类函数
	_declspec(dllexport) string cfr(CvMat _img) const;
};
