// ======================================================================
// \title  EventExpander/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for EventExpander component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
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

#include "GTestBase.hpp"

namespace HLProc {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  EventExpanderGTestBase ::
    EventExpanderGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) : 
        EventExpanderTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  EventExpanderGTestBase ::
    ~EventExpanderGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void EventExpanderGTestBase ::
    assertFromPortHistory_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistorySize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all from port histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistorySize << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: LogSend
  // ----------------------------------------------------------------------

  void EventExpanderGTestBase ::
    assert_from_LogSend_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_LogSend->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_LogSend\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_LogSend->size() << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: Time
  // ----------------------------------------------------------------------

  void EventExpanderGTestBase ::
    assert_from_Time_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_Time->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_Time\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_Time->size() << "\n";
  }

} // end namespace HLProc
