/*
 * amt22_multi_turn.h
 *
 *  Created on: Jan 10, 2025
 *      Author: Bartlomiej Ufnalski
 */

#ifndef INC_AMT22_MULTI_TURN_H_
#define INC_AMT22_MULTI_TURN_H_

#include "main.h"
#include "spi.h"

#define AMT22_TIMEOUT 2 // ms

//#define READ_MULTIBLE_BYTES  // to induce read errors (consult AMT22 datasheet for required delays)

typedef enum
{
	AMT22_CHECKSUM_OK = 0x00U, AMT22_CHECKSUM_ERROR = 0x01U
} AMT22Checksum_StatusTypeDef;

typedef union
{
	uint16_t uint16;
	int16_t int16;
} Uint16toInt16DecoderTypeDef;

AMT22Checksum_StatusTypeDef IsAmtChecksumOk(uint8_t *_amt22_data);
HAL_StatusTypeDef GetAmtPositionAndTurnsRawData(uint8_t *_amt22_position_data,
		uint8_t *_amt22_turns_data);
AMT22Checksum_StatusTypeDef GetAmtPosition(uint8_t *_amt22_position_data,
		uint16_t *_amt22_position, uint8_t _resolution);
AMT22Checksum_StatusTypeDef GetAmtTurns(uint8_t *_amt22_turns_data,
		int16_t *_amt22_turns);
#endif /* INC_AMT22_MULTI_TURN_H_ */
