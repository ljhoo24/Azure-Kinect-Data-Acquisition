#include "azure_kinect.h"
#include "data_mng.h"

int main()
{
	azure_kinect kinect;
	data_mng mng;
	k4a::image rs;
	bool tag = true;
	int count = 0;

	while (tag)
	{
		rs = kinect.getPointCloud();
		mng.setData(rs);
		count = mng.getDataCount();

		if (count > 29)
			tag = false;
	}

	mng.saveDataSet();
	
	return 0;
}