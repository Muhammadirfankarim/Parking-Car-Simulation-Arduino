#include <Servo.h>
#include <LiquidCrystal.h>

Servo servoMasuk; // Motor servo pintu masuk
Servo servoKeluar; // Motor servo pintu keluar
LiquidCrystal lcdMasuk(A0, A1, A2, A3, A4, A5); // Inisialisasi LCD
LiquidCrystal lcdKeluar(7, 8, 9, 10, 12, 13);

const int buttonMasukPin = 2; // Pin untuk tombol masuk
const int buttonKeluarPin = 4; // Pin untuk tombol keluar
int kendaraanMasuk = 0; // Jumlah kendaraan yang masuk
int kendaraanKeluar = 10; // Jumlah kendaraan yang keluar

void setup() {
  servoMasuk.attach(3); // Attach motor servo pintu masuk ke pin 3
  servoKeluar.attach(11); // Attach motor servo pintu keluar ke pin 11
  pinMode(buttonMasukPin, INPUT_PULLUP); // Konfigurasi tombol masuk sebagai input dengan pull-up resistor
  pinMode(buttonKeluarPin, INPUT_PULLUP); // Konfigurasi tombol keluar sebagai input dengan pull-up resistor
  lcdMasuk.begin(16, 2); // Inisialisasi LCD dengan ukuran 16x2
  //lcdMasuk.clear(); // Membersihkan tampilan awal LCD
  lcdMasuk.print("Pintu Masuk: ");
  lcdKeluar.begin(16, 2);
  //lcdKeluar.clear();
  lcdKeluar.print("Pintu Keluar: ");
}

void status() {
  lcdMasuk.setCursor(6, 0);
  lcdMasuk.clear();
  lcdMasuk.print("Pintu Masuk: "+ String(kendaraanMasuk));
  lcdKeluar.setCursor(6, 0);
  lcdKeluar.clear();
  lcdKeluar.print("Pintu Keluar: "+ String(kendaraanKeluar));
}

void loop() {
  if (digitalRead(buttonMasukPin) == LOW) {
    if (kendaraanMasuk < 10) {
      kendaraanMasuk+=1;
      kendaraanKeluar-=1;
      status();
      servoMasuk.write(90); // Menggerakkan servo pintu masuk ke posisi terbuka
      delay(1000); // Delay untuk simulasi kendaraan masuk
      servoMasuk.write(0); // Mengembalikan servo pintu masuk ke posisi tertutup
    }
  }

  if (digitalRead(buttonKeluarPin) == LOW) {
    if (kendaraanKeluar <= 10) {
      kendaraanMasuk-=1;
      kendaraanKeluar+=1;
      status();
      servoKeluar.write(90); // Menggerakkan servo pintu keluar ke posisi terbuka
      delay(1000); // Delay untuk simulasi kendaraan keluar
      servoKeluar.write(0); // Mengembalikan servo pintu keluar ke posisi tertutup
    }
  }
}
