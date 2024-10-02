#pragma once
#include "Basic.h"
#include "CBlobData.h"

namespace Blob
{
	class IMAGE_PROC_TOOLS_API CBlobDetection
	{
	private:


	public:
		CBlobDetection();
		~CBlobDetection();

		bool BlobDetected(cv::Mat& Image, std::vector<Blob::CBlobData>& Blobs);

	private:
		bool PreProecssing(cv::Mat& Image, cv::Mat& PreImage);
	};
}


