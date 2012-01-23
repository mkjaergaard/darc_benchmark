#include <darc/node.h>
#include <darc/component.h>
#include <darc/procedure/server.h>

#include <std_msgs/Int32.h>

class PongComponent : public darc::Component
{
protected:
  darc::procedure::Server<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> ping_server_;

protected:
  void procedureCall( boost::shared_ptr<std_msgs::Int32> msg )
  {
    ping_server_.reply(msg);
  }

public:
  PongComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    ping_server_( this, "ping", boost::bind(&PongComponent::procedureCall, this, _1) )
  {
  }

};

DARC_REGISTER_COMPONENT(PongComponent)
