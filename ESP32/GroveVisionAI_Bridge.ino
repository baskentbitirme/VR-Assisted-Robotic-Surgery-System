/*
========================================================
ESP32 Grove Vision AI Bridge

Project:
VR-Assisted Robotic Surgical Training Platform

Description:
This module interfaces with the Grove Vision AI V2 camera,
receives object detection results, tracks surgical instruments,
and transmits detection data to the Arduino Mega via UART.

Detected Objects:
- Hemostat
- Forceps (Penset)
- Sterile Compress
- Contaminated Compress

Hardware:
- ESP32 Dev Board
- Grove Vision AI V2
- Arduino Mega 2560

Communication:
I2C  : Grove Vision AI <-> ESP32
UART : ESP32 <-> Arduino Mega

========================================================
*/

#include <Arduino.h>
#include <Wire.h>
#include <Seeed_Arduino_SSCMA.h>

SSCMA AI;

const char* classNames[] = {
  "hemostat",
  "kontamineKompress",
  "penset",
  "sterilKompress"
};

struct Detection {
  bool active = false;
  int score = 0;
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;
  unsigned long lastSeen = 0;
};

Detection detections[4];

unsigned long lastSendTime = 0;

const unsigned long sendInterval = 500;
const unsigned long timeoutMs = 2000;

void setup() {

  Serial.begin(115200);

  // UART2
  // RX = GPIO16
  // TX = GPIO17
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  // Grove Vision AI I2C
  Wire.begin(21, 22);

  AI.begin(&Wire);

  Serial.println("Grove Vision AI V2 hazir!");
}

void loop() {

  // Detection oku
  if (!AI.invoke(1, false, false)) {

    for (int i = 0; i < AI.boxes().size(); i++) {

      int t = AI.boxes()[i].target;

      if (t >= 0 && t < 4) {

        detections[t].active = true;

        detections[t].score = AI.boxes()[i].score;

        detections[t].x = AI.boxes()[i].x;
        detections[t].y = AI.boxes()[i].y;

        detections[t].w = AI.boxes()[i].w;
        detections[t].h = AI.boxes()[i].h;

        detections[t].lastSeen = millis();
      }
    }
  }

  // Eski detectionları kapat
  for (int i = 0; i < 4; i++) {

    if (detections[i].active &&
        millis() - detections[i].lastSeen > timeoutMs) {

      detections[i].active = false;
    }
  }

  // Belirli aralıklarla gönder
  if (millis() - lastSendTime >= sendInterval) {

    lastSendTime = millis();

    // =========================
    // MEGA'YA VERİ GÖNDER
    // =========================

    Serial2.print("D;");

    for (int i = 0; i < 4; i++) {

      Serial2.print(i);
      Serial2.print(",");

      Serial2.print(detections[i].active ? 1 : 0);
      Serial2.print(",");

      Serial2.print(detections[i].score);
      Serial2.print(",");

      Serial2.print(detections[i].x);
      Serial2.print(",");

      Serial2.print(detections[i].y);
      Serial2.print(",");

      Serial2.print(detections[i].w);
      Serial2.print(",");

      Serial2.print(detections[i].h);

      if (i < 3) {
        Serial2.print(";");
      }
    }

    Serial2.println();

    // =========================
    // ESP32 SERIAL MONITOR
    // =========================

    Serial.print("Tespitler: ");

    for (int i = 0; i < 4; i++) {

      Serial.print(classNames[i]);
      Serial.print(": ");

      if (detections[i].active) {

        Serial.print("skor=");
        Serial.print(detections[i].score);

        Serial.print(" x=");
        Serial.print(detections[i].x);

        Serial.print(" y=");
        Serial.print(detections[i].y);

        Serial.print(" w=");
        Serial.print(detections[i].w);

        Serial.print(" h=");
        Serial.print(detections[i].h);
      }
      else {

        Serial.print("yok");
      }

      if (i < 3) {
        Serial.print("  ||  ");
      }
    }

    Serial.println();
  }
}
