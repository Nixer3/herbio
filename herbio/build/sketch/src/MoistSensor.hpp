#line 1 "C:\\Users\\Matej-Windows\\Desktop\\sem8\\TP2\\arduino\\herbio\\src\\MoistSensor.hpp"
#ifndef MOISTSENSOR_H
#define MOISTSENSOR_H

#include "Entity.hpp"
#include "Measurable.hpp"
#include <ArduinoJson.h>
#include <Arduino.h>

class MoistureSensor : public Entity, public Measurable {
  private:
    byte pin;
    int value;
    
  public:
    MoistureSensor();
    MoistureSensor(byte id, byte pin, const char* name);
     JsonObject toJson(JsonDocument &doc) ;
     float measure();
     Measurable* getMeasurable();
     void dump(byte* buffer);
     void load(byte* buffer);
};

#endif


