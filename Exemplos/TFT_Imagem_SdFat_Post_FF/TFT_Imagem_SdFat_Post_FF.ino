// Programa : Teste Display Touch Arduino - Imagem
// Autor : FILIPEFLOP

#include <UTFT.h>
#include <SdFat.h>

char bkgRaw[] = "imagem1.raw";
char bkgRaw2[] = "FF.raw";

// Seta o pino CS do SD
uint8_t sdCS = 10;
SdFat sd;
SdFile inFile;
int lastTouch;

UTFT myGLCD(UNO_24, A2, A1, A3, A4);

void dispRaw(UTFT *utft, SdFile* inFile)
{
  char VH, VL;
  int i, j = 0;
  cbi(utft->P_CS, utft->B_CS);
  for (i = 0; i < 240; i++)
    for (j = 0; j < 320; j++) {
      VL = inFile->read();
      VH = inFile->read();
      utft->LCD_Write_DATA(VL, VH);
    }
  sbi(utft->P_CS, utft->B_CS);
  utft->clrXY();
}

void setup()
{
  Serial.begin(115200);
  pinMode(A0, OUTPUT); // for the UNO_SHIELD_1IN1
  digitalWrite(A0, HIGH);
  myGLCD.InitLCD();
  myGLCD.clrScr();
  Serial.print("Testando cartao SD... ");
  if (sd.begin(sdCS, SPI_FULL_SPEED))
  {
    Serial.println("SD Card OK...");
  }
  else Serial.println("SD Card Falhou...");
}

void loop()
{
  if (inFile.open(bkgRaw, O_READ)) {
    Serial.println("Imagem 1 aberta...");
    dispRaw(&myGLCD, &inFile);
    inFile.close();
  }
  else Serial.println("Imagem 1 nao encontrada...");
  delay(10000);
  if (inFile.open(bkgRaw2, O_READ)) {
    Serial.println("Imagem 2 aberta...");
    dispRaw(&myGLCD, &inFile);
    inFile.close();
  }
  else Serial.println("Imagem 2 nao encontrada...");
  delay(10000);
}

