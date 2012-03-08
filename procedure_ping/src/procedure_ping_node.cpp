#include <iostream>
#include <boost/thread.hpp>
#include <darc/node.h>
#include <darc/registry.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Create and run Component1
  darc::Component::Ptr c1 = darc::Registry::instantiateComponent( "PingComponent", node );
  c1->run();

  darc::Component::Ptr c2 = darc::Registry::instantiateComponent( "PongComponent", node );
  c2->run();

  // Set up node connections
  node->accept("udp://127.0.0.1:5135");
  node->connect("udp://127.0.0.1:5130");

  // Run Node in main thread
  node->run(true);
  return 0;
}
