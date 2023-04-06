void setup() {
  // put your setup code here, to run once:
  //Request date and time from an NTP Server
/*NTP stands for Network Time Protocol and it is a networking protocol for 
clock
synchronization between computer systems*/
/*Here we use local wifi which is FTNT*/
#include <WiFi.h>
/*To get date and time with the ESP32, you don’t need to install any 
libraries. You
simply need to include the time.h library in your code*/
#include "time.h"
  const char* ssid = "FTNT";
  const char* password = "vnit@123123123";
  const char* ntpServer = "pool.ntp.org";
  /*request the time from pool.ntp.org, which is a cluster of timeservers that
anyone can use to request the time*/
  const long gmtOffset_sec = 0;
  /*The gmtOffset_sec variable defines the offset in seconds between your time
zone and GMT. Let's consider UK as a standard time, so the time offset is 0*/
  const int daylightOffset_sec = 3600;
  void setup() {
    Serial.begin(115200);
    // Connect to Wi-Fi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();
    //disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
  }
  void loop() {
    delay(1000);
    printLocalTime();
  }
  void printLocalTime() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
      Serial.println("Failed to obtain time");
      return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    Serial.print("Day of week: ");
    Serial.println(&timeinfo, "%A");
    Serial.print("Month: ");
    Serial.println(&timeinfo, "%B");
    Serial.print("Day of Month: ");
    Serial.println(&timeinfo, "%d");
    Serial.print("Year: ");
    Serial.println(&timeinfo, "%Y");
    Serial.print("Hour: ");
    Serial.println(&timeinfo, "%H");
    Serial.print("Hour (12 hour format): ");
    Serial.println(&timeinfo, "%I");
    Serial.print("Minute: ");
    Serial.println(&timeinfo, "%M");
    Serial.print("Second: ");
    Serial.println(&timeinfo, "%S");
    Serial.println("Time variables");
    char timeHour[3];
    strftime(timeHour, 3, "%H", &timeinfo);
    Serial.println(timeHour);
    char timeWeekDay[10];
    strftime(timeWeekDay, 10, "%A", &timeinfo);
    Serial.println(timeWeekDay);
    Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}