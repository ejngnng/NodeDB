#include <Arduino.h>
#include "NodeDB.h"

void setup() {
    Serial.begin(115200);
}

void loop() {

    Serial.printf("unsigned long size: %d\n", sizeof(unsigned long));
    Serial.printf("unsigned int size: %d\n", sizeof(unsigned int));
    delay(500);
}
