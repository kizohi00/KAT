#include <WiFi.h>
#include <Firebase_ESP_Client.h>
//IN THE BOARD MANAGER SELECT (DOIT ESP32 DEVKIT)

#define WIFI_SSID "YOUR WIFI SSID"
#define WIFI_PASSWORD "YOUT WIFI PASSWORD"
#define BUZZER_PIN 5

#define API_KEY "YOUR FIREBASE API KEY"

#define DATABASE_URL "YOUR FIREBASE DATABASE URL" 

//Important: Create firebase auth > New sign in method > select email and password > and add new account
#define USER_EMAIL "FIREBASE AUTH EMAIL"
#define USER_PASSWORD "FIREBASE AUTH PASSWORD"

FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
  }
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  if (config.signer.tokens.error.message.length() > 0) {
  } else {
    if (Firebase.ready())
    {
  }}
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
}

void loop()
{
  if (true && (millis() - sendDataPrevMillis > 1000 || sendDataPrevMillis == 0))
  {
  sendDataPrevMillis = millis();
  int buzzerState;
  if(Firebase.RTDB.getInt(&fbdo, "/Buzzer/state", &buzzerState)){
    if (buzzerState == 1) {
        digitalWrite(BUZZER_PIN, buzzerState);
      if (Firebase.RTDB.setInt(&fbdo, "/Buzzer/state", 0)) {
        digitalWrite(BUZZER_PIN, 0);
      }
    }

   } else {
    ESP.restart();
    //restart if there is any problem with firebase
   }
  }
}
