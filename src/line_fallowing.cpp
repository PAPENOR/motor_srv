#include "ros/ros.h"
#include "motor_srv/line_fallowing.h"
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int64MultiArray.h>
using namespace std;
int CNY70_DATA[5];
void CNY70_READ(const std_msgs::Int16MultiArray& CNY70_msg)
{
for(int i=0;i<CNY70_msg.data.size();i++)
{
  CNY70_DATA[i]=CNY70_msg.data.at(i);
}
}

bool add(motor_srv::line_fallowing::Request  &req,
        motor_srv::line_fallowing::Response &res)
{
  ros::NodeHandle ny,n;
  ros::Publisher move_pub = n.advertise<std_msgs::Int64MultiArray>("move", 100);
  ros::Rate loop_rate(10);
  ros::Subscriber CNY70_pub = n.subscribe("/CNY70", 100, CNY70_READ);
    /*Controler Data reset*/
    int sum=0,Mode=req.LineColor,Speed=req.Speed;
    /*Start line_fallowing*/
    for(int j=0;j<50;j++)/*line_fallowing condition*/
    {
    /*line_fallowing */
     res.ActionStaus=0;
    /*sum of CNY70*/
    for(int i=0;i<5;i++)
    {
      sum+=CNY70_DATA[i];
    }
    /*Controler*/

   int pose_pub[2]={0,0};



      pose_pub[0]=Speed*Mode;
      pose_pub[1]=Speed*Mode;




     /*Publish the value of motors*/
      std_msgs::Int64MultiArray msgmove;
      msgmove.data.push_back(pose_pub[0]);
      msgmove.data.push_back(pose_pub[1]);
      move_pub.publish(msgmove);
     ros::spinOnce();
     loop_rate.sleep();


   }
ROS_INFO("Service Done");


  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "line_fallowing");
  ros::NodeHandle nh;
  ros::NodeHandle n;
  ros::NodeHandle ny;
  ros::Rate loop_rate(10);
  ros::Publisher move_pub = n.advertise<std_msgs::Int64MultiArray>("move", 100);
  ros::Subscriber CNY70_pub = n.subscribe("/CNY70", 100, CNY70_READ);
  ros::ServiceServer service = n.advertiseService("line_fallowing", add);
  ROS_INFO("Ready to fallow the line");
  ros::spin();

  return 0;
}
