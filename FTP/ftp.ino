#include <WiFi.h>
#include <WiFiClient.h>    
#include "ESP32_FTPClient.h"


int CS_PIN = ?;
#define WIFI_SSID " "
#define WIFI_PASS " "

char ftp_server[] = " ";
char ftp_user[]   = " ";
char ftp_pass[]   = " ";

char working_dir[]   = "/test";
String temp = "/testftp.txt";
ESP32_FTPClient ftp (ftp_server,ftp_user,ftp_pass, 5000, 4);
File file;
////////////////////

void setup()
{

  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.println("Connecting Wifi...");
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
      
  }
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  /////////////////////////
  ftp.OpenConnection();
  ftp.ChangeWorkDir(working_dir);
  ftp.InitFile("Type A");
  ftp.NewFile("testftp.txt");
  //reading coould be from file in sd
  //initializeSD();
  //createFile("1.txt");
  //writeToFile("This is sample text!");
  //closeFile()
  //openFile("/1.txt");
  int counter =0;
  while (counter < 86479){
    String bermoda = (readLine());
    counter++;
    Serial.println(bermoda);
    Serial.println(counter);

    ftp.Write(bermoda.c_str());
    
   }
  closeFile();
  ftp.CloseFile();
}

void loop()
{
}
String readLine()
{
  String received = "";
  char ch;
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
     {
       received += ch;
    }
  }
  return "";
}
