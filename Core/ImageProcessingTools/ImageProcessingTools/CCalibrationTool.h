#pragma once
#include "Basic.h"
#include "CFov.h"

namespace CalibrationTool
{
	class IMAGE_PROC_TOOLS_API CCalibrationTool
	{
	private:
		cv::Mat m_IntrinsicMatrix;
		cv::Mat m_ExtrinsicMatrix;

	public:
		CCalibrationTool();
		~CCalibrationTool();

		cv::Mat GetIntrinsicMatrix() { return m_IntrinsicMatrix.clone(); }
		cv::Mat GetExtrinsicMatrix() { return m_ExtrinsicMatrix.clone(); }

		bool Calibration(cv::Mat &Image);

		bool Calibration(std::vector<CalibrationTool::CFov>& Fovs);

	private:
		bool PreProecssing(cv::Mat& Image, cv::Mat& PreImage);

		void BlobDetection(cv::Mat& Image);

		cv::Mat MargeFovImage(std::vector<CalibrationTool::CFov>& Fovs);
	};
}


