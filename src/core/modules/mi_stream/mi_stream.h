/*
 * Copyright (C) 2006 Voice Sistem SRL
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *
 * History:
 * ---------
 *  2006-09-25  first version (bogdan)
 */


#ifndef _MI_FIFO_H_
#define _MI_FIFO_H_

#define DEFAULT_MI_REPLY_DIR "/tmp/"

#define DEFAULT_MI_REPLY_IDENT "\t"

#define MI_CMD_SEPARATOR       ':'

/* the 2-chars separator between name and value */
#define MI_ATTR_VAL_SEP1 ':'
#define MI_ATTR_VAL_SEP2 ':'

/* maximum length of a FIFO line */
#define MAX_MI_FIFO_BUFFER    1024

/* how patient is opensips with FIFO clients not awaiting a reply? 
	4 x 80ms = 0.32 sec */
#define FIFO_REPLY_RETRIES  4

/* maximum size for the composed fifo reply name */
#define MAX_MI_FILENAME 128

/* size of buffer used by parser to read and build the MI tree */
#define MAX_MI_FIFO_READ 8192

enum fd_type {TYPE_NONE=0,TYPE_FIFO,TYPE_SOCKET_SERVER,TYPE_SOCKET_CLIENT};

struct wrap_fd {
	int fd;
	int type;
	/* buffer use for both reading and writing */
	char buffer[MAX_MI_FIFO_BUFFER];
	/* length of the command received on this fd */
	int current_comm_len;
	/* where we have got with the parsing of the current command */
	int mi_buf_pos;
};

typedef struct wrap_fd fd_wrapper;

struct reply_wrap {
	fd_wrapper *wrap;
	struct mi_root *reply_tree;
};

typedef struct reply_wrap reply_wrapper;


#endif /* _MI_FIFO */
