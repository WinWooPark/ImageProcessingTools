#include "pch.h"
#include "CCalibrationTool.h"

using namespace std;
using namespace cv;
using namespace CalibrationTool;

CalibrationTool::CCalibrationTool::CCalibrationTool()
{
	m_ExtrinsicMatrix.create(3, 3, CV_64F);

	m_IntrinsicMatrix.create(3, 3, CV_64F);
}

CalibrationTool::CCalibrationTool::~CCalibrationTool()
{
	if (!m_ExtrinsicMatrix.empty())
		m_ExtrinsicMatrix.release();

	if (!m_IntrinsicMatrix.empty())
		m_IntrinsicMatrix.release();
}

bool CalibrationTool::CCalibrationTool::Calibration(cv::Mat& Image)
{
	Mat PreImage;
	if (!PreProecssing(Image, PreImage)) return false;

	if (PreImage.empty()) return false;



	return true;
}

bool CalibrationTool::CCalibrationTool::Calibration(vector<CalibrationTool::CFov>& Fovs)
{
	if (Fovs.empty()) return false;

	Mat Image = MargeFovImage(Fovs);

	if (Image.empty()) return false;

	Calibration(Image);

	return true;
}

bool CalibrationTool::CCalibrationTool::PreProecssing(Mat& Image, Mat& PreImage)
{
	if (Image.empty()) return false;

	Mat Filtered, thresholded;
	
	/*cv::bilateralFilter(Image, Filter,)*/

	double Val = cv::threshold(Filtered, PreImage, 128, 255, THRESH_OTSU);

	return true;
}

cv::Mat CalibrationTool::CCalibrationTool::MargeFovImage(std::vector<CalibrationTool::CFov>& Fovs)
{
	int FovCount = Fovs.size();
	
	int MargeWidth = FovCount * Fovs.front().GetFovSize().width;
	int MargeHeight = FovCount * Fovs.front().GetFovSize().height;

	Mat MargeImage;

	MargeImage.create(MargeWidth, MargeHeight, CV_8UC1);

	std::vector<CalibrationTool::CFov>::iterator iter = Fovs.begin();

	for (iter; iter != Fovs.end(); ++iter) 
	{
		
	}

	return cv::Mat();
}
