/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CMSISRTOS_9D881823_0A3B_4E45_B5C7_EDF387D559D9
#define CMSISRTOS_9D881823_0A3B_4E45_B5C7_EDF387D559D9

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
  class CmsisRtosThread;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cmsisrtos::CmsisRtosThread extends mcuf::lang::Object implements
public mcuf::lang::rtos::InterfaceThread{

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
     * @brief Construct a new Cmsis Rtos Thread object
     * 
     */
    CmsisRtosThread(void);

    /**
     * @brief Destroy the Cmsis Rtos Thread object
     * 
     */
    virtual ~CmsisRtosThread(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */
  public:
    /**
     * @brief ???????????????????????????ID
     * 
     * @return uint32_t ?????????ID
     */
    virtual uint32_t threadGetCurrentID(void) const override;

    /**
     * @brief ??????????????????????????????????????????????????? READY ??????????????????????????? 
     *        ??????READY??????????????????????????????????????????????????????????????????????????????????????????????????????
     * 
     * @return true ??????????????????????????????????????????
     * @return false ?????????????????????????????????????????????????????????????????????????????????
     */
    virtual bool threadYield(void) const override;

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t threadGetHandlerSize(void) const override;

    /**
     * @brief 
     * 
     * @return mcuf::lang::ThreadState 
     */
    virtual mcuf::lang::ThreadState threadGetState(const mcuf::lang::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @param name 
     */
    virtual void threadSetName(mcuf::lang::Memory& handler, const char* name) override;
    
    /**
     * @brief 
     * 
     * @param handler 
     * @return uint32_t 
     */
    virtual uint32_t threadGetID(const mcuf::lang::Memory& handler) const override;
    
    /**
     * @brief 
     * 
     * @param thread 
     * @return const char* 
     */
    virtual const char* threadGetName(const mcuf::lang::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return mcuf::lang::ThreadPriority 
     */
    virtual mcuf::lang::ThreadPriority threadGetPriority(const mcuf::lang::Memory& handler) const override;
      
    /**
     * @brief 
     * 
     * @param handler 
     * @param priority 
     * @param stackMemory 
     * @param runnable 
     * @return true 
     * @return false 
     */
    virtual bool threatStart(mcuf::lang::Memory& handler, mcuf::lang::ThreadPriority priority, mcuf::lang::Memory& stackMemory, mcuf::function::Runnable& runnable) override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return mcuf::lang::ThreadPriority 
     */
    virtual bool threadSetPriority(mcuf::lang::Memory& handler,  mcuf::lang::ThreadPriority) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return true 
     * @return false 
     */
    virtual bool threadExit(mcuf::lang::Memory& handler) override;
    
    /**
     * @brief 
     * 
     * @param thread 
     * @return int 
     */
    virtual int threadGetStackSize(const mcuf::lang::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param thread 
     * @return true 
     * @return false 
     */
    virtual bool threadNotify(const mcuf::lang::Memory& handler) const override;

    /**
     * @brief 
     * 
     * @param threadID 
     * @return true 
     * @return false 
     */
    virtual bool threadNotify(uint32_t threadID) const override;

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

#endif /* CMSISRTOS_9D881823_0A3B_4E45_B5C7_EDF387D559D9 */
