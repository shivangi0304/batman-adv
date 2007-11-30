/*
 * Copyright (C) 2007 B.A.T.M.A.N. contributors:
 * Marek Lindner
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 *
 */





#include <linux/module.h>	/* needed by all modules */
#include <linux/version.h>	/* LINUX_VERSION_CODE */
#include <linux/netdevice.h>	/* netdevice */
#include <linux/timer.h>	/* timer */
#include <linux/if_ether.h>	/* ethernet header */
#include <linux/poll.h>		/* poll_table */
#include <linux/kthread.h>	/* kernel threads */
#include <net/sock.h>		/* struct sock */



#include "batman-adv-proc.h"


/* Kernel Programming */
#define LINUX

#define DRIVER_AUTHOR "Marek Lindner <lindner_marek@yahoo.de>"
#define DRIVER_DESC   "B.A.T.M.A.N. Advanced"
#define DRIVER_DEVICE "batman-adv"

#define SOURCE_VERSION "0.1-alpha"
#define COMPAT_VERSION 1
#define UNIDIRECTIONAL 0x80
#define DIRECTLINK 0x40
#define TQ_MAX_VALUE 255
#define JITTER 100
#define TTL 50                /* Time To Live of broadcast messages */

#define LOG_BUF_LEN 8192      /* has to be a power of 2 */
#define ETH_STR_LEN 20
#define LOG_TYPE_CRIT 0		/* highest priority for fatal errors such as blocked sockets / failed packet delivery / programming errors */
#define LOG_TYPE_WARN 1		/* warnings for  small errors like wrong user input / damaged packets / etc */
#define LOG_TYPE_NOTICE 2	/* notice information for new interfaces / changed settings / new originators / etc */
#define LOG_TYPE_ROUTING 4	/* all messages related to routing / flooding / broadcasting / etc */

#ifndef REVISION_VERSION
#define REVISION_VERSION "0"
#endif



extern struct list_head if_list;

extern int16_t originator_interval;
extern int16_t num_hna;

extern unsigned char broadcastAddr[];



int ether_ntoa(char *buff, uint8_t addr[6]);




/* int batman_core_attach(struct net_device *dev, u_int8_t *ie_buff, u_int8_t *ie_buff_len);
int batman_core_detach(struct net_device *dev);
void batman_core_ogm_update(struct net_device *dev, u_int8_t *ie_buff, u_int8_t *ie_buff_len); */

