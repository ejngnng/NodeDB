/*
 * Description: node database source file
 *
 * Author: ninja
 *
 * Date: 2018-06-08
 */
#include "NodeDB.h"

NodeDB::NodeDB()
  : _id(1)
  , _start(0)
  , _addr(0)
  , _counter(0)
{
  memset(_name, 0, 6);
  memset(&_meshNode, 0, sizeof(node));
}


NodeDB::NodeDB(int start)
  : _id(1)
  , _start(0)
  , _addr(0)
  , _counter(0)
{
  
}
