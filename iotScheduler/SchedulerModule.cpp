/**
 *  iotinator Scheduler Agent module
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "SchedulerModule.h"
 
SchedulerModule::SchedulerModule(SchedulerConfigClass* config, int displayAddr, int displaySda, int displayScl, int relayPin):XIOTModule(config, displayAddr, displaySda, displayScl) {
  _relayPin = relayPin;
  pinMode(relayPin, OUTPUT);
  _oledDisplay->setLineAlignment(2, TEXT_ALIGN_CENTER);
  setStatus(false);
}

char* SchedulerModule::_customData() {
//  Serial.println("SchedulerModule::_customData");
  char* data = (char *)malloc(100);
  sprintf(data, "{\"status\":\"%s\"}", _status ? "on": "off");
  return data;  
}

char* SchedulerModule::useData(char* data, int* httpCode) {
Serial.println("scheduler");
Serial.println(data);
  const int bufferSize = 2*JSON_OBJECT_SIZE(1);
  StaticJsonBuffer<bufferSize> jsonBuffer;   
  JsonObject& root = jsonBuffer.parseObject(data); 
  if (!root.success()) {
    _oledDisplay->setLine(1, "Got bad data", TRANSIENT, NOT_BLINKING);
  } else {
    const char *status = (const char*)root["status"];
    if(strcmp(status, "on") == 0) {
      setStatus(true);
    } else {
      setStatus(false);
    }
  }
  *httpCode = 200;
  return emptyMallocedResponse();
}

void SchedulerModule::setStatus(bool status) {
  _status = status;
  digitalWrite(_relayPin, _status ? HIGH : LOW);
  char message[100];
  sprintf(message, "Scheduler is %s", _status ? "ON": "OFF");
  _oledDisplay->setLine(2, message, NOT_TRANSIENT, NOT_BLINKING);
}