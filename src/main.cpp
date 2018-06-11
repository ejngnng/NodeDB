#include <Arduino.h>
#include "NodeDB.h"

NodeDB DB;
int id = 0;
int id_01 = 0;
void setup() {
    Serial.begin(115200);

    node meshNode(5);

    meshNode.setTemperature(8);
    meshNode.setColorH(200);
    meshNode.setColorS(50);
    meshNode.setColorV(30);
    meshNode.setRegisted(true);
    meshNode.setLightness(50);
    meshNode.setOnoff(1);
    meshNode.setMode(4);

    id = DB.insertNode(&meshNode);

    node mesh01(20);

    mesh01.setTemperature(60);
    mesh01.setColorH(270);
    mesh01.setColorS(50);
    mesh01.setColorV(80);
    mesh01.setRegisted(true);
    mesh01.setLightness(80);
    mesh01.setOnoff(0);
    mesh01.setMode(3);

    id_01 = DB.insertNode(&mesh01);
    Serial.printf("id_01: %d\n", id_01);
}

void loop() {

  ColorHType color_h = 0;
  ColorSType color_s = 0;
  ColorVType color_v = 0;

  DB.getNodeColorHById(id, &color_h);
  DB.getNodeColorSById(id, &color_s);
  DB.getNodeColorVById(id, &color_v);

  Serial.printf("color h: %d\n", color_h);
  Serial.printf("color s: %d\n", color_s);
  Serial.printf("color v: %d\n", color_v);

  TemperatureType temperature = 0;
  DB.getNodeTemperatureById(id, &temperature);
  Serial.printf("temperature: %d\n", temperature);

  LightnessType lightness = 0;
  DB.getNodeLightnessById(id, &lightness);
  Serial.printf("lightness: %d\n", lightness);

  ModeType mode = 0;
  DB.getNodeModeById(id, &mode);
  Serial.printf("mode: %d\n", mode);

  DeviceAddrType addr = 0;
  DB.getNodeAddrById(id, &addr);
  Serial.printf("addr: %d\n", addr);

  Serial.println("=============");
  ColorHType color_h_01 = 0;
  ColorSType color_s_01 = 0;
  ColorVType color_v_01 = 0;

  DB.getNodeColorHById(id_01, &color_h_01);
  DB.getNodeColorSById(id_01, &color_s_01);
  DB.getNodeColorVById(id_01, &color_v_01);

  Serial.printf("color h 01: %d\n", color_h_01);
  Serial.printf("color s 01: %d\n", color_s_01);
  Serial.printf("color v 01: %d\n", color_v_01);

  TemperatureType temperature_01 = 0;
  DB.getNodeTemperatureById(id_01, &temperature_01);
  Serial.printf("temperature_01: %d\n", temperature_01);

  LightnessType lightness_01 = 0;
  DB.getNodeLightnessById(id_01, &lightness_01);
  Serial.printf("lightness_01: %d\n", lightness_01);

  ModeType mode_01 = 0;
  DB.getNodeModeById(id_01, &mode_01);
  Serial.printf("mode_01: %d\n", mode_01);

  DeviceAddrType addr_01 = 0;
  DB.getNodeAddrById(id_01, &addr_01);
  Serial.printf("addr_01: %d\n", addr_01);
  Serial.println("=============");
  Serial.printf("all node count is: %d\n", DB.count());
  delay(500);


}
