/**
reference - https://docs.microsoft.com/en-us/azure/kinect-dk/build-first-app
*/

#pragma once
#include "defines.h"

class azure_kinect
{
public:
	azure_kinect();
	~azure_kinect(); 
	k4a::image getPointCloud();
private:
	void Initialize_Device();
	void deviceCalibration();
	void Finalize_Device();
	k4a::device m_Device;
	k4a_device_configuration_t m_Config;
	k4a::calibration m_Calibration;
};

