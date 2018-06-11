/*
 * Description: node database header file
 *
 * Author: ninja
 *
 * Date: 2018-06-08
 */

#ifndef node_h
#define node_h

#include <Arduino.h>

typedef uint8_t   RegistedType;
typedef uint16_t  DeviceAddrType;
typedef uint8_t   FirstType;
typedef uint8_t   SecondType;
typedef uint8_t   GroupType;
typedef uint8_t   OnoffType;
typedef uint8_t   LightnessType;
typedef uint8_t   ModeType;
typedef uint16_t  TemperatureType;
typedef uint16_t  ColorHType;
typedef uint8_t   ColorSType;
typedef uint8_t   ColorVType;
typedef uint32_t  RegisterTimeType;

typedef struct{
  uint8_t  isRegisted;
  uint16_t device_addr;
  uint8_t  firstType;
  uint8_t  secondType;
  uint8_t  group;
  uint8_t  onoff;
  uint8_t  lightness;
  uint8_t  mode;
  uint16_t temperature;
  uint16_t color_h;
  uint8_t  color_s;
  uint8_t  color_v;
  uint32_t registerTime;
}NODE_META __attribute__((aligned(4)));

class node{
public:
  node();
  node(uint16_t addr);
  ~node(){};

  void getSize(uint8_t *size);
  bool isRegisted();
  void setRegisted(bool registed);

  void setAddr(DeviceAddrType addr);
  DeviceAddrType getAddr();

  void setType(uint16_t type);
  uint16_t getType();

  void setFirstType(FirstType type);
  FirstType getFirstType();

  void setSecondType(SecondType type);
  SecondType getSecondType();

  void setGroup(GroupType group);
  GroupType getGroup();

  void setOnoff(OnoffType value);
  OnoffType getOnoff();

  void setLightness(LightnessType value);
  LightnessType getLightness();

  void setMode(ModeType value);
  ModeType getMode();

  void setTemperature(TemperatureType value);
  TemperatureType getTemperature();

  void setColorH(ColorHType value);
  void setColorS(ColorSType value);
  void setColorV(ColorVType value);

  ColorHType getColorH();
  ColorSType getColorS();
  ColorVType getColorV();

  void setRegisterTime(RegisterTimeType value);
  RegisterTimeType getRegisterTime();
  
private:
  NODE_META _node;
};


#endif
