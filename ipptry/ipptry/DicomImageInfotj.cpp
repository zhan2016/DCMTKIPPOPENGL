#include "dcmtk/config/osconfig.h"  // 引入dicom头文件
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmdata/dcistrmf.h"
#include "DicomImageInfotj.h"
#include "ImageInfo.h"
#include <stdio.h>

DicomImageInfotj::DicomImageInfotj(char* filename)
{
	dicomfilename = filename;
	if (dicomfilename == NULL)
	{
		Image = NULL;
		return;
	}
	dicomimage = new DicomImage(filename, 0,0,0);
	EI_Status somestatus = dicomimage->getStatus();
	std::cout << somestatus << std::endl;

	OFCondition status = Image.loadFile(filename);
	if (status.good())
	{
		dataset = Image.getDataset();
		OFString patientName;
		if (Image.getDataset()->findAndGetOFString(DCM_PatientName, patientName).good())
		{
			std::cout << "Patient's Name:" << patientName << std::endl;
		}
		else
		{
			std::cout << "Error: cannot access Patient's Name!" << std::endl;

		}
	}
	else
	{
		std::cout << "Error: cannot read DICOM file (" << status.text() << ")" << std::endl;
	}
}

bool DicomImageInfotj::InitImageInfo()
{
	bool isSuccess = true;
	unsigned long count;
	if (dataset == NULL)
	{
		return false;
	}
	imageinfo = new ImageInfo();
	
	if (!dataset->findAndGetFloat64(DCM_WindowCenter, imageinfo->widthCenter).good())
	{
		std::cout << "Failed to get wc"<< std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetFloat64(DCM_WindowWidth, imageinfo->widthWidth).good())
	{
		std::cout << "Failed to get ww" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetUint16(DCM_BitsAllocated,imageinfo->bitsAllocated).good())
	{
		std::cout << "Failed to get bitsAllocated" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetUint16(DCM_BitsStored, imageinfo->bitsStored).good())
	{
		std::cout << "Failed to get bitsStored" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetUint16(DCM_Rows, imageinfo->rows).good())
	{
		std::cout << "Failed to get rows" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetUint16(DCM_Columns, imageinfo->columns).good())
	{
		std::cout << "Failed to get columns" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetUint16(DCM_PixelRepresentation, imageinfo->issigned).good())
	{
		std::cout << "Failed to get issigned" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetUint16Array(DCM_PixelData, imageinfo->RawpixelData, &count).good())
	{
		std::cout << "Failed to get RawpixelData" << std::endl;
		isSuccess = false;
	}
	imageinfo->bmppixelData = (Uint16 *)dicomimage->getOutputData(0,0);
	if (!dataset->findAndGetOFString(DCM_RescaleSlope, imageinfo->rescaleslope).good())
	{
		std::cout << "Failed to get rescaleslope" << std::endl;
		isSuccess = false;
	}
	if (!dataset->findAndGetOFString(DCM_RescaleIntercept, imageinfo->rescaleIntercept).good())
	{
		std::cout << "Failed to get rescaleIntercept" << std::endl;
		isSuccess = false;
	}
	return isSuccess;

}