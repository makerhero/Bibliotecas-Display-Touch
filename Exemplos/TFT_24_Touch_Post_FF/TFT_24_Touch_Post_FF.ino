// Programa : Teste Display Touch Arduino - Touchscreen
// Autor : FILIPEFLOP

#include <UTFT.h>
#include "TouchScreen.h"

// Relacao de fontes utilizadas
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
extern uint8_t Grotesk24x48[];
extern uint8_t GroteskBold16x32[];
extern uint8_t OCR_A_Extended_M[];
extern uint8_t arial_bold[];

#define YP A1
#define XM A2
#define YM 7
#define XP 6

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

#define MINPRESSURE 10
#define MAXPRESSURE 1000

// Armazena o estado dos botões
int valor_botao1 = 0;
int valor_botao2 = 0;
int valor_botao3 = 0;
int valor_botao4 = 0;

UTFT myGLCD(UNO_24, A2, A1, A3, A4);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup()
{
  Serial.begin(115200);
  pinMode(A0, OUTPUT); // for the UNO_SHIELD_1IN1
  digitalWrite(A0, HIGH);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  myGLCD.InitLCD();
  myGLCD.clrScr();

  // Inicio - Texto e botoes
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.setBackColor (VGA_BLACK);

  myGLCD.setFont(GroteskBold16x32);
  myGLCD.setColor (VGA_YELLOW);
  myGLCD.print("Led Amarelo", 15, 23);
  myGLCD.setColor (VGA_WHITE);
  myGLCD.drawRoundRect (255, 15, 312, 60);
  myGLCD.drawRoundRect (5, 15, 312, 60);
  myGLCD.setColor(VGA_GRAY);
  myGLCD.print("OFF", 260, 23);

  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.print("Led Verde", 15, 73);
  myGLCD.setColor (VGA_WHITE);
  myGLCD.drawRoundRect (255, 65, 312, 110);
  myGLCD.drawRoundRect (5, 65, 312, 110);
  myGLCD.setColor(VGA_GRAY);
  myGLCD.print("OFF", 260, 73);

  myGLCD.setColor(VGA_BLUE);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.print("Led Azul", 15, 123);
  myGLCD.setColor (VGA_WHITE);
  myGLCD.drawRoundRect (255, 115, 312, 160);
  myGLCD.drawRoundRect (5, 115, 312, 160);
  myGLCD.setColor(VGA_GRAY);
  myGLCD.print("OFF", 260, 123);

  myGLCD.setColor(VGA_RED);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.print("Led Vermelho", 15, 173);
  myGLCD.setColor (VGA_WHITE);
  myGLCD.drawRoundRect (255, 165, 312, 210);
  myGLCD.drawRoundRect (5, 165, 312, 210);
  myGLCD.setColor(VGA_GRAY);
  myGLCD.print("OFF", 260, 173);

  Serial.println("Aguardando touch...");
}

void loop(void)
{
  delay(50);
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
  {
    int dim_tela_x = myGLCD.getDisplayXSize();
    int dim_tela_y = myGLCD.getDisplayYSize();
    p.x = dim_tela_x - (map(p.x, TS_MINX, TS_MAXX, dim_tela_x, 0));
    p.y = dim_tela_y - (map(p.y, TS_MINY, TS_MAXY, dim_tela_y, 0));
    // Envia coordenadas e pressao para o Serial Monitor
    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tPressao = "); Serial.println(p.z);

    if (p.y > 200)
    {
      //Testa botao LED Amarelo
      if (p.x > 235 & p.x < 295)
      {
        if (valor_botao1 == 0)
        {
          //myGLCD.fillRoundRect (255, 15, 312, 60);
          myGLCD.setColor(VGA_YELLOW);
          myGLCD.fillRoundRect(256, 16, 311 , 59);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.setBackColor(VGA_TRANSPARENT);
          myGLCD.print("ON", 266, 23);
          delay(100);
          valor_botao1 = !valor_botao1;
        }
        else
        {
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(256, 16, 311 , 59);
          myGLCD.setColor(VGA_GRAY);
          //myGLCD.setBackColor(VGA_YELLOW);
          myGLCD.print("OFF", 260, 23);
          delay(100);
          valor_botao1 = !valor_botao1;
        }
      }

      // Testa botao LED Verde
      else if (p.x > 170 & p.x < 230)
      {
        // myGLCD.fillRoundRect (255, 65, 312, 110);
        if (valor_botao2 == 0)
        {
          myGLCD.setColor(VGA_LIME);
          myGLCD.fillRoundRect(256, 66, 311 , 109);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.setBackColor(VGA_TRANSPARENT);
          //myGLCD.setBackColor(VGA_SILVER);
          myGLCD.print("ON", 266, 73);
          delay(100);
          valor_botao2 = !valor_botao2;
        }
        else
        {
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(256, 66, 311 , 109);
          myGLCD.setColor(VGA_GRAY);
          //myGLCD.setBackColor(VGA_LIME);
          myGLCD.print("OFF", 260, 73);
          delay(100);
          valor_botao2 = !valor_botao2;
        }

      }

      // Testa botao LED Azul
      else if (p.x > 105 & p.x < 165)
      {
        // myGLCD.fillRoundRect (255, 115, 312, 160);
        if (valor_botao3 == 0)
        {
          myGLCD.setColor(VGA_BLUE);
          myGLCD.fillRoundRect(256, 116, 311 , 159);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.setBackColor(VGA_TRANSPARENT);
          myGLCD.print("ON", 266, 123);
          delay(100);
          valor_botao3 = !valor_botao3;
        }
        else
        {
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(256, 116, 311 , 159);
          myGLCD.setColor(VGA_GRAY);
          //myGLCD.setBackColor(VGA_BLUE);
          myGLCD.print("OFF", 260, 123);
          delay(100);
          valor_botao3 = !valor_botao3;
        }
      }

      // Testa botao LED Vermelho
      else if (p.x > 40 & p.x < 100)
      {
        // myGLCD.fillRoundRect (255, 165, 312, 210);
        if (valor_botao4 == 0)
        {
          myGLCD.setColor(VGA_RED);
          myGLCD.fillRoundRect(256, 166, 311 , 209);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.setBackColor(VGA_TRANSPARENT);
          myGLCD.print("ON", 266, 173);
          delay(100);
          valor_botao4 = !valor_botao4;
        }
        else
        {
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(256, 166, 311 , 209);
          myGLCD.setColor(VGA_GRAY);
          //myGLCD.setBackColor(VGA_RED);
          myGLCD.print("OFF", 260, 173);
          delay(100);
          valor_botao4 = !valor_botao4;
        }
      }
    }
  }
}
