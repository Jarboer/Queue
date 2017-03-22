/*
  RolloverTest
  Simple test to test queue rollover (for lib testing purposes mainly)
  
  Queues an incrementing counter & pull a record from queue each cycle

  This example code is in the public domain.

  created 22 March 2017
  by SMFSW
 */

#include <Queue.h>

uint16_t in = 0;

Queue	q(sizeof(in), 10, FIFO);	// Instanciate queue

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	
	q.push(&in);		// First push into queue
}

// the loop function runs over and over again forever
void loop() {
	uint16_t out;
	
	q.push(&(++in));
	q.pull(&out);
	Serial.println(out);
	delay(200);
}