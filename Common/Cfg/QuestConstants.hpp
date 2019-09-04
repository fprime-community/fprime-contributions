/*
 * QuestConstants.hpp
 *
 *  Created on: Mar 1, 2017
 *      Author: tcanham
 */

#ifndef CFG_QUESTCONSTANTS_HPP_
#define CFG_QUESTCONSTANTS_HPP_

#include <Fw/Types/BasicTypes.hpp>

namespace Cfg {

    static const BYTE UART_SYNC_BYTE = 0xA5; //!< Byte that starts each UART frame
  
#ifdef SOC_8096
    static const U32 DIRECT_CHUNK_SIZE = 4096;
#else
    static const U32 DIRECT_CHUNK_SIZE = 512;
#endif

}

#endif /* CFG_QUESTCONSTANTS_HPP_ */
