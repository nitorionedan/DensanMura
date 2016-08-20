#include "Include\Image.hpp"


Image::Image()	: count(0){}


Image::~Image()
{
	if (count != 0)	for (auto& gh : this->gh) DeleteGraph(gh);
}


int Image::Load(const TCHAR * FNAME, std::string key)
{
	this->key.push_back(key);

	gh.push_back( LoadGraph(FNAME) );

	count++;
	
	return 0;
}


void Image::List()
{
	if (count == 0)	return;

	int c = 0;

	printfDx("Imageキーリスト：\n");

	for (auto key : this->key)
	{
		std::string list = key + "\n";
		printfDx(list.c_str());
		c++;
	}

	printfDx("合計%dファイル", c);
}


int Image::Draw(const int& X, const int& Y, std::string key, int TransFlag)
{
	if (count == 0)	return -1;

	const int& Hdl = GetHandle(key);

	return DrawGraph(X, Y, Hdl, TransFlag);
}


int Image::DrawRota(const int& X, const int& Y, const double& ExRate, const double& Angle, std::string key, int TransFlag, int TurnFlag)
{
	if (count == 0)	return -1;

	const int& Hdl = GetHandle(key);

	return DrawRotaGraph(X, Y, ExRate, Angle, Hdl, TransFlag, TurnFlag);

	return 0;
}


int Image::DrawRect(const int & DestX, const int & DestY, const int & SrcX, const int & SrcY, const int & Width, const int & Height, std::string key, const int & TransFlag, const int & TurnFlag)
{
	if (count == 0)	return -1;

	const int& Hdl = GetHandle(key);

	return DrawRectGraph(DestX, DestY, SrcX, SrcY, Width, Height, Hdl, TransFlag, TurnFlag);
}


int Image::GetSize(std::string key, int * width, int * height)
{
	if (count == 0)	return -1;

	const int& Hdl = GetHandle(key);

	return GetGraphSize(Hdl, width, height);;
}


int Image::GetHandle(std::string key)
{
	for (int i = 0; i != this->key.size(); ++i)
	{
		if (this->key[i] != key)	continue;
		return this->gh[i];
	}

	std::string warning = key + "というキーが見当たりません。";

	MessageBox(NULL, warning.c_str(), "NOT FOUND", MB_OK);
	
	return -1;
}

// EOF