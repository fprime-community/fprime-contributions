// ======================================================================
// \title  BlspSerialDriver/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for BlspSerialDriver component Google Test harness base class
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

namespace SnapdragonFlight {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  BlspSerialDriverGTestBase ::
    BlspSerialDriverGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) : 
        BlspSerialDriverTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  BlspSerialDriverGTestBase ::
    ~BlspSerialDriverGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Telemetry
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertTlm_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->tlmSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all telemetry histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: DR_BytesSent
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertTlm_DR_BytesSent_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_DR_BytesSent->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel DR_BytesSent\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_DR_BytesSent->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertTlm_DR_BytesSent(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_DR_BytesSent->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel DR_BytesSent\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_DR_BytesSent->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_DR_BytesSent& e =
      this->tlmHistory_DR_BytesSent->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel DR_BytesSent\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: DR_BytesRecv
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertTlm_DR_BytesRecv_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_DR_BytesRecv->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel DR_BytesRecv\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_DR_BytesRecv->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertTlm_DR_BytesRecv(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_DR_BytesRecv->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel DR_BytesRecv\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_DR_BytesRecv->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_DR_BytesRecv& e =
      this->tlmHistory_DR_BytesRecv->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel DR_BytesRecv\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all event histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_OpenError
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_OpenError_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_OpenError->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_OpenError\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_OpenError->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_OpenError(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device,
        const I32 error
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_OpenError->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_OpenError\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_OpenError->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_OpenError& e =
      this->eventHistory_DR_OpenError->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_OpenError\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
    ASSERT_EQ(error, e.error)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument error at index "
      << __index
      << " in history of event DR_OpenError\n"
      << "  Expected: " << error << "\n"
      << "  Actual:   " << e.error << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_ConfigError
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_ConfigError_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_ConfigError->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_ConfigError\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_ConfigError->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_ConfigError(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device,
        const I32 error
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_ConfigError->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_ConfigError\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_ConfigError->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_ConfigError& e =
      this->eventHistory_DR_ConfigError->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_ConfigError\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
    ASSERT_EQ(error, e.error)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument error at index "
      << __index
      << " in history of event DR_ConfigError\n"
      << "  Expected: " << error << "\n"
      << "  Actual:   " << e.error << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_WriteError
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_WriteError_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_WriteError->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_WriteError\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_WriteError->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_WriteError(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device,
        const I32 error
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_WriteError->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_WriteError\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_WriteError->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_WriteError& e =
      this->eventHistory_DR_WriteError->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_WriteError\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
    ASSERT_EQ(error, e.error)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument error at index "
      << __index
      << " in history of event DR_WriteError\n"
      << "  Expected: " << error << "\n"
      << "  Actual:   " << e.error << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_ReadError
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_ReadError_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_ReadError->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_ReadError\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_ReadError->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_ReadError(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device,
        const I32 error
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_ReadError->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_ReadError\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_ReadError->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_ReadError& e =
      this->eventHistory_DR_ReadError->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_ReadError\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
    ASSERT_EQ(error, e.error)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument error at index "
      << __index
      << " in history of event DR_ReadError\n"
      << "  Expected: " << error << "\n"
      << "  Actual:   " << e.error << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_PortOpened
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_PortOpened_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_PortOpened->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_PortOpened\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_PortOpened->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_PortOpened(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_PortOpened->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_PortOpened\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_PortOpened->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_PortOpened& e =
      this->eventHistory_DR_PortOpened->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_PortOpened\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_NoBuffers
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_NoBuffers_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_NoBuffers->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_NoBuffers\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_NoBuffers->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_NoBuffers(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_NoBuffers->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_NoBuffers\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_NoBuffers->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_NoBuffers& e =
      this->eventHistory_DR_NoBuffers->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_NoBuffers\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: DR_BufferTooSmall
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_BufferTooSmall_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_DR_BufferTooSmall->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event DR_BufferTooSmall\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_DR_BufferTooSmall->size() << "\n";
  }

  void BlspSerialDriverGTestBase ::
    assertEvents_DR_BufferTooSmall(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 device,
        const U32 size,
        const U32 needed
    ) const
  {
    ASSERT_GT(this->eventHistory_DR_BufferTooSmall->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event DR_BufferTooSmall\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_DR_BufferTooSmall->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_DR_BufferTooSmall& e =
      this->eventHistory_DR_BufferTooSmall->at(__index);
    ASSERT_EQ(device, e.device)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument device at index "
      << __index
      << " in history of event DR_BufferTooSmall\n"
      << "  Expected: " << device << "\n"
      << "  Actual:   " << e.device << "\n";
    ASSERT_EQ(size, e.size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument size at index "
      << __index
      << " in history of event DR_BufferTooSmall\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << e.size << "\n";
    ASSERT_EQ(needed, e.needed)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument needed at index "
      << __index
      << " in history of event DR_BufferTooSmall\n"
      << "  Expected: " << needed << "\n"
      << "  Actual:   " << e.needed << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
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
  // From port: serialRecv
  // ----------------------------------------------------------------------

  void BlspSerialDriverGTestBase ::
    assert_from_serialRecv_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_serialRecv->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_serialRecv\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_serialRecv->size() << "\n";
  }

} // end namespace SnapdragonFlight
