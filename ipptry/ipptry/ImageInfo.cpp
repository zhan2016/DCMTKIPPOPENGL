#include "ImageInfo.h"

ImageInfo::ImageInfo()
{

}
Uint32* ImageInfo::DoLut()
{

	if (this->RawpixelData == NULL)
	{
		return NULL;
	}

	double k = 65535 / 255;
	int index = 0;

	for (int i = 0; i < this->columns; i++)
	{
		for (int j = 0; j < this->rows; j++)
		{
			Uint16 pixel = this->RawpixelData[index++];
		}
	}
}