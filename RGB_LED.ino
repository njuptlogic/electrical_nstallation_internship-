#include <Adafruit_NeoPixel.h>
#define ULTRASONIC_IN_PIN          12  // 超声波接收脚 E
#define ULTRASONIC_OUT_PIN         13  // 超声波发射脚 T
//距离
float distance = 0;

int PIR_PIN = 2;
int LED_PIN = 4;
int RGB_PIN = 5;
int LED_NUM = 12;
int LDR_PIN = A0; // 光敏电阻引脚
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUM, RGB_PIN, NEO_GRB + NEO_KHZ800);

uint32_t Wheel(byte WheelPos);
void rainbow(uint8_t wait);
void colorWipe(uint32_t c, uint8_t wait);
void blink();

void setup(){
  Serial.begin(9600);
  pinMode(ULTRASONIC_IN_PIN, INPUT); //
  pinMode(ULTRASONIC_OUT_PIN, OUTPUT); //
  Serial.println("-------------- setup ok -----------------");

  strip.begin();
  strip.show(); 

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(ULTRASONIC_OUT_PIN, LOW); //
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_OUT_PIN, HIGH); //超声波发送一个不小于10us的高脉冲
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_OUT_PIN, LOW); //
  float Fdistance = pulseIn(ULTRASONIC_IN_PIN, HIGH); // 读取返回脉冲宽度(即高电平持续的时间长短),单位为ms
  //distance = Fdistance / 3.4 / 10; // 时间转成距离 （单位：公分） 理论值340米/每秒,实际测试中并不准确
  distance = Fdistance / 5.8 / 10; // 时间转成距离 （单位：公分）
  Serial.print("检测结果：");
  Serial.print(distance);
  Serial.println("cm");
  delay(50);


  int lightValue = analogRead(LDR_PIN); // 读取光敏电阻的模拟值
  Serial.print("LightValue: ");
  Serial.println(lightValue);
  // 判断是否够暗
  Serial.print("LightValue:");
  Serial.println(lightValue);
  if (lightValue > 1020){
    if(digitalRead(PIR_PIN))
    {
      Serial.println("Organism Detected!");
      // 闪烁
      blink();
      

      // 彩虹灯
      // rainbow(20);

      // 流水灯
      // for (int i = 1; i <= 12; i = i + (1)) {
      // rgb_display_5.setPixelColor((i)-1, ((((i * 21) & 0xffffff) << 16) | ((0 & 0xffffff) << 8) | 0));
      // rgb_display_5.show();
      // delay(200);
      // rgb_display_5.setPixelColor((i)-1, (0xffff00));
      // rgb_display_5.show();
      // delay(200);
      // }
      digitalWrite(LED_PIN, LOW);
    }
    else
    {
      if(distance<10)
      {
        Serial.println("Approaching obj Detected!");
        // 闪烁
        blink();
        digitalWrite(LED_PIN, LOW);
      }
      else
      {
      Serial.println("NOT Detected!");
      // 彩虹灯
      rainbow(20);
      // 保持红色
      // colorWipe(strip.Color(255, 0, 0), 50);
      digitalWrite(LED_PIN, HIGH);
      }
    }
  }
  else
  {
    Serial.println("Not Dark Enough!");
    colorWipe(strip.Color(0, 0, 0), 50);
  }

}

// 灯光一起闪烁
void blink(){
    strip.setPixelColor(0, 255, 0, 0); //设置红色
    strip.setPixelColor(1, 255, 0, 0); //设置红色
    strip.setPixelColor(2, 255, 0, 0); //设置红色
    strip.setPixelColor(3, 255, 0, 0); //设置红色
    strip.setPixelColor(4, 255, 0, 0); //设置红色
    strip.setPixelColor(5, 255, 0, 0); //设置红色
    strip.setPixelColor(6, 255, 0, 0); //设置红色
    strip.setPixelColor(7, 255, 0, 0); //设置红色
    strip.setPixelColor(8, 255, 0, 0); //设置红色
    strip.setPixelColor(9, 255, 0, 0); //设置红色
    strip.setPixelColor(10, 255, 0, 0); //设置红色
    strip.setPixelColor(11, 255, 0, 0); //设置红色
    strip.show();
    delay(100); //延迟100毫秒
    strip.setPixelColor(0, 0, 255, 0); //设置绿色
    strip.setPixelColor(1, 0, 255, 0); //设置绿色
    strip.setPixelColor(2, 0, 255, 0); //设置绿色
    strip.setPixelColor(3, 0, 255, 0); //设置绿色
    strip.setPixelColor(4, 0, 255, 0); //设置绿色
    strip.setPixelColor(5, 0, 255, 0); //设置绿色
    strip.setPixelColor(6, 0, 255, 0); //设置绿色
    strip.setPixelColor(7, 0, 255, 0); //设置绿色
    strip.setPixelColor(8, 0, 255, 0); //设置绿色
    strip.setPixelColor(9, 0, 255, 0); //设置绿色
    strip.setPixelColor(10, 0, 255, 0); //设置绿色
    strip.setPixelColor(11, 0, 255, 0); //设置绿色
    strip.show();
    delay(100); //延迟100毫秒
    strip.setPixelColor(0, 0, 0, 255); //设置蓝色
    strip.setPixelColor(1, 0, 0, 255); //设置蓝色
    strip.setPixelColor(2, 0, 0, 255); //设置蓝色
    strip.setPixelColor(3, 0, 0, 255); //设置蓝色
    strip.setPixelColor(4, 0, 0, 255); //设置蓝色
    strip.setPixelColor(5, 0, 0, 255); //设置蓝色
    strip.setPixelColor(6, 0, 0, 255); //设置蓝色
    strip.setPixelColor(7, 0, 0, 255); //设置蓝色
    strip.setPixelColor(8, 0, 0, 255); //设置蓝色
    strip.setPixelColor(9, 0, 0, 255); //设置蓝色
    strip.setPixelColor(10, 0, 0, 255); //设置蓝色
    strip.setPixelColor(11, 0, 0, 255); //设置蓝色
    strip.show();
    delay(100); //延迟100毫秒
}


// #include <Adafruit_NeoPixel.h>

// #ifdef __AVR__

// #include <avr/power.h>

// #endif

// #define PIN 5

// // Parameter 1 = number of pixels in strip

// // Parameter 2 = Arduino pin number (most are valid)

// // Parameter 3 = pixel type flags, add together as needed:

// //  NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)

// //  NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)

// //  NEO_GRB    Pixels are wired for GRB bitstream (most NeoPixel products)

// //  NEO_RGB    Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

// //  NEO_RGBW  Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);

// // IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across

// // pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input

// // and minimize distance between Arduino and first pixel.  Avoid connecting

// // on a live circuit...if you must, connect GND first.



// void setup() {

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket

  // #if defined (__AVR_ATtiny85__)

  // if (F_CPU == 16000000) clock_prescale_set(clock_div_1);

  // #endif

  // // End of trinket special code

  // strip.begin();

  // strip.show(); // Initialize all pixels to 'off'

// }



// void loop() {

//   // Some example procedures showing how to display to the pixels:

//   //colorWipe(strip.Color(255, 0, 0), 50); // Red

// // colorWipe(strip.Color(0, 255, 0), 50); // Green

//   //colorWipe(strip.Color(0, 0, 255), 50); // Blue

// //colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW

//   // Send a theater pixel chase in...

// // theaterChase(strip.Color(127, 127, 127), 50); // White

//   //theaterChase(strip.Color(127, 0, 0), 50); // Red

//   //theaterChase(strip.Color(0, 0, 127), 50); // Blue

//   rainbow(20);

//   //rainbowCycle(20);

//   //theaterChaseRainbow(50);

// }

// Fill the dots one after the other with a color

void colorWipe(uint32_t c, uint8_t wait) {

  for(uint16_t i=0; i<strip.numPixels(); i++) {

  strip.setPixelColor(i, c);

  strip.show();

  delay(wait);

  }

}

void rainbow(uint8_t wait) {

  uint16_t i, j;

  for(j=0; j<256; j++) {

  for(i=0; i<strip.numPixels(); i++) {

    strip.setPixelColor(i, Wheel((i+j) & 255));

  }

  strip.show();

  delay(wait);

  }

}

// Slightly different, this makes the rainbow equally distributed throughout

void rainbowCycle(uint8_t wait) {

  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel

  for(i=0; i< strip.numPixels(); i++) {

    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));

  }

  strip.show();

  delay(wait);

  }

}

//Theatre-style crawling lights.

void theaterChase(uint32_t c, uint8_t wait) {

  for (int j=0; j<10; j++) {  //do 10 cycles of chasing

  for (int q=0; q < 3; q++) {

    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {

      strip.setPixelColor(i+q, c);  //turn every third pixel on

    }

    strip.show();

    delay(wait);

    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {

      strip.setPixelColor(i+q, 0);      //turn every third pixel off

    }

  }

  }

}

//Theatre-style crawling lights with rainbow effect

void theaterChaseRainbow(uint8_t wait) {

  for (int j=0; j < 256; j++) {    // cycle all 256 colors in the wheel

  for (int q=0; q < 3; q++) {

    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {

      strip.setPixelColor(i+q, Wheel( (i+j) % 255));  //turn every third pixel on

    }

    strip.show();

    delay(wait);

    for (uint16_t i=0; i < strip.numPixels(); i=i+3) {

      strip.setPixelColor(i+q, 0);      //turn every third pixel off

    }

  }

  }

}

// Input a value 0 to 255 to get a color value.

// The colours are a transition r - g - b - back to r.

uint32_t Wheel(byte WheelPos) {

  WheelPos = 255 - WheelPos;

  if(WheelPos < 85) {

  return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);

  }

  if(WheelPos < 170) {

  WheelPos -= 85;

  return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);

  }

  WheelPos -= 170;

  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
} 
