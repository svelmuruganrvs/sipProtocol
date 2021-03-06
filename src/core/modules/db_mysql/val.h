/* 
 * $Id: val.h 5901 2009-07-21 07:45:05Z bogdan_iancu $ 
 *
 * Copyright (C) 2001-2003 FhG Fokus
 * Copyright (C) 2008 1&1 Internet AG
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef VAL_H
#define VAL_H

#include <mysql/mysql.h>
#include "../../db/db_val.h"
#include "../../db/db_to_module.h"


/**
 * Does not copy strings
 */
int db_mysql_str2val( db_type_t _t, db_val_t* _v,  char* _s,
	 int _l);


/**
 * Used when converting result from a query
 */
int db_mysql_val2str( db_con_t* _con,  db_val_t* _v, char* _s,
		int* _len);
int db_mysql_val2bind( db_val_t* v, MYSQL_BIND *binds, unsigned int i);

#endif /* VAL_H */
