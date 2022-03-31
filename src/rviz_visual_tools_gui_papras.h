#pragma once

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "std_msgs/String.h"

#include <rviz/panel.h>
#endif

#include <QPushButton>
#include <QComboBox>

class QLineEdit;
class QSpinBox;

namespace rviz_visual_tools
{
class RvizVisualToolsGuiPAPRAS : public rviz::Panel
{
  Q_OBJECT
public:
  explicit RvizVisualToolsGuiPAPRAS(QWidget* parent = nullptr);

  void load(const rviz::Config& config) override;
  void save(rviz::Config config) const override;

public Q_SLOTS:

protected Q_SLOTS:

  void moveArm1Rest();
  void moveArm1Main();
  void moveArm1High();
  void moveArm1Forward();

  void moveArm2Rest();
  void moveArm2Main();
  void moveArm2High();
  void moveArm2Forward();

  void moveArm1_2Rest();
  void moveArm1_2Main();
  void moveArm1_2High();
  void moveArm1_2Forward();

  void moveGripper1Open();
  void moveGripper1Close();

  void moveGripper2Open();
  void moveGripper2Close();

  void moveGripper1_2Open();
  void moveGripper1_2Close();

protected:
  QPushButton* btn_arm1_rest_;
  QPushButton* btn_arm1_main_;
  QPushButton* btn_arm1_high_;
  QPushButton* btn_arm1_forward_;
  
  QPushButton* btn_arm2_rest_;
  QPushButton* btn_arm2_main_;
  QPushButton* btn_arm2_high_;
  QPushButton* btn_arm2_forward_;

  QPushButton* btn_arm1_2_rest_;
  QPushButton* btn_arm1_2_main_;
  QPushButton* btn_arm1_2_high_;
  QPushButton* btn_arm1_2_forward_;

  QPushButton* btn_gripper1_open_;
  QPushButton* btn_gripper1_close_;

  QPushButton* btn_gripper2_open_;
  QPushButton* btn_gripper2_close_;

  QPushButton* btn_gripper1_2_open_;
  QPushButton* btn_gripper1_2_close_;

  ros::NodeHandle nh_;
  ros::Publisher gui_publisher_;
};

}  // end namespace rviz_visual_tools
