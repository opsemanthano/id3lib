/* $Id: demo_simple.cpp,v 1.1 2002/07/23 13:47:58 t1mpy Exp $

 * Copyright 2000 Scott Thomas Haug <scott@id3.org>
 *  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <id3.h>
#include <stdio.h>
#include <string.h>

int
main( int argc, char *argv[] )
{
  char *filename = NULL;
  ID3Tag *tag;
  int update = 0;
  
  if (argc != 2)
  {
    printf("*** Usage: %s file\n", argv[0]);
    exit (1);
  }
  filename = argv[1];
  printf("*** Reading %s\n", filename);
  
  if ((tag = ID3Tag_New()) != NULL)
  {
    ID3Frame *frame;

    (void) ID3Tag_Link(tag, filename);
    if ((frame = ID3Tag_FindFrameWithID(tag, ID3FID_TITLE)) != NULL)
    {
      ID3Field *field;
      if ((field = ID3Frame_GetField(frame, ID3FN_TEXT)) != NULL)
      {
        char title[1024];
        (void) ID3Field_GetASCII(field, title, 1024);
        if ( title[0] == '"' && title[strlen(title)-1] == '"' ) {
           title[strlen(title)-1] = '\0' ;
           ID3Field_SetASCII(field, &title[1]) ;
           printf("Title: %s\n", &title[1]);
           update = 1 ;
        } else {
           printf("Title: %s\n", title);
        }
      }
      else
      {
        printf("Didn't get the field\n");
      }
    }
    else
    {
      printf("Didn't get the frame\n");
    }

    if ((frame = ID3Tag_FindFrameWithID(tag, ID3FID_LEADARTIST)) != NULL)
    {
      ID3Field *field;
      if ((field = ID3Frame_GetField(frame, ID3FN_TEXT)) != NULL)
      {
        char artist[1024];
        (void) ID3Field_GetASCII(field, artist, 1024);
        if ( artist[0] == '"' && artist[strlen(artist)-1] == '"' ) {
           artist[strlen(artist)-1] = '\0' ;
           ID3Field_SetASCII(field, &artist[1]) ;
           printf("Artist: %s\n", &artist[1]);
           update = 1 ;
        } else {
           printf("Artist: %s\n", artist);
        }
      }
      else
      {
        printf("Didn't get the field\n");
      }
    }
    else
    {
      printf("Didn't get the frame\n");
    }

    if ((frame = ID3Tag_FindFrameWithID(tag, ID3FID_ALBUM)) != NULL)
    {
      ID3Field *field;
      if ((field = ID3Frame_GetField(frame, ID3FN_TEXT)) != NULL)
      {
        char album[1024];
        (void) ID3Field_GetASCII(field, album, 1024);
        if ( album[0] == '"' && album[strlen(album)-1] == '"' ) {
           album[strlen(album)-1] = '\0' ;
           ID3Field_SetASCII(field, &album[1]) ;
           printf("Album: %s\n", &album[1]);
           update = 1 ;
        } else {
           printf("Album: %s\n", album);
        }
      }
      else
      {
        printf("Didn't get the field\n");
      }
    }
    else
    {
      printf("Didn't get the frame\n");
    }
  }
  else
  {
    printf("Didn't get the tag\n");
  }

  if ( update ) {
     ID3Tag_Update(tag) ;
  }
  exit (0);
}
