#pragma once
#include "Basic.h"
#include "CBlobData.h"

#include <chrono>

#define _USE_CONCURRENT_TASK_
#ifdef _USE_CONCURRENT_TASK_
#include <concurrent_vector.h>
#include <ppl.h>
#endif


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


