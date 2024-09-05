#pragma once

#define SAFETY_DELETE(p) ( if(p != nullptr){ delete p; p = nullptr;})
	
