#pragma once
#include <SDL.h>
class Colour
{
private:
	Uint32 m_Colour;

public:
	static const SDL_PixelFormat* m_Format;
	static void InitFormat(const SDL_PixelFormat* format);

	Colour(Uint32 colour): m_Colour(colour){}
	Colour() : m_Colour(0) {};
	Colour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	//Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

	inline bool operator==(const Colour& c) { return m_Colour == c.GetPixelColour(); }
	inline bool operator!=(const Colour& c) { return !(*this == c); }
	inline Uint32 GetPixelColour() const { return m_Colour; }

	void SetColour(Uint32 colour);
	void SetRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	//void SetRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void SetRed(Uint8 r);
	void SetGreen(Uint8 g);
	void SetBlue(Uint8 b);
	void SetAlpha(Uint8 a);

	Uint8 GetRed() const;
	Uint8 GetGreen() const;
	Uint8 GetBlue() const;
	Uint8 GetAlpha() const;

};

