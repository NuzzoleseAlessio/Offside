#include <iostream>
#include "include/raylib.h"
#include "prototipi.hpp"
// #define PI 3.141

int main(int argc, char** argv) 
{
	SetConfigFlags(FLAG_MSAA_4X_HINT); //antialiasing
	SetConfigFlags(FLAG_VSYNC_HINT); //vsync
	Color SKINPINK = GetColor(0xbda599FF); //color pelle
	Color TURIN = GetColor(0x7b1b02FF);	//color granata
	Color CYAN = GetColor(0x00FFFFFF); //ciano
	Color VERDECAMPO = GetColor(0x36b54eFF); //verde scuro
	
	const int screenWidth = 1920;
	const int screenHeight = 1080;
	
	int modalita=0;
	
	// Crea la finestra
	InitWindow(screenWidth, screenHeight, "Offside!");
	Texture2D palla = LoadTexture("immagini/campo/pallina.png");
	Texture2D rete = LoadTexture("immagini/campo/retina.png");
	
	Image reteF = GetTextureData(rete); 
	ImageFlipHorizontal(&reteF);
	Texture2D rete2 = LoadTextureFromImage(reteF);
	
	const int numeroTeste = 14;
	const char* percorsi[] = {
		"messi1.png",
		"ronaldo1.png",
		"singo1.png",
		"tomori.png",
		"ibra1.png",
		"sciapò1.png",
		"grave1.png",
		"benzema1.png",
		"mhango1.png",
		"vaandevordt.png",
		"haaland1.png",
		"chatriz1.png",
		"torre1.png",
		"aivalotis.png"
	};
	
	const Color pelle[] = {
		SKINPINK,
		SKINPINK,
		BROWN,
		BROWN,
		SKINPINK,
		SKINPINK,
		BROWN,
		SKINPINK,
		BROWN,
		SKINPINK,
		SKINPINK,
		SKINPINK,
		SKINPINK,
		SKINPINK
	};
	
	const string nomiGiocatori[] = {
		"Messi",
		"Ronaldo",
		"Singo",
		"Tomori",
		"Ibrahimovic",
		"Cassano",
		"Gravenberch",
		"Benzema",
		"Mhango",
		"Vandevoordt",
		"Haaland",
		"Chabot",
		"Ernesto",
		"G.O.A.T"
	};
	
	Texture2D teste[numeroTeste];
	
	const int numeroMaglie = 19;
	const Maglia maglia[]{
		{
			RED,
			BLACK
		},
		
		{
			BLUE,
			BLACK
		},
		
		{
			WHITE,
			BLACK
		},
		
		{
			ORANGE,
			ORANGE
		},
		
		{
			SKYBLUE,
			SKYBLUE
		},
		
		{
			DARKGREEN,
			BLACK
		},
		
		{
			RED,
			BLUE
		},
		
		{
			TURIN,
			TURIN
		},
		
		{
			PURPLE,
			PURPLE
		},
		
		{
			YELLOW,
			BLUE
		},
		
		{
			CYAN,
			CYAN
		},
		
		{
			RAYWHITE,
			RAYWHITE
		},
		
		{
			RED,
			RAYWHITE
		},
		
		{
			YELLOW,
			BLACK
		},
		
		{
			RED,
			RED
		},
		
		{
			BLUE,
			BLUE
		},
		
		{
			BLUE,
			WHITE
		},
		
		{
			PINK,
			BLACK
		},
		
		{
			YELLOW,
			RED
		},
	
	};
	
	for (int i = 0; i < numeroTeste; i++)
		teste[i] = LoadTexture(FormatText("immagini/teste di calciatori/%s", percorsi[i]));
	
		
	// Definizione variabili
	float x1 = 300;
	float x2 = 1450;
	
	float y1 = 150;
	float y2 = 150;
	
	float x3 = 300;
	float x4 = 1450;
	
	float y3 = 450;
	float y4 = 450;
	
	int t1, t2;
	
		
	// Stato del gioco
	
	// 0: selezione personaggio
	// 1: partita
	// 2: post gol
	// 3: selezione modalità
	
	int statoGioco = 3;
	ClearBackground(RAYWHITE);
	
	//modalità
	
	// 0: selezione modalità
	// 1: 1vs1
	// 2: 2vs2
	
	testoCentrato("Seleziona la modalità", 960, 540, 21);
	testoCentrato("Premi O per la modalità 1vs1", 960, 700, 28);
	testoCentrato("Premi P per la modalità 2vs2", 960, 800, 28);

	do{
		if(IsKeyPressed[KEY_O]){
		modalita=1;
	}
	else if(IsKeyPressed[KEY_P]){
		modalita=2;
	}
	} while(modalita != 1 || modalita != 2);

	
	statoGioco = 0;
	
	int personaggio1 = 0;
	int personaggio2 = 0;
	int maglia1 = 0;
	int maglia2 = 0;
	
	int p1 = 0, p2 = 0;
	Vector2 posizionePalla = { screenWidth / 2 - palla.width / 2, screenHeight / 2 - palla.height / 2 };
	Vector2 direzionePalla = { 1, 1 };
	float velocitaPalla = 1;
	int haSegnato = 0;
	
	// Game Loop
	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		switch (statoGioco)
		{
			case 0:
				ShowCursor();
				if (IsKeyPressed(KEY_ENTER))
					statoGioco = 1;
				
				if (IsKeyPressed(KEY_A))
					personaggio1--;
				if (IsKeyPressed(KEY_D))
					personaggio1++;
				
				if (personaggio1 < 0)
					personaggio1 = numeroTeste - 1;
				if (personaggio1 >= numeroTeste)
					personaggio1 = 0;
					
				if (IsKeyPressed(KEY_LEFT))
					personaggio2--;
				if (IsKeyPressed(KEY_RIGHT))
					personaggio2++;
				
				if (personaggio2 < 0)
					personaggio2 = numeroTeste - 1;
				if (personaggio2 >= numeroTeste)
					personaggio2 = 0;
					
				if (IsKeyPressed(KEY_W))
					maglia1--;
				if (IsKeyPressed(KEY_S))
					maglia1++;
				
				if (maglia1 < 0)
					maglia1 = numeroMaglie - 1;
				if (maglia1 >= numeroMaglie)
					maglia1 = 0;
					
				if (IsKeyPressed(KEY_UP))
					maglia2--;
				if (IsKeyPressed(KEY_DOWN))
					maglia2++;
				
				if (maglia2 < 0)
					maglia2 = numeroMaglie - 1;
				if (maglia2 >= numeroMaglie)
					maglia2 = 0;
				break;
			case 1:
				HideCursor();
				//x1
				
				if (IsKeyDown(KEY_D) && x1 < screenWidth / 2 - 279)
					x1 += 10;
				if (IsKeyDown(KEY_A) && x1 > 200)
					x1 -= 10;
					
				//y1
				
				if (IsKeyDown(KEY_W) && y1 > - 80)
					y1 -= 10;
				if (IsKeyDown(KEY_S) && y1 < screenHeight - 250)
					y1 += 10;
				
				//x2
				
				if (IsKeyDown(KEY_RIGHT) && x2 < screenWidth - 400 )
					x2 += 10;
				if (IsKeyDown(KEY_LEFT) && x2 > screenWidth / 2 + 78)
					x2 -= 10;
				
				//y2
				
				if (IsKeyDown(KEY_UP) && y2 > - 80)
					y2 -= 10;
				if (IsKeyDown(KEY_DOWN) && y2 < screenHeight - 250)
					y2 += 10;
					
				//muovi la palla
				posizionePalla.x += 5 * direzionePalla.x * velocitaPalla;
				posizionePalla.y += 5 * direzionePalla.y * velocitaPalla;
				
				if (posizionePalla.x < 0 || posizionePalla.x > screenWidth - 75)
					direzionePalla.x = -direzionePalla.x;
				if (posizionePalla.y < 0 || posizionePalla.y > screenHeight - 75)
					direzionePalla.y = -direzionePalla.y;
						
				// Giocatore 1
				if (CheckCollisionRecs(Rectangle { x1 + 100, y1 + 75, 10, 250}, Rectangle { posizionePalla.x, posizionePalla.y, 69, 69}) && direzionePalla.x == -1)
				{
					direzionePalla.x = 1;
					if (velocitaPalla<5){
						
					velocitaPalla += 0.1;
					
					}
					t1++;
				}
				
				// Giocatore 2
				if (CheckCollisionRecs(Rectangle { x2 + 100, y2 + 75, 10, 250}, Rectangle { posizionePalla.x, posizionePalla.y, 69, 69}) && direzionePalla.x == 1 )
				{
					direzionePalla.x = -1;
					if (velocitaPalla<5){
						
						velocitaPalla += 0.1;
						
					}
				
					t2++;	
				}
				
				// Controllo gol
				// Prima porta
				if (CheckCollisionRecs(Rectangle { posizionePalla.x, posizionePalla.y, 69, 69}, Rectangle {rete.width, (float)screenHeight / 2 - (float)rete.height / 2 - 80, 10, rete.height}) && direzionePalla.x == -1)
				{
					p2++;
					velocitaPalla = 1;
					posizionePalla = Vector2 { screenWidth / 2 - palla.width / 2, screenHeight / 2 - palla.height / 2 };
					statoGioco = 2;
					haSegnato = 2;
				}
				// Seconda porta
				if (CheckCollisionRecs(Rectangle { posizionePalla.x, posizionePalla.y, 69, 69}, Rectangle {(float)screenWidth - rete.width - 10, (float)screenHeight / 2 - (float)rete.height / 2 - 80, 10, (float)rete.height}) && direzionePalla.x == 1)
				{
					p1++;
					velocitaPalla = 1;
					posizionePalla = Vector2 { screenWidth / 2 - palla.width / 2, screenHeight / 2 - palla.height / 2 };
					statoGioco = 2;
					haSegnato = 1;
				}
				
				if (p1 == 3 || p2 == 3)
					statoGioco = 4;
				break;
			case 2:
				ShowCursor();
				if (IsKeyPressed(KEY_ENTER))
					statoGioco = 1;
				break;
		}
		if (IsKeyPressed(KEY_F))
			ToggleFullscreen();
		
		BeginDrawing();
		// Inizio disegno
		
			ClearBackground(GREEN);
		 	
			
				 //campo
		
			DrawCircle(screenWidth / 2, screenHeight / 2, 120, RAYWHITE);
			DrawCircle(screenWidth / 2, screenHeight / 2, 100, GREEN);
			DrawCircle(screenWidth / 2, screenHeight / 2, 20, RAYWHITE);
			DrawRectangle(screenWidth / 2 - 10, 0, 20, screenHeight, RAYWHITE);
		 
			//giocatori
			disegnaGiocatore(x1, y1, teste[personaggio1], maglia[maglia1], pelle[personaggio1], nomiGiocatori[personaggio1]);
			disegnaGiocatore(x2, y2, teste[personaggio2], maglia[maglia2], pelle[personaggio2], nomiGiocatori[personaggio2]);
		
			//Pallone
			DrawTextureV(palla, posizionePalla, WHITE);
		
			//Reti
			DrawTexture(rete, 10, screenHeight / 2 - rete.height / 2 - 80, WHITE);
			DrawTexture(rete2, screenWidth - rete.width - 10, screenHeight / 2.0 - rete.height / 2.0 - 80, WHITE);
		
		
			//SegnaPunti
			DrawRectangleRounded(Rectangle { screenWidth / 2 - 100, 20, 200, 100 }, 0.5, 10, DARKGRAY);
			DrawRectangleRounded(Rectangle { screenWidth / 2 - 85, 32.5, 75, 75}, 0.5, 10, BLACK);
			DrawRectangleRounded(Rectangle { screenWidth / 2 + 10, 32.5, 75, 75}, 0.5, 10, BLACK);
			DrawText(TextFormat("%d", p1), screenWidth / 2 - 47.5 - (MeasureText(TextFormat("%d", p1), 50) / 2), 45, 50, RED);
			DrawText(TextFormat("%d", p2), screenWidth / 2 + 47.5 - (MeasureText(TextFormat("%d", p2), 50) / 2), 45, 50, RED);

			DrawFPS(20, 20);
	
			if (statoGioco == 0)
			{
				testoCentrato("Premi F per mettere a schermo intero", 1620, 20, 30);
				testoCentrato("Premi INVIO per iniziare", screenWidth / 2, 200, 100);
				testoCentrato("A-D: Selezione giocatore 1", screenWidth / 2, 400, 50);
				testoCentrato("W-S: Selezione maglia 1", screenWidth / 2, 450, 40);
				testoCentrato("LT-RT: Selezione giocatore 2", screenWidth / 2, 550, 50);
				testoCentrato("UP-DN: Selezione maglia 2", screenWidth / 2, 600, 40);
			}
			
			if (statoGioco == 2)
			{
				testoCentrato("GOAL!", screenWidth / 2, 200, 100);
				testoCentrato(TextFormat("%s ha segnato!", nomiGiocatori[(haSegnato == 1) ? personaggio1 : personaggio2].c_str()), screenWidth / 2, 300, 50);
				testoCentrato("Premi INVIO per continuare", screenWidth / 2, 450, 50);
			}
			
			if (statoGioco == 4){
				testoCentrato("MATCH OVER!", screenWidth / 2, 200, 100);
				testoCentrato(TextFormat("%s ha vinto!", nomiGiocatori[(haSegnato == 1) ? personaggio1 : personaggio2].c_str()), screenWidth / 2, 350, 120);
				testoCentrato("Premi ESC per uscire", screenWidth / 2, 500, 50);
				testoCentrato("Premi INVIO per continuare", screenWidth / 2, 550, 50);
					if(IsKeyPressed(KEY_ENTER)){
						
						statoGioco=0;
						p1=0;
						p2=0;
						x1 = 300;
						x2 = 1450;
 						y1 = 300; 
						y2 = 300;
						
					}
					
			}
		
				 	
			 
		 	
			
		//Fine disegno
		EndDrawing();
	}
	// Chiudi la finestra
	UnloadTexture(palla);
	UnloadTexture(rete);
	UnloadTexture(rete2);
	UnloadImage(reteF);
	for (int i = 0; i < numeroTeste; i++)
		UnloadTexture(teste[i]);
	CloseWindow();
	return 0;
}
