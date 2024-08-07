/*
 * states.h
 *
 *  Created on: Jun 13, 2024
 *      Author: nv
 */

#ifndef INC_STATES_H_
#define INC_STATES_H_

#include "sensor.h"
#include "sim.h"

enum State {
	STANDBY, // Ground, unarmed, can connect to computer
	ARMED, // Armed, ready to launch
	BURN, // Motor burning
	CONTROL, // Active control (after motor burn)
	DESCENT, // Parachute descent
};

extern enum State currentState;
void StateUpdate();

enum CommandType {
	ServoMin,
	ServoMax,
	Status,
	ConfigWrite,
	DataRead,
	FlightReplay,
};
#pragma pack(1)
typedef struct {
	enum CommandType commandType;
	Config config;
} Command; // Command from host

#pragma pack(1)
typedef struct {
	bool hasData;
	Config config;
} StatusData;

extern Command command;
extern bool commandAvailable;

#pragma pack(1)
typedef struct {
	int delay; //ms
	float servo;
} ReplayData;

extern ReplayData replayPacket[8];

#endif /* INC_STATES_H_ */
