#pragma once
#include <k4a/k4a.h>

class azure_kinect
{
public:
	azure_kinect();
	~azure_kinect();
private:
	void Initialize_Device();
	void Finalize_Device();
};

