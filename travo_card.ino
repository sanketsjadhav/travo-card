#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>

#include <FreeDefaultFonts.h>



Adafruit_GFX_Button on_btn, off_btn;

int r;


#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup(void)
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(0);            //PORTRAIT
    tft.fillScreen(BLACK);

    tft.drawFastHLine(0, 5, tft.width(), RED);
    showmsgXY(0, 300, 1, &FreeSans12pt7b, "ACCESS RFID CARD");
  
}

/* two buttons are quite simple
 */
void loop(void)
{
   tft.drawFastHLine(0, 5, tft.width(), WHITE);
    showmsgXY(0, 30, 1, &FreeSans12pt7b, "1) PASSPORT CARD");
     tft.drawFastHLine(0, 5, tft.width(), WHITE);
    showmsgXY(0, 60, 1, &FreeSans12pt7b, "2) PAN CARD");
    tft.drawFastHLine(0, 5, tft.width(), WHITE);
    showmsgXY(0, 90, 1, &FreeSans12pt7b, "3) ADHAR CARD");
 tft.drawFastHLine(0, 5, tft.width(), WHITE);
    showmsgXY(0, 120, 1, &FreeSans12pt7b, "4) RATION CARD");
    
  
}

void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
    int16_t x1, y1;
    uint16_t wid, ht;
    tft.setFont(f);
    tft.setCursor(x, y);
    tft.setTextColor(GREEN);
    tft.setTextSize(sz);
    tft.print(msg);
    delay(1000);
}


