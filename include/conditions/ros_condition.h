/* Copyright (C) 2015-2017 Michele Colledanchise - All Rights Reserved
*
*   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
*   to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
*   and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*   The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef CONDITIONS_ROS_CONDITION_H
#define CONDITIONS_ROS_CONDITION_H

#include <condition_node.h>
#include <string>

#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <Group_Voice_of_BigBaby/BTAction.h>

namespace BT
{
class ROSCondition : public ConditionNode
{
protected:
    actionlib::SimpleActionClient<Group_Voice_of_BigBaby::BTAction> action_client_;
    Group_Voice_of_BigBaby::BTResult node_result;
    Group_Voice_of_BigBaby::BTGoal goal;
public:
    // Constructor
    explicit ROSCondition(std::string Name);
    ~ROSCondition();

    ReturnStatus Tick();
};
}  // namespace BT

#endif  // CONDITIONS_ROS_CONDITION_H
