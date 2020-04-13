/*
 * toeiCommon.h
 *
 *  Created on: Nov 26, 2019
 *      Author: pegasus12
 */

#ifndef TOEI_PROTOCOL_H_
#define TOEI_PROTOCOL_H_

#define PACKET_SIZE_MIN (22)
#define PACKET_SIZE_MAX (1046)

#define FUNC_CODE_ALARM_NOW (101)
#define FUNC_CODE_ALARM_STORY (102)
#define FUNC_CODE_SYS_INFO (103)
#define FUNC_CODE_AXIS_INFO (104)
#define FUNC_CODE_FILE_READ (105)
#define FUNC_CODE_FILE_WRITE (106)
#define FUNC_CODE_REG_LIST (108)
#define FUNC_CODE_REG_WRITE (109)
#define FUNC_CODE_POWER_ON_TIMES (110)

#define PACKET_OFFSET_COMMAND (0)
#define PACKET_OFFSET_ID (2)
#define PACKET_OFFSET_PARA1 (6)
#define PACKET_OFFSET_PARA2 (10)
#define PACKET_OFFSET_PARA3 (14)
#define PACKET_OFFSET_PARA4 (18)
#define PACKET_OFFSET_BUFFER (22)

uint32_t toei_packet(uint32_t id, char *buf);
void toei_decode(char *buf, uint32_t count);

#endif /* TOEI_PROTOCOL_H_ */
