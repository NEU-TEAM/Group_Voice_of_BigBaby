#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# this node continues get the param_wakeup, when this param is true,
# BigBaby switch the status from sleep to working
import rospy
import actionlib
import Group_Voice_of_BigBaby.msg

param_wakeup = '/comm/param/ctrl/wakeup'
# this param the bigbaby which status(sleep or working) she is on


class BTAction(object):
    _feedback = Group_Voice_of_BigBaby.msg.BTFeedback()
    _result = Group_Voice_of_BigBaby.msg.BTResult()

    def __init__(self, name):
        self._action_name = name
        self._as = actionlib.SimpleActionServer(self._action_name, Group_Voice_of_BigBaby.msg.BTAction,
                                                execute_cb=self.execute_cb, auto_start=False)
        self._as.start()

    def execute_cb(self, goal):
        if rospy.get_param(param_wakeup):
            self.set_status('SUCCESS')
        else:
            self.set_status('FAILURE')

    def set_status(self, status):
        if status == 'SUCCESS':
            self._feedback.status = 1
            self._result.status = self._feedback.status
            self._as.set_succeeded(self._result)
        else:
            self._feedback.status = 2
            self._result.status = self._feedback.status
            self._as.set_succeeded(self._result)


if __name__ == '__main__':
    try:
        rospy.init_node('WakeUp')
        BTAction(rospy.get_name())
        rospy.spin()
    except rospy.ROSInterruptException:
        print('WakeUp is over!')
