#include "ActivePetUpdate.h"
#include "../PacketType.h"

// Constructors
ActivePetUpdate::ActivePetUpdate()
{
	// Set packet id
	this->id = PacketType::ACTIVEPETUPDATE;
}
ActivePetUpdate::ActivePetUpdate(byte *b, int i) : Packet(b, i)
{
	// Set id and pass data to Parse
	this->id = PacketType::ACTIVEPETUPDATE;
	read();
}
ActivePetUpdate::ActivePetUpdate(const Packet &p) : Packet(p)
{
	this->id = PacketType::ACTIVEPETUPDATE;
	read();
}

Packet *ActivePetUpdate::write()
{
	// Clear the packet data just to be safe
	this->clearData();
	// Write data
	this->writeBytes<int>(instanceId);
	// Send the packet
	//PacketIOHelper::SendPacket(this);
	return this;
}

void ActivePetUpdate::read()
{
	// Make sure the index is set to 0
	this->setIndex(0);
	// Read in the data
	instanceId = this->readBytes<int>();
	// done!
}