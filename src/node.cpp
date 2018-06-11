/*
 * Description: node database header file
 *
 * Author: ninja
 *
 * Date: 2018-06-08
 */
#include "node.h"

node::node(){
  memset(&_node, 0, sizeof(NODE_META));
}

node::node(uint16_t addr){
  memset(&_node, 0, sizeof(NODE_META));
  _node.device_addr = addr;
}

void node::getSize(uint8_t *size){
  *size = sizeof(NODE_META);
}

bool node::isRegisted(){
  if(_node.isRegisted){
    return true;
  }else{
    return false;
  }
}
void node::setRegisted(bool registed){
  if(registed){
    _node.isRegisted = 1;
  }else{
    _node.isRegisted = 0;
  }
}

void node::setAddr(DeviceAddrType addr){
  _node.device_addr = addr;
}

DeviceAddrType node::getAddr(){
  return _node.device_addr;
}

void node::setType(uint16_t type){
  _node.firstType = type >> 8;
  _node.secondType = type & 0XFF;
}

uint16_t node::getType(){
  uint16_t temp = 0;
  temp = (temp | _node.firstType) << 8 | _node.secondType;
  return temp;
}

void node::setFirstType(FirstType type){
  _node.firstType = type;
}

FirstType node::getFirstType(){
  return _node.firstType;
}

void node::setSecondType(SecondType type){
  _node.secondType = type;
}

SecondType node::getSecondType(){
  return _node.secondType;
}

void node::setGroup(GroupType group){
  _node.group = group;
}

GroupType node::getGroup(){
  return _node.group;
}

void node::setOnoff(OnoffType value){
  _node.onoff = value;
}

OnoffType node::getOnoff(){
  return  _node.onoff;
}

void node::setLightness(LightnessType value){
  _node.lightness = value;
}

LightnessType node::getLightness(){
  return _node.lightness;
}

void node::setMode(ModeType value){
  _node.mode = value;
}

ModeType node::getMode(){
  return _node.mode;
}

void node::setTemperature(TemperatureType value){
  _node.temperature = value;
}

TemperatureType node::getTemperature(){
  return _node.temperature;
}

void node::setColorH(ColorHType value){
  _node.color_h = value;
}

void node::setColorS(ColorSType value){
  _node.color_s = value;
}

void node::setColorV(ColorVType value){
  _node.color_v = value;
}

ColorHType node::getColorH(){
  return _node.color_h;
}

ColorSType node::getColorS(){
  return _node.color_s;
}

ColorVType node::getColorV(){
  return _node.color_v;
}

void node::setRegisterTime(RegisterTimeType value){
  _node.registerTime = value;
}

RegisterTimeType node::getRegisterTime(){
  return _node.registerTime;
}
