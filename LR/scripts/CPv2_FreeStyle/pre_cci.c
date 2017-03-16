# 1 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c"
# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"








































































	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 266 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 505 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 508 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 531 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 565 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 588 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 612 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);
int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 683 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											int * col_name_len);
# 744 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 759 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   int const in_len,
                                   char * * const out_str,
                                   int * const out_len);
# 783 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 795 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 803 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 809 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char *buffer, long buf_size, unsigned int occurrence,
			    char *search_string, int offset, unsigned int param_val_len, 
			    char *param_name);

 
char *   lr_string (char * str);

 
# 905 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 912 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 934 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1010 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1039 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


# 1051 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char *sourceString, char *fromEncoding, char *toEncoding, char *paramName);





 
 

















# 1 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/SharedParameter.h"





typedef int PVCI2;
typedef int VTCERR2;

 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(int pvci);
extern VTCERR2  vtc_get_last_error(int pvci);

 
extern VTCERR2  vtc_query_column(int pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(int pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(int pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(int pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(int pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(int pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(int pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(int pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(int pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(int pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(int pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_increment(int pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(int pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(int pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(int pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(int pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(int pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(int pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(int pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(int pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern int     lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern int     lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h" 1























































 




 








 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);










# 631 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"


# 644 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"



























# 682 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 750 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"



 
 
 






# 9 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/web_api.h" 2

















 






 














  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 





# 7 "globals.h" 2

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrw_custom_body.h" 1
 





# 8 "globals.h" 2







 
 








int tt=0;
int use_hcproxy=0;
int use_tc=0;
int use_translation=0;
void fire_count ();

void printme(char * what){
			lr_vuser_status_message("DEBUG:########################## %s #####################\n" , lr_eval_string(what));
			lr_output_message("DEBUG:########################## %s #####################\n" , lr_eval_string(what));
}

# 3 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "vuser_init.c" 1
int use_CDN;

vuser_init()
{
	int index;
	
	web_set_sockets_option("SSL_VERSION", "TLS");
    web_set_sockets_option("OVERLAPPED_SEND", "0");
    web_set_sockets_option("IGNORE_PREMATURE_SHUTDOWN", "1");


	tt = atoi((lr_get_attrib_string("THINK_TIME")));
	lr_save_string(lr_get_attrib_string("host"), "host");
	lr_save_string(lr_get_attrib_string("account"), "account");	
	lr_save_string(lr_get_attrib_string("domain"), "domain");	
	
	lr_save_string(lr_eval_string("{host}-{account}.{domain}"), "hostUrl");
	lr_save_string(lr_get_attrib_string("ui5_server"), "ui5_server");
	
	use_CDN = atoi((lr_get_attrib_string("use_CDN")));
				
	web_set_sockets_option("MAX_TOTAL_CONNECTIONS" , "6");
	web_set_sockets_option("MAX_CONNECTIONS_PER_HOST" , "6");
	web_set_max_html_param_len("10485760");
	web_add_auto_header("Accept-Language", "en-US,en;q=0.8");
	web_add_auto_header("Upgrade-Insecure-Requests", "1");

	 
	 
	 
	lr_save_string(lr_eval_string("00000000-0000-0000-0000-000000000000"), "siteID");														   
	
	 
	
	if (use_translation==1){
		index = atoi(lr_eval_string("{site_index}"));
		translation_distribution(index);
	}

	return 0;
}


void print_message(){
	lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
	lr_output_message("%s - INFO - [%s]", lr_eval_string("{error_date}") , lr_eval_string("{PRINT_MESSAGE}"));
	lr_vuser_status_message("%s - INFO - [%s]", lr_eval_string("{error_date}") , lr_eval_string("{PRINT_MESSAGE}"));
}

translation_distribution(int index)
{
	switch(index/20)
		{
		case 0 :
			lr_save_string("en","locale");	
			lr_save_string("en-US","fullLocale");
			web_add_auto_header("Accept-Language", "en-US,en;q=0.8"); 
    		break;
   		case 1 :
    		lr_save_string("de","locale");	
    		lr_save_string("de-DE","fullLocale");
			web_add_auto_header("Accept-Language", "de-DE,de;q=0.8"); 		
	       	break;
		case 2 :
	       	lr_save_string("it","locale");
	       	lr_save_string("it-IT","fullLocale");
	       	web_add_auto_header("Accept-Language", "it-IT,it;q=0.8"); 
	       	break;
	    case 3 :
    		lr_save_string("fr","locale");	
    		lr_save_string("fr-FR","fullLocale");
			web_add_auto_header("Accept-Language", "fr-FR,fr;q=0.8"); 		
	       	break;
		case 4 :
	       	lr_save_string("he","locale");	
	       	lr_save_string("he-HE","fullLocale");
			web_add_auto_header("Accept-Language", "he-HE,he;q=0.8"); 		
	       	break;
	}
	
	return 0;
}
# 4 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Login_EP.c" 1
Login_EP()
{
		char *userLogin;
		int status = 0 ;		 


		lr_save_string("http://10.26.156.125:50000/saml2/idp/sso", "SAML_REDIRECT_URL");		
		
		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", "LAST"); 
			
		web_url("launch site", 
			"URL=https://{hostUrl}/sites?siteId={siteID}", 				
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			"LAST");
		
		web_reg_save_param("SAMLRequest",
			"LB=\"SAMLRequest\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");
	
		web_reg_save_param("RelayState",
			"LB=\"RelayState\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");
								
		web_reg_save_param("oucrszdwftirmqxbqmeaiksqa",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST");

		web_reg_save_param("cookie_v",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST");



		lr_start_transaction("001_SAML");
				
		 
		web_url("launch site", 
			"URL=https://{hostUrl}/sites?siteId={siteID}&hc_login", 				
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			"LAST");

		web_reg_save_param("SAMLRequest_2",
			"LB=\"SAMLRequest\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");

		web_reg_save_param("RelayState_2",
			"LB=\"RelayState\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");
		
		 
		web_reg_save_param("j_salt",
			"LB=j_salt\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");

		 
		web_reg_save_param("initial_post_parameters",
			"LB=name=\"sap.com/initial_post_parameters\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");

		web_reg_save_param("IDP_Response",
 			"LB=",
 			"RB=",
 			"Ord=1",
 			"Search=All",
 			"LAST");


		status = web_submit_data("submit user to ilperf125", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"RecContentType=application/x-www-form-urlencoded", 
					"Referer=https://{hostUrl}/sites?siteId={siteID}", 
					"Snapshot=t2.inf", 
					"Mode=HTTP", 
					"ITEMDATA", 
					"Name=SAMLRequest", "Value={SAMLRequest}", "ENDITEM", 
					"Name=RelayState", "Value={RelayState}", "ENDITEM", 
					"LAST");


		if ( status == 1 ) 
		{
			lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
			lr_error_message(" %s  -  Response for user %s", lr_eval_string("{error_date}") , lr_eval_string("{user}"));
			lr_exit(0, 1);
		}

		lr_end_transaction("001_SAML" , 2);
		
		lr_think_time(tt);
		
		
		lr_start_transaction("002_Logon_SDN");


		 
		 
		 

		web_reg_save_param("SAMLResponse",
				"LB=\"SAMLResponse\" value=\"",
				"RB=\"",
				"Ord=1",
				"Search=Body",
				"LAST");

		web_reg_save_param("RelayState_3",
				"LB=\"RelayState\" value=\"",
				"RB=\"",
				"Ord=1",
				"Search=Body",
				"LAST");

		
		lr_save_string(lr_eval_string("P700{user}"), "USER_ID");	
		 
		
		status = web_submit_data("submit user to ilperf125", 
			"Action={SAML_REDIRECT_URL}", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			"ITEMDATA", 
			"Name=method", "Value=POST", "ENDITEM", 
			"Name=j_username", "Value={USER_ID}", "ENDITEM", 
			"Name=j_password", "Value=Start123!", "ENDITEM", 
			"Name=SAMLRequest", "Value={SAMLRequest_2}", "ENDITEM", 
			"Name=RelayState", "Value={RelayState_2}", "ENDITEM",
			"Name=j_salt", "Value={j_salt}", "ENDITEM",
			"Name=sap.com/initial_post_parameters", "Value={initial_post_parameters}", "ENDITEM",
            "Name=uidPasswordLogon","Value=Log On", "ENDITEM",
			"LAST");
	
		if ( status == 1 ) 
		{
			lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
			lr_error_message(" %s  -  Problem with for user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{USER_ID}"));
			lr_vuser_status_message(" %s  -  Problem with user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{USER_ID}"));
		}

		lr_vuser_status_message(" Logged in with user[%s]", lr_eval_string("{USER_ID}"));

		 
		 
		 
	
		web_set_option("MaxRedirectionDepth", "10", "LAST"); 
	

		web_reg_save_param("SERVER_JSESSONID",
			"LB/IC=Set-Cookie: JSESSIONID=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST");
		
		web_reg_save_param("oucrspalbaihdguwdjbbpejpr",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST");
		
		web_reg_save_param("oucrspalbaihdguwdjbbpejpr_anchor",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^_anchor=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST"); 
		
		web_reg_save_param("JTENANTSESSIONID_{account}",
			"LB/IC=Set-Cookie: JTENANTSESSIONID_{account}=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST");

		 
		web_reg_save_param("build-timestamp",
			"LB=window[\"sap-hana-uis-build-timestamp\"] = \'",
			"RB=\';",
			"Ord=1",
			"Search=Body",
			"LAST");
		
		 
			web_reg_save_param("heliumVersion",
				"LB=window[\"sap-hana-uis-build-version\"] = \'",
				"RB=\';",
				"Ord=1",
				"Search=Body",
				"LAST");
			
		
		if (use_CDN ==0){
			
			 
			web_reg_save_param("ui5InnovationVersion",
				"LB=ui5InnovationVersion: \'",
				"RB=\',",
				"Ord=1",
				"Search=Body",
				"LAST");
		}else{ 
			 
			web_reg_save_param("siteUi5VersionNumber",
				"LB=siteUi5VersionNumber: \'",
				"RB=\',",
				"Ord=1",
				"Search=Body",
				"LAST");
		}
				
		web_submit_data("index 1", 
			"Action=https://{hostUrl}/sites?siteId={siteID}&hc_login",
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			"ITEMDATA", 
			"Name=SAMLResponse", "Value={SAMLResponse}", "ENDITEM", 
			"Name=RelayState", "Value={RelayState_3}", "ENDITEM", 
			"LAST");

		if (use_CDN==1){
			lr_save_string(lr_eval_string("{ui5_server}/{siteUi5VersionNumber}/resources"), "ui5_prefix");
		}else{ 
			lr_save_string(lr_eval_string("{hostUrl}/{heliumVersion}/sap/ui5/1/innovation/resources"), "ui5_prefix");			
			 
		} 
		
		lr_end_transaction("002_Logon_SDN" , 2);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", "LAST"); 

		lr_save_string(lr_eval_string("Login user {USER_ID} logged in to site id [{siteID}]"),"PRINT_MESSAGE");
		
		print_message();
		
		lr_think_time(10);

		return 0;

}
# 5 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Load_Site.c" 1
Load_Site()
{
	 
	 
	web_add_auto_header("Connection", "keep-alive");

	web_save_timestamp_param("timestamp","LAST");
	
	lr_start_transaction("003_Load_Site");
	web_concurrent_start(0);
		
	web_url("core-min-0.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-0.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		"LAST");

	web_url("core-min-1.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-1.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		"LAST");
	
	
	web_url("core-min-2.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-2.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		"LAST");

	web_url("core-min-3.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-3.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		"LAST");

		web_url("core-min-0.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-0.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		"LAST");

	web_url("core-min-1.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-1.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		"LAST");
	
	
	web_url("core-min-2.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-2.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		"LAST");

	web_url("core-min-3.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-3.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		"LAST");
	
	web_url("sap-ui-version.json_6", 
		"URL=https://{ui5_prefix}/sap-ui-version.json?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		"LAST");
	
	web_reg_save_param_ex(
			"ParamName=CSRF-token",
			"LB/IC=x-csrf-token: ", 
			"RB=\r\n", 
			"SEARCH_FILTERS",
			"Scope=Headers",
			"LAST");
	
	web_add_header("X-CSRF-Token", 
		"fetch");
		
	web_url("{siteID}_20", 
		"URL=https://{hostUrl}/fiori/cp/runtime/v1/sites/{siteID}?_={timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t457.inf", 
		"LAST");
	
	
	if (atoi(lr_eval_string("{iter_num}"))==1){
		 
		web_reg_save_param("sapui5-sdk-dist-version",
				"LB=\"version\": \"",
				"RB=\",",
				"Ord=1",
				"Search=Body",
				"LAST");
	}
	
	web_url("sap-ui-version.json_8", 
		"URL=https://{ui5_prefix}/sap-ui-version.json", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t459.inf", 		"LAST");
	
	web_concurrent_end(0);
	
	web_concurrent_start(0);
	
	web_url("library.css_8", 
		"URL=https://{ui5_prefix}/sap/fiori/themes/sap_bluecrystal/library.css?sap-ui-dist-version={sapui5-sdk-dist-version}",
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t459.inf", 
		"LAST");
	
	web_url("library-preload.js_17", 
		"URL=https://{hostUrl}/{heliumVersion}/runtime/sap/hana/uis/flp/library-preload.js.map", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t462.inf", 
		"LAST");
	
	web_url("library-preload.json_17", 
		"URL=https://{hostUrl}/{heliumVersion}/cpv2-services/sap/ushell/cpv2/services/library-preload.json", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t462.inf", 
		"LAST");
		
	web_url("messagebundle-preload_iw.js_3", 
		"URL=https://{ui5_prefix}/sap/fiori/messagebundle-preload_en.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t464.inf", 
		"LAST");

	web_url("Component-preload.js_7", 
		"URL=https://{ui5_prefix}/sap/ushell/components/flp/Component-preload.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t465.inf", 
		"LAST");

	web_url("library-parameters.json_8", 
		"URL=https://{ui5_prefix}/sap/fiori/themes/sap_bluecrystal/library-parameters.json?version={sapui5-sdk-dist-version}&sap-ui-dist-version={sapui5-sdk-dist-version}",
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t468.inf", 
		"LAST");

	web_url("sap_50x26.png_6", 
		"URL=https://{ui5_prefix}/sap/ui/core/mimes/logo/sap_50x26.png", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t469.inf", 
		"LAST");

	web_url("SAP-icons.ttf", 
		"URL=https://{ui5_prefix}/sap/ui/core/themes/base/fonts/SAP-icons.ttf", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/x-font-ttf",
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t470.inf", 
		"LAST");

	web_url("Menu.js_5", 
		"URL=https://{ui5_prefix}/sap/ui/unified/Menu.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t471.inf", 
		"LAST");

	

	web_url("style.css_11", 
		"URL=https://{hostUrl}/sap.ushell.apps.cpv2MenuPlugin/css/style.css?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t475.inf", 
		"LAST");


	web_url("core-ext-light.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-ext-light.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t478.inf", 
		"LAST");
	
	web_url("core-ext-light.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-ext-light.js.map", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t478.inf", 
		"LAST");	

	web_url("Component.js_13", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/pageTemplates/BlankPage/Component.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t479.inf", 
		"LAST");

	web_url("main.css_5", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/css/main.css?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t480.inf", 
		"LAST");

	web_url("Template.view.xml_5", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/pageTemplates/BlankPage/Template.view.xml?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t481.inf", 
		"LAST");

	web_url("Template.controller.js_5", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/pageTemplates/BlankPage/Template.controller.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t482.inf", 
		"LAST");

	web_url("Widget.js_5",
		"URL=https://{hostUrl}/{heliumVersion}/cpv2-services/sap/ushell/cpv2/services/control/widget/Widget.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		"LAST");
	
	web_url("Widget.js_5",
		"URL=https://{hostUrl}/sap.ushell.apps.cpv2MenuPlugin/css/style.css?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		"LAST");
	
	web_url("Component-preload_5",
		"URL=https://{hostUrl}/{heliumVersion}/sap.ushell.apps.cpv2MenuPlugin/Component-preload.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		"LAST");
	
	web_url("megaMenuControl.js_5",
		"URL=https://{hostUrl}/{heliumVersion}/sap.ushell.apps.cpv2MenuPlugin/horizontalMenu/controls/megaMenuControl.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		"LAST");
	
	web_url("megaMenuItem.js_5",
		"URL=https://{hostUrl}/{heliumVersion}/sap.ushell.apps.cpv2MenuPlugin/horizontalMenu/controls/megaMenuItem.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		"LAST");

	web_concurrent_end(0);
	
	lr_end_transaction("003_Load_Site" , 2);
	
	lr_think_time(tt);
	
	return 0;
}
# 6 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page2_HTML.c" 1
Nav_Page2_HTML()
{
	lr_start_transaction("004_Nav_HTML_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
		
	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/htmlwidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("Component.js_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/ecmWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t131.inf",
		"LAST");

	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/htmlwidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("ecmview.controller.js_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/ecmWidget/view/ecmview.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=Albert%20Einstein.html&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_concurrent_end(0);
	
	lr_end_transaction("004_Nav_HTML_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}
# 7 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page3_Image.c" 1
Nav_Page3_Image()
{
	lr_start_transaction("005_Nav_Image_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
		
	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageWidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageWidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageWidget/i18n/i18n_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=NHr1M8S.jpg&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_concurrent_end(0);
	
	lr_end_transaction("005_Nav_Image_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}
# 8 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page4_ImageCarousel.c" 1
Nav_Page4_ImageCarousel()
{
	lr_start_transaction("006_Nav_ImageCarousel_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageCarouselWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageCarouselWidget/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageCarouselWidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");	

	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageCarouselWidget/i18n/i18n_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");	

	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageCarouselWidget/view/Widget.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/imageCarouselWidget/controller/Widget.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		
	 
# 66 "Nav_Page4_ImageCarousel.c"
	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=NHr1M8S.jpg&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");
	
	web_custom_request("{siteID}_5", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=WTyNmvO.jpg&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_custom_request("{siteID}_6", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=dcFwnop.jpg&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");
	
	web_concurrent_end(0);
	
	lr_end_transaction("006_Nav_ImageCarousel_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}
# 9 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page5_RTE.c" 1
Nav_Page5_RTE()
{
	lr_start_transaction("007_Nav_RTE_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component_preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/rte/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/rte/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/rte/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");		

	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/rte/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/controller/RTEBase.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		
	
	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/resource/i18nApp_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=RTE_Page_Rich_Text_Editor_1483878579491.html&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");
	
	web_concurrent_end(0);
	
	lr_end_transaction("007_Nav_RTE_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}
# 10 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page6_Video.c" 1
Nav_Page6_Video()
{
	lr_start_transaction("008_Nav_Video_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	
	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");		

	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/controller/Main.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		
	
	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/videoWidget/i18n/i18n_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");
	
	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	 
	 
	 
	 
	 
	 
# 90 "Nav_Page6_Video.c"

	web_concurrent_end(0);
	
	lr_end_transaction("008_Nav_Video_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}
# 11 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page7_ListBuilder.c" 1
Nav_Page7_ListBuilder()
{

	lr_start_transaction("009_Nav_ListBuilder_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/listbuilder/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/listbuilder/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/listbuilder/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	 
# 43 "Nav_Page7_ListBuilder.c"
	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/listbuilder/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/listbuilder/controller/Main.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=List_Builder_Page_List_Builder_1483878589240.html&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");
	
	web_custom_request("{siteID}_5", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_custom_request("{siteID}_6", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=albert-einstein-150x150.jpg&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");


	web_custom_request("{siteID}_7", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=albert-einstein-150x150.jpg&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_url("header.jpg",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/listbuilder/templates/images/header.jpg",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_concurrent_end(0);
	
	lr_end_transaction("009_Nav_ListBuilder_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}

# 12 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page8_TileGrid.c" 1
Nav_Page8_TileGrid()
{
	lr_start_transaction("010_Nav_TileGrid_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");		
	
	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/controller/Main.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=Tile_Grid_Page_Tile_Grid_1483878561915.html&isRuntime=truee", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");
	
	web_custom_request("{siteID}_5", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_custom_request("{siteID}_6", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");


	web_custom_request("{siteID}_7", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_custom_request("{siteID}_8", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");

	web_custom_request("{siteID}_9", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");


	web_custom_request("{siteID}_10", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		"LAST");
		
	web_url("emptyT.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/templates/images/emptyT.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("tile1.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/templates/images/tile1.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("tile2.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/templates/images/tile2.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		
		
	web_concurrent_end(0);
	
	lr_end_transaction("010_Nav_TileGrid_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}

# 13 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page9_SocialNetworks.c" 1
Nav_Page9_SocialNetworks()
{
	lr_start_transaction("011_Nav_SocialNetworks_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");		
	
	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/i18n/i18n_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");
	
	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/controller/Main.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_url("emptyT.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/images/facebook.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("tile1.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget//images/youtube.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
		
	web_url("tile2.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/images/twitter.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		
		
	web_concurrent_end(0);
	
	lr_end_transaction("011_Nav_SocialNetworks_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}

# 14 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "Nav_Page10_Jam.c" 1
Nav_Page10_Jam()
{
	lr_start_transaction("012_Nav_JamGroupFeed_Page");
	web_concurrent_start(0);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");

	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");
	
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");		
	
	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/i18n/i18n_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		"LAST");
	
	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		"LAST");

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/jamGroupFeedWidget/controller/Main.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		"LAST");		
	
	web_concurrent_end(0);
	
	lr_end_transaction("012_Nav_JamGroupFeed_Page" , 2);
	
	lr_think_time(tt);
			
	return 0;
}
# 15 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 16 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\cpv2_freestyle\\\\combined_CPv2_FreeStyle.c" 2

