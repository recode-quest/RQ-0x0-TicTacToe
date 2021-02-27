#include <TouchScreen.h>
#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>
#include <IRremote.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define YP A2
#define XM A3
#define YM 8
#define XP 9

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 400);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);


//x = 0 :blue
//x = 1 :red
int x = 0;
int rturn = 0;

int a;
int ab;
int b;
int bb;
int c;
int cb;
int d;
int db;
int e;
int eb;
int f;
int fb;
int g;
int gb;
int h;
int hb;
int i;
int ib;

bool one = false;
bool two = false;
bool three = false;
bool four = false;
bool five = false;
bool six = false;
bool seven = false;
bool eight = false;
bool nine = false;

const byte IR_RECEIVE_PIN = 22;
String whichPlace;

void setup() {

  tft.reset();
  tft.begin(0x9341);
  tft.fillScreen(BLACK);
  tft.setRotation(1);

  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  tft.setCursor(60, 110);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.println("Tic Tac Toe");
  delay(2000);

  tft.setCursor(90, 154);
  tft.setTextColor(CYAN);
  tft.setTextSize(1);
  tft.println("by Krzychu(Commander)");

  delay(2000);

  tft.setCursor(10, 178);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.println("You win or you lose");
  tft.setCursor(10, 187);
  tft.println("Good Luck");
  tft.setCursor(10, 196);
  tft.println("Have Fun");

  delay(3000);


  tft.fillScreen(BLACK);

  tft.drawLine(113, 10, 113, 230, WHITE);
  tft.drawLine(208, 10, 208, 230, WHITE);

  tft.drawLine(30, 80, 290, 80, WHITE);
  tft.drawLine(30, 160, 290, 160, WHITE);

  pinMode(13, OUTPUT);

}


void loop() {

returning:

  if (rturn == 1) {
    tft.fillScreen(BLACK);
    tft.drawLine(113, 10, 113, 230, WHITE);
    tft.drawLine(208, 10, 208, 230, WHITE);

    tft.drawLine(30, 80, 290, 80, WHITE);
    tft.drawLine(30, 160, 290, 160, WHITE);
    rturn = 0;
    x = 0;

    a = 0;
    ab = 0;
    b = 0;
    bb = 0;
    c = 0;
    cb = 0;
    d = 0;
    db = 0;
    e = 0;
    eb = 0;
    f = 0;
    fb = 0;
    g = 0;
    gb = 0;
    h = 0;
    hb = 0;
    i = 0;
    ib = 0;
  }


  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  if (IrReceiver.decode())
  {

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    whichPlace = IrReceiver.decodedIRData.command, HEX;
    Serial.println(whichPlace);
    if (whichPlace == "22" && one == false) {

      if (x == 0) {
        tft.fillCircle(70, 45, 25, BLUE);
        x = x + 1;
        a = 1;
        one = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(50, 10);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        ab = 1;
        one = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "25" && two == false) {

      if (x == 0) {
        tft.fillCircle(160, 45, 25, BLUE);
        x = x + 1;
        b = 1;
        two = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(140, 10);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        bb = 1;
        two = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "13" && three == false) {

      if (x == 0) {
        tft.fillCircle(250, 45, 25, BLUE);
        x = x + 1;
        c = 1;
        three = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(230, 10);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        cb = 1;
        three = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "12" && four == false) {

      if (x == 0) {
        tft.fillCircle(70, 120, 25, BLUE);
        x = x + 1;
        d = 1;
        four = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(50, 85);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        db = 1;
        four = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "24" && five == false) {

      if (x == 0) {
        tft.fillCircle(160, 120, 25, BLUE);
        x = x + 1;
        e = 1;
        five = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(140, 85);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        eb = 1;
        five = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "94" && six == false) {

      if (x == 0) {
        tft.fillCircle(250, 120, 25, BLUE);
        x = x + 1;
        f = 1;
        six = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(230, 85);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        fb = 1;
        six = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "8" && seven == false) {

      if (x == 0) {
        tft.fillCircle(70, 195, 25, BLUE);
        x = x + 1;
        g = 1;
        seven = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(50, 160);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        gb = 1;
        seven = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "28" && eight == false) {

      if (x == 0) {
        tft.fillCircle(160, 195, 25, BLUE);
        x = x + 1;
        h = 1;
        eight = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(140, 160);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        hb = 1;
        eight = true;
        delay(10);
      }
    }
    IrReceiver.resume();

    if (whichPlace == "90" && nine == false) {

      if (x == 0) {
        tft.fillCircle(250, 195, 25, BLUE);
        x = x + 1;
        i = 1;
        nine = true;
        delay(10);
      }
      else if (x == 1) {
        tft.setCursor(230, 160);
        tft.setTextColor(RED);
        tft.setTextSize(8);
        tft.println("x");
        x = x - 1;
        ib = 1;
        nine = true;
        delay(10);
      }
    }
    if (a == 1 && b == 1 && c == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;


    }
    if (d == 1 && e == 1 && f == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (g == 1 && h == 1 && i == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (a == 1 && d == 1 && g == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (b == 1 && e == 1 && h == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (c == 1 && f == 1 && i == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (c == 1 && e == 1 && g == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (a == 1 && e == 1 && i == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (ab == 1 && bb == 1 && cb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (db == 1 && eb == 1 && fb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (gb == 1 && hb == 1 && ib == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }


    if (ab == 1 && db == 1 && gb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (bb == 1 && eb == 1 && hb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (cb == 1 && fb == 1 && ib == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (cb == 1 && eb == 1 && gb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;

    }
    if (ab == 1 && eb == 1 && ib == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }


    if (a || ab == 1) {
      if (b || bb == 1) {
        if (c || cb == 1) {
          if (d || db == 1) {
            if (e || eb == 1) {
              if (f || fb == 1) {
                if (g || gb == 1) {
                  if (h || hb == 1) {
                    if (i || ib == 1) {
                      one = false;
                      two = false;
                      three = false;
                      four = false;
                      five = false;
                      six = false;
                      seven = false;
                      eight = false;
                      nine = false;
                      tft.fillScreen(BLACK);
                      tft.setCursor(65, 100);
                      tft.setTextColor(GREEN);
                      tft.setTextSize(3);
                      tft.println("Two noobs.");
                      delay(2000);
                      tft.fillScreen(BLACK);
                      tft.setCursor(20, 110);
                      tft.setTextColor(CYAN);
                      tft.setTextSize(2);
                      tft.println("Ready for another game ?");
                      delay(2000);
                      tft.setCursor(100, 140);
                      tft.setTextColor(MAGENTA);
                      tft.setTextSize(2);
                      tft.println("Loading");
                      delay(800);
                      tft.setCursor(100, 140);
                      tft.println("Loading.");
                      delay(800);
                      tft.setCursor(100, 140);
                      tft.println("Loading..");
                      delay(800);
                      tft.setCursor(100, 140);
                      tft.println("Loading...");
                      delay(800);
                      rturn = 1;
                      goto returning;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    IrReceiver.resume();
  }


  if (p.z > ts.pressureThreshhold) {

    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.y < 380) {

      if (p.x < 400 && one == false) {
        if (x == 0) {
          tft.fillCircle(70, 45, 25, BLUE);
          x = x + 1;
          a = 1;
          one = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(50, 10);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          ab = 1;
          one = true;
          delay(10);
        }
      }



      else if (p.x < 650 && p.x > 400 && two == false) {
        if (x == 0) {
          tft.fillCircle(160, 45, 25, BLUE);
          x = x + 1;
          b = 1;
          two = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(140, 10);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          bb = 1;
          two = true;
          delay(10);
        }

      }



      else if (p.x > 650 && three == false) {
        if (x == 0) {
          tft.fillCircle(250, 45, 25, BLUE);
          x = x + 1;
          c = 1;
          three = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(230, 10);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          cb = 1;
          three = true;
          delay(10);
        }

      }
    }



    else if (p.y > 380 && p.y < 650) {

      if (p.x < 400 && four == false) {
        if (x == 0) {
          tft.fillCircle(70, 120, 25, BLUE);
          x = x + 1;
          d = 1;
          four = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(50, 85);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          db = 1;
          four = true;
          delay(10);
        }

      }


      else if (p.x < 650 && p.x > 400 && five == false) {
        if (x == 0) {
          tft.fillCircle(160, 120, 25, BLUE);
          x = x + 1;
          e = 1;
          five = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(140, 85);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          eb = 1;
          five = true;
          delay(10);
        }

      }


      else if (p.x > 650 && six == false) {
        if (x == 0) {
          tft.fillCircle(250, 120, 25, BLUE);
          x = x + 1;
          f = 1;
          six = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(230, 85);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          fb = 1;
          six = true;
          delay(10);
        }

      }

    }


    else if (p.y > 650) {

      if (p.x < 400 && seven == false) {
        if (x == 0) {
          tft.fillCircle(70, 195, 25, BLUE);
          x = x + 1;
          g = 1;
          seven = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(50, 160);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          gb = 1;
          seven = true;
          delay(10);
        }

      }


      else if (p.x < 650 && p.x > 400 && eight == false) {
        if (x == 0) {
          tft.fillCircle(160, 195, 25, BLUE);
          x = x + 1;
          h = 1;
          eight = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(140, 160);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          hb = 1;
          eight = true;
          delay(10);
        }

      }


      else if (p.x > 650 && nine == false) {
        if (x == 0) {
          tft.fillCircle(250, 195, 25, BLUE);
          x = x + 1;
          i = 1;
          nine = true;
          delay(10);
        }
        else if (x == 1) {
          tft.setCursor(230, 160);
          tft.setTextColor(RED);
          tft.setTextSize(8);
          tft.println("x");
          x = x - 1;
          ib = 1;
          nine = true;
          delay(10);
        }

      }

    }

    delay(500);

    if (a == 1 && b == 1 && c == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;


    }
    if (d == 1 && e == 1 && f == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (g == 1 && h == 1 && i == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (a == 1 && d == 1 && g == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (b == 1 && e == 1 && h == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (c == 1 && f == 1 && i == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (c == 1 && e == 1 && g == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (a == 1 && e == 1 && i == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(BLUE);
      tft.setTextSize(2);
      tft.println("Player 1 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (ab == 1 && bb == 1 && cb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (db == 1 && eb == 1 && fb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (gb == 1 && hb == 1 && ib == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }


    if (ab == 1 && db == 1 && gb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (bb == 1 && eb == 1 && hb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }
    if (cb == 1 && fb == 1 && ib == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }

    if (cb == 1 && eb == 1 && gb == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;

    }
    if (ab == 1 && eb == 1 && ib == 1) {
      tft.fillScreen(BLACK);
      tft.setCursor(80, 110);
      tft.setTextColor(YELLOW);
      tft.setTextSize(3);
      tft.println("GG Easy !");
      tft.setCursor(72, 140);
      tft.setTextColor(RED);
      tft.setTextSize(2);
      tft.println("Player 2 Win !");
      one = false;
      two = false;
      three = false;
      four = false;
      five = false;
      six = false;
      seven = false;
      eight = false;
      nine = false;
      delay(3000);

      tft.fillScreen(BLACK);
      tft.setCursor(20, 110);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.println("Ready for another game ?");
      delay(2000);
      tft.setCursor(100, 140);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(2);
      tft.println("Loading");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading.");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading..");
      delay(800);
      tft.setCursor(100, 140);
      tft.println("Loading...");
      delay(800);
      rturn = 1;
      goto returning;
    }


    if (a || ab == 1) {
      if (b || bb == 1) {
        if (c || cb == 1) {
          if (d || db == 1) {
            if (e || eb == 1) {
              if (f || fb == 1) {
                if (g || gb == 1) {
                  if (h || hb == 1) {
                    if (i || ib == 1) {
                      one = false;
                      two = false;
                      three = false;
                      four = false;
                      five = false;
                      six = false;
                      seven = false;
                      eight = false;
                      nine = false;
                      tft.fillScreen(BLACK);
                      tft.setCursor(65, 100);
                      tft.setTextColor(GREEN);
                      tft.setTextSize(3);
                      tft.println("Two noobs.");
                      delay(2000);
                      tft.fillScreen(BLACK);
                      tft.setCursor(20, 110);
                      tft.setTextColor(CYAN);
                      tft.setTextSize(2);
                      tft.println("Ready for another game ?");
                      delay(2000);
                      tft.setCursor(100, 140);
                      tft.setTextColor(MAGENTA);
                      tft.setTextSize(2);
                      tft.println("Loading");
                      delay(800);
                      tft.setCursor(100, 140);
                      tft.println("Loading.");
                      delay(800);
                      tft.setCursor(100, 140);
                      tft.println("Loading..");
                      delay(800);
                      tft.setCursor(100, 140);
                      tft.println("Loading...");
                      delay(800);
                      rturn = 1;
                      goto returning;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

  }
}