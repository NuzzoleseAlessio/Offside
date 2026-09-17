#include <iostream>
#include <string>
#include "include/raylib.h"
using namespace std;

struct Maglia {
	Color c1;
	Color c2;
};

void disegnaGiocatore(float x, float y, Texture2D testa, Maglia coloreMaglia, Color colorePelle, string nome);
void testoCentrato(const char* text, float x, float y, int size);

