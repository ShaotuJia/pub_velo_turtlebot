# Real Robot Implementation: TurtleBot 3
## Brief
This project uses the planned trajectory from Project 3 part 2 and publish it to Turtlebot.

## How to Run in Gazebo
- Prerequisites: generate trajectory using the program of project 3 part 2. [project_3](https://github.com/ShaotuJia/ENPM661_Astar_RRL.git)
- Clone this package to ROS workspace
```
$ cd ~/your_workspace/src
$ git clone https://github.com/ShaotuJia/pub_velo_turtlebot.git
```
- Set up the trajectory by changing a sequence of velocity mode in mode_lists(line 72~73 in src/main.cpp).
- Define the rostopic that the velocities will be published.(line 80 in src/main.cpp) 
- Complie code
```
$ catkin_make
```
- Launch gazebo and initial the pose of turtlebot; change the value in line 25 of navigate.launch
```
$ source devel/setup.bash
$ roslaunch pub_velo navigate.launch
```
- Change the turtlebot orientation using teleop
```
$ roslaunch turtlebot_teleop keyboard_teleop.launch 
```
- Run node pub_velo and publish the velocities
```
$ rosrun pub_velo pub_velo
```
## How to Run in Real Turtlebot
- Install and configure based on TurtleBot 3 Manual. [Manual_Link](http://emanual.robotis.com/docs/en/platform/turtlebot3/overview/)
- Define the rostopic that remote PC will publish to, usually it is "/cmd_vel". (line 80 in src/main.cpp)
- Compile code in remote PC
```
$ cd ~/your_workspace
$ catkin_make
```
- Bring up basic packages to start TurtleBot3 applications.(TurtleBot)
```
$ roslaunch turtlebot3_bringup turtlebot3_robot.launch
```
- Run node to publish velocities to TurtleBot 3. (remote PC)
```
$ rosrun pub_velo pub_velo
```
