#include <darc/component.h>
#include <darc/procedure/client.h>
#include <darc/timer/periodic_timer.h>

#include <std_msgs/Int32.h>

class PingComponent : public darc::Component
{
protected:
  darc::procedure::Client<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> ping_client_;
  darc::timer::PeriodicTimer timer_;

  uint32_t count_;

protected:
  void timerHandler()
  {
    std::cout << count_ << std::endl;
    count_ = 0;
  }

  void statusHandler( boost::shared_ptr<std_msgs::Int32> msg )
  {
  }

  void returnHandler( boost::shared_ptr<std_msgs::Int32> msg )
  {
    ping();
    count_++;
  }

  void onStart()
  {
    DARC_AUTOTRACE();
    ping();
    darc::Component::onStart();
  }

  void ping()
  {
    std_msgs::Int32::Ptr msg;
    ping_client_.call(msg);
  }

public:
  PingComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    ping_client_( this, "ping", boost::bind( &PingComponent::returnHandler, this, _1 ), boost::bind( &PingComponent::statusHandler, this, _1 ) ),
    timer_( this, boost::bind(&PingComponent::timerHandler, this), boost::posix_time::seconds(1) ),
    count_(0)
  {
  }

};

DARC_REGISTER_COMPONENT(PingComponent)
