#include "azure_kinect.h"



azure_kinect::azure_kinect()
{
	Initialize_Device();
}


azure_kinect::~azure_kinect()
{
	Finalize_Device();
}


void azure_kinect::Initialize_Device()
{
	// device connection check

	uint32_t count = k4a::device::get_installed_count();
	if (count == 0)
	{
		cout << "No k4a devices attached!" << endl;
		return ;
	}
	
	// initailize device (open)
	m_Device = k4a::device::open(0);

	// set config for device
	m_Config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
	m_Config.camera_fps = K4A_FRAMES_PER_SECOND_15;
	m_Config.depth_mode = K4A_DEPTH_MODE_WFOV_UNBINNED;
	m_Config.color_format = K4A_IMAGE_FORMAT_COLOR_BGRA32;
	m_Config.color_resolution = K4A_COLOR_RESOLUTION_1080P;

	// device start based on config
	m_Device.start_cameras(&m_Config);

	deviceCalibration();
		
}


void azure_kinect::Finalize_Device()
{
	m_Device.stop_cameras();
	m_Device.close();
}


k4a::image azure_kinect::getPointCloud()
{
	k4a::capture capture;

	m_Device.get_capture(&capture);

	k4a::image depthImage = capture.get_depth_image();

	k4a::transformation transform(m_Calibration);

	k4a::image rt = transform.depth_image_to_point_cloud(depthImage, k4a_calibration_type_t::K4A_CALIBRATION_TYPE_DEPTH);
	
	return rt;
}


void azure_kinect::deviceCalibration()
{
	// mode is set in initialize function
	m_Calibration =	m_Device.get_calibration(K4A_DEPTH_MODE_WFOV_UNBINNED, K4A_COLOR_RESOLUTION_1080P);

}
