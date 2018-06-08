/*
 * Description: node database header file
 *
 * Author: ninja
 *
 * Date: 2018-06-08
 */
#ifndef NodeDB_h
#define NodeDB_h

#include <Arduino.h>
#include <EEPROM.h>
#include "node.h"

#define DEBUG_DB  Serial

#define NODE_MAX_SIZE 100


class NodeDB{
public:
  NodeDB();
  NodeDB(uint8_t *mac);
  ~NodeDB(){};

  void setDBName(uint8_t *mac);
  uint8_t insertNode(node *meshnode);

  void getNodeById(uint8_t id, node *meshNode);
  void getNodeByAddr(uint8_t addr, node *meshNode);

  void getNodeRegistedById(uint8_t id, RegistedType *isRegisted);
  void getNodeRegistedByAddr(DeviceAddrType addr, RegistedType *isRegisted);

  void getNodeFirstTypeById(uint8_t id, FirstType *type);
  void getNodeFirstTypeByAddr(DeviceAddrType addr, FirstType *type);

  void getNodeSecondTypeById(uint8_t id, SecondType *type);
  void getNodeSecondTypeByAddr(DeviceAddrType addr, SecondType *type);

  void getNodeGroupById(uint8_t id, GroupType *group);
  void getNodeGroupByAddr(DeviceAddrType addr, GroupType *group);

  void getNodeOnoffById(uint8_t id, OnoffType *onoff);
  void getNodeOnoffByAddr(DeviceAddrType addr, OnoffType *onoff);

  void getNodeModeById(uint8_t id, ModeType *mode);
  void getNodeModeByAddr(DeviceAddrType addr, ModeType *mode);

  void getNodeTemperatureById(uint8_t id, TemperatureType *temperature);
  void getNodeTemperatureByAddr(DeviceAddrType addr, TemperatureType *temperature);

  void getNodeColorHById(uint8_t id, ColorHType *color_h);
  void getNodeColorHByAddr(DeviceAddrType addr, ColorHType *color_h);

  void getNodeColorSById(uint8_t id, ColorSType *color_s);
  void getNodeColorSByAddr(DeviceAddrType addr, ColorSType *color_s);

  void getNodeColorVById(uint8_t id, ColorVType *color_v);
  void getNodeColorVByAddr(DeviceAddrType addr, ColorVType *color_v);

  void getNodeRegTimeById(uint8_t id, RegisterTimeType *regTime);
  void getNodeRegTimeByAddr(DeviceAddrType addr, RegisterTimeType *regTime);

  void updateRegistedById(uint8_t id, RegistedType isRegisted);
  void updateRegistedByAddr(DeviceAddrType addr, RegistedType isRegisted);

  void updateFirstTypeById(uint8_t id, FirstType type);
  void updateFirstTypeByAddr(DeviceAddrType addr, FirstType type);

  void updateSecondTypeById(uint8_t id, SecondType type);
  void updateSecondTypeByAddr(DeviceAddrType addr, SecondType type);

  void updateGroupById(uint8_t id, GroupType group);
  void updateGroupByAddr(DeviceAddrType addr, GroupType group);

  void updateOnoffById(uint8_t id, OnoffType onoff);
  void getOnoffByAddr(DeviceAddrType addr, OnoffType onoff);

  void updateModeById(uint8_t id, ModeType mode);
  void updateModeByAddr(DeviceAddrType addr, ModeType mode);

  void updateTemperatureById(uint8_t id, TemperatureType temperature);
  void updateTemperatureByAddr(DeviceAddrType addr, TemperatureType temperature);

  void updateColorHById(uint8_t id, ColorHType color_h);
  void updateColorHByAddr(DeviceAddrType addr, ColorHType color_h);

  void updateColorSById(uint8_t id, ColorSType color_s);
  void updateColorSByAddr(DeviceAddrType addr, ColorSType color_s);

  void updateColorVById(uint8_t id, ColorVType color_v);
  void updateColorVByAddr(DeviceAddrType addr, ColorVType color_v);

  void updateRegTimeById(uint8_t id, RegisterTimeType regTime);
  void updateRegTimeByAddr(DeviceAddrType addr, RegisterTimeType regTime);

  void deleteNodeById(uint8_t id);
  void deleteNodeByAddr(DeviceAddrType addr);

  unsigned int count();

private:
  unsigned char _name[6];
  unsigned char _id;     // auto increase
  unsigned char _addr;
  unsigned char _counter;
  node _meshNode;



};

#endif
