#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C biasanya 0x27

// Array lirik, tiap 2 baris sekali
String lyrics[][2] = {
  {"SUDAH TERBIASA", "TERJADI TANTE"},
  {"TEMAN DATANG ", "KETIKA BUTUH SAJA"},
  {"APA LAGI", "KALAU SUSAH"},
  {"SEMUA PERGI", "MENGHILANG"},
};

int currentIndex = 0;
unsigned long previousMillis = 0;
const long interval = 3000; // 3 detik

void setup() {
  Wire.begin(21, 22); // SDA, SCL (opsional, default juga bisa)
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    lcd.clear();
    lcd.setCursor(0, 0); // Baris pertama
    lcd.print(lyrics[currentIndex][0]);

    lcd.setCursor(0, 1); // Baris kedua
    lcd.print(lyrics[currentIndex][1]);

    currentIndex++;
    if (currentIndex >= sizeof(lyrics) / sizeof(lyrics[0])) {
      currentIndex = 0;
    }
  }
}
