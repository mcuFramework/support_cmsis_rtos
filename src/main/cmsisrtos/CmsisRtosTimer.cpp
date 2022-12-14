/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "cmsis_os2.h"
#include "rtx_os.h"

//-----------------------------------------------------------------------------------------
#include "cmsisrtos/CmsisRtosTimer.h"

/* ****************************************************************************************
 * Tyoedef Struct
 */
namespace cmsisrtos{
  typedef struct _cmsis_rtos_timer_memory_t{
    osRtxTimer_t handler;
    osTimerId_t id;
  }cmsis_rtos_timer_memory_t;
}

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using cmsisrtos::CmsisRtosTimer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Cmsis Rtos Timer object
 * 
 */
CmsisRtosTimer::CmsisRtosTimer(void){
  return;
}

/**
 * @brief Destroy the Cmsis Rtos Timer object
 * 
 */
CmsisRtosTimer::~CmsisRtosTimer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::rtos::InterfaceTimer
 */

/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t CmsisRtosTimer::timerGetHandlerSize(void) const{
  return sizeof(cmsis_rtos_timer_memory_t);
}

/**
 * @brief 
 * 
 * @param timerTask 
 * @param delay ???????????? ??????ms
 * @param mode false = ??????; true = ??????
 * @param runnable ???????????????
 * @return true TimerID
 */
bool CmsisRtosTimer::timerStart(mcuf::lang::Memory& handler, uint32_t delay, bool mode, mcuf::function::Runnable& runnable){
  cmsis_rtos_timer_memory_t* h  = static_cast<cmsis_rtos_timer_memory_t*>(handler.pointer());
  
  if(CmsisRtosTimer::timerIsStart(handler) == true)
    return false;
  
  osTimerAttr_t attr;
  attr.name = "";
  attr.attr_bits = 0;
  attr.cb_mem = &h->handler;
  attr.cb_size = sizeof(h->handler);
  
  if(mode)
    h->id = osTimerNew(CmsisRtosTimer::entryPoint, osTimerOnce, &runnable, &attr);
  else
    h->id = osTimerNew(CmsisRtosTimer::entryPoint, osTimerPeriodic, &runnable, &attr);
  
  return (osTimerStart(h->id, delay) == osOK);
}

/**
 * @brief ??????Timer
 * 
 * @param timerTask 
 * @return true ????????????
 * @return false Timer????????????
 */
bool CmsisRtosTimer::timerStop(mcuf::lang::Memory& handler){
  cmsis_rtos_timer_memory_t* h  = static_cast<cmsis_rtos_timer_memory_t*>(handler.pointer());
  
  if(CmsisRtosTimer::timerIsStart(handler) == false)
    return false;
  
  if(osTimerStop(h->id) != osOK)
    return false;
  
  h->id = static_cast<osTimerId_t>(nullptr);
  return true;
}

/**
 * @brief ??????timer???????????????
 * 
 * @param timerTask 
 * @return true Timer????????????
 * @return false Timer????????????
 */
bool CmsisRtosTimer::timerIsStart(mcuf::lang::Memory& handler){
  cmsis_rtos_timer_memory_t* h  = static_cast<cmsis_rtos_timer_memory_t*>(handler.pointer());
  
  if(static_cast<void*>(h->id) == nullptr)
    return false;
  
  return osTimerIsRunning(h->id);
}

/**
 * @brief 
 * 
 * @param handler 
 * @return uint32_t 
 */
uint32_t CmsisRtosTimer::timerGetID(mcuf::lang::Memory& handler){
  cmsis_rtos_timer_memory_t* h  = static_cast<cmsis_rtos_timer_memory_t*>(handler.pointer());
  return reinterpret_cast<uint32_t>(h->id);
}
/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
/**
 * @brief 
 * 
 * @param attachment 
 */
void CmsisRtosTimer::entryPoint(void* attachment){
  mcuf::function::Runnable* runnable = static_cast<mcuf::function::Runnable*>(attachment);
  runnable->run();
}

/* ****************************************************************************************
 * End of file
 */
