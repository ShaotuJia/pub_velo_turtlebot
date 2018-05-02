
#include <array>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"







int main(int argc, char **argv)
{
  // define mode_0 to stop turtlebot
  geometry_msgs::Twist mode_0;
  mode_0.linear.x = 0;
  mode_0.linear.y = 0;
  mode_0.linear.z = 0;
  mode_0.angular.x = 0;
  mode_0.angular.y = 0;
  mode_0.angular.z = 0;


    // define mode_1 linear and angular velocity
  geometry_msgs::Twist mode_1;
  mode_1.linear.x = 0.1;    // linear velocity 0.1 m/s
  mode_1.linear.y = 0;
  mode_1.linear.z = 0;
  mode_1.angular.x = 0;
  mode_1.angular.y = 0;
  mode_1.angular.z = 0.1;   // angular velocity 0.1 radian/s



  // define mode_2 linear and angular velocity
  geometry_msgs::Twist mode_2;
  mode_2.linear.x = 0.1;    // linear velocity 0.1 m/s
  mode_2.linear.y = 0;     
  mode_2.linear.z = 0;
  mode_2.angular.x = 0;
  mode_2.angular.y = 0;
  mode_2.angular.z = 0.075;  // angular velocity 0.05 radian/s

  // define mode_3 linear and angular velocity
  geometry_msgs::Twist mode_3;
  mode_3.linear.x = 0.1;    // linear velocity 0.1 m/s
  mode_3.linear.y = 0;
  mode_3.linear.z = 0;
  mode_3.angular.x = 0;
  mode_3.angular.y = 0;
  mode_3.angular.z = 0;     // angular velocity 0

  // define mode 4 linear and angular velocity
  geometry_msgs::Twist mode_4;
  mode_4.linear.x = 0.1;    // linear velocity 0.1 m/s
  mode_4.linear.y = 0;
  mode_4.linear.z = 0;
  mode_4.angular.x = 0;
  mode_4.angular.y = 0;
  mode_4.angular.z = -0.075; // angular velocity -0.05 rad/s

  geometry_msgs::Twist mode_5;
  mode_5.linear.x = 0.1;    // linear velocity 0.1 m/s
  mode_5.linear.y = 0;
  mode_5.linear.z = 0;
  mode_5.angular.x = 0;
  mode_5.angular.y = 0;
  mode_5.angular.z = -0.1; // angular velocity -0.1 rad/s


  // set up an array to store all modes
  std::array<geometry_msgs::Twist, 11> mode_list = {mode_1, mode_4, mode_3, \
    mode_3, mode_3, mode_1, mode_3, mode_3, mode_4, mode_3, mode_0};

  ros::init(argc, argv, "pub_velocity_node");

  ros::NodeHandle n;

  // Advertize the publisher on the topic you like
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

  // ros::Publisher pub = n.advertise<geometry_msgs::Twist>("robot1/mobile_base/commands/velocity", 1000);
  
  // loop rate
  ros::Rate loop_rate(10);

  ros::Time start_time = ros::Time::now(); // set the start time as current time


  int index = -1;

  ros::Duration duration = ros::Duration(10.0);


  while (ros::ok() && (index < 10)) {


    // the time difference between now and start time
    ros::Duration time_diff = ros::Time::now() - start_time;

    ROS_INFO_STREAM("time_diff = " << time_diff);

    if (time_diff > duration) {

      index += 1;   //increment the index for next mode velocity

      start_time = ros::Time::now();    // update start time

    }

    if (index >= 0 && index < 11) {

        pub.publish(mode_list[index]);

        ROS_INFO_STREAM("index = " << index);

    }


    loop_rate.sleep();    


  }



  #if 0
  // count
  int count = 0;

  while (ros::ok()) {

    if (count < 100) {

       ROS_INFO_STREAM("publish velocity");
       pub.publish(mode_list[9]);
    }

    count ++;


    loop_rate.sleep();

  }

#endif

  return 0;
}

