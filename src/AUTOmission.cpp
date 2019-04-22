#include "actioncoding.h"
using namespace std;
void ActionCallback(const std_msgs::Int16MultiArray& msg)
{
    cout<<msg<<endl;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "AUTOmission");
    motor_srv::Actioncode srv;
    Askforservice(Actioncodeing(1,"move_light","fallowblack2white",100,0,0,0));
    Askforservice(Actioncodeing(2,"move_light","fallowblack2white",50,0,0,0));
    Askforservice(Actioncodeing(3,"move_light","fallowblack2white",80,0,0,0));



    ros::spin();

    return 0;
}
