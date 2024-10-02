#include "pch.h"
#include "CCalibrationTool.h"

using namespace std;
using namespace cv;
using namespace CalibrationTool;
using namespace Blob;

CalibrationTool::CCalibrationTool::CCalibrationTool()
{
	m_pBlobDetection = new CBlobDetection();
}

CalibrationTool::CCalibrationTool::~CCalibrationTool()
{
	delete m_pBlobDetection;
	m_pBlobDetection = nullptr;
}

bool CalibrationTool::CCalibrationTool::Calibration(cv::Mat& Image, std::vector<cv::Point3d>& ObjectPoint ,std::vector<CCalibrationData>& CalibrationDatas)
{
	if (Image.empty()) return false;

	if (ObjectPoint.empty()) return false;
	
	if (!CalibrationDatas.empty()) CalibrationDatas.clear();

	vector<CBlobData> Blobs;
	if (!m_pBlobDetection->BlobDetected(Image, Blobs)) return false;

	if(!MappingPoints(Blobs, ObjectPoint, CalibrationDatas)) return false;
	
	return true;
}

bool CalibrationTool::CCalibrationTool::MappingPoints(vector<CBlobData>& Blobs, std::vector<Point3d>& ObjectPoint, std::vector<CCalibrationData>& CalibrationDatas)
{
	if(Blobs.empty() || ObjectPoint.empty()) return false;

	if (!CalibrationDatas.empty()) CalibrationDatas.clear();

	for(int Index = 0 ; Index < Blobs.size(); ++Index)
	{
		/*CCalibrationData CalibrationData(Blobs[Index].GetCenterPoint(), Point3d(0, 0, 0), ObjectPoint[Index]);
		CalibrationDatas.push_back(CalibrationData);*/
	}
}

