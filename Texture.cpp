#include "Include\Texture.hpp"


Texture::Texture(const TCHAR* FILENAME)
{
	gh = ::LoadGraph(FILENAME);
}


Texture::~Texture()
{
	printfDx("%d Çè¡ÇµÇ‹Ç∑");
	if(gh != -1)	DeleteGraph(gh);
}


void Texture::LoadGraph(const TCHAR * FILENAME)
{
	if (gh != -1 || gh != 0)	DeleteGraph(gh);

	gh = ::LoadGraph(FILENAME);
}


int Texture::GetHandle(){
	return gh;
}


void Texture::Draw(int x, int y, int TransFlag) 
{
	::DrawGraph(x, y, gh, TransFlag);
}


void Texture::DrawRota(int x, int y, double ExRate, double Angle, int TransFlag, int TurnFlag)
{
	::DrawRotaGraph(x, y, ExRate, Angle, gh, TransFlag, TurnFlag);
}

// EOF