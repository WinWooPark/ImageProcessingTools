#pragma once
#include "Basic.h"

namespace CalibrationTool 
{
	class IMAGE_PROC_TOOLS_API CFov
	{
	private:
		cv::Mat m_FovImage;
		cv::Rect m_FovRect;
		cv::Size m_FovSize;
	public:
		CFov();
		~CFov();

		cv::Rect GetFovRect() {return m_FovRect;}
		cv::Size GetFovSize() { return m_FovSize; }

		bool CreateFov(cv::Mat& Image , cv::Rect FovRect);
	};
}


