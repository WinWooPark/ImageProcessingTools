#pragma once
#include "Basic.h"

namespace CalibrationTool
{
	class IMAGE_PROC_TOOLS_API CCalibrationData
	{
	private:
		cv::Point m_ImagePoint;
		cv::Point3d m_WorldPoint;

	public:
		CCalibrationData();
		~CCalibrationData();
	};
}


