/*
 * Description: node database source file
 *
 * Author: ninja
 *
 * Date: 2018-06-08
 */
#include "NodeDB.h"

/* | id | isRegisted | device_addr | firstType | secondType | group | onoff | lightness | mode | temperature | color_h | color_s | color_v | registerTime | */
NodeDB::NodeDB(){
  _id = 1;
  _start = 0;
  _addr = 0;
  memset(_name, 0, 6);
  EEPROM.begin(NODE_MAX_SIZE * sizeof(node) + _start);
  clear_db();
}


NodeDB::NodeDB(int start){
  _id = 1;
  _start = start;
  _addr = 0;
  memset(_name, 0, 6);
  EEPROM.begin(NODE_MAX_SIZE * sizeof(node) + _start);
  clear_db();
}

NodeDB::NodeDB(uint8_t *mac){
  _id = 1;
  _start = 0;
  _addr = 0;
  memset(_name, 0, 6);
  memcpy(_name, mac, 6*sizeof(uint8_t));
  EEPROM.begin(NODE_MAX_SIZE * sizeof(node) + _start);
  clear_db();
}

void NodeDB::clear_db(){
  for(uint16_t i=0; i<(NODE_MAX_SIZE * sizeof(node) + _start); i++){
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
}

void NodeDB::calcu_insert_eeprom(){
  int start_addr = (_id - 1) * (sizeof(node) + 1) + _start;
  _id_eeprom = _id * start_addr;
  _isregiste_eeprom = _id_eeprom + sizeof(_id);
  _device_addr_eeprom = _isregiste_eeprom + sizeof(RegistedType);
  _firstType_eeprom = _device_addr_eeprom + sizeof(DeviceAddrType);
  _secondType_eeprom = _firstType_eeprom + sizeof(FirstType);
  _group_eeprom = _secondType_eeprom + sizeof(SecondType);
  _onof_eeprom = _group_eeprom + sizeof(GroupType);
  _lightness_eeprom = _onof_eeprom + sizeof(OnoffType);
  _mode_eeprom = _lightness_eeprom + sizeof(LightnessType);
  _temperature_eeprom = _mode_eeprom + sizeof(ModeType);
  _color_h_eeprom = _temperature_eeprom + sizeof(TemperatureType);
  _color_s_eeprom = _color_h_eeprom + sizeof(ColorHType);
  _color_v_eeprom = _color_s_eeprom + sizeof(ColorSType);
  _registerTime_eeprom = _color_v_eeprom + sizeof(ColorVType);

}

void NodeDB::calcu_select_eeprom(int id){
  int start_addr = (id - 1) * (sizeof(node) + 1) + _start;
  _id_eeprom = id * start_addr;
  _isregiste_eeprom = _id_eeprom + sizeof(_id);
  _device_addr_eeprom = _isregiste_eeprom + sizeof(RegistedType);
  _firstType_eeprom = _device_addr_eeprom + sizeof(DeviceAddrType);
  _secondType_eeprom = _firstType_eeprom + sizeof(FirstType);
  _group_eeprom = _secondType_eeprom + sizeof(SecondType);
  _onof_eeprom = _group_eeprom + sizeof(GroupType);
  _lightness_eeprom = _onof_eeprom + sizeof(OnoffType);
  _mode_eeprom = _lightness_eeprom + sizeof(LightnessType);
  _temperature_eeprom = _mode_eeprom + sizeof(ModeType);
  _color_h_eeprom = _temperature_eeprom + sizeof(TemperatureType);
  _color_s_eeprom = _color_h_eeprom + sizeof(ColorHType);
  _color_v_eeprom = _color_s_eeprom + sizeof(ColorSType);
  _registerTime_eeprom = _color_v_eeprom + sizeof(ColorVType);

}

void NodeDB::setDBName(uint8_t *mac){
  memset(_name, 0, 6*sizeof(uint8_t));
  memcpy(_name, mac, 6*sizeof(uint8_t));
}

/* | id | isRegisted | device_addr | firstType | secondType | group | onoff | lightness | mode | temperature | color_h | color_s | color_v | registerTime | */
int NodeDB::insertNode(node *meshNode){
  calcu_insert_eeprom();
#if SLOW_OP
  slow_write(_id_eeprom, _id);   // id
  slow_write(_isregiste_eeprom, meshNode->isRegisted() ? 0x01 : 0); // isRegisted

  uint16_t addr = 0;
  addr = meshNode->getAddr();
  slow_write(_device_addr_eeprom, addr >> 8 & 0xFF); // device addr
  slow_write(_device_addr_eeprom + 1, addr & 0xFF);

  slow_write(_firstType_eeprom, meshNode->getFirstType()); // first type

  slow_write(_secondType_eeprom, meshNode->getSecondType()); // second type

  slow_write(_group_eeprom, meshNode->getGroup()); // group

  slow_write(_onof_eeprom, meshNode->getOnoff()); // onoff

  slow_write(_lightness_eeprom, meshNode->getLightness()); // lightness

  slow_write(_mode_eeprom, meshNode->getMode());

  uint16_t temperature = 0;
  temperature = meshNode->getTemperature();
  slow_write(_temperature_eeprom, temperature >> 8 & 0xFF);
  slow_write(_temperature_eeprom + 1, temperature & 0xFF);

  uint16_t color_h = 0;
  color_h = meshNode->getColorH();
  slow_write(_color_h_eeprom, color_h >> 8 & 0xFF);
  slow_write(_color_h_eeprom + 1, color_h & 0xFF);

  slow_write(_color_s_eeprom, meshNode->getColorS());

  slow_write(_color_v_eeprom, meshNode->getColorV());

  uint32_t regTime = 0;
  regTime = meshNode->getRegisterTime();
  slow_write(_registerTime_eeprom, regTime >> 24 & 0xFF);
  slow_write(_registerTime_eeprom + 1, regTime >> 16 & 0xFF);
  slow_write(_registerTime_eeprom + 2, regTime >> 8 & 0xFF);
  slow_write(_registerTime_eeprom + 3, regTime & 0xFF);

  _id ++;
#else

#endif
  return (_id-1);
}

void NodeDB::getNodeById(uint8_t id, node *meshNode){
  calcu_select_eeprom(id);

#if SLOW
  RegistedType isReg = 0;
  slow_read(_isregiste_eeprom, &isReg);
  meshNode->setRegisted(isReg);

  DeviceAddrType addr;
  slow_read(_device_addr_eeprom, &addr);
  meshNode->setAddr(addr);

  FirstType ftype = 0;
  slow_read(_firstType_eeprom, &ftype); // first type
  meshNode->setFirstType(ftype);

  SecondType stype = 0;
  slow_read(_secondType_eeprom, &stype); // second type
  meshNode->setSecondType(stype);

  GroupType group = 0;
  slow_read(_group_eeprom, &group); // group
  meshNode->setGroup(group);

  OnoffType onoff = 0;
  slow_read(_onof_eeprom, onoff); // onoff
  meshNode->setOnoff(onoff);

  LightnessType lightness = 0;
  slow_read(_lightness_eeprom, lightness); // lightness
  meshNode->setLightness(lightness);

  ModeType mode = 0;
  slow_read(_mode_eeprom, &mode);
  meshNode->setMode(mode);

  TemperatureType  temp;
  slow_read(_temperature_eeprom, &temp);
  meshNode->setTemperature(temp);

  uint8_t color_h_H = 0;
  uint8_t color_h_L = 0
  slow_read(_color_h_eeprom, &color_h_H);
  slow_read(_color_h_eeprom + 1, &color_h_L);
  ColorHType color_h = 0;
  color_h = (color_h | color_h_H << 8) | color_h_L;
  meshNode->setColorH(color_h);

  ColorSType color_s = 0;
  slow_read(_color_s_eeprom, &color_s);
  meshNode->setColorS(color_s);

  ColorVType color_v = 0;
  slow_read(_color_v_eeprom, &color_v);
  meshNode->setColorV(color_v);

  RegisterTimeType regTime = 0;
  slow_read(_registerTime_eeprom, &regTime);
  meshNode->setRegisterTime(regTime);


#else


#endif

}

void NodeDB::getNodeByAddr(uint8_t addr, node *meshNode){
  for(unsigned char i = _id; i>0; i--){
    calcu_select_eeprom(i);

    uint8_t temp = 0;
    slow_read(_device_addr_eeprom, &temp);
    if(temp == addr){
      getNodeById(i, meshNode);
      return;
    }

  }
}

void NodeDB::getNodeAddrById(uint8_t id, DeviceAddrType *addr){
  calcu_select_eeprom(id);
  uint8_t addr_h = 0;
  uint8_t addr_l = 0;
  slow_read(_device_addr_eeprom, &addr_h);
  slow_read(_device_addr_eeprom + 1, &addr_l);

  uint16_t buf = 0;
  buf = (buf | addr_h) << 8 | addr_l;
  *addr = buf;
}

void NodeDB::getNodeRegistedById(uint8_t id, RegistedType *isRegisted){
  calcu_select_eeprom(id);
  slow_read(_isregiste_eeprom, isRegisted);
}

void NodeDB::getNodeRegistedByAddr(DeviceAddrType addr, RegistedType *isRegisted){
  for(unsigned char i = _id; i>0; i--){
    calcu_select_eeprom(i);

    uint8_t temp = 0;
    slow_read(_device_addr_eeprom, &temp);
    if(temp == addr){
      slow_read(_isregiste_eeprom, isRegisted);
      return;
    }

  }
}


void NodeDB::getNodeFirstTypeById(uint8_t id, FirstType *type){
  calcu_select_eeprom(id);
  slow_read(_firstType_eeprom, type);
}

void NodeDB::getNodeFirstTypeByAddr(DeviceAddrType addr, FirstType *type){
  for(unsigned char i = _id; i>0; i--){
    calcu_select_eeprom(i);

    uint8_t temp = 0;
    slow_read(_device_addr_eeprom, &temp);
    if(temp == addr){
      slow_read(_firstType_eeprom, type);
      return;
    }

  }
}

void NodeDB::getNodeSecondTypeById(uint8_t id, SecondType *type){
  calcu_select_eeprom(id);
  slow_read(_secondType_eeprom, type);
}

void NodeDB::getNodeSecondTypeByAddr(DeviceAddrType addr, SecondType *type){
  for(unsigned char i = _id; i>0; i--){
    calcu_select_eeprom(i);

    uint8_t temp = 0;
    slow_read(_device_addr_eeprom, &temp);
    if(temp == addr){
      slow_read(_secondType_eeprom, type);
      return;
    }

  }
}

void NodeDB::getNodeGroupById(uint8_t id, GroupType *group){
  calcu_select_eeprom(id);
  slow_read(_group_eeprom, group);
}

void NodeDB::getNodeGroupByAddr(DeviceAddrType addr, GroupType *group){

}

void NodeDB::getNodeOnoffById(uint8_t id, OnoffType *onoff){
  calcu_select_eeprom(id);
  slow_read(_onof_eeprom, onoff);
}

void NodeDB::getNodeOnoffByAddr(DeviceAddrType addr, OnoffType *onoff){

}

void NodeDB::getNodeLightnessById(uint8_t id, LightnessType *lightness){
  calcu_select_eeprom(id);
  slow_read(_lightness_eeprom, lightness);
}

void NodeDB::getNodeLightnessByAddr(DeviceAddrType addr, LightnessType *lightness){

}

void NodeDB::getNodeModeById(uint8_t id, ModeType *mode){
  calcu_select_eeprom(id);
  slow_read(_mode_eeprom, mode);
}

void NodeDB::getNodeModeByAddr(DeviceAddrType addr, ModeType *mode){

}

void NodeDB::getNodeTemperatureById(uint8_t id, TemperatureType *temperature){
  calcu_select_eeprom(id);
  uint8_t temp_H = 0;
  uint8_t temp_L = 0;
  slow_read(_temperature_eeprom, &temp_H);
  slow_read(_temperature_eeprom + 1, &temp_L);
  #ifdef DEBUG_DB
  DEBUG_DB.printf("color h high low bits: %02x %02x\n", temp_H, temp_L);
  #endif
  uint16_t buf = 0;
  buf = (buf | temp_H) << 8 | temp_L;
  *temperature = buf;
}

void NodeDB::getNodeTemperatureByAddr(DeviceAddrType addr, TemperatureType *temperature){

}

void NodeDB::getNodeColorHById(uint8_t id, ColorHType *color_h){
  calcu_select_eeprom(id);
  uint8_t color_H = 0;
  uint8_t color_L = 0;
  slow_read(_color_h_eeprom, &color_H);
  slow_read(_color_h_eeprom + 1, &color_L);
  #ifdef DEBUG_DB
  DEBUG_DB.printf("color h high low bits: %02x %02x\n", color_H, color_L);
  #endif
  uint16_t temp = 0;
  temp = (temp | color_H) << 8 | color_L;
  *color_h = temp;
}

void NodeDB::getNodeColorHByAddr(DeviceAddrType addr, ColorHType *color_h){

}

void NodeDB::getNodeColorSById(uint8_t id, ColorSType *color_s){
  calcu_select_eeprom(id);
  slow_read(_color_s_eeprom, color_s);
}

void NodeDB::getNodeColorSByAddr(DeviceAddrType addr, ColorSType *color_s){

}

void NodeDB::getNodeColorVById(uint8_t id, ColorVType *color_v){
  calcu_select_eeprom(id);
  slow_read(_color_v_eeprom, color_v);
}

void NodeDB::getNodeColorVByAddr(DeviceAddrType addr, ColorVType *color_v){

}

void NodeDB::getNodeRegTimeById(uint8_t id, RegisterTimeType *regTime){
  calcu_select_eeprom(id);
  unsigned char length = sizeof(RegisterTimeType);
  for(unsigned char i = 0; i<length; i++){
    uint8_t buf = 0;
    slow_read(_registerTime_eeprom + i, &buf);
    *regTime = (*regTime | buf) << 8;
  }
}

void NodeDB::getNodeRegTimeByAddr(DeviceAddrType addr, RegisterTimeType *regTime){

}

void NodeDB::updateRegistedById(uint8_t id, RegistedType isRegisted){
  calcu_select_eeprom(id);
  slow_write(_isregiste_eeprom, isRegisted);
}

void NodeDB::updateRegistedByAddr(DeviceAddrType addr, RegistedType isRegisted){

}

void NodeDB::updateFirstTypeById(uint8_t id, FirstType type){
  calcu_select_eeprom(id);
  slow_write(_firstType_eeprom, type);
}

void NodeDB::updateFirstTypeByAddr(DeviceAddrType addr, FirstType type){

}

void NodeDB::updateSecondTypeById(uint8_t id, SecondType type){
  calcu_select_eeprom(id);
  slow_write(_secondType_eeprom, type);
}

void NodeDB::updateSecondTypeByAddr(DeviceAddrType addr, SecondType type){

}

void NodeDB::updateGroupById(uint8_t id, GroupType group){
  calcu_select_eeprom(id);
  slow_write(_group_eeprom, group);
}

void NodeDB::updateGroupByAddr(DeviceAddrType addr, GroupType group){

}

void NodeDB::updateOnoffById(uint8_t id, OnoffType onoff){
  calcu_select_eeprom(id);
  slow_write(_onof_eeprom, onoff);
}

void NodeDB::updateOnoffByAddr(DeviceAddrType addr, OnoffType onoff){

}

void NodeDB::updateModeById(uint8_t id, ModeType mode){
  calcu_select_eeprom(id);
  slow_write(_mode_eeprom, mode);
}

void NodeDB::updateModeByAddr(DeviceAddrType addr, ModeType mode){

}

void NodeDB::updateTemperatureById(uint8_t id, TemperatureType temperature){
  calcu_select_eeprom(id);
  slow_write(_temperature_eeprom, temperature);
}

void NodeDB::updateTemperatureByAddr(DeviceAddrType addr, TemperatureType temperature){

}

void NodeDB::updateColorHById(uint8_t id, ColorHType color_h){
  calcu_select_eeprom(id);
  slow_write(_color_h_eeprom, color_h >> 8);
  slow_write(_color_h_eeprom + 1, color_h | 0XFF);
}

void NodeDB::updateColorHByAddr(DeviceAddrType addr, ColorHType color_h){

}

void NodeDB::updateColorSById(uint8_t id, ColorSType color_s){
  calcu_select_eeprom(id);
  slow_write(_color_s_eeprom, color_s);
}

void NodeDB::updateColorSByAddr(DeviceAddrType addr, ColorSType color_s){

}

void NodeDB::updateColorVById(uint8_t id, ColorVType color_v){
  calcu_select_eeprom(id);
  slow_write(_color_v_eeprom, color_v);
}

void NodeDB::updateColorVByAddr(DeviceAddrType addr, ColorVType color_v){

}

void NodeDB::updateRegTimeById(uint8_t id, RegisterTimeType regTime){
  calcu_select_eeprom(id);
  unsigned char length = sizeof(RegisterTimeType);
  for(unsigned char i = 0; i<length; i++){
    slow_write(_registerTime_eeprom + i, regTime & 0XFF000000);
    regTime = regTime << 8;

  }

}

void NodeDB::updateRegTimeByAddr(DeviceAddrType addr, RegisterTimeType regTime){

}

unsigned int NodeDB::count(){
  return (_id - 1);
}

void NodeDB::deleteNodeById(uint8_t id){
  int start_addr = (id - 1) * (sizeof(node) + 1) + _start;
  for(unsigned char i = 0; i < sizeof(node); i++){
    slow_write(start_addr + i, 0);
    EEPROM.commit();
  }
}

void NodeDB::deleteNodeByAddr(DeviceAddrType addr){

}

void NodeDB::slow_write(int addr, uint8_t value){
  EEPROM.write(addr, value);
  EEPROM.commit();
}

void NodeDB::slow_read(int addr, uint8_t *value){
  *value = EEPROM.read(addr);
}

void NodeDB::fast_write(int addr, uint8_t value){

}

void NodeDB::fast_read(int addr, uint8_t *value){

}
