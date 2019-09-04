// ====================================================================== 
// \title  RosSeqImpl.hpp
// \author genemerewether
// \brief  hpp file for RosSeq component implementation class
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

#ifndef RosSeq_HPP
#define RosSeq_HPP

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <fprime_msgs/RunSeqAction.h>

#include "ROS/RosSeq/RosSeqComponentAc.hpp"
#include <Os/Task.hpp>

namespace ROS {

  class RosSeqComponentImpl :
    public RosSeqComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object RosSeq
      //!
      RosSeqComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object RosSeq
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object RosSeq
      //!
      ~RosSeqComponentImpl(void);

      //! Start interrupt task
      Os::Task::TaskStatus startIntTask(NATIVE_INT_TYPE priority,
                                        NATIVE_INT_TYPE stackSize,
                                        NATIVE_INT_TYPE cpuAffinity = -1);

      void disableRos();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for sched
      //!
      void sched_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

      //! Handler implementation for pingIn
      //!
      void pingIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

      //! Handler implementation for seqDoneIn
      //!
      void seqDoneIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< Command Op Code*/
          U32 cmdSeq, /*!< Command Sequence*/
          Fw::CommandResponse response /*!< The command response argument*/
      );

      // ----------------------------------------------------------------------
      // Member variables
      // ----------------------------------------------------------------------

      void goalCB();
      void preemptCB();

      volatile bool m_rosInited;

      //! Entry point for task serving action requests
      static void intTaskEntry(void * ptr);

      //! Task object for action server task
      //!
      Os::Task m_intTask;

      ros::NodeHandle* m_nodeHandle;
      actionlib::SimpleActionServer<fprime_msgs::RunSeqAction>* m_actionServer;
    };

} // end namespace ROS

#endif
