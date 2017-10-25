#pragma once

#include <memory>
#include <ostream>

struct Color
{
	Color(uint8_t Red, uint8_t Green, uint8_t Blue):
		mRed(Red),
		mGreen(Green),
		mBlue(Blue)
	{}
	
	uint8_t mRed;
	uint8_t mGreen;
	uint8_t mBlue;
};

struct BMPBitData;
struct BMPInfoHeader;
struct BMPFileHeader;

struct BMPImage
{
	BMPImage(const uint32_t Width, const uint32_t Height);
	~BMPImage();
	
	void setColor(const uint32_t Col, const uint32_t Row, const Color aColor);
	friend std::ostream& operator<<(std::ostream& Out, const BMPImage& Data);
	
private:
	std::unique_ptr<BMPBitData> mData;
	std::unique_ptr<BMPInfoHeader> mInfo;
	std::unique_ptr<BMPFileHeader> mFile;
};
