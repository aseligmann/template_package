#include "template_package/template_package.hpp"

// Constructor
TemplatePackage::TemplatePackage(ros::NodeHandle& nh, ros::NodeHandle& pnh) {
  nh_ = nh;  // Set nodehandle

  // Initialise variables / parameters to class variables


  // Initialise publishers and subscribers
  pub_state = nh_.advertise<diagnostic_msgs::DiagnosticStatus>("state", 100);
  sub_emergency = nh_.subscribe("emergency", 100, &TemplatePackage::subCallbackEmergency, this);

}

// Destructor
TemplatePackage::~TemplatePackage() {
  ROS_INFO_STREAM("Destructing TemplatePackage...");
  // Free up allocated memory
  // delete pointer_name;
}

void TemplatePackage::subCallbackEmergency(diagnostic_msgs::DiagnosticStatus msg) {
  // Emergency has been annouced, put everything in safe-state and stop further activity

  if (msg.level == msg.ERROR) {
    ROS_WARN_STREAM("EMERGENCY MESSAGE HEARD FROM " << msg.name);
    ROS_WARN_STREAM("GOING TO SAFE-STATE");

    gotoSafeState();
  }  
}

int TemplatePackage::pubState(diagnostic_msgs::DiagnosticStatus msg) {
  // Publish current state

  if(pub_state.getNumSubscribers() > 0) {
    pub_state.publish(msg);
  }
}