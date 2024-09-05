#pragma once
#include "Basic.h"

//Blobs ฐüทร 
#include "CBlobData.h"
#include "CBlobDetection.h"

namespace CalibrationTool
{
	class IMAGE_PROC_TOOLS_API CCalibrationTool
	{
	private:
		cv::Mat m_IntrinsicMatrix;
		cv::Mat m_ExtrinsicMatrix;

		Blob::CBlobDetection* m_pBlobDetection = nullptr;

	public:
		CCalibrationTool();
		~CCalibrationTool();

		cv::Mat GetIntrinsicMatrix() { return m_IntrinsicMatrix.clone(); }
		cv::Mat GetExtrinsicMatrix() { return m_ExtrinsicMatrix.clone(); }

		bool Calibration(cv::Mat &Image, std::vector<cv::Point3d> World);

		bool MappingPoint();
	};
}


