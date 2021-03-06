#include "Pong.h"


// Constructors
Pong::Pong()
{
	// Set packet id
	this->type_ = PacketType::PONG;
}
Pong::Pong(byte *b, int i) : Packet(b, i)
{
	// Set id and pass data to Parse
	this->type_ = PacketType::PONG;
	read();
}
Pong::Pong(Packet &p) : Packet(p)
{
	this->type_ = PacketType::PONG;
	read();
}

Packet *Pong::write()
{
	// Clear the packet data just to be safe
	this->clearData();
	// Write data
	this->writeBytes<int>(serial);
	this->writeBytes<int>(time);
	// Send the packet
	return this;
}

void Pong::read()
{
	// Make sure the index is set to 0
	this->setIndex(0);
	// Read in the data
	serial = this->readBytes<int>();
	time = this->readBytes<int>();
	// done!
}