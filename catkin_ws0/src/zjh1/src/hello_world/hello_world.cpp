#include "ros/ros.h" //ros.h包含常用的ros程序文件,是必须包含的

int main(int argc,char **argv)
{
	ros::init(argc,argv,"hello_world"); //初始化ros,并命名节点
	ros::NodeHandle n;                  //初始化节点,调用ros api接口句柄(非必须)
	ROS_INFO("Hello_world.");	    //打印操作
	ros::spin();			    //处理所有回调函数(非必须)
	return 0;
}
