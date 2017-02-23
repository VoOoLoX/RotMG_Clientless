#include "AoeAck.h"
#include "../PacketType.h"

// Constructors
AoeAck::AoeAck()
{
	// Set packet id
	this->id = PacketType::AOEACK;
}
AoeAck::AoeAck(byte *b, int i) : Packet(b, i)
{
	// Set id and pass data to Parse
	this->id = PacketType::AOEACK;
	read();
}
AoeAck::AoeAck(Packet &p) : Packet(p)
{
	this->id = PacketType::AOEACK;
	read();
}

Packet *AoeAck::write()
{
	// Clear the packet data just to be safe
	this->clearData();
	// Write data
	this->writeBytes<int>(time);
	position.Write(this);
	// Send the packet
	return this;
}

void AoeAck::read()
{
	// Make sure the index is set to 0
	this->setIndex(0);
	// Read in the data
	time = this->readBytes<int>();
	position.Read(this);
	// done!
}