#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    //定义一个发布者
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1); //advertise< >()是一个模板函数,需要传入发布消息的类型.第一个参数是话题名,第二个是发布者队列大小
    ros::Rate loop_rate(10); //发布频率
    int count = 0; //发布消息计数
    while(ros::ok()){
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"hello world"<<count;
        msg.data = ss.str(); //填充发布的消息
        ROS_INFO("%s",msg.data.c_str());//打印发布的消息
        
        //将消息发布出去
        chatter_pub.publish(msg);

        ros::spinOnce(); //处理回调函数,会返回(此处没有回调函数,可以不加)
        loop_rate.sleep(); //与ros::Rate loop_rate(10); 配合使用,控制发布频率
        ++count;
    }
    return 0;
}