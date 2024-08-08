#include "pch.h"
#include "CFov.h"

CalibrationTool::CFov::CFov()
{
}

CalibrationTool::CFov::~CFov()
{
	if (!m_FovImage.empty()) m_FovImage.release();
}

bool CalibrationTool::CFov::CreateFov(cv::Mat& Image, cv::Rect FovRect)
{
	if (Image.empty()) return false;

	if (FovRect.empty()) return false;

	if (!m_FovImage.empty()) m_FovImage.release();

	m_FovRect = FovRect;

	m_FovSize.height = m_FovRect.height;
	m_FovSize.width = m_FovRect.width;

	m_FovImage = Image(FovRect);
}
