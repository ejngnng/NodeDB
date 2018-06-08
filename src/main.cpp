#include <Arduino.h>
#include "NodeDB.h"

void setup() {
    Serial.begin(115200);
}

void loop() {

    Serial.printf("unsigned long size: %d\n", sizeof(unsigned long));
    Serial.printf("unsigned int size: %d\n", sizeof(unsigned int));
    node meshNode;
    uint8_t size = 0;
    meshNode.getSize(&size);
    Serial.printf("node size: %d\n", size);
    delay(500);
}
