/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CMSISRTOS_B8299F1B_6D5F_4D4A_B524_B23A774599B7
#define CMSISRTOS_B8299F1B_6D5F_4D4A_B524_B23A774599B7

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace cmsisrtos{
  class CmsisRtosTimer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cmsisrtos::CmsisRtosTimer extends mcuf::lang::Object implements 
public mcuf::lang::rtos::InterfaceTimer{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 
    /**
     * @brief Construct a new Cmsis Rtos Timer object
     * 
     */
    CmsisRtosTimer(void);
    /**
     * @brief Destroy the Cmsis Rtos Timer object
     * 
     */
    virtual ~CmsisRtosTimer(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::rtos::InterfaceTimer
   */
  public:
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t timerGetHandlerSize(void) const override;

    /**
     * @brief 
     * 
     * @param timerTask 
     * @param delay ???????????? ??????ms
     * @param mode false = ??????; true = ??????
     * @param runnable ???????????????
     * @return true TimerID
     */
    virtual bool timerStart(mcuf::lang::Memory& handler, uint32_t delay, bool mode, mcuf::function::Runnable& runnable) override;

    /**
     * @brief ??????Timer
     * 
     * @param timerTask 
     * @return true ????????????
     * @return false Timer????????????
     */
    virtual bool timerStop(mcuf::lang::Memory& handler) override;

    /**
     * @brief ??????timer???????????????
     * 
     * @param timerTask 
     * @return true Timer????????????
     * @return false Timer????????????
     */
    virtual bool timerIsStart(mcuf::lang::Memory& handler) override;
    
    /**
     * @brief 
     * 
     * @param handler 
     * @return uint32_t 
     */
    virtual uint32_t timerGetID(mcuf::lang::Memory& handler) override;
    
  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */
  private:
    
    /**
     * @brief 
     * 
     * @param attachment 
     */
    static void entryPoint(void* attachment);

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* CMSISRTOS_B8299F1B_6D5F_4D4A_B524_B23A774599B7 */
