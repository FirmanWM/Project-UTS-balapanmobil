/*
 * task.h
 *
 *  Created on: Nov 3, 2019
 *      Author: Sudjat
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

void task_init(void);
void task_mulai(void);
void task_errordis(_Bool state, char *msg);
void task_display(uint8_t sesi);
void task_displayreset(void);
void task_LED(uint8_t Dled, uint8_t slot);

#endif /* INC_TASK_H_ */
