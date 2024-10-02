#include "pch.h"
#include "CBlobData.h"

using namespace Blob;

Blob::CBlobData::CBlobData(cv::Point2d Point, cv::Rect BoundingBox, double Area)
{
	m_Center = Point;
	m_boundingBox = BoundingBox;
	m_Area = Area;
}

Blob::CBlobData::~CBlobData(){}

CBlobData* Blob::CBlobData::operator=(const CBlobData& rhs)
{
	this->m_Area = rhs.m_Area;
	this->m_Center = rhs.m_Center;
	
	return this;
}
