#include "Aoe.h"


// Constructors
Aoe::Aoe()
{
	// Set packet id
	this->type_ = PacketType::AOE;
}
Aoe::Aoe(byte *b, int i) : Packet(b, i)
{
	// Set id and pass data to Parse
	this->type_ = PacketType::AOE;
	read();
}
Aoe::Aoe(const Packet &p) : Packet(p)
{
	this->type_ = PacketType::AOE;
	read();
}

Packet *Aoe::write()
{
	// Clear the packet data just to be safe
	this->clearData();
	// Write data
	pos.Write(this);
	this->writeBytes<float>(static_cast<float>(radius));
	this->writeBytes<ushort>(damage);
	this->writeBytes<byte>(effect);
	this->writeBytes<float>(static_cast<float>(duration));
	this->writeBytes<ushort>(origType);

	// Send the packet
	//PacketIOHelper::SendPacket(this);
	return this;
}

void Aoe::read()
{
	// Make sure the index is set to 0
	this->setIndex(0);
	// Read in the data
	pos.Read(this);
	radius = static_cast<double>(this->readBytes<float>());
	damage = this->readBytes<ushort>();
	effect = this->readBytes<byte>();
	duration = static_cast<double>(this->readBytes<float>());
	origType = this->readBytes<ushort>();

	// done!
}