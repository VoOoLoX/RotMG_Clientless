#pragma once

#ifndef QUESTREDEEM_H
#define QUESTREDEEM_H

#include "../Packet.h"
#include "../data/SlotObjectData.h"

class QuestRedeem : public Packet
{
public:
	SlotObjectData slotObj;

	// Constructor
	QuestRedeem();
	QuestRedeem(byte*, int);
	QuestRedeem(Packet&);

	// Output
	Packet *write();
	// Input
	void read();
};

#endif