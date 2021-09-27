#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
 
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int
main (int argc, char *argv[])
{
  CommandLine cmd (__FILE__);
  cmd.Parse (argc, argv);
  
  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (3);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

  NetDeviceContainer device1, device2;
  device1 = pointToPoint.Install (nodes.Get(0), nodes.Get(1));
  device2 = pointToPoint.Install (nodes.Get(2), nodes.Get(1));

  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address1, address2;
  address1.SetBase ("10.1.1.0", "255.255.255.0");
  address2.SetBase ("198.168.1.0", "255.255.255.0");

  Ipv4InterfaceContainer interface1 = address1.Assign (device1);
  Ipv4InterfaceContainer interface2 = address2.Assign (device2);

  UdpEchoServerHelper echoServer1 (90);
  UdpEchoServerHelper echoServer2 (91);

  ApplicationContainer serverApps = echoServer1.Install (nodes.Get (1));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));

  UdpEchoClientHelper echoClient1 (interface1.GetAddress (1), 90);
  echoClient1.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient1.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient1.SetAttribute ("PacketSize", UintegerValue (1024));

  UdpEchoClientHelper echoClient2 (interface2.GetAddress (1), 91);
  echoClient2.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient2.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient2.SetAttribute ("PacketSize", UintegerValue (1024));

  ApplicationContainer clientApp1 = echoClient1.Install (nodes.Get (0));
  clientApp1.Start (Seconds (2.0));
  clientApp1.Stop (Seconds (10.0));

  ApplicationContainer clientApp2 = echoClient2.Install (nodes.Get (2));
  clientApp2.Start (Seconds (7.0));
  clientApp2.Stop (Seconds (10.0));

  pointToPoint.EnablePcapAll("p2p");

  AsciiTraceHelper ascii;
  pointToPoint.EnableAsciiAll(ascii.CreateFileStream("p2p.tr"));

  AnimationInterface anim("anim.xml");
  anim.SetConstantPosition(nodes.Get(0), 10.0, 10.0);
  anim.SetConstantPosition(nodes.Get(1), 20.0, 20.0);
  anim.SetConstantPosition(nodes.Get(2), 30.0, 30.0);

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
