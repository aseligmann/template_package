#pragma once           // Only include once per compile
#ifndef TEMPLATE_PACKAGE  // Conditional compiling
#define TEMPLATE_PACKAGE

// Includes
#include <ros/ros.h>  // ROS header


// Define class
class TemplatePackage {
public:
  // Constructor and destructor
  TemplatePackage(ros::NodeHandle& nh, ros::NodeHandle& pnh);
  ~TemplatePackage();

  // Public functions
  void subCallbackEmergency(diagnostic_msgs::DiagnosticStatus msg);
  int pubState(diagnostic_msgs::DiagnosticStatus msg);

  // Public variables and objects
  ros::Publisher pub_state;
  ros::Subscriber sub_emergency;
  
private:
  // Private functions


  // Private variables and objects
  ros::NodeHandle nh_;
};

#endif