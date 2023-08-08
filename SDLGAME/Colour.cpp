#include "Colour.h"

const SDL_PixelFormat* Colour::m_Format = nullptr;
void Colour::InitFormat(const SDL_PixelFormat* format)
{
	Colour::m_Format = format;
}

Colour::Colour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_Colour = SDL_MapRGBA(m_Format, r, g, b, a);
}

void Colour::SetColour(Uint32 colour)
{
	m_Colour = colour;
}

void Colour::SetRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	m_Colour = SDL_MapRGBA(m_Format, r, g, b, a);
}

void Colour::SetRed(Uint8 r){
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	SetRGBA(r, green, blue, alpha);
}
void Colour::SetGreen(Uint8 g){
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	SetRGBA(red, g, blue, alpha);
}
void Colour::SetBlue(Uint8 b){
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	SetRGBA(red, green, b, alpha);
}
void Colour::SetAlpha(Uint8 a){
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	SetRGBA(red, green, blue, a);
}

Uint8 Colour::GetRed() const{
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	return red;
}
Uint8 Colour::GetGreen() const{
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	return green;
}
Uint8 Colour::GetBlue() const{
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	return blue;
}
Uint8 Colour::GetAlpha() const{
	Uint8 red;
	Uint8 blue;
	Uint8 green;
	Uint8 alpha;
	SDL_GetRGBA(m_Colour, m_Format, &red, &blue, &green, &alpha);
	return alpha;
}
