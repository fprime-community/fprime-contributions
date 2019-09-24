// ======================================================================
// \title  DmaDrv.c
// \author Igor Uchenik
// \brief  Dma Driver component implementation class
//
// \copyright
// Copyright 2009-2017, by the California Institute of Technology.
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

#include "DmaDrv.hpp"

#include <R5/TiHal/include/HL_sys_dma.h>


void DmaDrvInit(void)
{
    // Clear Block Transfer Complete Flag Register
    dmaREG->BTCFLAG = 0xffffffff;

    // Enable DMA
    dmaEnable();
}
