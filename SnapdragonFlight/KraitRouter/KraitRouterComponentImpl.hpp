// ======================================================================
// \title  KraitRouterImpl.hpp
// \author vagrant
// \brief  hpp file for KraitRouter component implementation class
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

#ifndef KraitRouter_HPP
#define KraitRouter_HPP

#include <SnapdragonFlight/KraitRouter/KraitRouterComponentImplCfg.hpp>

#include "SnapdragonFlight/KraitRouter/KraitRouterComponentAc.hpp"

#include <Fw/Types/EightyCharString.hpp>
#include <Os/Queue.hpp>

namespace SnapdragonFlight {

    class KraitRouterComponentImpl :
      public KraitRouterComponentBase
    {

      public:

        // ----------------------------------------------------------------------
        // Construction, initialization, and destruction
        // ----------------------------------------------------------------------

        //! Construct object KraitRouter
        //!
        KraitRouterComponentImpl(
  #if FW_OBJECT_NAMES == 1
            const char *const compName /*!< The component name*/
  #else
            void
  #endif
        );

        //! Initialize object KraitRouter
        //!
        void init(
            const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
            const NATIVE_INT_TYPE msgSize, /*!< The message size*/
            const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
        );

        //! Destroy object KraitRouter
        //!
        ~KraitRouterComponentImpl(void);

        void quit();
      
        int buffRead(unsigned int* port, unsigned char* buff, int buffLen, int* bytes);

        // multiple serialized port calls
        int portRead(unsigned char* buff, int buffLen, int* bytes);

        int buffWrite(unsigned int port, const unsigned char* buff, int buffLen);

        int portWrite(const unsigned char* buff, int buffLen);

      PRIVATE:

        // ----------------------------------------------------------------------
        // Handler implementations for user-defined typed input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for Sched
        //!
        void Sched_handler(
            const NATIVE_INT_TYPE portNum, /*!< The port number*/
            NATIVE_UINT_TYPE context /*!< The call order*/
        );

      PRIVATE:

        // ----------------------------------------------------------------------
        // Handler implementations for user-defined serial input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for HexPortsIn
        //!
        void HexPortsIn_handler(
          NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
        );

        U32 m_localMsgSize;

        volatile enum InitState {
            KR_STATE_PREINIT,
            KR_STATE_INIT,
            KR_STATE_QUIT_PREINIT,
            KR_STATE_QUIT
        } m_initialized;

        Os::Queue m_recvQueue;
        Os::Queue m_sendQueue;
    };

} // end namespace SnapdragonFlight

#endif
