#include "pch.h"
#include "CImageConversionTool.h"

cv::Mat CImageConversionTool::ConversionUCHARToMat(UCHAR* Byte, int Height, int Width)
{
    return cv::Mat();
}

UCHAR* CImageConversionTool::ConversionMatToUCHAR(cv::Mat* Image)
{
    UCHAR* byteImage = nullptr;

    if (Image == nullptr || Image->empty()) return nullptr;

    int Size = Image->cols * Image->rows * Image->channels();
    
    byteImage = new UCHAR[Size];
    
    memcpy(byteImage, Image->data, Size);

    if (byteImage == nullptr) return nullptr;

    return std::move(byteImage);
}
