#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"






//--------------------------------------------------------------------
// Global Variables






#endif // _GLOBALS_H

int tt=0;
int use_hcproxy=0;
int use_tc=0;
int use_translation=0;
void fire_count ();

void printme(char * what){
			lr_vuser_status_message("DEBUG:########################## %s #####################\n" , lr_eval_string(what));
			lr_output_message("DEBUG:########################## %s #####################\n" , lr_eval_string(what));
}

