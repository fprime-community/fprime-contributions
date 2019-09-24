// ======================================================================
// \title  ShortLogQueue/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for ShortLogQueue component Google Test harness base class
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

#ifndef ShortLogQueue_GTEST_BASE_HPP
#define ShortLogQueue_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_LogSend_SIZE(size) \
  this->assert_from_LogSend_size(__FILE__, __LINE__, size)

#define ASSERT_from_LogSend(index, _id, _severity, _args) \
  { \
    ASSERT_GT(this->fromPortHistory_LogSend->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_LogSend\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_LogSend->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_LogSend& _e = \
      this->fromPortHistory_LogSend->at(index); \
    ASSERT_EQ(_id, _e.id) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument id at index " \
    << index \
    << " in history of from_LogSend\n" \
    << "  Expected: " << _id << "\n" \
    << "  Actual:   " << _e.id << "\n"; \
    ASSERT_EQ(_severity, _e.severity) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument severity at index " \
    << index \
    << " in history of from_LogSend\n" \
    << "  Expected: " << _severity << "\n" \
    << "  Actual:   " << _e.severity << "\n"; \
    ASSERT_EQ(_args, _e.args) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument args at index " \
    << index \
    << " in history of from_LogSend\n" \
    << "  Expected: " << _args << "\n" \
    << "  Actual:   " << _e.args << "\n"; \
  }

namespace LLProc {

  //! \class ShortLogQueueGTestBase
  //! \brief Auto-generated base class for ShortLogQueue component Google Test harness
  //!
  class ShortLogQueueGTestBase :
    public ShortLogQueueTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object ShortLogQueueGTestBase
      //!
      ShortLogQueueGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object ShortLogQueueGTestBase
      //!
      virtual ~ShortLogQueueGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // From ports 
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: LogSend 
      // ----------------------------------------------------------------------

      void assert_from_LogSend_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace LLProc

#endif
