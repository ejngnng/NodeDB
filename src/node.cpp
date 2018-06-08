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

void node::setAddr(uint16_t addr){
  _node.device_addr = addr;
}

void node::getAddr(uint16_t *addr){
  *addr = _node.device_addr;
}

void node::setType(uint16_t type){
  _node.firstType = type >> 8;
  _node.secondType = type & 0XFF;
}

void node::getType(uint16_t *type){
  uint16_t temp = 0;
  *type = (temp | _node.firstType) << 8 | _node.secondType;
}

void node::setFirstType(uint8_t type){
  _node.firstType = type;
}

void node::getFirstType(uint8_t *type){
  *type = _node.firstType;
}

void node::setSecondType(uint8_t type){
  _node.secondType = type;
}

void node::getSecondType(uint8_t *type){
  *type = _node.secondType;
}

void node::setGroup(uint8_t group){
  _node.group = group;
}

void node::getGroup(uint8_t *group){
  *group = _node.group;
}

void node::setOnoff(uint8_t value){
  _node.onoff = value;
}

void node::getOnoff(uint8_t *value){
  *value = _node.onoff;
}

void node::setLightness(uint8_t value){
  _node.lightness = value;
}

void node::getLightness(uint8_t *value){
  *value = _node.lightness;
}

void node::setMode(uint8_t value){
  _node.mode = value;
}

void node::getMode(uint8_t *value){
  *value = _node.mode;
}

void node::setTemperature(uint16_t value){
  _node.temperature = value;
}

void node::getTemperature(uint16_t *value){
  *value = _node.temperature;
}

void node::setColorH(uint16_t value){
  _node.color_h = value;
}

void node::setColorS(uint8_t value){
  _node.color_s = value;
}

void node::setColorV(uint8_t value){
  _node.color_v = value;
}

void node::getColorH(uint16_t *value){
  *value = _node.color_h;
}

void node::getColorS(uint8_t *value){
  *value = _node.color_s;
}

void node::getColorV(uint8_t *value){
  *value = _node.color_v;
}

void node::setRegisterTime(uint32_t value){
  _node.registerTime = value;
}

void node::getRegisterTime(uint32_t *value){
  *value = _node.registerTime;
}
