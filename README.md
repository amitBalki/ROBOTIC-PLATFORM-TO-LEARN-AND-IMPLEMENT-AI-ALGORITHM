# ROBOTIC PLATFORM TO LEARN AND IMPLEMENT AI ALGORITHM


**Mentor:**

Kartik Paigwar

---
**Introduction:**

  Automatic path planning is one of the most challenging problems confronted by autonomous robots. Generating optimal paths for autonomous robots are some of the heavily studied subjects in mobile robotics applications. The aim of the project is to develop a rapid prototyping platform to run and test path planning algorithms. It uses overhead camera for 2D environment mapping, Bluetooth for wireless communication and the robot has calibrated PID controller for smooth trajectories. It overlooks the hardware complications and provides easy implementation for search algorithms.

---
**Tools Used:**

OPENCV

Arduino IDE

AprilTag Libraries

---
**Methodology:**

#### 1. Image Processing

i) Detection of the environment through overhead camera and cropping out the region of interest.

ii) Detecting the obstacles in the environment which will be used along with the start
and goal point to build a roadmap of the environment.

iii) Converting the image into an nXn grid such that the robot properly fits in the smallest block. 


#### 2. The Robot

A compact and robust robot was built with arduino uno as microcontroller. It has Calibrated PID control for smooth trajectories. Bluetooth serial communication was implemented for wireless transfer of data from PC to the robot using BLuetooth module (HC05). It has april-tag attached on its top for realtime localization. 


#### 3. Loacalization using April-Tag
AprilTag is a visual fiducial system, useful for a wide variety of tasks including
augmented reality, robotics, and camera calibration. Targets can be created from an
ordinary printer, and the AprilTag detection software computes the precise 3D position,
orientation, and identity of the tags relative to the camera. The AprilTag library is
implemented in C with no external dependencies. It is designed to be easily included in
other applications, as well as be portable to embedded devices. Real-time performance
can be achieved even on cell-phone grade processors. The


#### 4. Implementing Search Algorithm

A* Search algorithm is one of the best and popular technique used in path-finding and graph
traversals.
A* Search algorithms, unlike other traversal techniques, it has “brains”. What it means is
that it is really a smart algorithm which separates it from the other conventional algorithms.
And it is also worth mentioning that many games and web-based maps use this algorithm to
find the shortest path very efficiently.


Explanation -
Consider a square grid having many obstacles and we are given a starting cell and a target
cell. We want to reach the target cell (if possible) from the starting cell as quickly as
possible. Here A* Search Algorithm comes to the rescue.
What A* Search Algorithm does is that at each step it picks the node according to a value-‘f’
which is a parameter equal to the sum of two other parameters – ‘g’ and ‘h’. At each step it
picks the node/cell having the lowest ‘f’, and process that node/cell.

We define ‘g’ and ‘h’ as simply as possible below


g = the movement cost to move from the starting point to a given square on the grid,
following the path generated to get there.


h = the estimated movement cost to move from that given square on the grid to the final
destination. This is often referred to as the heuristic, which is nothing but a kind of smart
guess. We really don’t know the actual distance until we find the path, because all sorts of
things can be in the way (walls, water, etc.).

