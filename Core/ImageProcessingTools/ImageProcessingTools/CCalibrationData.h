#pragma once
#include "Basic.h"

namespace CalibrationTool
{
	class IMAGE_PROC_TOOLS_API CCalibrationData
	{
	private:
		std::vector<cv::Point> m_ImagePoints;
		std::vector<cv::Point3d> m_CameraPoints;
		std::vector<cv::Point3d> m_WorldPoints;
		
		cv::Mat m_IntrinsicMatrix;
		cv::Mat m_ExtrinsicMatrix;
		cv::Mat m_TransformMatrix;

	public:
		CCalibrationData();
		~CCalibrationData();
	};
}


