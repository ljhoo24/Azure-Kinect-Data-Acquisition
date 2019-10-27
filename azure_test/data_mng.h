#pragma once
#include "defines.h"

class data_mng
{
public:
	data_mng();
	~data_mng();
	void setData(k4a::image data);
	int getDataCount();
	void saveDataSet();
private:
	vector<k4a::image> m_DataSet;
};

