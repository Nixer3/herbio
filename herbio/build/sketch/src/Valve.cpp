#line 1 "/home/nixer/Desktop/arduino/herbio/src/Valve.cpp"
#include "Valve.hpp"
#include "Pump.hpp"
#include <Arduino.h>

Valve::Valve(byte id, byte pin, const char* name, Pump *pump) : Entity(id,name) {
  this->pin = pin;
  this->pump = pump;
  pinMode(pin, OUTPUT);
}

bool Valve::open(){
  if(this->opened) return; //already opened
  digitalWrite(pin, HIGH);
  this->opened = true;
  pump->up();
}

bool Valve::close() {
  if(!this->opened) return;//already closed
  digitalWrite(pin, LOW);
  this->opened = false;
   pump->down();
}


JsonObject Valve::toJson(JsonDocument &doc) {
  JsonObject json = Entity::toJson(doc);
  json["value"] = this->opened;
  return json;
}
void Valve::dump(byte* buffer){
  memcpy(buffer, this, sizeof(Valve));
}
void Valve::load(byte* buffer) {
  memcpy(this, buffer, sizeof(Valve));
}
byte Valve::size() {
  return sizeof(Valve);
}
