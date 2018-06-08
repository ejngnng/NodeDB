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

#define NODE_MAX_SIZE 256


class NodeDB{
public:
  NodeDB();
  ~NodeDB(){};
  bool insert();
  bool get();
  bool update();
  unsigned int counte();

private:
  unsigned char _name[6];
  unsigned char _id;     // auto increase
  unsigned char _addr;
  node _node;



};

#endif
