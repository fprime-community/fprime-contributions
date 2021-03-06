// ======================================================================
// \title  LLCmdDispatcher/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for LLCmdDispatcher component test harness base class
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
//
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ======================================================================

#include <stdlib.h>
#include <string.h>
#include "TesterBase.hpp"

namespace LLProc {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  LLCmdDispatcherTesterBase ::
    LLCmdDispatcherTesterBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
#if FW_OBJECT_NAMES == 1
      Fw::PassiveComponentBase(compName)
#else
      Fw::PassiveComponentBase()
#endif
  {
    // Initialize command history
    this->cmdResponseHistory = new History<CmdResponse>(maxHistorySize);
    // Initialize telemetry histories
    this->tlmHistory_CommandsDispatched = 
      new History<TlmEntry_CommandsDispatched>(maxHistorySize);
    this->tlmHistory_CommandErrors = 
      new History<TlmEntry_CommandErrors>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_OpCodeRegistered =
      new History<EventEntry_OpCodeRegistered>(maxHistorySize);
    this->eventHistory_OpCodeDispatched =
      new History<EventEntry_OpCodeDispatched>(maxHistorySize);
    this->eventHistory_OpCodeCompleted =
      new History<EventEntry_OpCodeCompleted>(maxHistorySize);
    this->eventHistory_OpCodeError =
      new History<EventEntry_OpCodeError>(maxHistorySize);
    this->eventHistory_MalformedCommand =
      new History<EventEntry_MalformedCommand>(maxHistorySize);
    this->eventHistory_InvalidCommand =
      new History<EventEntry_InvalidCommand>(maxHistorySize);
    this->eventHistory_TooManyCommands =
      new History<EventEntry_TooManyCommands>(maxHistorySize);
    this->eventHistory_NoOpStringReceived =
      new History<EventEntry_NoOpStringReceived>(maxHistorySize);
    this->eventHistory_TestCmd1Args =
      new History<EventEntry_TestCmd1Args>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_compCmdSend =
      new History<FromPortEntry_compCmdSend>(maxHistorySize);
    this->fromPortHistory_seqCmdStatus =
      new History<FromPortEntry_seqCmdStatus>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  LLCmdDispatcherTesterBase ::
    ~LLCmdDispatcherTesterBase(void) 
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy telemetry histories
    delete this->tlmHistory_CommandsDispatched;
    delete this->tlmHistory_CommandErrors;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_OpCodeRegistered;
    delete this->eventHistory_OpCodeDispatched;
    delete this->eventHistory_OpCodeCompleted;
    delete this->eventHistory_OpCodeError;
    delete this->eventHistory_MalformedCommand;
    delete this->eventHistory_InvalidCommand;
    delete this->eventHistory_TooManyCommands;
    delete this->eventHistory_NoOpStringReceived;
    delete this->eventHistory_TestCmd1Args;
  }

  void LLCmdDispatcherTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port compCmdSend

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_compCmdSend();
        ++_port
    ) {

      this->m_from_compCmdSend[_port].init();
      this->m_from_compCmdSend[_port].addCallComp(
          this,
          from_compCmdSend_static
      );
      this->m_from_compCmdSend[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_compCmdSend[%d]",
          this->m_objName,
          _port
      );
      this->m_from_compCmdSend[_port].setObjName(_portName);
#endif

    }

    // Attach input port seqCmdStatus

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_seqCmdStatus();
        ++_port
    ) {

      this->m_from_seqCmdStatus[_port].init();
      this->m_from_seqCmdStatus[_port].addCallComp(
          this,
          from_seqCmdStatus_static
      );
      this->m_from_seqCmdStatus[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_seqCmdStatus[%d]",
          this->m_objName,
          _port
      );
      this->m_from_seqCmdStatus[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdStatus

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdStatus();
        ++_port
    ) {

      this->m_from_CmdStatus[_port].init();
      this->m_from_CmdStatus[_port].addCallComp(
          this,
          from_CmdStatus_static
      );
      this->m_from_CmdStatus[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdStatus[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdStatus[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdReg

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdReg();
        ++_port
    ) {

      this->m_from_CmdReg[_port].init();
      this->m_from_CmdReg[_port].addCallComp(
          this,
          from_CmdReg_static
      );
      this->m_from_CmdReg[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdReg[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdReg[_port].setObjName(_portName);
#endif

    }

    // Attach input port Tlm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Tlm();
        ++_port
    ) {

      this->m_from_Tlm[_port].init();
      this->m_from_Tlm[_port].addCallComp(
          this,
          from_Tlm_static
      );
      this->m_from_Tlm[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Tlm[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Tlm[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Attach input port Log

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Log();
        ++_port
    ) {

      this->m_from_Log[_port].init();
      this->m_from_Log[_port].addCallComp(
          this,
          from_Log_static
      );
      this->m_from_Log[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Log[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Log[_port].setObjName(_portName);
#endif

    }

    // Attach input port LogText

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_LogText();
        ++_port
    ) {

      this->m_from_LogText[_port].init();
      this->m_from_LogText[_port].addCallComp(
          this,
          from_LogText_static
      );
      this->m_from_LogText[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_LogText[%d]",
          this->m_objName,
          _port
      );
      this->m_from_LogText[_port].setObjName(_portName);
#endif

    }
#endif

    // Initialize output port compCmdReg

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_compCmdReg();
        ++_port
    ) {
      this->m_to_compCmdReg[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_compCmdReg[%d]",
          this->m_objName,
          _port
      );
      this->m_to_compCmdReg[_port].setObjName(_portName);
#endif

    }

    // Initialize output port compCmdStat

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_compCmdStat();
        ++_port
    ) {
      this->m_to_compCmdStat[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_compCmdStat[%d]",
          this->m_objName,
          _port
      );
      this->m_to_compCmdStat[_port].setObjName(_portName);
#endif

    }

    // Initialize output port seqCmdBuff

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_seqCmdBuff();
        ++_port
    ) {
      this->m_to_seqCmdBuff[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_seqCmdBuff[%d]",
          this->m_objName,
          _port
      );
      this->m_to_seqCmdBuff[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_compCmdSend(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_compCmdSend);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_to_compCmdReg(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_compCmdReg);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_to_compCmdStat(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_compCmdStat);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_seqCmdStatus(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_seqCmdStatus);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_to_seqCmdBuff(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_seqCmdBuff);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_to_CmdDisp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_CmdDisp);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_CmdStatus(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdStatus);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_CmdReg(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdReg);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_Tlm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Tlm);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_Log(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Log);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE LLCmdDispatcherTesterBase ::
    getNum_from_LogText(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_LogText);
  }
#endif

  // ----------------------------------------------------------------------
  // Connectors for to ports 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    connect_to_compCmdReg(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdRegPort *const compCmdReg
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_compCmdReg(),static_cast<AssertArg>(portNum));
    this->m_to_compCmdReg[portNum].addCallPort(compCmdReg);
  }

  void LLCmdDispatcherTesterBase ::
    connect_to_compCmdStat(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdResponsePort *const compCmdStat
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_compCmdStat(),static_cast<AssertArg>(portNum));
    this->m_to_compCmdStat[portNum].addCallPort(compCmdStat);
  }

  void LLCmdDispatcherTesterBase ::
    connect_to_seqCmdBuff(
        const NATIVE_INT_TYPE portNum,
        Fw::InputComPort *const seqCmdBuff
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_seqCmdBuff(),static_cast<AssertArg>(portNum));
    this->m_to_seqCmdBuff[portNum].addCallPort(seqCmdBuff);
  }

  void LLCmdDispatcherTesterBase ::
    connect_to_CmdDisp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const CmdDisp
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(),static_cast<AssertArg>(portNum));
    this->m_to_CmdDisp[portNum].addCallPort(CmdDisp);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    invoke_to_compCmdReg(
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode
    )
  {
    FW_ASSERT(portNum < this->getNum_to_compCmdReg(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_compCmdReg(),static_cast<AssertArg>(portNum));
    this->m_to_compCmdReg[portNum].invoke(
        opCode
    );
  }

  void LLCmdDispatcherTesterBase ::
    invoke_to_compCmdStat(
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    FW_ASSERT(portNum < this->getNum_to_compCmdStat(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_compCmdStat(),static_cast<AssertArg>(portNum));
    this->m_to_compCmdStat[portNum].invoke(
        opCode, cmdSeq, response
    );
  }

  void LLCmdDispatcherTesterBase ::
    invoke_to_seqCmdBuff(
        const NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data,
        U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_seqCmdBuff(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_seqCmdBuff(),static_cast<AssertArg>(portNum));
    this->m_to_seqCmdBuff[portNum].invoke(
        data, context
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool LLCmdDispatcherTesterBase ::
    isConnected_to_compCmdReg(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_compCmdReg(), static_cast<AssertArg>(portNum));
    return this->m_to_compCmdReg[portNum].isConnected();
  }

  bool LLCmdDispatcherTesterBase ::
    isConnected_to_compCmdStat(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_compCmdStat(), static_cast<AssertArg>(portNum));
    return this->m_to_compCmdStat[portNum].isConnected();
  }

  bool LLCmdDispatcherTesterBase ::
    isConnected_to_seqCmdBuff(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_seqCmdBuff(), static_cast<AssertArg>(portNum));
    return this->m_to_seqCmdBuff[portNum].isConnected();
  }

  bool LLCmdDispatcherTesterBase ::
    isConnected_to_CmdDisp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(), static_cast<AssertArg>(portNum));
    return this->m_to_CmdDisp[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------
 
  Fw::InputCmdPort *LLCmdDispatcherTesterBase ::
    get_from_compCmdSend(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_compCmdSend(),static_cast<AssertArg>(portNum));
    return &this->m_from_compCmdSend[portNum];
  }

  Fw::InputCmdResponsePort *LLCmdDispatcherTesterBase ::
    get_from_seqCmdStatus(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_seqCmdStatus(),static_cast<AssertArg>(portNum));
    return &this->m_from_seqCmdStatus[portNum];
  }

  Fw::InputCmdResponsePort *LLCmdDispatcherTesterBase ::
    get_from_CmdStatus(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdStatus(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdStatus[portNum];
  }

  Fw::InputCmdRegPort *LLCmdDispatcherTesterBase ::
    get_from_CmdReg(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdReg(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdReg[portNum];
  }

  Fw::InputTlmPort *LLCmdDispatcherTesterBase ::
    get_from_Tlm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Tlm(),static_cast<AssertArg>(portNum));
    return &this->m_from_Tlm[portNum];
  }

  Fw::InputTimePort *LLCmdDispatcherTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputLogPort *LLCmdDispatcherTesterBase ::
    get_from_Log(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Log(),static_cast<AssertArg>(portNum));
    return &this->m_from_Log[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *LLCmdDispatcherTesterBase ::
    get_from_LogText(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_LogText(),static_cast<AssertArg>(portNum));
    return &this->m_from_LogText[portNum];
  }
#endif

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    from_compCmdSend_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {
    FW_ASSERT(callComp);
    LLCmdDispatcherTesterBase* _testerBase = 
      static_cast<LLCmdDispatcherTesterBase*>(callComp);
    _testerBase->from_compCmdSend_handlerBase(
        portNum,
        opCode, cmdSeq, args
    );
  }

  void LLCmdDispatcherTesterBase ::
    from_seqCmdStatus_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    FW_ASSERT(callComp);
    LLCmdDispatcherTesterBase* _testerBase = 
      static_cast<LLCmdDispatcherTesterBase*>(callComp);
    _testerBase->from_seqCmdStatus_handlerBase(
        portNum,
        opCode, cmdSeq, response
    );
  }

  void LLCmdDispatcherTesterBase ::
    from_CmdStatus_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
  {
    LLCmdDispatcherTesterBase* _testerBase =
      static_cast<LLCmdDispatcherTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void LLCmdDispatcherTesterBase ::
    from_CmdReg_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void LLCmdDispatcherTesterBase ::
    from_Tlm_static(
        Fw::PassiveComponentBase *const component,
        NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    LLCmdDispatcherTesterBase* _testerBase =
      static_cast<LLCmdDispatcherTesterBase*>(component);
    _testerBase->dispatchTlm(id, timeTag, val);
  }

  void LLCmdDispatcherTesterBase ::
    from_Log_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    LLCmdDispatcherTesterBase* _testerBase =
      static_cast<LLCmdDispatcherTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void LLCmdDispatcherTesterBase ::
    from_LogText_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    LLCmdDispatcherTesterBase* _testerBase =
      static_cast<LLCmdDispatcherTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void LLCmdDispatcherTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    LLCmdDispatcherTesterBase* _testerBase =
      static_cast<LLCmdDispatcherTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_compCmdSend->clear();
    this->fromPortHistory_seqCmdStatus->clear();
  }

  // ---------------------------------------------------------------------- 
  // From port: compCmdSend
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    pushFromPortEntry_compCmdSend(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {
    FromPortEntry_compCmdSend _e = {
      opCode, cmdSeq, args
    };
    this->fromPortHistory_compCmdSend->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ---------------------------------------------------------------------- 
  // From port: seqCmdStatus
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    pushFromPortEntry_seqCmdStatus(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    FromPortEntry_seqCmdStatus _e = {
      opCode, cmdSeq, response
    };
    this->fromPortHistory_seqCmdStatus->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    from_compCmdSend_handlerBase(
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CmdArgBuffer &args
    )
  {
    FW_ASSERT(portNum < this->getNum_from_compCmdSend(),static_cast<AssertArg>(portNum));
    this->from_compCmdSend_handler(
        portNum,
        opCode, cmdSeq, args
    );
  }

  void LLCmdDispatcherTesterBase ::
    from_seqCmdStatus_handlerBase(
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    FW_ASSERT(portNum < this->getNum_from_seqCmdStatus(),static_cast<AssertArg>(portNum));
    this->from_seqCmdStatus_handler(
        portNum,
        opCode, cmdSeq, response
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    cmdResponseIn(
        const FwOpcodeType opCode,
        const U32 seq,
        const Fw::CommandResponse response
    )
  {
    CmdResponse e = { opCode, seq, response };
    this->cmdResponseHistory->push_back(e);
  }

  // ---------------------------------------------------------------------- 
  // Command: CMD_NO_OP
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    sendCmd_CMD_NO_OP(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = LLCmdDispatcherComponentBase::OPCODE_CMD_NO_OP + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CMD_NO_OP_STRING
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    sendCmd_CMD_NO_OP_STRING(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        const Fw::CmdStringArg& arg1
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(arg1);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = LLCmdDispatcherComponentBase::OPCODE_CMD_NO_OP_STRING + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CMD_TEST_CMD_1
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    sendCmd_CMD_TEST_CMD_1(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        I32 arg1,
        F32 arg2,
        U8 arg3
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(arg1);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));
    _status = buff.serialize(arg2);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));
    _status = buff.serialize(arg3);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = LLCmdDispatcherComponentBase::OPCODE_CMD_TEST_CMD_1 + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CMD_CLEAR_TRACKING
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    sendCmd_CMD_CLEAR_TRACKING(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = LLCmdDispatcherComponentBase::OPCODE_CMD_CLEAR_TRACKING + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  
  void LLCmdDispatcherTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {
       
    const U32 idBase = this->getIdBase();   
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          args
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }
        
  }
  
  // ----------------------------------------------------------------------
  // History 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->clearTlm();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Telemetry dispatch
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    dispatchTlm(
        const FwChanIdType id,
        const Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {

    val.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {

      case LLCmdDispatcherComponentBase::CHANNELID_COMMANDSDISPATCHED:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CommandsDispatched: %d\n", _status);
          return;
        }
        this->tlmInput_CommandsDispatched(timeTag, arg);
        break;
      }

      case LLCmdDispatcherComponentBase::CHANNELID_COMMANDERRORS:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CommandErrors: %d\n", _status);
          return;
        }
        this->tlmInput_CommandErrors(timeTag, arg);
        break;
      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void LLCmdDispatcherTesterBase ::
    clearTlm(void)
  {
    this->tlmSize = 0;
    this->tlmHistory_CommandsDispatched->clear();
    this->tlmHistory_CommandErrors->clear();
  }

  // ---------------------------------------------------------------------- 
  // Channel: CommandsDispatched
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    tlmInput_CommandsDispatched(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_CommandsDispatched e = { timeTag, val };
    this->tlmHistory_CommandsDispatched->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CommandErrors
  // ---------------------------------------------------------------------- 

  void LLCmdDispatcherTesterBase ::
    tlmInput_CommandErrors(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_CommandErrors e = { timeTag, val };
    this->tlmHistory_CommandErrors->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case LLCmdDispatcherComponentBase::EVENTID_OPCODEREGISTERED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
        U32 Opcode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Opcode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 slot;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(slot);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_DIAGNOSTIC_OpCodeRegistered(Opcode, port, slot);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_OPCODEDISPATCHED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);
        
#endif    
        U32 Opcode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Opcode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        I32 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_COMMAND_OpCodeDispatched(Opcode, port);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_OPCODECOMPLETED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 Opcode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Opcode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_COMMAND_OpCodeCompleted(Opcode);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_OPCODEERROR: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);
        
#endif    
        U32 Opcode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Opcode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(FwEnumStoreType),_argSize,sizeof(FwEnumStoreType));
        }
#endif      
        FwEnumStoreType errorInt;
        _status = args.deserialize(errorInt);
        LLCmdDispatcherComponentBase::ErrorResponse error = static_cast<LLCmdDispatcherComponentBase::ErrorResponse>(errorInt);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_OpCodeError(Opcode, error);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_MALFORMEDCOMMAND: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(FwEnumStoreType),_argSize,sizeof(FwEnumStoreType));
        }
#endif      
        FwEnumStoreType StatusInt;
        _status = args.deserialize(StatusInt);
        LLCmdDispatcherComponentBase::CmdSerError Status = static_cast<LLCmdDispatcherComponentBase::CmdSerError>(StatusInt);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_MalformedCommand(Status);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_INVALIDCOMMAND: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 Opcode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Opcode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_InvalidCommand(Opcode);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_TOOMANYCOMMANDS: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        U32 Opcode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif      
        _status = args.deserialize(Opcode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_TooManyCommands(Opcode);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_NOOPRECEIVED: 
      {

#if FW_AMPCS_COMPATIBLE
        // For AMPCS, decode zero arguments
        Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
        U8 _noArgs;
        _zero_status = args.deserialize(_noArgs);
        FW_ASSERT(
            _zero_status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_zero_status)
        );
#endif    
        this->logIn_COMMAND_NoOpReceived();

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_NOOPSTRINGRECEIVED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        Fw::LogStringArg No_op_string;
        _status = args.deserialize(No_op_string);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_COMMAND_NoOpStringReceived(No_op_string);

        break;

      }

      case LLCmdDispatcherComponentBase::EVENTID_TESTCMD1ARGS: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 3,_numArgs,3);
        
#endif    
        I32 arg1;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif      
        _status = args.deserialize(arg1);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        F32 arg2;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(arg2);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U8 arg3;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif      
        _status = args.deserialize(arg3);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_COMMAND_TestCmd1Args(arg1, arg2, arg3);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void LLCmdDispatcherTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_OpCodeRegistered->clear();
    this->eventHistory_OpCodeDispatched->clear();
    this->eventHistory_OpCodeCompleted->clear();
    this->eventHistory_OpCodeError->clear();
    this->eventHistory_MalformedCommand->clear();
    this->eventHistory_InvalidCommand->clear();
    this->eventHistory_TooManyCommands->clear();
    this->eventsSize_NoOpReceived = 0;
    this->eventHistory_NoOpStringReceived->clear();
    this->eventHistory_TestCmd1Args->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::TextLogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void LLCmdDispatcherTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity) {
      case Fw::LOG_FATAL:
        severityString = "FATAL";
        break;
      case Fw::LOG_WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::LOG_WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::LOG_COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::LOG_ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::LOG_ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::LOG_DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%d) (%d:%d,%d) %s: %s\n",
        e.id,
        const_cast<TextLogEntry&>(e).timeTag.getTimeBase(),
        const_cast<TextLogEntry&>(e).timeTag.getSeconds(),
        const_cast<TextLogEntry&>(e).timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void LLCmdDispatcherTesterBase ::
    printTextLogHistory(FILE *file) 
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i), 
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: OpCodeRegistered 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_DIAGNOSTIC_OpCodeRegistered(
        U32 Opcode,
        I32 port,
        I32 slot
    )
  {
    EventEntry_OpCodeRegistered e = {
      Opcode, port, slot
    };
    eventHistory_OpCodeRegistered->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: OpCodeDispatched 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_COMMAND_OpCodeDispatched(
        U32 Opcode,
        I32 port
    )
  {
    EventEntry_OpCodeDispatched e = {
      Opcode, port
    };
    eventHistory_OpCodeDispatched->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: OpCodeCompleted 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_COMMAND_OpCodeCompleted(
        U32 Opcode
    )
  {
    EventEntry_OpCodeCompleted e = {
      Opcode
    };
    eventHistory_OpCodeCompleted->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: OpCodeError 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_WARNING_HI_OpCodeError(
        U32 Opcode,
        LLCmdDispatcherComponentBase::ErrorResponse error
    )
  {
    EventEntry_OpCodeError e = {
      Opcode, error
    };
    eventHistory_OpCodeError->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MalformedCommand 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_WARNING_HI_MalformedCommand(
        LLCmdDispatcherComponentBase::CmdSerError Status
    )
  {
    EventEntry_MalformedCommand e = {
      Status
    };
    eventHistory_MalformedCommand->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: InvalidCommand 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_WARNING_HI_InvalidCommand(
        U32 Opcode
    )
  {
    EventEntry_InvalidCommand e = {
      Opcode
    };
    eventHistory_InvalidCommand->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: TooManyCommands 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_WARNING_HI_TooManyCommands(
        U32 Opcode
    )
  {
    EventEntry_TooManyCommands e = {
      Opcode
    };
    eventHistory_TooManyCommands->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: NoOpReceived 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_COMMAND_NoOpReceived(
        void
    )
  {
    ++this->eventsSize_NoOpReceived;
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: NoOpStringReceived 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_COMMAND_NoOpStringReceived(
        Fw::LogStringArg& No_op_string
    )
  {
    EventEntry_NoOpStringReceived e = {
      No_op_string
    };
    eventHistory_NoOpStringReceived->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: TestCmd1Args 
  // ----------------------------------------------------------------------

  void LLCmdDispatcherTesterBase ::
    logIn_COMMAND_TestCmd1Args(
        I32 arg1,
        F32 arg2,
        U8 arg3
    )
  {
    EventEntry_TestCmd1Args e = {
      arg1, arg2, arg3
    };
    eventHistory_TestCmd1Args->push_back(e);
    ++this->eventsSize;
  }

} // end namespace LLProc
