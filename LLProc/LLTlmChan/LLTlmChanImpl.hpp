/**
 * \file
 * \author T. Canham
 * \brief Component that stores telemetry channel values
 *
 * \copyright
 * Copyright 2009-2015, by the California Institute of Technology.
 * ALL RIGHTS RESERVED.  United States Government Sponsorship
 * acknowledged. Any commercial use must be negotiated with the Office
 * of Technology Transfer at the California Institute of Technology.
 * <br /><br />
 * This software may be subject to U.S. export control laws and
 * regulations.  By accepting this document, the user agrees to comply
 * with all U.S. export laws and regulations.  User has the
 * responsibility to obtain export licenses, or other export authority
 * as may be required before exporting such information to foreign
 * countries or providing access to foreign persons.
 */

#ifndef TELEMCHANIMPL_HPP_
#define TELEMCHANIMPL_HPP_

#include <LLProc/LLTlmChan/LLTlmChanComponentAc.hpp>
#include <LLProc/LLTlmChan/LLTlmChanImplCfg.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Tlm/TlmPacket.hpp>

namespace LLProc {

    class LLTlmChanImpl: public LLTlmChanComponentBase {
        public:
            friend class TlmChanImplTester;
    #if FW_OBJECT_NAMES == 1
            LLTlmChanImpl(const char* compName);
    #else
            LLTlmChanImpl();
    #endif
            virtual ~LLTlmChanImpl();
            void init(
                    NATIVE_INT_TYPE instance /*!< The instance number*/
                    );
        PROTECTED:

            // can be overridden for alternate algorithms
            virtual NATIVE_UINT_TYPE doHash(FwChanIdType id);

        PRIVATE:

            // Port functions
            void TlmRecv_handler(NATIVE_INT_TYPE portNum, FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val);
            void TlmGet_handler(NATIVE_INT_TYPE portNum, FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val);
            void Run_handler(NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context);

            typedef struct tlmEntry {
                FwChanIdType id; //!< telemetry id stored in slot
                bool updated; //!< set whenever a value has been written. Used to skip if writing out values for downlinking
                Fw::Time lastUpdate; //!< last updated time
                Fw::TlmBuffer buffer; //!< buffer to store serialized telemetry
                tlmEntry* next; //!< pointer to next bucket in table
                bool used; //!< if entry has been used
                NATIVE_UINT_TYPE bucketNo; //!< for testing
            } TlmEntry;

            struct TlmSet {
                TlmEntry* slots[TLMCHAN_NUM_TLM_HASH_SLOTS]; //!< set of hash slots in hash table
                TlmEntry buckets[TLMCHAN_HASH_BUCKETS]; //!< set of buckets used in hash table
                NATIVE_INT_TYPE free; //!< next free bucket
            } m_tlmEntries[2];

            U32 m_activeBuffer; // !< which buffer is active for storing telemetry

            // work variables
            Fw::ComBuffer m_comBuffer;
            Fw::TlmPacket m_tlmPacket;

    };

}

#endif /* TELEMCHANIMPL_HPP_ */
