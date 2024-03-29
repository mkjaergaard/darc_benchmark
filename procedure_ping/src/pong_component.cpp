#include <darc/node.h>
#include <darc/component.h>
#include <darc/procedure/server.h>

#include <std_msgs/Int32.h>

class PongComponent : public darc::Component
{
protected:
  darc::procedure::Server<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> ping_server_;

protected:
  void procedureCall(const darc::procedure::CallID& call_id,  boost::shared_ptr<std_msgs::Int32> msg )
  {
    ping_server_.result(call_id, msg);
  }

public:
  PongComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    ping_server_( this, "ping", boost::bind(&PongComponent::procedureCall, this, _1, _2) )
  {
  }

};

DARC_REGISTER_COMPONENT(PongComponent)
