#pragma once
#include <string>
#include <opencv2/opencv.hpp>
#include <memory>	// shared_ptr
using std::string;

#ifdef MYCFAFFE_EXPORTS
#define MYCAFFE_API _declspec(dllexport)
#else
#define MYCAFFE_API _declspec(dllimport)
#endif

class CCaffeCfr {
public: //构造函数
	MYCAFFE_API CCaffeCfr();
	MYCAFFE_API CCaffeCfr(string deploy_prototxt, string network_caffemodel, string mean_binaryproto, string labels_txt);
	MYCAFFE_API void reset(string deploy_prototxt, string network_caffemodel, string mean_binaryproto, string labels_txt);

	MYCAFFE_API ~CCaffeCfr();

public: //分类函数
	//opencv2、opencv3的Mat不一样，为了mycaffe.dll能兼容cv2、cv3，使用CvMat作为接口
	MYCAFFE_API string cfr(CvMat _img) const;

private:
	class impl;
	std::shared_ptr<impl> pImpl;
};
