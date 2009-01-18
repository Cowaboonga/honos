#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <string>
#include <exception>
#include "UIBase.h"

namespace ui{

struct SVertex
{
	SVertex() {}
	SVertex(float x, float y, float z, float tu, float tv):pos(x,y,z), u(tu), v(tv){}
	D3DXVECTOR3 pos;	
	float u;
	float v;	
};

/**
* Esta clase implementa la estructura m�s simple de la biblioteca gr�fica, un bitmap. Encapsula funcionalidad m�nima para poder pintar en pantalla un objeto 2D simple.
* Se trata de uno de los mayores puntos de cohesi�n de la biblioteca con el motor de render, y por lo tanto candidata a la reimplementaci�n si este varia.
*/
class Bitmap{

public:	
	/**
	* Constructor de Bitmap. Construye un bitmap de tama�o, en pixels, igual al de la textura que recibe como par�metro.
	* @param pD3Ddevice puntero a un dispositivo D3D9.
	* @param pwcFilename puntero a una cadena de caracteres que representa la ubicaci�n del archivo de textura.
	* @param iXpos posici�n de pintado X, en pixels.
	* @param iYpos posici�n de pintado Y, en pixels.
	*/
	Bitmap(IDirect3DDevice9* pD3Ddevice, const WCHAR* pcwFilename, int iXpos = 0, int iYpos = 0) throw(std::exception);
	
	/**
	* Constructor de Bitmap.
	* @param pD3Ddevice puntero a un dispositivo D3D9.
	* @param pwcFilename puntero a una cadena de caracteres que representa la ubicaci�n del archivo de textura.
	* @param iXpos posici�n de pintado X, en pixels.
	* @param iYpos posici�n de pintado Y, en pixels.
	* @param iWidth ancho en pixels del bitmap.
	* @param iHeight alto en pixels del bitmap.
	*/
	Bitmap(IDirect3DDevice9* pD3Ddevice,int iXpos, int iYpos, int iWidth, int iHeight, const WCHAR* wcpFilename) throw(std::exception);

	void drawBitmapHere(int iXpos, int iYpos);

	/**
	* Dibuja el bitmap.
	*/
	void draw();

	/**
	* Devuelve el ancho del bitmap en pixels.
	* @return ancho del bitmap, en pixels.
	*/
	int getWidth() const;

	/**
	* Devuelve el largo del bitmap en pixels.
	* @return largo del bitmap, en pixels.
	*/
	int getHeight() const;

	/**
	* Devuelve la posici�n X del bitmap en pixels.
	* @return posici�n X del bitmap en pixels.
	*/
	int getXPosition() const;

	/**
	* Devuelve la posici�n Y del bitmap en pixels.
	* @return posici�n Y del bitmap en pixels.
	*/
	int getYPosition() const;

	/**
	* Modifica la posici�n X de pintado.
	* @param iXpos posici�n X, en pixels.
	*/
	void setXPosition(int iXpos);

	/**
	* Modifica la posici�n Y de pintado.
	* @param iYpos posici�n Y, en pixels.
	*/
	void setYPosition(int iYpos);

	/**
	* Destructor.
	*/
	~Bitmap(void);

private:	
	int m_iXpos;
	int m_iYpos;
	int m_iWidth;
	int m_iHeight;

	std::wstring m_wsFileName;
	SVertex m_vertex;
	IDirect3DDevice9* m_pD3Ddevice;
	IDirect3DTexture9* m_pTexture;
	IDirect3DVertexDeclaration9* m_pVertexDeclarations;
	IDirect3DVertexBuffer9* m_pVertexBuffer;

};
}
#endif