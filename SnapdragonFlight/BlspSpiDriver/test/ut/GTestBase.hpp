// ======================================================================
// \title  BlspSpiDriver/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for BlspSpiDriver component Google Test harness base class
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

#ifndef BlspSpiDriver_GTEST_BASE_HPP
#define BlspSpiDriver_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for telemetry history assertions
// ----------------------------------------------------------------------

#define ASSERT_TLM_SIZE(size) \
  this->assertTlm_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_SPI_Bytes_SIZE(size) \
  this->assertTlm_SPI_Bytes_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_SPI_Bytes(index, value) \
  this->assertTlm_SPI_Bytes(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions 
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SPI_OpenError_SIZE(size) \
  this->assertEvents_SPI_OpenError_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SPI_OpenError(index, _device, _error) \
  this->assertEvents_SPI_OpenError(__FILE__, __LINE__, index, _device, _error)

#define ASSERT_EVENTS_SPI_ConfigError_SIZE(size) \
  this->assertEvents_SPI_ConfigError_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SPI_ConfigError(index, _device, _error) \
  this->assertEvents_SPI_ConfigError(__FILE__, __LINE__, index, _device, _error)

#define ASSERT_EVENTS_SPI_WriteError_SIZE(size) \
  this->assertEvents_SPI_WriteError_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SPI_WriteError(index, _device, _error) \
  this->assertEvents_SPI_WriteError(__FILE__, __LINE__, index, _device, _error)

#define ASSERT_EVENTS_SPI_PortOpened_SIZE(size) \
  this->assertEvents_SPI_PortOpened_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_SPI_PortOpened(index, _device) \
  this->assertEvents_SPI_PortOpened(__FILE__, __LINE__, index, _device)

namespace SnapdragonFlight {

  //! \class BlspSpiDriverGTestBase
  //! \brief Auto-generated base class for BlspSpiDriver component Google Test harness
  //!
  class BlspSpiDriverGTestBase :
    public BlspSpiDriverTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object BlspSpiDriverGTestBase
      //!
      BlspSpiDriverGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object BlspSpiDriverGTestBase
      //!
      virtual ~BlspSpiDriverGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Telemetry
      // ----------------------------------------------------------------------

      //! Assert size of telemetry history
      //!
      void assertTlm_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: SPI_Bytes
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_SPI_Bytes_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_SPI_Bytes(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: SPI_OpenError
      // ----------------------------------------------------------------------

      void assertEvents_SPI_OpenError_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_SPI_OpenError(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const I32 device, /*!< The device*/
          const I32 error /*!< The error code*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: SPI_ConfigError
      // ----------------------------------------------------------------------

      void assertEvents_SPI_ConfigError_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_SPI_ConfigError(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const I32 device, /*!< The device*/
          const I32 error /*!< The error code*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: SPI_WriteError
      // ----------------------------------------------------------------------

      void assertEvents_SPI_WriteError_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_SPI_WriteError(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const I32 device, /*!< The device*/
          const I32 error /*!< The error code*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: SPI_PortOpened
      // ----------------------------------------------------------------------

      void assertEvents_SPI_PortOpened_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_SPI_PortOpened(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const I32 device /*!< The device*/
      ) const;

  };

} // end namespace SnapdragonFlight

#endif
