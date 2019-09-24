// ======================================================================
// \title  LLTlmChan/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for LLTlmChan component test harness base class
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

  LLTlmChanTesterBase ::
    LLTlmChanTesterBase(
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
    // Initialize histories for typed user output ports
    this->fromPortHistory_PktSend =
      new History<FromPortEntry_PktSend>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  LLTlmChanTesterBase ::
    ~LLTlmChanTesterBase(void) 
  {
  }

  void LLTlmChanTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port PktSend

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_PktSend();
        ++_port
    ) {

      this->m_from_PktSend[_port].init();
      this->m_from_PktSend[_port].addCallComp(
          this,
          from_PktSend_static
      );
      this->m_from_PktSend[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_PktSend[%d]",
          this->m_objName,
          _port
      );
      this->m_from_PktSend[_port].setObjName(_portName);
#endif

    }

    // Initialize output port TlmRecv

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_TlmRecv();
        ++_port
    ) {
      this->m_to_TlmRecv[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_TlmRecv[%d]",
          this->m_objName,
          _port
      );
      this->m_to_TlmRecv[_port].setObjName(_portName);
#endif

    }

    // Initialize output port TlmGet

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_TlmGet();
        ++_port
    ) {
      this->m_to_TlmGet[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_TlmGet[%d]",
          this->m_objName,
          _port
      );
      this->m_to_TlmGet[_port].setObjName(_portName);
#endif

    }

    // Initialize output port Run

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_Run();
        ++_port
    ) {
      this->m_to_Run[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_Run[%d]",
          this->m_objName,
          _port
      );
      this->m_to_Run[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE LLTlmChanTesterBase ::
    getNum_to_TlmRecv(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_TlmRecv);
  }

  NATIVE_INT_TYPE LLTlmChanTesterBase ::
    getNum_to_TlmGet(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_TlmGet);
  }

  NATIVE_INT_TYPE LLTlmChanTesterBase ::
    getNum_to_Run(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_Run);
  }

  NATIVE_INT_TYPE LLTlmChanTesterBase ::
    getNum_from_PktSend(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_PktSend);
  }

  // ----------------------------------------------------------------------
  // Connectors for to ports 
  // ----------------------------------------------------------------------

  void LLTlmChanTesterBase ::
    connect_to_TlmRecv(
        const NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort *const TlmRecv
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_TlmRecv(),static_cast<AssertArg>(portNum));
    this->m_to_TlmRecv[portNum].addCallPort(TlmRecv);
  }

  void LLTlmChanTesterBase ::
    connect_to_TlmGet(
        const NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort *const TlmGet
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_TlmGet(),static_cast<AssertArg>(portNum));
    this->m_to_TlmGet[portNum].addCallPort(TlmGet);
  }

  void LLTlmChanTesterBase ::
    connect_to_Run(
        const NATIVE_INT_TYPE portNum,
        Svc::InputSchedPort *const Run
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_Run(),static_cast<AssertArg>(portNum));
    this->m_to_Run[portNum].addCallPort(Run);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void LLTlmChanTesterBase ::
    invoke_to_TlmRecv(
        const NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    FW_ASSERT(portNum < this->getNum_to_TlmRecv(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_TlmRecv(),static_cast<AssertArg>(portNum));
    this->m_to_TlmRecv[portNum].invoke(
        id, timeTag, val
    );
  }

  void LLTlmChanTesterBase ::
    invoke_to_TlmGet(
        const NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    FW_ASSERT(portNum < this->getNum_to_TlmGet(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_TlmGet(),static_cast<AssertArg>(portNum));
    this->m_to_TlmGet[portNum].invoke(
        id, timeTag, val
    );
  }

  void LLTlmChanTesterBase ::
    invoke_to_Run(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_Run(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_Run(),static_cast<AssertArg>(portNum));
    this->m_to_Run[portNum].invoke(
        context
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool LLTlmChanTesterBase ::
    isConnected_to_TlmRecv(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_TlmRecv(), static_cast<AssertArg>(portNum));
    return this->m_to_TlmRecv[portNum].isConnected();
  }

  bool LLTlmChanTesterBase ::
    isConnected_to_TlmGet(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_TlmGet(), static_cast<AssertArg>(portNum));
    return this->m_to_TlmGet[portNum].isConnected();
  }

  bool LLTlmChanTesterBase ::
    isConnected_to_Run(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_Run(), static_cast<AssertArg>(portNum));
    return this->m_to_Run[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------
 
  Fw::InputComPort *LLTlmChanTesterBase ::
    get_from_PktSend(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_PktSend(),static_cast<AssertArg>(portNum));
    return &this->m_from_PktSend[portNum];
  }

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void LLTlmChanTesterBase ::
    from_PktSend_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data,
        U32 context
    )
  {
    FW_ASSERT(callComp);
    LLTlmChanTesterBase* _testerBase = 
      static_cast<LLTlmChanTesterBase*>(callComp);
    _testerBase->from_PktSend_handlerBase(
        portNum,
        data, context
    );
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void LLTlmChanTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_PktSend->clear();
  }

  // ---------------------------------------------------------------------- 
  // From port: PktSend
  // ---------------------------------------------------------------------- 

  void LLTlmChanTesterBase ::
    pushFromPortEntry_PktSend(
        Fw::ComBuffer &data,
        U32 context
    )
  {
    FromPortEntry_PktSend _e = {
      data, context
    };
    this->fromPortHistory_PktSend->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void LLTlmChanTesterBase ::
    from_PktSend_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data,
        U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_from_PktSend(),static_cast<AssertArg>(portNum));
    this->from_PktSend_handler(
        portNum,
        data, context
    );
  }

  // ----------------------------------------------------------------------
  // History 
  // ----------------------------------------------------------------------

  void LLTlmChanTesterBase ::
    clearHistory()
  {
    this->clearFromPortHistory();
  }

} // end namespace LLProc
