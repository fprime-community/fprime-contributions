// ======================================================================
// \title  ShortLogQueue/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for ShortLogQueue component test harness base class
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

#ifndef ShortLogQueue_TESTER_BASE_HPP
#define ShortLogQueue_TESTER_BASE_HPP

#include <LLProc/ShortLogQueue/ShortLogQueueComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace LLProc {

  //! \class ShortLogQueueTesterBase
  //! \brief Auto-generated base class for ShortLogQueue component test harness
  //!
  class ShortLogQueueTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object ShortLogQueueTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect LogRecv to to_LogRecv[portNum]
      //!
      void connect_to_LogRecv(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputLogPort *const LogRecv /*!< The port*/
      );

      //! Connect Run to to_Run[portNum]
      //!
      void connect_to_Run(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputSchedPort *const Run /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from LogSend
      //!
      //! \return from_LogSend[portNum]
      //!
      Common::InputShortLogPort* get_from_LogSend(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object ShortLogQueueTesterBase
      //!
      ShortLogQueueTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object ShortLogQueueTesterBase
      //!
      virtual ~ShortLogQueueTesterBase(void);

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize /*!< The maximum history size*/
          ) : 
              numEntries(0), 
              maxSize(maxSize) 
          { 
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry /*!< The item*/
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i /*!< The index*/
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size(void) const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory(void);

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_LogSend
      //!
      virtual void from_LogSend_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          U8 severity, /*!< The shorter severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      ) = 0;

      //! Handler base function for from_LogSend
      //!
      void from_LogSend_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          U8 severity, /*!< The shorter severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory(void);

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_LogSend
      void pushFromPortEntry_LogSend(
          FwEventIdType id, /*!< Log ID*/
          U8 severity, /*!< The shorter severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

      //! A history entry for from_LogSend
      //!
      typedef struct {
        FwEventIdType id;
        U8 severity;
        Fw::LogBuffer args;
      } FromPortEntry_LogSend;

      //! The history for from_LogSend
      //!
      History<FromPortEntry_LogSend> 
        *fromPortHistory_LogSend;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to LogRecv
      //!
      void invoke_to_LogRecv(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

      //! Invoke the to port connected to Run
      //!
      void invoke_to_Run(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of to_LogRecv ports
      //!
      //! \return The number of to_LogRecv ports
      //!
      NATIVE_INT_TYPE getNum_to_LogRecv(void) const;

      //! Get the number of from_LogSend ports
      //!
      //! \return The number of from_LogSend ports
      //!
      NATIVE_INT_TYPE getNum_from_LogSend(void) const;

      //! Get the number of to_Run ports
      //!
      //! \return The number of to_Run ports
      //!
      NATIVE_INT_TYPE getNum_to_Run(void) const;

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_LogRecv[portNum] is connected
      //!
      bool isConnected_to_LogRecv(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_Run[portNum] is connected
      //!
      bool isConnected_to_Run(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to LogRecv
      //!
      Fw::OutputLogPort m_to_LogRecv[1];

      //! To port connected to Run
      //!
      Svc::OutputSchedPort m_to_Run[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to LogSend
      //!
      Common::InputShortLogPort m_from_LogSend[1];

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_LogSend
      //!
      static void from_LogSend_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          U8 severity, /*!< The shorter severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

  };

} // end namespace LLProc

#endif
