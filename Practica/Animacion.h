#pragma once
using namespace System::Drawing;
enum Estados{Ninguna, Izquierda, Derecha};
class Animacion
{
private:
	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Estados estado;
public:
	Animacion()
	{
		this->x = 0;
		this->y = 0;
		this->ancho = 800;
		this->alto = 600;
		this->indiceX = 0;
		this->indiceY = 0;
		this->estado = Ninguna;
	}

	~Animacion(){}

	void setEstado(Estados estado) { this->estado = estado; }
	void setindiceX(int indiceX) { this->indiceX = indiceX; }
	void setindiceY(int indiceY) { this->indiceY = indiceY; }

	void dibujarAnimacion(BufferedGraphics^ buffer, Bitmap^ bmp)
	{
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bmp, aumento, area, GraphicsUnit::Pixel);
	}

	void cambiarAnimacion(BufferedGraphics^ buffer, Bitmap^ bmp)
	{
		switch (estado)
		{
		case Ninguna:
			//Elegir imagen
			if (indiceY == 0 || indiceY == 1 || indiceY == 7)
			{
				if (indiceX >= 0 && indiceX < 4)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY++; }
			}
			if (indiceY == 2)
			{
				if (indiceX >= 0 && indiceX < 2)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY = 7;}
			}
			if (indiceY == 8)
			{
				if (indiceX >= 0 && indiceX < 2)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY = 0; }
			}
			break;

		case Izquierda:
			if (indiceY == 2)
			{
				if (indiceX >= 1 && indiceX < 4)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY++; }
			}
			if (indiceY == 3 || indiceY == 4 || indiceY == 5)
			{
				if (indiceX >= 0 && indiceX < 4)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY++; }
			}
			if (indiceY == 6)
			{
				if (indiceX >= 0 && indiceX < 3)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY = 7; this->estado = Ninguna; }
			}
			break;
		case Derecha:
			if (indiceY == 11)
			{
				if (indiceX >= 0 && indiceX < 4)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY++; }
			}
			if (indiceY == 12 || indiceY == 13 || indiceY == 14)
			{
				if (indiceX >= 0 && indiceX < 4)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY++; }
			}
			if (indiceY == 15)
			{
				if (indiceX == 0)
				{
					indiceX++;
				}
				else { indiceX = 0; indiceY = 7; this->estado = Ninguna;}
			}
			break;
		}

		dibujarAnimacion(buffer, bmp);
	}


};
