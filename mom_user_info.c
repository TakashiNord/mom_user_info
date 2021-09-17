/*****************************************************************************
**
** mom_user_info.cpp
**
** Description:
**    Main file for the application.
**
*****************************************************************************/

/* Include files */
#include <stdio.h>
#include <uf.h>
#include <uf_ui.h>
#include "mom_user_info.h"

/* Main routine */
extern void main( char argc, char *argv[] )
{
    /* Initialize the API environment */
    int errorCode = UF_initialize();

    if ( 0 == errorCode )
    {
     
	 char str[256];	
		/* TODO: Add your application code here */
     UF_system_info_t               zSystemInfo;

     zSystemInfo.date_buf = NULL;      /* Current date and time info */
     zSystemInfo.user_name = NULL;     /* User, who is running this process */
     zSystemInfo.program_name = NULL;  /* The current program name */
     zSystemInfo.node_name = NULL;     /* Machine, on which this process is running */
     zSystemInfo.machine_type = NULL;  /* Hardware type on which the machine is running */
     zSystemInfo.os_name = NULL;       /* Operating system, on which this process is running*/
     zSystemInfo.os_version = NULL;    /* Version and release level of this Operating System */

	 UF_UI_open_listing_window( );

     /* Get some system info : Date time user etc... */
     UF_ask_system_info(&zSystemInfo);
	 if (zSystemInfo.user_name!=NULL) {
	    sprintf(str,"\n user_name = %s",zSystemInfo.user_name) ;
	    UF_UI_write_listing_window(str);
	 }
	 if (zSystemInfo.node_name!=NULL) {
	    sprintf(str,"\n node_name = %s",zSystemInfo.node_name) ;
	    UF_UI_write_listing_window(str);
	 }
	 if (zSystemInfo.program_name!=NULL) {
	    sprintf(str,"\n program_name = %s",zSystemInfo.program_name) ;
	    UF_UI_write_listing_window(str);
	 }
     /* Free system info */
     UF_free_system_info(&zSystemInfo); 

        /* Terminate the API environment */
        errorCode = UF_terminate();
    }

    /* Print out any error messages */
    PrintErrorMessage( errorCode );
}

/* PrintErrorMessage
**
**     Prints error messages to standard error. */
static void PrintErrorMessage( int errorCode )
{
    if ( 0 != errorCode )
    {
        /* Retrieve the associated error message */
        char message[133];
        UF_get_fail_message( errorCode, message );

        /* Print out the message */

        fprintf( stderr, "%s\n", message );
    }
}
