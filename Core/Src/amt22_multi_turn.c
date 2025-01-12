/*
 * amt22_multi_turn.c
 *
 *  Created on: Jan 10, 2025
 *      Author: Bartlomiej Ufnalski
 */

#include "amt22_multi_turn.h"

uint8_t ask_for_position_and_turns[4] =
{ 0x00, 0xA0, 0x00, 0x00 }; // https://www.sameskydevices.com/product/resource/amt22.pdf

AMT22Checksum_StatusTypeDef IsAmtChecksumOk(uint8_t *_amt22_data)
{
	uint16_t data = (uint16_t) (_amt22_data[0])
			| (((uint16_t) (_amt22_data[1])) << 8);
	uint8_t csum0 = 0; // change to 1 to test checksum error handling
	uint8_t csum1 = 0;
	for (uint8_t i = 0; i < 8; i++)
	{
		csum0 ^= (data >> i * 2) & 1;
		csum1 ^= (data >> (i * 2 + 1)) & 1;
	}
	if (csum0 && csum1)
	{
		return AMT22_CHECKSUM_OK;
	}
	else
	{
		return AMT22_CHECKSUM_ERROR;
	}
}

HAL_StatusTypeDef GetAmtPositionAndTurnsRawData(uint8_t *_amt22_position_data,
		uint8_t *_amt22_turns_data)
{
	HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_RESET);

#ifdef READ_MULTIBLE_BYTES
	uint8_t rx_data[4] = {0,0,0,0};

		if (HAL_SPI_TransmitReceive(&hspi1, ask_for_position_and_turns, rx_data, 4, AMT22_TIMEOUT) != HAL_OK)
		{
			HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
			return HAL_ERROR;
		}
		else
		{
			*_amt22_position_data = rx_data[1];
			*(_amt22_position_data + 1) = rx_data[0];
			*_amt22_turns_data = rx_data[3];
			*(_amt22_turns_data + 1)= rx_data[2];
			HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
			return HAL_OK;
		}
#else
	if (HAL_SPI_TransmitReceive(&hspi1, ask_for_position_and_turns,
			_amt22_position_data + 1, 1,
			AMT22_TIMEOUT) != HAL_OK)
	{
		HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
		return HAL_ERROR;
	}
	else if (HAL_SPI_TransmitReceive(&hspi1, ask_for_position_and_turns + 1,
			_amt22_position_data, 1, AMT22_TIMEOUT) != HAL_OK)
	{
		HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
		return HAL_ERROR;
	}
	else if (HAL_SPI_TransmitReceive(&hspi1, ask_for_position_and_turns + 2,
			_amt22_turns_data + 1, 1, AMT22_TIMEOUT) != HAL_OK)
	{
		HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
		return HAL_ERROR;
	}
	else if (HAL_SPI_TransmitReceive(&hspi1, ask_for_position_and_turns + 3,
			_amt22_turns_data, 1,
			AMT22_TIMEOUT) != HAL_OK)
	{
		HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
		return HAL_ERROR;
	}
	else
	{
		HAL_GPIO_WritePin(AMT222CV_CS_GPIO_Port, AMT222CV_CS_Pin, GPIO_PIN_SET);
		return HAL_OK;
	}
#endif
}

AMT22Checksum_StatusTypeDef GetAmtPosition(uint8_t *_amt22_position_data,
		uint16_t *_amt22_position, uint8_t _resolution)
{
	if (IsAmtChecksumOk(_amt22_position_data) == AMT22_CHECKSUM_OK)
	{
		*_amt22_position = (((uint16_t) (_amt22_position_data[0])
				| (((uint16_t) (_amt22_position_data[1])) << 8)) & 0x3FFF)
				>> (14 - _resolution);
		return AMT22_CHECKSUM_OK;
	}
	else
	{
		return AMT22_CHECKSUM_ERROR;
	}
}

AMT22Checksum_StatusTypeDef GetAmtTurns(uint8_t *_amt22_turns_data,
		int16_t *_amt22_turns)
{
	if (IsAmtChecksumOk(_amt22_turns_data) == AMT22_CHECKSUM_OK)
	{
		Uint16toInt16DecoderTypeDef uint16_to_int16;
		uint16_to_int16.uint16 = ((uint16_t) (_amt22_turns_data[0])
				| (((uint16_t) (_amt22_turns_data[1])) << 8)) << 2;
		*_amt22_turns = uint16_to_int16.int16 / 4;
		return AMT22_CHECKSUM_OK;
	}
	else
	{
		return AMT22_CHECKSUM_ERROR;
	}
}
