#include "Main.h"

using namespace std;
using namespace cv;
using namespace CalibrationTool;

typedef struct TestStruct 
{
	int Num;
	double dNum;
}TestStruct;

class MYclass 
{
public:
	int Num;
	double dNum;
};

int main() 
{
	CCalibrationTool* pCalibrationTool = new CCalibrationTool();

	Mat Image = imread("..\\TEST.bmp");

	vector<CCalibrationData> CalibrationDatas;
	vector<Point3d> ObjectPoint;

	for (int x = 0; x < 10; ++x) 
	{
		for (int y = 0; y < 10; ++y) 
		{
			ObjectPoint.push_back(Point3d(x * 5, y * 5, 0));
		}
	}

	if(!pCalibrationTool->Calibration(Image, ObjectPoint,CalibrationDatas)) return -1;

	return 0;
}