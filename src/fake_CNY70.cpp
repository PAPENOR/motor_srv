#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int16MultiArray.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fake_CNY70");
  ros::NodeHandle nh;
  ros::Publisher CNY70 = nh.advertise<std_msgs::Int16MultiArray>("/CNY70", 100);
  ros::Rate loop_rate(10);
  int times=0;
  while (ros::ok())
  {
            times=times+1;
    std_msgs::Int16MultiArray msgCNY70;
    int y[6]={100,20,50,100,10};
    for(int i=0;i<5;i++)
    {
   msgCNY70.data.push_back(y[i]+times);
    }

   CNY70.publish(msgCNY70);
   ROS_INFO("The fake msg has been sent");
/**/
    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
