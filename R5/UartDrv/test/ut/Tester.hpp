// ======================================================================
// \title  R5UartDriver/test/ut/Tester.hpp
// \author tcanham
// \brief  hpp file for R5UartDriver test harness implementation class
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

#ifndef TESTER_HPP
#define TESTER_HPP

#include "TesterBase.hpp"
#include "R5/UartDrv/R5UartDriverComponentImpl.hpp"

namespace R5 {

  class Tester :
    public R5UartDriverTesterBase
  {

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object Tester
      //!
        Tester(NATIVE_INT_TYPE instance);

      //! Destroy object Tester
      //!
      ~Tester(void);

    public:

      // ----------------------------------------------------------------------
      // Tests
      // ----------------------------------------------------------------------

      //! To do
      //!
      void toDo(void);

      void r5FlowTester(void);

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts(void);

      //! Initialize components
      //!
      void initComponents(NATIVE_INT_TYPE instance);

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
        R5UartDriverComponentImpl component;
        NATIVE_INT_TYPE instance;

  };

} // end namespace R5

#endif
