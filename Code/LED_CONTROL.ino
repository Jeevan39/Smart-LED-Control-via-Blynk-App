/*******************************************************
 *  SMART LED CONTROL VIA BLYNK APP - ESP32 PROJECT
 *  
 *  Description:
 *  This program connects an ESP32 to the Blynk IoT platform.
 *  Using the Blynk mobile app, you can control three LEDs
 *  (Red, Green, and Blue) remotely through virtual pins (V0, V1, V2).
 *  
 *  Author: JEEVAN L
 *  Year: 2025
 *******************************************************/

#define BLYNK_TEMPLATE_ID "YOUR-ID"      // Your Blynk Template ID (from Blynk Dashboard)
#define BLYNK_TEMPLATE_NAME "YOUR-ID"    // Template name shown in Blynk Cloud
#define BLYNK_AUTH_TOKEN "YOUR-ID"       // Unique Auth Token for your project

#define BLYNK_PRINT Serial   // Enables serial debugging output for Blynk

// --- Include Required Libraries ---
#include <WiFi.h>             // For connecting ESP32 to Wi-Fi
#include <BlynkSimpleEsp32.h> // Blynk library for ESP32 communication

// --- Wi-Fi Credentials ---
// Replace these with your Wi-Fi name and password
char auth[] = BLYNK_AUTH_TOKEN;  // Blynk authentication token
char ssid[] = "Wokwi-GUEST";     // Wi-Fi network name
char pass[] = "";                // Wi-Fi password (empty for open networks)

// --- Define LED Pins (GPIO Pins on ESP32) ---
#define RED_LED   25
#define GREEN_LED 26
#define BLUE_LED  27

/*******************************************************
 *  BLYNK VIRTUAL PIN HANDLERS
 *  These functions are automatically triggered when 
 *  the virtual pins (V0, V1, V2) are activated in the app.
 *******************************************************/

// Virtual pin V0 controls RED LED
BLYNK_WRITE(V0) { 
  int value = param.asInt();        // Read value sent from Blynk app (0 or 1)
  digitalWrite(RED_LED, value);     // Turn LED ON/OFF based on received value
  Serial.println(value ? "RED LED: ON" : "RED LED: OFF");  // Print LED state to Serial Monitor
} 

// Virtual pin V1 controls GREEN LED
BLYNK_WRITE(V1) { 
  int value = param.asInt(); 
  digitalWrite(GREEN_LED, value); 
  Serial.println(value ? "GREEN LED: ON" : "GREEN LED: OFF"); 
} 

// Virtual pin V2 controls BLUE LED
BLYNK_WRITE(V2) { 
  int value = param.asInt(); 
  digitalWrite(BLUE_LED, value); 
  Serial.println(value ? "BLUE LED: ON" : "BLUE LED: OFF"); 
}

/*******************************************************
 *  SETUP FUNCTION
 *  This runs once when the ESP32 is powered on or reset.
 *******************************************************/
void setup() {
  Serial.begin(115200);                  // Start serial communication for debugging
  Blynk.begin(auth, ssid, pass);         // Connect ESP32 to Wi-Fi and Blynk cloud

  // Configure LED pins as OUTPUT
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  // Initialize LEDs to OFF state
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);

  Serial.println("✅ ESP32 is Ready and Connected to Blynk Cloud!");
  Serial.println("📲 Waiting for Commands from Blynk App...");
}

/*******************************************************
 *  LOOP FUNCTION
 *  This runs continuously after setup().
 *  Blynk.run() keeps the connection alive and 
 *  listens for commands from the Blynk cloud.
 *******************************************************/
void loop() {
  Blynk.run();   // Continuously handles communication between ESP32 and Blynk
}
