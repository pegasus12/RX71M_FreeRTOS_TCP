/*
 * toei_protocol.c
 *
 *  Created on: Nov 26, 2019
 *      Author: pegasus12
 */
#include "string.h"
#include "stdint.h"
#include "toei_protocol.h"

uint32_t Block_No;

uint16_t reply_cmd;
uint32_t reply_id;
uint32_t reply_para1;
uint32_t reply_para2;
uint32_t reply_para3;
uint32_t reply_para4;

//write area
uint32_t HQ500_HQ5FF[256];

//read area
uint32_t HQ600_HQ6FF[256];
uint32_t HQ700_HQ7FF[256];

void uint16ToArray(char *buf, uint16_t value)
{
	buf[0] = (uint8_t)((value >> 8) & 0x00FF);
	buf[1] = (uint8_t)(value & 0x00FF);
}

void uint32ToArray(char *buf, uint32_t value)
{
	buf[0] = (uint8_t)((value >> 24) & 0x000000FF);
	buf[1] = (uint8_t)((value >> 16) & 0x000000FF);
	buf[2] = (uint8_t)((value >> 8) & 0x000000FF);
	buf[3] = (uint8_t)(value & 0x000000FF);
}

uint16_t arrayToUint16(char *buf)
{
	uint16_t value;

	value = buf[0];
	value <<= 8;
	value += buf[1];

	return value;
}

uint32_t arrayToUint32(char *buf)
{
	uint32_t value = 0;

	value = buf[0];
	value <<= 8;
	value += buf[1];
	value <<= 8;
	value += buf[2];
	value <<= 8;
	value += buf[3];

	return value;
}

void toei_init(void)
{
	uint32_t i;

	for(i=0 ; i < 256 ; ++i)
		HQ500_HQ5FF[i] = i;

	Block_No = 999;
}

void toei_packet_head_set(char *buf, uint16_t cmd, uint32_t id, uint32_t para1, uint32_t para2, uint32_t para3, uint32_t para4 )
{
	uint16ToArray(&buf[PACKET_OFFSET_COMMAND], cmd);
	uint32ToArray(&buf[PACKET_OFFSET_ID], id); //ID
	uint32ToArray(&buf[PACKET_OFFSET_PARA1], para1); //Para1
	uint32ToArray(&buf[PACKET_OFFSET_PARA2], para2); //Para2
	uint32ToArray(&buf[PACKET_OFFSET_PARA3], para3); //Para3
	uint32ToArray(&buf[PACKET_OFFSET_PARA4], para4); //Para4
}

uint32_t toei_alarm_real(char *buf)
{//實際警報
	toei_packet_head_set(buf, 101, 0, 0, 0, 0, 0);
	return 22;
}

uint32_t toei_alarm_list(char *buf, uint32_t list_id)
{//警報列表
	toei_packet_head_set(buf, 102, list_id, 0, 0, 0, 0);
	return 22;
}

uint32_t toei_system_info(char *buf)
{//系統訊息
	toei_packet_head_set(buf, 103, 0, 0, 0, 0, 0);
	return 22;
}

uint32_t toei_state_info(char *buf, uint32_t axis_id)
{//狀態訊息
	toei_packet_head_set(buf, 104, 0, axis_id, 0, 0, 0);
	return 22;
}

uint32_t toei_block_read(char *buf)
{//暫存器區塊讀取
	uint32_t readCnt = 256;
	//uint32_t readCnt = 25;
	Block_No = 13; //No. 13 R/W HQ500~HQ5FF
	//if (Block_No == 15)
		//Block_No = 14; //No. 14 R/W HQ600~HQ6FF
	//else
	//	Block_No = 15; //No. 15 R/W HQ700~HQ7FF
	toei_packet_head_set(buf, 108, 0, Block_No, readCnt, 0, 0);
	buf[22] = 0x0;

	return 22;
}

uint32_t toei_block_write(char *buf)
{//暫存器區塊寫入
	uint32_t offset = 0;
	uint32_t writeCnt = 256;
	Block_No = 13; //No. 13 R/W HQ500~HQ5FF
	//Block_No = 14; //No. 14 R/W HQ600~HQ6FF
	uint32_t i, j, count;

	count = 22;
	toei_packet_head_set(buf, 109, 0, Block_No, offset, writeCnt, 0);


	if (Block_No == 13)
	{
		j = HQ500_HQ5FF[0];

		for (i = 0 ; i < 256 ; ++i)
		{
			if (j == 1)
				HQ500_HQ5FF[i] = 256 -i;
			else
				HQ500_HQ5FF[i] = i + 1;

			count += 4;
			uint32ToArray(&buf[PACKET_OFFSET_BUFFER + i * 4], HQ500_HQ5FF[i]);
		}
	}else
	if (Block_No == 14){
		j = HQ600_HQ6FF[0];

		for (i = 0 ; i < 256 ; ++i)
		{
			if (j == 1)
				HQ600_HQ6FF[i] = 256 -i;
			else
				HQ600_HQ6FF[i] = i + 1;

			count += 4;
			uint32ToArray(&buf[PACKET_OFFSET_BUFFER + i * 4], HQ600_HQ6FF[i]);
		}
	}

	buf[count] = 0x00;
	count++; //1047

	return count;
}

uint32_t toei_packet(uint32_t id, char *buf)
{
	uint32_t ret = 0;

	if (id == 108)
		ret = toei_block_read(buf);
	else
	if (id == 109)
		ret = toei_block_write(buf);

	return ret;
}

void toei_decode(char *buf, uint32_t count)
{
	uint32_t temp, i;

	if ((count < PACKET_SIZE_MIN) || (count > PACKET_SIZE_MAX))
	{// data error
		return;
	}

	reply_cmd = arrayToUint16(&buf[PACKET_OFFSET_COMMAND]);
	reply_id = arrayToUint32(&buf[PACKET_OFFSET_ID]);
	reply_para1 = arrayToUint32(&buf[PACKET_OFFSET_PARA1]);
	reply_para2 = arrayToUint32(&buf[PACKET_OFFSET_PARA2]);
	reply_para3 = arrayToUint32(&buf[PACKET_OFFSET_PARA3]);
	reply_para4 = arrayToUint32(&buf[PACKET_OFFSET_PARA4]);

#if defined(DEBUG_PRINT)
	print_packet_head();
#endif

	if (reply_cmd == 108)
	{
		if (Block_No >= 999)
			return;

		temp = reply_para2 / 4;
		for (i = 0 ; i < temp ; ++i)
		{
			if (Block_No == 13)
				HQ500_HQ5FF[i] = arrayToUint32(&buf[PACKET_OFFSET_BUFFER + i * 4]);
			else
			if (Block_No == 14)
				HQ600_HQ6FF[i] = arrayToUint32(&buf[PACKET_OFFSET_BUFFER + i * 4]);
			else
			if (Block_No == 15)
				HQ700_HQ7FF[i] = arrayToUint32(&buf[PACKET_OFFSET_BUFFER + i * 4]);
		}
#if defined(DEBUG_PRINT)
		print_register(Block_No);
#endif
	}else
	if (reply_cmd == 109)
	{
		if (Block_No >= 999)
			return;
	}

}
