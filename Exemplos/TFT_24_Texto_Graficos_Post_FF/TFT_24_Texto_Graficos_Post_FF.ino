// Programa : Teste Display Touch Arduino - Texto e Graficos
// Autor : FILIPEFLOP

#include <UTFT.h>

// Relacao de fontes
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
extern uint8_t GroteskBold16x32[];
extern uint8_t arial_bold[];
extern uint8_t Grotesk24x48[];
extern uint8_t Ubuntu[];
extern uint8_t arial_normal[];

UTFT myGLCD(UNO_24, A2, A1, A3, A4);

void setup()
{
  pinMode(A0, OUTPUT); // for the UNO_SHIELD_1IN1
  digitalWrite(A0, HIGH);
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop(void)
{
  // Rotinas de teste
  Texto();
  delay(3000);
  Teste_Circulos();
  delay(3000);
  Teste_Linhas();
  delay(3000);
}

void Texto()
{
  // Preenche a tela
  myGLCD.fillScr(0, 0, 0);
  // Seleciona cor de fundo
  myGLCD.setBackColor (0, 0, 0);

  // Seleciona fonte
  myGLCD.setFont(Ubuntu);
  // Seleciona cor
  myGLCD.setColor(VGA_WHITE);
  myGLCD.print("FILIPEFLOP", 15, 20);

  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(BigFont);
  myGLCD.print("Arduino", 15, 70);

  myGLCD.setColor(VGA_BLUE);
  myGLCD.setFont(arial_bold);
  myGLCD.print("Raspberry", 15, 105);

  myGLCD.setColor(VGA_YELLOW);
  //myGLCD.setFont(SmallFont);
  myGLCD.print("Embarcados", 15, 140);

  myGLCD.setColor(VGA_AQUA);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print("1234567890", 0, 180);
}

void Teste_Circulos()
{
  //Preenche a tela com circulos amarelos
  myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(VGA_YELLOW);
  int xa = myGLCD.getDisplayXSize();
  long radius = 6;
  unsigned long start;
  int x, y, r2 = radius * 2,
      w = myGLCD.getDisplayXSize() + radius,
      h = myGLCD.getDisplayYSize() + radius;
  for (x = 0; x < w; x += r2)
  {
    for (y = 0; y < h; y += r2)
    {
      myGLCD.drawCircle(x, y, radius);
    }
  }
}

void Teste_Linhas()
{
  //Desenha varias linhas na tela, formando
  //uma grade
  int x1, y1, x2, y2,
      w = myGLCD.getDisplayXSize(),
      h = myGLCD.getDisplayYSize();
  myGLCD.fillScr(0, 0, 0);
  myGLCD.setColor(VGA_AQUA);
  x1 = y1 = 10;
  y2 = h - 10;
  for (x2 = 10; x2 < w; x2 += 20)
  {
    myGLCD.drawLine(x2, y1, x2, y2);
  }
  x2 = w - 10;
  for (y1 = 10; y1 < w; y1 += 20)
  {
    myGLCD.drawLine(x1, y1, x2, y1);
  }
}
