#pragma once
#include "Basic.h"

//Calibration Data;
#include "CCalibrationData.h"

//Blobs ฐüทร 
#include "CBlobData.h"
#include "CBlobDetection.h"

namespace CalibrationTool
{
	class IMAGE_PROC_TOOLS_API CCalibrationTool
	{
	private:
		Blob::CBlobDetection* m_pBlobDetection = nullptr;

	public:
		CCalibrationTool();
		~CCalibrationTool();

		bool Calibration(cv::Mat& Image, std::vector<cv::Point3d>& ObjectPoint, std::vector<CCalibrationData>& CalibrationDatas);

	private:
		bool MappingPoints(std::vector<Blob::CBlobData>& Blobs, std::vector<cv::Point3d>& ObjectPoint, std::vector<CCalibrationData>& CalibrationDatas);
	};
}


