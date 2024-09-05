#pragma once
#include "Basic.h"

namespace Blob
{
	class IMAGE_PROC_TOOLS_API CBlobData
	{
	private:
		cv::Point2d m_Center;

	public:
		CBlobData(cv::Point2d Point);
		~CBlobData();

		cv::Point2d GetCenterPoint() { return m_Center; }

		cv::Point2d SetCenterPoint(cv::Point2d Center) { m_Center = Center;}
	};
}