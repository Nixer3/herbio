#include "Section.hpp"



Section::Section() {}

Section::Section(byte id,String name, byte min_humid, time_t water_time, Valve *valve) : Entity(id,name){
  this->min_humid  = min_humid;
  this->water_time = water_time;
  this->valve = valve;
}

Section* Section::setValve(Valve *valve) {
  this->valve = valve;
  return this;
}

Section* Section::setTimer(time_t time_start, time_t time_end) {
  this->timer_start = time_start;
  this->timer_end = time_end;
  return this;
}

Section* Section::setMinHumid(byte min_humid) {
  this->min_humid = min_humid;
  return this;
}

Section* Section::setWaterTime(time_t water_time) {
  this->water_time = water_time;
  return this;
}

Section* Section::setMoistureSensor(MoistureSensor *sensor) {
  this->moisture = sensor;
  return this;
}

JsonObject Section::toJson(JsonDocument &doc) {
  JsonObject json = Entity::toJson(doc);
  json["water_time"]  = this->water_time;
  json["min_humidity"]= this->min_humid;
  json["valve"]       = this->valve->toJson(doc);
  json["moisture"]    = this->moisture->toJson(doc);
  return json;
}

boolean Section::update(JsonObject &obj) {
  if(obj["id"] != this->id)
    return false;
  this->name      = obj["name"].as<String>() ;
  this->water_time= obj["water_time"].as<int>();
  this->min_humid = obj["min_humidity"].as<int>();
  //this->moisture = getEntity(obj["moisture"].as<int>());
  return true;
}