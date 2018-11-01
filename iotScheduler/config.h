/**
 *  Definition of the config data structure for the iotScheduler module and the class to persist it to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XIOTConfig.h>
#include <XUtils.h>

#define CONFIG_VERSION 1
#define MODULE_NAME "Scheduler"

struct SchedulerConfigStruct:ModuleConfigStruct {
  // Add config fields needed if any
};

class SchedulerConfigClass:public ModuleConfigClass {
public:
  SchedulerConfigClass(unsigned int version, const char* name);
  void initFromDefault();
  const char* getDefaultUIClassName() override;

protected:
  SchedulerConfigStruct* _getDataPtr(void);  
};
