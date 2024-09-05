#pragma once
#define IMAGE_PROC_TOOLS_EXPORTS

#ifdef IMAGE_PROC_TOOLS_EXPORTS
#define IMAGE_PROC_TOOLS_API __declspec(dllexport)
#else
#define IMAGE_PROC_TOOLS_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"