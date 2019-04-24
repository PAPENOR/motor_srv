#include "ros/ros.h"
#include <std_msgs/Int64MultiArray.h>
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include <std_msgs/Int16MultiArray.h>


void err_READ(const sensor_msgs::LaserScan msg){

	ros::NodeHandle n;
	int errpoint=0;
	ros::Publisher err_pub = n.advertise<std_msgs::Int16MultiArray>("err", 100);
	
	if(msg.ranges[0] <0.3){
		errpoint=1;
   		std_msgs::Int16MultiArray msgerr;
   		msgerr.data.push_back(errpoint);
   		err_pub.publish(msgerr);   
		ROS_INFO("errpoint=1");
	}
	else{
   		std_msgs::Int16MultiArray msgerr;
   		msgerr.data.push_back(errpoint);
   		err_pub.publish(msgerr);   
		ROS_INFO("errpoint=0");
	}
	

}
int main(int argc, char **argv){
	ros::init(argc,argv,"test_break");
	ros::NodeHandle n;
	
	ros::Subscriber lidar_err_sub = n.subscribe("/scan", 100, err_READ);
	ros::Publisher err_pub = n.advertise<std_msgs::Int16MultiArray>("err", 100);
	ros::spin();
	return 0;
}
