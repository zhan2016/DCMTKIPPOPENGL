#ifndef Dicom_Image_H
#define Dicom_Image_
#include "ImageInfo.h"
#include "dcmtk/dcmimgle/dcmimage.h"
//class ImageInfo; //��ǰ�������ã� c++�﷨
class DicomImageInfotj
{
private:
	DcmMetaInfo metainfo; //meta info 
	char* dicomfilename;
	
	DicomImage* dicomimage;
public:DcmFileFormat  Image; // dicom image info
DcmDataset *dataset; //dicom dataset
DicomImageInfotj(char* filename);
ImageInfo* imageinfo;
bool  InitImageInfo();

};


#endif