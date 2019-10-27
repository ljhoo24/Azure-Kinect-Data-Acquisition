#include "data_mng.h"



data_mng::data_mng()
{
}


data_mng::~data_mng()
{
}


void data_mng::setData(k4a::image data)
{
	m_DataSet.push_back(data);
}


int data_mng::getDataCount()
{
	return m_DataSet.size();
}


void data_mng::saveDataSet()
{
	ofstream fst;

	fst.open("test.obj");

	k4a::image rs;
	rs = m_DataSet[0];

	uint8_t* data = rs.get_buffer();
	int height = rs.get_height_pixels(), width = rs.get_width_pixels();

	for (register int h = 0; h < height; h++)
	{
		for (register int w = 0; w < width; w++)
		{
			fst << data[h * width + w] << endl;
		}
	}

	fst.close();
}
