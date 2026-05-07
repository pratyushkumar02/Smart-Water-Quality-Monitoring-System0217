#include <WiFi.h>
#include <ThingSpeak.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TURBIDITY_PIN 34
#define TDS_PIN 35
#define ONE_WIRE_BUS 4
#define BUZZER_PIN 25

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_WRITE_API_KEY";

WiFiClient client;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int turbidityClean = 200;
int turbidityModerate = 500;
int tdsSafe = 300;

void setup() {

  Serial.begin(115200);

  sensors.begin();

  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");

  ThingSpeak.begin(client);

  Serial.println("Smart Water Quality Monitoring System");
}

void loop() {

  int turbidityValue = analogRead(TURBIDITY_PIN);

  int tdsValue = analogRead(TDS_PIN);

  sensors.requestTemperatures();

  float temperature = sensors.getTempCByIndex(0);

  Serial.println();
  Serial.println("Sensor Readings");

  Serial.print("Turbidity: ");
  Serial.println(turbidityValue);

  Serial.print("TDS: ");
  Serial.println(tdsValue);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  String waterStatus = "";

  if (turbidityValue < turbidityClean &&
      tdsValue < tdsSafe) {

    waterStatus = "CLEAN AND SAFE";

    digitalWrite(BUZZER_PIN, LOW);
  }

  else if (turbidityValue >= turbidityClean &&
           turbidityValue < turbidityModerate) {

    waterStatus = "MODERATE";

    digitalWrite(BUZZER_PIN, LOW);
  }

  else {

    waterStatus = "DIRTY AND UNSAFE";

    digitalWrite(BUZZER_PIN, HIGH);
  }

  Serial.print("Water Quality Status: ");
  Serial.println(waterStatus);

  Serial.print("Temperature Status: ");

  if (temperature < 10) {

    Serial.println("TOO COLD");
  }

  else if (temperature > 40) {

    Serial.println("TOO HOT");
  }

  else {

    Serial.println("NORMAL");
  }

  ThingSpeak.setField(1, turbidityValue);
  ThingSpeak.setField(2, tdsValue);
  ThingSpeak.setField(3, temperature);

  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (response == 200) {

    Serial.println("Data uploaded to ThingSpeak successfully");
  }

  else {

    Serial.print("Upload failed. Error code: ");
    Serial.println(response);
  }

  Serial.println();

  delay(15000);
}