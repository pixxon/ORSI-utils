#include "include/bmp_image.h"

#include "bmp_structures.h"

BMPImage::BMPImage(const uint32_t Width, const uint32_t Height):
	mData(new BMPBitData(Width, Height)),
	mInfo(new BMPInfoHeader(Width, Height)),
	mFile(new BMPFileHeader(Width, Height))
{}

BMPImage::~BMPImage()
{}

void BMPImage::setColor(const uint32_t Col, const uint32_t Row, const Color aColor)
{
	mData->set(Col, Row, aColor);
}

std::ostream& operator<<(std::ostream& Out, const BMPImage& Data)
{
	Out << *(Data.mFile) << *(Data.mInfo) << *(Data.mData);
	return Out;
}
