/**
 *  Class to persist the iotScheduler module configuration data structure to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "config.h"


SchedulerConfigClass::SchedulerConfigClass(unsigned int version, const char* name):ModuleConfigClass(version, "iotscheduler", name, sizeof(SchedulerConfigStruct)) {
}

/**
 * Reset the config data structure to the default values.
 * This is done each time the data structure version is different from the one saved in EEPROM
 * NB: version and name are handled by base class 
 */
void SchedulerConfigClass::initFromDefault() {
  ModuleConfigClass::initFromDefault(); // handles version and name init, ssid and pwd

}

const char* SchedulerConfigClass::getDefaultUIClassName() {
  Serial.println("SchedulerConfigClass::getDefaultUIClassName");
  return "schedulerUIClass";
}

/**
 * Return the typed data structure object
 *
 */
SchedulerConfigStruct* SchedulerConfigClass::_getDataPtr(void) {
  return (SchedulerConfigStruct*)ModuleConfigClass::_getDataPtr();
}