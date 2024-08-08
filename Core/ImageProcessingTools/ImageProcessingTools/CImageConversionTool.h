#pragma once
#include "Basic.h"

class CImageConversionTool
{
	static cv::Mat ConversionUCHARToMat(UCHAR* Byte , int Height , int Width);

	static UCHAR* ConversionMatToUCHAR(cv::Mat* Image);
};

