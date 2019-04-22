#include "ros/ros.h"
#include "std_msgs/String.h"
#include "motor_srv/Actioncode.h"
#include "sensor_msgs/Joy.h"
#include <std_msgs/Int16MultiArray.h>
using namespace std;
void Askforservice(motor_srv::Actioncode srv)
{
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<motor_srv::Actioncode>("Actioncode");
    client.call(srv);

}
motor_srv::Actioncode coding2srv(int coding[])
{
    motor_srv::Actioncode srv;
    srv.request.Mission_num=coding[0];
    srv.request.Action_name1 =coding[1];
    srv.request.Action_name2 =coding[2];
    srv.request.Action_staus1 =coding[3];
    srv.request.Action_staus2 =coding[4];
    srv.request.Action_staus3 =coding[5];
    srv.request.Action_staus4 =coding[6];
    return srv;
}

motor_srv::Actioncode Actioncodeing (int mission_number,string Action_type,string Action_mode,int status1,int status2,int status3 ,int status4)
{
    motor_srv::Actioncode srv;
    int code[7]={0,0,0,0,0,0,0};
    code[0]=mission_number;
    if( Action_type=="move_light")
    {
        cout<<"Action"<<mission_number<<":move_light-";
        code[1]=1;
        if(Action_mode=="fallowblack2white")
        {
            code[2]=1;
            cout<<"fallowblack2white-";
            code[3]=status1;
            cout<<"Speed:"<<status1<<endl;
        }
        else
        {
            cout<<"Unknow Commend";
        }

    }
    else if(Action_type=="move_gyr")
    {
        cout<<"Action:move_gry-";
    }
    else
    {
        cout<<"Unknow Commend"<<endl;
    }



    srv=coding2srv(code);
    return srv;

}
