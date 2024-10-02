#pragma once
#include "Basic.h"

typedef std::vector<cv::Point> vecPoints;

namespace Blob
{
	class IMAGE_PROC_TOOLS_API CBlobData
	{
	private:
		cv::Point2d m_Center;

		double m_Area;
		
		cv::Rect m_boundingBox;
		
		vecPoints m_Contours;

	public:
		CBlobData(cv::Point2d Point, cv::Rect BoundingBox, double Area);
		~CBlobData();

		cv::Point2d GetCenterPoint() { return m_Center; }
		void SetCenterPoint(cv::Point2d Center) { m_Center = Center;}

		double GetArea() {return m_Area;}
		void SetArea(double Area) { m_Area = Area; }

		cv::Rect GetBoundingBox() { return m_boundingBox; }
		void SetBoundingBox(cv::Rect Box) { m_boundingBox = Box; }

		int GetWidth() { return m_boundingBox.width;}
		int GetHeight() { return m_boundingBox.height; }
		
		vecPoints* GetContours() { return &m_Contours; }

		CBlobData* operator =(const CBlobData& rhs);
	};
}