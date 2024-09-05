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
			double cx = m.m10 / m.m00; // x ÁÂÇ¥
			double cy = m.m01 / m.m00; // y ÁÂÇ¥

			CBlobData BlobData(cv::Point2d(cx, cy));
			Blobs.push_back(BlobData);
		}
	}

	auto SortRule = [&](cv::Point2d Left, cv::Point2d Right)->bool
		{
			if (Left.x < Right.x && Left.y < Right.y) 
				return true;

			else 
				return false;
		};

	std::sort(Blobs.begin(), Blobs.end(), SortRule);

	return true;
}

bool Blob::CBlobDetection::PreProecssing(cv::Mat& Image, cv::Mat& PreImage)
{
	if (Image.empty()) return false;

	Mat Filtered;

	/*cv::bilateralFilter(Image, Filter,)*/

	double Val = cv::threshold(Filtered, PreImage, 128, 255, THRESH_OTSU);

	return true;
}