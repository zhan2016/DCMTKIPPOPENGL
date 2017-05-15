#ifndef Image_Info_H
#define Image_Info_H
#include "dcmtk/config/osconfig.h" 
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmdata/dcistrmf.h"

class ImageInfo
{
public:
	double widthCenter;
	double widthWidth;
	Uint16 bitsAllocated;
	Uint16 bitsStored;
	Uint16 rows; //height
	Uint16 columns; //width
	Uint16 issigned;
	OFString rescaleslope;
	OFString rescaleIntercept;
	bool IsSigned;
	const Uint16* RawpixelData;
	const Uint16* bmppixelData;
	ImageInfo();
	~ImageInfo();
public:
	/*
	do a simple lut just for DR unsinged 16 bit
	*/
	Uint32* DoLut();
/*public:
	void setWidthCenter(double wc);
	void setwidthWidth(double ww);
	void setbitsAllocated(short bitsA);
	void setbitsStored(short bitsS);
	void setSigned(bool issigned);*/


};

#endif