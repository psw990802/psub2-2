#include "psub2-2/pub.hpp"
Pub::Pub() : Node("mypub"), count_(0)
{
auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile);
timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this));
}
void Pub::publish_msg()
{
static double a;
auto msg = geometry_msgs::msg::Vector3();
a++;
msg.x = a;
msg.y = a;
msg.z = a;
RCLCPP_INFO(this->get_logger(), "Published message: '%.3f, %.3f, %.3f'", msg.x,msg.y,msg.z);
pub_->publish(msg);
}