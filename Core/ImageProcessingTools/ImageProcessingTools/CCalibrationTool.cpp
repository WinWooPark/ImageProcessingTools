#include "pch.h"
#include "CCalibrationTool.h"

using namespace std;
using namespace cv;
using namespace CalibrationTool;
using namespace Blob;

CalibrationTool::CCalibrationTool::CCalibrationTool()
{
	m_ExtrinsicMatrix.create(3, 3, CV_64F);

	m_IntrinsicMatrix.create(3, 3, CV_64F);

	if (m_pBlobDetection == nullptr)
		m_pBlobDetection = new CBlobDetection();
}

CalibrationTool::CCalibrationTool::~CCalibrationTool()
{
	if (!m_ExtrinsicMatrix.empty())
		m_ExtrinsicMatrix.release();

	if (!m_IntrinsicMatrix.empty())
		m_IntrinsicMatrix.release();

	if (m_pBlobDetection != nullptr) 
	{
		delete m_pBlobDetection;
		m_pBlobDetection = nullptr;
	}
}

bool CalibrationTool::CCalibrationTool::Calibration(cv::Mat& Image, std::vector<cv::Point3d> World)
{
	Mat PreImage;
	
	vector<CBlobData> Datas;

	if (!m_pBlobDetection->BlobDetected(Image, Datas)) return false;

	if (Datas.empty()) return false;

	if (Datas.size() != World.size()) return false;

	return true;
}

