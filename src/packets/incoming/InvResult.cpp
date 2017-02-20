#include "InvResult.h"
#include "../PacketType.h"

// Constructors
InvResult::InvResult()
{
	// Set packet id
	this->id = PacketType::INVRESULT;
}
InvResult::InvResult(byte *b, int i) : Packet(b, i)
{
	// Set id and pass data to Parse
	this->id = PacketType::INVRESULT;
	read();
}
InvResult::InvResult(const Packet &p) : Packet(p)
{
	this->id = PacketType::INVRESULT;
	read();
}

Packet *InvResult::write()
{
	// Clear the packet data just to be safe
	this->clearData();
	// Write data
	this->writeBytes<int>(result);
	// Send the packet
	//PacketIOHelper::SendPacket(this);
	return this;
}

void InvResult::read()
{
	// Make sure the index is set to 0
	this->setIndex(0);
	// Read in the data
	result = this->readBytes<int>();
	// done!
}