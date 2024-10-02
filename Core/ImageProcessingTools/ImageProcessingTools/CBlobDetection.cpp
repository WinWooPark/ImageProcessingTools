#include "pch.h"
#include "CBlobDetection.h"

using namespace std;
using namespace cv;
using namespace Blob;

Blob::CBlobDetection::CBlobDetection()
{
}

Blob::CBlobDetection::~CBlobDetection()
{
}

bool Blob::CBlobDetection::BlobDetected(cv::Mat& Image, std::vector<CBlobData>& Blobs)
{
	if (Image.empty()) return false;

	if (!Blobs.empty()) Blobs.clear();

	Mat PreImage;
	if (!PreProecssing(Image, PreImage)) return false;

	if (PreImage.empty()) return false;

	Mat hierarchy;
	vector<vector<cv::Point>> Contours;

	cv::findContours(PreImage, Contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

	if (Contours.empty()) return false;

	vector<vector<cv::Point>>::iterator iter = Contours.begin();

	for (; iter != Contours.end(); ++iter)
	{
		cv::Moments m = cv::moments(*iter);

		if (m.m00 != 0)
		{
			double cx = m.m10 / m.m00; // x 좌표
			double cy = m.m01 / m.m00; // y 좌표

			//무게중심점
			cv::Point2d point(cx, cy);
			
			//영역 넓이
			double Area = contourArea(*iter);
			
			//외접 사각형
			cv::Rect boundingBox = cv::boundingRect(*iter);

			CBlobData BlobData(point, boundingBox, Area);

			//컨투어 좌표 복사
			auto contours = BlobData.GetContours();
			contours->assign(iter->begin(), iter->end());

			Blobs.push_back(BlobData);
		}
	}

	return true;
}

bool Blob::CBlobDetection::PreProecssing(cv::Mat& Image, cv::Mat& PreImage)
{
	if (Image.empty()) return false;

	Mat Filtered;

	switch (Image.channels())
	{
	case 1: //Gray
		break;

	case 3: //Color
		cv::cvtColor(Image, Filtered, COLOR_BGR2GRAY);
		break;

	default:
		break;
	}

	/*cv::bilateralFilter(Image, Filter,)*/

	double Val = cv::threshold(Filtered, PreImage, 128, 255, THRESH_OTSU);

	return true;
}