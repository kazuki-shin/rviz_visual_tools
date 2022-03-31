#include <cstdio>

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>

#include "rviz_visual_tools_gui_papras.h"

namespace rviz_visual_tools
{
RvizVisualToolsGuiPAPRAS::RvizVisualToolsGuiPAPRAS(QWidget* parent) : rviz::Panel(parent)
{
  // Arm 1 Poses
  btn_arm1_rest_ = new QPushButton(this); btn_arm1_rest_->setText("arm1 rest");
  connect(btn_arm1_rest_, SIGNAL(clicked()), this, SLOT(moveArm1Rest()));
  btn_arm1_main_ = new QPushButton(this); btn_arm1_main_->setText("arm1 main");
  connect(btn_arm1_main_, SIGNAL(clicked()), this, SLOT(moveArm1Main()));
  btn_arm1_high_ = new QPushButton(this); btn_arm1_high_->setText("arm1 high");
  connect(btn_arm1_high_, SIGNAL(clicked()), this, SLOT(moveArm1High()));
  btn_arm1_forward_ = new QPushButton(this); btn_arm1_forward_->setText("arm1 forward");
  connect(btn_arm1_forward_, SIGNAL(clicked()), this, SLOT(moveArm1Forward()));

  // Arm 2 Poses
  btn_arm2_rest_ = new QPushButton(this); btn_arm2_rest_->setText("arm2 rest");
  connect(btn_arm2_rest_, SIGNAL(clicked()), this, SLOT(moveArm2Rest()));
  btn_arm2_main_ = new QPushButton(this); btn_arm2_main_->setText("arm2 main");
  connect(btn_arm2_main_, SIGNAL(clicked()), this, SLOT(moveArm2Main()));
  btn_arm2_high_ = new QPushButton(this); btn_arm2_high_->setText("arm2 high");
  connect(btn_arm2_high_, SIGNAL(clicked()), this, SLOT(moveArm2High()));
  btn_arm2_forward_ = new QPushButton(this); btn_arm2_forward_->setText("arm2 forward");
  connect(btn_arm2_forward_, SIGNAL(clicked()), this, SLOT(moveArm2Forward()));

  // Arm 1_2 Poses
  btn_arm1_2_rest_ = new QPushButton(this); btn_arm1_2_rest_->setText("arm1_2 rest");
  connect(btn_arm1_2_rest_, SIGNAL(clicked()), this, SLOT(moveArm1_2Rest()));
  btn_arm1_2_main_ = new QPushButton(this); btn_arm1_2_main_->setText("arm1_2 main");
  connect(btn_arm1_2_main_, SIGNAL(clicked()), this, SLOT(moveArm1_2Main()));
  btn_arm1_2_high_ = new QPushButton(this); btn_arm1_2_high_->setText("arm1_2 high");
  connect(btn_arm1_2_high_, SIGNAL(clicked()), this, SLOT(moveArm1_2High()));
  btn_arm1_2_forward_ = new QPushButton(this); btn_arm1_2_forward_->setText("arm1_2 forward");
  connect(btn_arm1_2_forward_, SIGNAL(clicked()), this, SLOT(moveArm1_2Forward()));

  // Gripper 1 Poses
  btn_gripper1_open_ = new QPushButton(this); btn_gripper1_open_->setText("gripper1 open");
  connect(btn_gripper1_open_, SIGNAL(clicked()), this, SLOT(moveGripper1Open()));
  btn_gripper1_close_ = new QPushButton(this); btn_gripper1_close_->setText("gripper1 close");
  connect(btn_gripper1_close_, SIGNAL(clicked()), this, SLOT(moveGripper1Close()));

  // Gripper 2 Poses
  btn_gripper2_open_ = new QPushButton(this); btn_gripper2_open_->setText("gripper2 open");
  connect(btn_gripper2_open_, SIGNAL(clicked()), this, SLOT(moveGripper2Open()));
  btn_gripper2_close_ = new QPushButton(this); btn_gripper2_close_->setText("gripper2 close");
  connect(btn_gripper2_close_, SIGNAL(clicked()), this, SLOT(moveGripper2Close()));

  // Gripper 1_2 Poses
  btn_gripper1_2_open_ = new QPushButton(this); btn_gripper1_2_open_->setText("gripper1_2 open");
  connect(btn_gripper1_2_open_, SIGNAL(clicked()), this, SLOT(moveGripper1_2Open()));
  btn_gripper1_2_close_ = new QPushButton(this); btn_gripper1_2_close_->setText("gripper1_2 close");
  connect(btn_gripper1_2_close_, SIGNAL(clicked()), this, SLOT(moveGripper1_2Close()));

  // Horizontal Layout
  auto* planning_group1 = new QHBoxLayout;
  planning_group1->addWidget(btn_arm1_rest_);
  planning_group1->addWidget(btn_arm1_main_);
  planning_group1->addWidget(btn_arm1_high_);
  planning_group1->addWidget(btn_arm1_forward_);

  auto* planning_group2 = new QHBoxLayout;
  planning_group2->addWidget(btn_arm2_rest_);
  planning_group2->addWidget(btn_arm2_main_);
  planning_group2->addWidget(btn_arm2_high_);
  planning_group2->addWidget(btn_arm2_forward_);

  auto* planning_group3 = new QHBoxLayout;
  planning_group3->addWidget(btn_arm1_2_rest_);
  planning_group3->addWidget(btn_arm1_2_main_);
  planning_group3->addWidget(btn_arm1_2_high_);
  planning_group3->addWidget(btn_arm1_2_forward_);

  auto* planning_group4 = new QHBoxLayout;
  planning_group4->addWidget(btn_gripper1_open_);
  planning_group4->addWidget(btn_gripper1_close_);

  auto* planning_group5 = new QHBoxLayout;
  planning_group5->addWidget(btn_gripper2_open_);
  planning_group5->addWidget(btn_gripper2_close_);

  auto* planning_group6 = new QHBoxLayout;
  planning_group6->addWidget(btn_gripper1_2_open_);
  planning_group6->addWidget(btn_gripper1_2_close_);

  // Verticle layout
  auto* layout = new QVBoxLayout;
  layout->addLayout(planning_group1);
  layout->addLayout(planning_group2);
  layout->addLayout(planning_group3);
  layout->addLayout(planning_group4);
  layout->addLayout(planning_group5);
  layout->addLayout(planning_group6);
  setLayout(layout);

  btn_arm1_rest_->setEnabled(true);
  btn_arm1_main_->setEnabled(true);
  btn_arm1_high_->setEnabled(true);
  btn_arm1_forward_->setEnabled(true);

  gui_publisher_ = nh_.advertise<std_msgs::String>("/rviz_visual_tools_gui_papras", 1);
}

// Arm 1 move
void RvizVisualToolsGuiPAPRAS::moveArm1Rest() {
  std_msgs::String msg;
  msg.data = "arm1_rest";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm1Main() {
  std_msgs::String msg;
  msg.data = "arm1_main";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm1High() {
  std_msgs::String msg;
  msg.data = "arm1_high";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm1Forward() {
  std_msgs::String msg;
  msg.data = "arm1_forward";
  gui_publisher_.publish(msg);
}

// Arm 2 move
void RvizVisualToolsGuiPAPRAS::moveArm2Rest() {
  std_msgs::String msg;
  msg.data = "arm2_rest";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm2Main() {
  std_msgs::String msg;
  msg.data = "arm2_main";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm2High() {
  std_msgs::String msg;
  msg.data = "arm2_high";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm2Forward() {
  std_msgs::String msg;
  msg.data = "arm2_forward";
  gui_publisher_.publish(msg);
}

// Arm 1_2 move
void RvizVisualToolsGuiPAPRAS::moveArm1_2Rest() {
  std_msgs::String msg;
  msg.data = "arm1_2_rest";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm1_2Main() {
  std_msgs::String msg;
  msg.data = "arm1_2_main";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm1_2High() {
  std_msgs::String msg;
  msg.data = "arm1_2_high";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveArm1_2Forward() {
  std_msgs::String msg;
  msg.data = "arm1_2_forward";
  gui_publisher_.publish(msg);
}

// Gripper 1 move
void RvizVisualToolsGuiPAPRAS::moveGripper1Open() {
  std_msgs::String msg;
  msg.data = "gripper1_open";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveGripper1Close() {
  std_msgs::String msg;
  msg.data = "gripper1_close";
  gui_publisher_.publish(msg);
}

// Gripper 2 move
void RvizVisualToolsGuiPAPRAS::moveGripper2Open() {
  std_msgs::String msg;
  msg.data = "gripper2_open";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveGripper2Close() {
  std_msgs::String msg;
  msg.data = "gripper2_close";
  gui_publisher_.publish(msg);
}


// Gripper 1_2 move
void RvizVisualToolsGuiPAPRAS::moveGripper1_2Open() {
  std_msgs::String msg;
  msg.data = "gripper1_2_open";
  gui_publisher_.publish(msg);
}
void RvizVisualToolsGuiPAPRAS::moveGripper1_2Close() {
  std_msgs::String msg;
  msg.data = "gripper1_2_close";
  gui_publisher_.publish(msg);
}


void RvizVisualToolsGuiPAPRAS::save(rviz::Config config) const
{
  rviz::Panel::save(config);
}

void RvizVisualToolsGuiPAPRAS::load(const rviz::Config& config)
{
  rviz::Panel::load(config);
}
}  // end namespace rviz_visual_tools

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_visual_tools::RvizVisualToolsGuiPAPRAS, rviz::Panel)
