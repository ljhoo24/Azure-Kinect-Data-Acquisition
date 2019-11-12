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

	for (register int i = 0; i < m_DataSet.size(); i++)
	{
		string str("test");
		str.append(to_string(i + 1));
		str.append(".obj");
		
		fst.open(str);

		k4a::image rs;
		rs = m_DataSet[i];

		int16_t* data = (int16_t*)rs.get_buffer();
		int height = rs.get_height_pixels(), width = rs.get_width_pixels();

		for (register int j = 0; j < height * width; j++)
		{
			int16_t x, y, z;

			x = data[3 * j + 0];
			y = data[3 * j + 1];
			z = data[3 * j + 2];

			fst << "v " << x << " " << y << " " << z << endl;
		}

		fst.close();
	}
}
