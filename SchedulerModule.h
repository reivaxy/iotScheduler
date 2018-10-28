/**
 *  iotinator Scheduler module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 
#include "config.h"
#include <XIOTModule.h>
 
class SchedulerModule:public XIOTModule {
public:
  SchedulerModule(SchedulerConfigClass* config, int displayAddr, int displaySda, int displayScl, int relayPin);
  
protected:
  bool _status = true;  
  char* _customData() override;
  char* useData(char *, int *) override;
  void setStatus(bool);
  int _relayPin;
};