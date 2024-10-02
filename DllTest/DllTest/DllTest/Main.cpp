#include "Main.h"

using namespace std;
using namespace cv;
using namespace CalibrationTool;
using namespace Blob;

int main() 
{
	CCalibrationTool* pCalibrationTool = new CCalibrationTool();
	CBlobDetection* pBlobDetection = new CBlobDetection();

	Mat Image = imread("..\\TEST.bmp");
	vector<CBlobData> BlobDatas;

	pBlobDetection->BlobDetected(Image, BlobDatas);

	Mat DrawImage = Image.clone();

	vector<CBlobData>::iterator iter = BlobDatas.begin();
	for (; iter != BlobDatas.end(); ++iter) 
	{
		vector<Point>::iterator iiter = iter->GetContours()->begin();
		for (; iiter != iter->GetContours()->end(); ++iiter)
		{
			cv::circle(DrawImage, *iiter, 1, Scalar(0, 0, 255));
		}
		
	}
	//vector<CCalibrationData> CalibrationDatas;
	//vector<Point3d> ObjectPoint;

	//for (int x = 0; x < 10; ++x) 
	//{
	//	for (int y = 0; y < 10; ++y) 
	//	{
	//		ObjectPoint.push_back(Point3d(x * 5, y * 5, 0));
	//	}
	//}

	//if(!pCalibrationTool->Calibration(Image, ObjectPoint,CalibrationDatas)) return -1;

	delete pCalibrationTool;
	delete pBlobDetection;
	return 0;
}