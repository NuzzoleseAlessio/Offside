#include "prototipi.hpp"

void disegnaGiocatore(float x, float y, Texture2D testa, Maglia maglia, Color colorePelle, string nome){
			
		//nome
		DrawText(nome.c_str(), x + 100 - MeasureText(nome.c_str(), 30) / 2, y + 35, 30, BLACK);
		//DrawEllipse(x+100,y+230,40,40,GRAY);
		//corpo
		
		DrawRectangle(175/2 + x,200/2 + y,50/2,200/2, colorePelle); 
		//braccia
		DrawRectangle(100/2 + x,250/2 + y,100/2,25/2, colorePelle); 
		DrawRectangle(200/2 + x,250/2 + y,100/2,25/2, colorePelle);
		
		//maglia
			//busto
			DrawRectangle(175/2 + x,250/2+y,50/2,100/2, maglia.c1);
			//maniche
			DrawRectangle(140/2 + x,250/2+y,120/2,35/2, maglia.c1);
			//linee
			DrawRectangle(205/2 + x,250/2+y,15/2,100/2, maglia.c2);
			DrawRectangle(180/2 + x,250/2+y,15/2,100/2, maglia.c2);			
			
		//gambe
		
		DrawTriangle(Vector2 {260/2 + x, 475/2+y}, Vector2 {200/2 + x, 350/2+y}, Vector2 {140/2 + x, 475/2+y}, colorePelle);
		DrawTriangle(Vector2 {230/2 + x, 475/2+y}, Vector2 {200/2 + x, 400/2+y}, Vector2 {170/2 + x, 475/2+y}, GREEN);
		
		//pantaloncini
		DrawRectangle(175/2 + x, 350/2+y, 50/2, 50/2, BLACK);
		DrawTriangle(Vector2 {240/2 + x, 425/2+y}, Vector2 {200/2 + x, 350/2+y}, Vector2 {160/2 + x, 425/2+y}, BLACK);
		DrawTriangle(Vector2 {205/2 + x, 425/2+y}, Vector2 {200/2 + x, 405/2+y}, Vector2 {195/2 + x, 425/2+y}, GREEN);
		
		//scarpe
		DrawRectangle(230/2 + x, 475/2+y, 50/2, 30/2, maglia.c1);
		DrawRectangle(120/2 + x, 475/2+y, 50/2, 30/2, maglia.c1);
		
		//testa
		DrawTexture(testa, 70 + x, 70 + y, WHITE);
}

void testoCentrato(const char* text, float x, float y, int size)
{
	DrawText(text, x - MeasureText(text, size) / 2 + size / 10, y + size / 10, size, BLACK);
	DrawText(text, x - MeasureText(text, size) / 2, y, size, RAYWHITE);
}

