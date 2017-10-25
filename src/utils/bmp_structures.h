#pragma once

#include <vector>
#include <ostream>
#include <algorithm>

template <typename T>
std::ostream& writeBinary(std::ostream& Out, T Data)
{
	Out.write(reinterpret_cast<const char*>(&Data), sizeof(T));
}

struct BMPFileHeader
{
	uint16_t mSignature = ('M' << 8) + 'B';
	uint32_t mFilesize;
	uint16_t mReserved1 = 0;
	uint16_t mReserved2 = 0;
	uint32_t mStartPosition = 54;
	
	BMPFileHeader(const uint32_t Width, const uint32_t Height):
		mFilesize((Width + Width % 4) * Height + 54)
	{}
	
	friend std::ostream& operator<<(std::ostream& Out, const BMPFileHeader& Data)
	{
		writeBinary(Out, Data.mSignature);
		writeBinary(Out, Data.mFilesize);
		writeBinary(Out, Data.mReserved1);
		writeBinary(Out, Data.mReserved2);
		writeBinary(Out, Data.mStartPosition);
		return Out;
	}
};

struct BMPInfoHeader
{
	uint32_t mHeaderSize = 40;
	uint32_t mWidth;
	uint32_t mHeight;
	uint16_t mDisplayMode = 1;
	uint16_t mDepth = 24;
	uint32_t mCompresion = 0;
	uint32_t mBitmapSize;
	std::array<uint8_t, 16> mReserved{{0}};
	
	BMPInfoHeader(const uint32_t Width, const uint32_t Height):
		mWidth(Width),
		mHeight(Height),
		mBitmapSize((Width + Width % 4) * Height)
	{}
	
	friend std::ostream& operator<<(std::ostream& Out, const BMPInfoHeader& Data)
	{
		writeBinary(Out, Data.mHeaderSize);
		writeBinary(Out, Data.mWidth);
		writeBinary(Out, Data.mHeight);
		writeBinary(Out, Data.mDisplayMode);
		writeBinary(Out, Data.mDepth);
		writeBinary(Out, Data.mCompresion);
		writeBinary(Out, Data.mBitmapSize);
		for(const uint8_t Element : Data.mReserved)
		{
			writeBinary(Out, Element);
		}
		return Out;
	}
};

struct BMPBitData
{
	BMPBitData(const uint32_t Width, const uint32_t Height):
		mData(Height, std::vector<Color>(Width, Color(0, 0, 0))),
		mWidth(Width),
		mHeight(Height)
	{
	}
	
	void set(const uint32_t Col, const uint32_t Row, const Color aColor)
	{
		mData[Row][Col] = aColor;
	}
	
	Color get(const uint32_t Col, const uint32_t Row)
	{
		return mData[Row][Col];
	}
	
	friend std::ostream& operator<<(std::ostream& Out, const BMPBitData& aData)
	{
		const uint8_t Padding = (aData.mWidth * 3) % 4;
		
		std::for_each(aData.mData.rbegin(), aData.mData.rend(), [&](const std::vector<Color>& Data)
		{
			std::for_each(Data.begin(), Data.end(), [&](const Color Element)
			{
				writeBinary(Out, Element.mBlue);
				writeBinary(Out, Element.mGreen);
				writeBinary(Out, Element.mRed);
			});
			
			for(uint8_t Index = 0; Index < Padding; Index++)
			{
				const uint8_t Null = 0;
				writeBinary(Out, Null);
			}
		});
	}
	
private:
	std::vector<std::vector<Color>> mData;
	uint32_t mWidth;
	uint32_t mHeight;
};
