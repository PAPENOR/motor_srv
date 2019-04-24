#include "ros/ros.h"
#include "motor_srv/Actioncode.h"
#include "motor_srv/line_fallowing.h"
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int64MultiArray.h>
#include <cstdlib>
using namespace std;


bool codetran(motor_srv::Actioncode::Request &req,
        motor_srv::Actioncode::Response &res)
{
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<motor_srv::line_fallowing>("line_fallowing");
    
    

    switch (req.Action_name1) {
    case 1:
    {
        cout<<"Calling line_fallowing"<<endl;

        motor_srv::line_fallowing srv;
        srv.request.LineColor =req.Action_name2;
        srv.request.Speed =req.Action_staus1;
        client.call(srv);


        break;
    }
        case 2:
    {
       cout<<"Calling Gy_L_fallowing"<<endl;
    }
    default:
        break;


    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Action");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<motor_srv::line_fallowing>("line_fallowing");
    ros::ServiceServer service = nh.advertiseService("Actioncode", codetran);
    ROS_INFO("Ready to decoding the action");
    ros::spin();


    return 0;
}
