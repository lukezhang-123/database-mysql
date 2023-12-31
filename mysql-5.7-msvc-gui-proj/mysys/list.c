/* Copyright (c) 2000, 2023, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   Without limiting anything contained in the foregoing, this file,
   which is part of C Driver for MySQL (Connector/C), is also subject to the
   Universal FOSS Exception, version 1.0, a copy of which can be found at
   http://oss.oracle.com/licenses/universal-foss-exception.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

/*
  Code for handling dubble-linked lists in C
*/

#include "mysys_priv.h"
#include "my_sys.h"
#include <my_list.h>

	/* Add a element to start of list */

LIST *list_add(LIST *root, LIST *element)
{
  DBUG_ENTER("list_add");
  DBUG_PRINT("enter",("root: 0x%lx  element: 0x%lx", (long) root, (long) element));
  if (root)
  {
    if (root->prev)			/* If add in mid of list */
      root->prev->next= element;
    element->prev=root->prev;
    root->prev=element;
  }
  else
    element->prev=0;
  element->next=root;
  DBUG_RETURN(element);			/* New root */
}


LIST *list_delete(LIST *root, LIST *element)
{
  if (element->prev)
    element->prev->next=element->next;
  else
    root=element->next;
  if (element->next)
    element->next->prev=element->prev;
  return root;
}


void list_free(LIST *root, uint free_data)
{
  LIST *next;
  while (root)
  {
    next=root->next;
    if (free_data)
      my_free(root->data);
    my_free(root);
    root=next;
  }
}


LIST *list_cons(void *data, LIST *list)
{
  LIST *new_charset=(LIST*) my_malloc(key_memory_LIST,
                                      sizeof(LIST),MYF(MY_FAE));
  if (!new_charset)
    return 0;
  new_charset->data=data;
  return list_add(list,new_charset);
}


LIST *list_reverse(LIST *root)
{
  LIST *last;

  last=root;
  while (root)
  {
    last=root;
    root=root->next;
    last->next=last->prev;
    last->prev=root;
  }
  return last;
}

uint list_length(LIST *list)
{
  uint count;
  for (count=0 ; list ; list=list->next, count++) ;
  return count;
}


int list_walk(LIST *list, list_walk_action action, uchar* argument)
{
  int error=0;
  while (list)
  {
    if ((error = (*action)(list->data,argument)))
      return error;
    list=list_rest(list);
  }
  return 0;
}
