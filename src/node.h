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
  void setAddr(uint16_t addr);
  void getAddr(uint16_t *addr);
  void setType(uint16_t type);
  void getType(uint16_t *type);
  void setFirstType(uint8_t type);
  void getFirstType(uint8_t *type);
  void setSecondType(uint8_t type);
  void getSecondType(uint8_t *type);
  void setGroup(uint8_t group);
  void getGroup(uint8_t *group);
  void setOnoff(uint8_t value);
  void getOnoff(uint8_t *value);
  void setLightness(uint8_t value);
  void getLightness(uint8_t *value);
  void setMode(uint8_t value);
  void getMode(uint8_t *value);
  void setTemperature(uint16_t value);
  void getTemperature(uint16_t *value);
  void setColorH(uint16_t value);
  void setColorS(uint8_t value);
  void setColorV(uint8_t value);
  void getColorH(uint16_t *value);
  void getColorS(uint8_t *value);
  void getColorV(uint8_t *value);
  void setRegisterTime(uint32_t value);
  void getRegisterTime(uint32_t *value);
private:
  NODE_META _node;
};


#endif
