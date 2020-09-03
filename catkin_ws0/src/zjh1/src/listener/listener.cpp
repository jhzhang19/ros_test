#include "ros/ros.h"
#include "std_msgs/String.h"

//回调函数定义,参数类型需要与所订阅的消息类型保持一致
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{   
    ROS_INFO("I heard:%s",msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener"); //初始化ros,并命名节点名称
    ros::NodeHandle n;                 //初始化节点,调用ros api接口句柄

    ros::Subscriber sub=n.subscribe("chatter",10,chatterCallback); //定义一个订阅者,参数包括订阅的话题名,订阅话题的队列长度(储存接受的话题内容,
                                                                        //保持最新的数据),回调函数(一旦有订阅者订阅的消息进入,就会立即调用函数进行处理,该函数处理函数)
    ros::spin();       //不返回函数,监听订阅者的回调队列,看队列里是否有数据,并一直执行回调函数
     
    return 0;       //正常执行时,不会运行到这一步
}