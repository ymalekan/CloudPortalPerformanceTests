# 1 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c"
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





 
 

















# 1 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

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

 
 
 

                               


 
 
 





















# 2 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

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

# 3 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{
	web_set_sockets_option("SSL_VERSION", "TLS");
    web_set_sockets_option("OVERLAPPED_SEND", "0");
    web_set_sockets_option("IGNORE_PREMATURE_SHUTDOWN", "1");


	tt = atoi((lr_get_attrib_string("THINK_TIME")));
	lr_save_string(lr_get_attrib_string("HOST"), "hostname");

	 
	 

	lr_save_string(lr_get_attrib_string("account"), "account");	
	lr_save_string(lr_get_attrib_string("protocol"), "protocol");

	use_hcproxy= atoi((lr_get_attrib_string("use_HCProxy")));
    use_tc = atoi((lr_get_attrib_string("use_TC")));
    use_translation = atoi((lr_get_attrib_string("use_Translation")));
	
	lr_save_string(lr_get_attrib_string("HOST"), "HOST");
	lr_save_string(lr_eval_string("https://{HOST}"), "HOST");
			
	web_set_sockets_option("MAX_TOTAL_CONNECTIONS" , "6");
	web_set_sockets_option("MAX_CONNECTIONS_PER_HOST" , "6");
	web_set_max_html_param_len("10485760");
	web_add_auto_header("Accept-Language", "en-US,en;q=0.8");

	 
	 
	
	 
	
	 
	 
	
	 
	 
	 
	
	 
	 
	
	 
	lr_save_string(lr_eval_string("00000000-0064-0008-0000-100000000001"), "site_id");
	
	 

	if (use_translation==1){
		translation_distribution();
	}
	 

	return 0;
}


void print_message(){
	lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
	lr_output_message("%s - INFO - [%s]", lr_eval_string("{error_date}") , lr_eval_string("{PRINT_MESSAGE}"));
	lr_vuser_status_message("%s - INFO - [%s]", lr_eval_string("{error_date}") , lr_eval_string("{PRINT_MESSAGE}"));
}

void translation_distribution(){
	int user_num=-1;

	 
	user_num = atoi(lr_eval_string("700006"));
	if (user_num >= 700000 && user_num < 701999) 
	{
		web_add_auto_header("Accept-Language", "it-IT"); 
		lr_save_string("it","locale");
		 
		 
		 
	} else if (user_num >= 702000 && user_num < 703999)
	{
		web_add_auto_header("Accept-Language", "he-IL"); 
		lr_save_string("he","locale");
		 
	} else if (user_num >= 704000 && user_num < 705999)
	{
		web_add_auto_header("Accept-Language", "de-DE"); 
		lr_save_string("de","locale");
		 
	} else if (user_num >= 706000 && user_num < 707999) 
	{
		web_add_auto_header("Accept-Language", "es-ES"); 
		lr_save_string("es","locale");
		 
	} else  
	{
		web_add_auto_header("Accept-Language", "fr-FR"); 
		lr_save_string("fr","locale");
		 

	}

}

void user_distribution()
{
	int site_number = 0;

	 
	site_number = atoi(lr_eval_string("{RandonNum}"));
	lr_save_int(site_number, "site_id");

	 
# 121 "vuser_init.c"
	
	switch(site_number % 10)
	{
	case 0:  
		lr_save_string(lr_eval_string("P7{Role_01_Users}"), "{USER_ID}");
		break;
	case 1:  
		lr_save_string(lr_eval_string("P7{Role_02_Users}"), "{USER_ID}");
		break;
	case 2:	 
		lr_save_string(lr_eval_string("P7{Role_03_Users}"), "{USER_ID}");
		break;
	case 3:
		lr_save_string(lr_eval_string("P7{Role_04_Users}"), "{USER_ID}");
		break;
	case 4:
		lr_save_string(lr_eval_string("P7{Role_05_Users}"), "{USER_ID}");
		break;
	case 5:
		lr_save_string(lr_eval_string("P7{Role_06_Users}"), "{USER_ID}");
		break;
	case 6:
		lr_save_string(lr_eval_string("P7{Role_07_Users}"), "{USER_ID}");
		break;
	case 7:
		lr_save_string(lr_eval_string("P7{Role_08_Users}"), "{USER_ID}");
		break;
	case 8:
		lr_save_string(lr_eval_string("P7{Role_09_Users}"), "{USER_ID}");
		break;
	case 9:
		lr_save_string(lr_eval_string("P7{Role_10_Users}"), "{USER_ID}");
		break;
		
	}

	lr_save_datetime("%B %d %Y at %H:%M", 0, "date_time");
	lr_vuser_status_message(" %s  -  user [%s] logging in to site [sap.hana.uis.content-HANAHomePage%s]", lr_eval_string("{date_time}"), lr_eval_string("{{USER_ID}}"), lr_eval_string("{site_id}"));
}
# 4 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "Login_SDN500.c" 1
Login_SDN500()
{
	
		char *userLogin;
		int status = 0 ;		 

		web_global_verification("Text/IC=The SAP Community Network is currently down",  "Fail=Found",  "ID=Gonduras", "LAST"); 

		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", "LAST"); 
			
 
 
 
 
 
 
		lr_save_string("https://accounts500.sap.com/saml2/idp/sso/accounts.sap.com", "SAML_REDIRECT_URL");

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
								
		web_reg_save_param("oucrsrzhqitptowviwhfmseri",
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
		
		 
		 
		 

		lr_save_string( lr_eval_string ("https://{hostname}/sap/hana/uis/clients/ushell-app/shells/fiori/FioriLaunchpad.html?siteID={site_id}"), "site_url");

		 
 
		 
		web_url("launch site", 
			"URL={site_url}", 				
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


 		web_reg_save_param("JSESSIONID_SDN500",
 			"LB=Set-Cookie: JSESSIONID=",
 			"RB=;",
 			"Ord=1",
 			"Search=Headers",
 			"LAST");

 
 
 
 
 
 

		web_reg_save_param("idpSSOEndpoint",
 			"LB=idpSSOEndpoint\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			"LAST");

 
# 134 "Login_SDN500.c"
		web_reg_save_param("loginXSRF",
			"LB=\"loginXSRF\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			"LAST");

		web_reg_save_param("Accounts500_Response",
 			"LB=",
 			"RB=",
 			"Ord=1",
 			"Search=All",
 			"LAST");


		 
		
			status = web_submit_data("redirected to https://accounts500.sap.com/saml2/idp/sso/accounts.sap.com", 
						"Action={SAML_REDIRECT_URL}", 
						"Method=POST", 
						"RecContentType=application/x-www-form-urlencoded", 
						"Referer={site_url}", 
						"Snapshot=t2.inf", 
						"Mode=HTTP", 
						"ITEMDATA", 
						"Name=SAMLRequest", "Value={SAMLRequest}", "ENDITEM", 
						"Name=RelayState", "Value={RelayState}", "ENDITEM", 
						"LAST");

			if ( status == 1 ) 
			{
				lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
				lr_error_message(" %s  -  Response for accounts 500 request %s", lr_eval_string("{error_date}") , lr_eval_string("{Accounts500_Response}"));
				lr_exit(0, 1);
			}
 

		lr_end_transaction("001_SAML" , 2);
		
		lr_think_time(tt);
		
		
		lr_start_transaction("002_Logon_SDN");


		 
		 
		 

		web_reg_save_param("SAMLResponse",
				"LB=\"SAMLResponse\" value='",
				"RB='",
				"Ord=1",
				"Search=Body",
				"LAST");

		web_reg_save_param("RelayState_3",
				"LB=\"RelayState\" value='",
				"RB='",
				"Ord=1",
				"Search=Body",
				"LAST");
 







		 
		

		status = web_submit_data("submit user to accounts.sap.com/saml2/idp/sso/accounts.sap.com", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=text/html", 
					"Referer={SAML_REDIRECT_URL}", 
					"Mode=HTTP", 
					"ITEMDATA", 
					"Name=_rememberme", "Value=on", "ENDITEM", 
					"Name=idpSSOEndpoint", "Value={idpSSOEndpoint}", "ENDITEM",
					"Name=j_password", "Value=Start123!", "ENDITEM", 
					"Name=j_username", "Value={{USER_ID}}", "ENDITEM", 
					"Name=loginXSRF", "Value={loginXSRF}", "ENDITEM",
					"Name=method", "Value=POST", "ENDITEM", 
					"Name=overlayOnIds", "Value=", "ENDITEM", 
					"Name=RelayState", "Value={RelayState_2}", "ENDITEM", 
					"Name=SAMLRequest", "Value={SAMLRequest_2}", "ENDITEM", 
					"Name=targetUrl", "Value=", "ENDITEM", 
					"Name=sourceUrl", "Value=", "ENDITEM",
					"LAST");
		

		if ( status == 1 ) 
		{
			lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
			lr_error_message(" %s  -  Problem with accounts 500 for user[%s]", lr_eval_string("{error_date}") , lr_eval_string("{viewer_id}"));
			lr_vuser_status_message(" %s  -  Problem with accounts 500 for user[%s]", lr_eval_string("{error_date}") , lr_eval_string("{viewer_id}"));
		}

		 
		 
		 
	
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

		web_submit_data("index 1", 
			"Action={site_url}",
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			"ITEMDATA", 
			"Name=SAMLResponse", "Value={SAMLResponse}", "ENDITEM", 
			"Name=RelayState", "Value={RelayState_3}", "ENDITEM", 
			"LAST");
		
		lr_end_transaction("002_Logon_SDN" , 2);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", "LAST"); 

		lr_save_string(lr_eval_string("Login user {viewer_id} logged in to site id [{site_id_to_nav}]"),"PRINT_MESSAGE");
		print_message();

		return 0;
}

# 5 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "Login_SDN.c" 1
Login_SDN()
{
	
		char *userLogin;
		int status = 0 ;		 

		web_global_verification("Text/IC=The SAP Community Network is currently down",  "Fail=Found",  "ID=Gonduras", "LAST"); 

		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", "LAST"); 
			

		lr_save_string("https://accounts.sap.com/saml2/idp/sso/accounts.sap.com", "SAML_REDIRECT_URL");

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
								
		web_reg_save_param("oucrsmltesrdhxjmwtvioopfy",
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


		lr_start_transaction("01_SAML");
		
		 
		 
		 

		 

		lr_save_string( lr_eval_string ("https://{hostname}/sap/hana/uis/clients/ushell-app/shells/fiori/FioriLaunchpad.html?dev=true&siteID={site_id}"), 
		               "site_url");
		
		 
		web_url("launch site", 
			"URL={site_url}", 				
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

		web_reg_save_param("ids",
			"LB=Set-Cookie: ids=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			"LAST");

 		web_reg_save_param("JSESSIONID_SDN",
 			"LB=Set-Cookie: JSESSIONID=",
 			"RB=;",
 			"Ord=1",
 			"Search=Headers",
 			"LAST");

 
 
 
 
 
 

		web_reg_save_param("idpSSOEndpoint",
 			"LB=idpSSOEndpoint\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			"LAST");

		web_reg_save_param("targetUrl",
 			"LB=targetUrl\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			"LAST");

		web_reg_save_param("sourceUrl",
 			"LB=sourceUrl\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			"LAST");
		
		web_reg_save_param("Accounts500_Response",
 			"LB=",
 			"RB=",
 			"Ord=1",
 			"Search=All",
 			"LAST");

 
 
 
			status = web_submit_data("redirected to {SAML_REDIRECT_URL}", 
						"Action={SAML_REDIRECT_URL}", 
						"Method=POST", 
						"RecContentType=text/html", 
						"Referer={site_url}", 
						"Snapshot=t2.inf", 
						"Mode=HTTP", 
						"ITEMDATA", 
						"Name=SAMLRequest", "Value={SAMLRequest}", "ENDITEM", 
						"Name=RelayState", "Value={RelayState}", "ENDITEM", 
						"LAST");

			if ( status == 1 ) 
			{
				lr_save_string(lr_eval_string("Response for accounts request request {Accounts500_Response}"),"PRINT_MESSAGE");
				print_message();		
				lr_exit(0, 1);
			}
 

		lr_end_transaction("01_SAML" , 2);
		
		lr_think_time(tt);
		
		lr_start_transaction("02_Logon_SDN");


		 
		 
		 

		web_reg_save_param("SAMLResponse",
				"LB=\"SAMLResponse\" value='",
				"RB='",
				"Ord=1",
				"Search=Body",
				"LAST");

		web_reg_save_param("RelayState_3",
				"LB=\"RelayState\" value='",
				"RB='",
				"Ord=1",
				"Search=Body",
				"LAST");

		web_reg_save_param("IDP_J_COOKIE",
					"LB/IC=Set-Cookie: IDP_J_COOKIE=",
					"RB=;",
					"Ord=1",
					"Search=Headers",
					"LAST");


		status = web_submit_data("submit user to accounts.sap.com/saml2/idp/sso/accounts.sap.com", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=text/html", 
					"Referer={SAML_REDIRECT_URL}", 
					"Mode=HTTP", 
					"ITEMDATA", 
					"Name=method", "Value=POST", "ENDITEM", 
					"Name=idpSSOEndpoint", "Value={idpSSOEndpoint}", "ENDITEM", 
					"Name=j_username", "Value=I046774", "ENDITEM", 
					"Name=j_password", "Value=Abcd1234", "ENDITEM", 
					"Name=SAMLRequest", "Value={SAMLRequest_2}", "ENDITEM", 
					"Name=RelayState", "Value={RelayState_2}", "ENDITEM", 
					"Name=targetUrl", "Value={targetUrl}", "ENDITEM", 
					"Name=sourceUrl", "Value={sourceUrl}", "ENDITEM", 
					"LAST");
		

		if ( status == 1 ) 
		{
			lr_save_string(lr_eval_string("Problem with accounts for user [{viewer_id}]"),"PRINT_MESSAGE");
			print_message();			
		}

		 
		 
		 
	
		web_set_option("MaxRedirectionDepth", "10", "LAST"); 
	

		web_reg_save_param("SERVER_JSESSONID",
					"LB/IC=Set-Cookie: JSESSIONID=",
					"RB=;",
					"Ord=1",
					"Search=Headers",
					"LAST");
		
		web_reg_save_param("oucrsmltesrdhxjmwtvioopfy",
					"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
					"RB=;",
					"Ord=1",
					"Search=Headers",
					"LAST");
		web_reg_save_param("oucrsmltesrdhxjmwtvioopfy_anchor",
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


		web_submit_data("index 1", 
			"Action={site_url}",
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			"ITEMDATA", 
			"Name=SAMLResponse", "Value={SAMLResponse}", "ENDITEM", 
			"Name=RelayState", "Value={RelayState_3}", "ENDITEM", 
			"EXTRARES",
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			 
			"LAST");
		
		lr_end_transaction("02_Logon_SDN" , 2);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", "LAST"); 

		lr_save_string(lr_eval_string("Login user {viewer_id} logged in to site id [{site_id}]"),"PRINT_MESSAGE");
		print_message();

		return 0;
}

# 6 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "Open_Catalogs.c" 1
Open_Catalogs()
{
	
	 
	 

	
	 

     

		web_add_auto_header("Accept", "application/json, text/javascript, */*; q=0.01");
		web_add_auto_header("X-Requested-With", "XMLHttpRequest");
		web_add_auto_header("Connection", "keep-alive");


		 
		 
		
			 
		web_reg_find("Text=ContentPackage_8" , "LAST");

		lr_start_transaction("02_2_Catalogs_API");

		web_url("Catalogs", 
			"URL=https://{hostname}/fiori/cp/runtime/v1/catalogs?siteId={site_id}&sap-statistics=true&_={timestamp}", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={site_url}", 
			"Snapshot=t91.inf", 
			"Mode=HTTP", 
			"LAST");

		lr_end_transaction("02_2_Catalogs_API",2);

		lr_think_time(tt);
			
	return 0;
}
# 7 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "Load_Navigation_Menu.c" 1
Load_Navigation_Menu()
{
	lr_start_transaction("05_Menu_Loading");

		web_url("PageSets", 
			"URL=https://{hostname}/v1/v1/nhs/filtered?siteId={site_id}",
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={site_url}", 
			"Snapshot=t91.inf", 
			"Mode=HTTP", 
			"LAST");

	lr_end_transaction("05_Menu_Loading", 2 );

	lr_think_time(tt);

	return 0;
}
# 8 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "Login_EP.c" 1
Login_EP()
{
		char *userLogin;
		int status = 0 ;		 

		
		if(use_tc ==0)
		{
			 
			lr_save_string("http://ilperf125.perflab.com:50000/saml2/idp/sso", "SAML_REDIRECT_URL");
		}else
		{
			 
			lr_save_string("http://10.26.156.125:50000/saml2/idp/sso", "SAML_REDIRECT_URL");
		}
		
		
		
		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", "LAST"); 
			

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
		
		 
		 
		 

		lr_save_string( lr_eval_string ("https://{hostname}/sites?siteId={site_id}&hc_login"), 
		               "site_url");
		
		 
		web_url("launch site", 
			"URL={site_url}", 				
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
						"Referer={site_url}", 
						"Snapshot=t2.inf", 
						"Mode=HTTP", 
						"ITEMDATA", 
						"Name=SAMLRequest", "Value={SAMLRequest}", "ENDITEM", 
						"Name=RelayState", "Value={RelayState}", "ENDITEM", 
						"LAST");


			if ( status == 1 ) 
			{
				lr_save_datetime("%B %d %Y at %H:%M", 0, "error_date");
				lr_error_message(" %s  -  Response for user %s", lr_eval_string("{error_date}") , lr_eval_string("{user_id}"));
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

	
		lr_save_string(lr_eval_string("P7{USER_ID}"), "user_id");
		 

		status = web_submit_data("submit user to ilperf125", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=text/html", 
					"Referer={SAML_REDIRECT_URL}", 
					"Mode=HTTP", 
					"ITEMDATA", 
					"Name=method", "Value=POST", "ENDITEM", 
					"Name=j_username", "Value={user_id}", "ENDITEM", 
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
			lr_error_message(" %s  -  Problem with for user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{user_id}"));
			lr_vuser_status_message(" %s  -  Problem with user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{user_id}"));
		}

		lr_vuser_status_message(" Logged in with user[%s]", lr_eval_string("{user_id}"));

		 
		 
		 
	
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

		 
		web_reg_save_param("timestamp",
			"LB=window[\"sap-hana-uis-build-timestamp\"] = \'",
			"RB=\';",
			"Ord=1",
			"Search=Body",
			"LAST");
		
		 
		web_reg_save_param("uis_version",
			"LB=window[\"sap-hana-uis-build-version\"] = \'",
			"RB=\';",
			"Ord=1",
			"Search=Body",
			"LAST");
		
		web_submit_data("index 1", 
			"Action={site_url}",
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			"ITEMDATA", 
			"Name=SAMLResponse", "Value={SAMLResponse}", "ENDITEM", 
			"Name=RelayState", "Value={RelayState_3}", "ENDITEM", 
			"LAST");
		
		lr_end_transaction("002_Logon_SDN" , 2);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", "LAST"); 

		lr_save_string(lr_eval_string("Login user {user_id} logged in to site id [{site_id}]"),"PRINT_MESSAGE");
		
		print_message();

		return 0;

}

	



# 9 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "scenario.c" 1
scenario()
{
	
	lr_start_transaction("02_open_catalogs");

	web_add_auto_header("Accept-Language", 
		"en");

	web_add_auto_header("MaxDataServiceVersion", 
		"3.0");

	web_add_auto_header("x-csrf-token",	"{x-csrf-token}");

	web_reg_find("Text=PAGE_BUILDER_PERS" , "LAST");
	
	web_url("allCatalogs", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_PERS/Pages('%2FUI2%2FFiori2LaunchpadHome')/allCatalogs?$expand=Chips/ChipBags/ChipProperties&$orderby=id&$filter=type%20eq%20'CATALOG_PAGE'%20or%20type%20eq%20'H'%20or%20type%20eq%20'SM_CATALOG'%20or%20type%20eq%20'REMOTE'", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t76.inf", 
		"Mode=HTTP", 
		"LAST");
	
	lr_end_transaction("02_open_catalogs",2);
	fire_count ();
	lr_think_time(tt);
	
	
 
 
# 82 "scenario.c"


	lr_start_transaction("06_refersh_home");

	(web_remove_auto_header("MaxDataServiceVersion", "ImplicitGen=Yes", "LAST"));

	(web_remove_auto_header("X-CSRF-Token", "ImplicitGen=Yes", "LAST"));

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.8");
	lr_start_sub_transaction("06_1_FioriLaunchpad_html","06_refersh_home");
	web_url("FioriLaunchpad.html_3", 
		"URL={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t87.inf", 
		"Mode=HTTP", 
		"LAST");
	lr_end_sub_transaction("06_1_FioriLaunchpad_html",2);

	
	lr_start_sub_transaction("06_2_startup_service","06_refersh_home");
	web_url("start_up_2", 
		"URL={HOST}/sap/bc/ui2/start_up?sap-language=EN&sap-client=100&shellType=FLP&depth=0", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t90.inf", 
		"Mode=HTTP", 
		"LAST");
	
	lr_end_sub_transaction("06_2_startup_service",2);

	web_add_header("X-CSRF-Token", 
		"fetch");
	web_reg_find("Text=PAGE_BUILDER_PERS" , "LAST");

	lr_start_sub_transaction("06_3_page_sets_API","06_refersh_home");
	web_url("PageSets('%2FUI2%2FFiori2LaunchpadHome')_2", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_PERS/PageSets('%2FUI2%2FFiori2LaunchpadHome')?$expand=Pages/PageChipInstances/Chip/ChipBags/ChipProperties,Pages/PageChipInstances/RemoteCatalog,Pages/PageChipInstances/ChipInstanceBags/ChipInstanceProperties,AssignedPages,DefaultPage", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t91.inf", 
		"Mode=HTTP", 
		"LAST");
	
	lr_end_sub_transaction("06_3_page_sets_API",2);
	web_save_timestamp_param("zbb" , "LAST");
	
	 
	web_url("applauncher.chip.xml_2", 
		"URL={HOST}/sap/bc/ui5_ui5/ui2/ushell/chips/applauncher.chip.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t92.inf", 
		"Mode=HTTP", 
		"LAST");
	
	 

	 
	
	web_url("applauncher_dynamic.chip.xml_2", 
		"URL={HOST}/sap/bc/ui5_ui5/ui2/ushell/chips/applauncher_dynamic.chip.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t93.inf", 
		"Mode=HTTP", 
		"LAST");
	
 


	lr_end_transaction("06_refersh_home",2);

	fire_count ();
	lr_think_time(tt);
		
	
	
	
	return 0;
}

void fire_count (){
	lr_start_transaction("99_count");
	
	web_url("count", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_CUST/Pages/$count", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t78.inf", 
		"LAST");	
	
	lr_end_transaction("99_count",2);

}
# 10 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "logoff.c" 1
logoff()
{
	
	lr_start_transaction("08_logoff");

	web_add_auto_header("Accept-Language", 
		"en");

	web_add_header("MaxDataServiceVersion", 
		"3.0");

	web_add_header("X-CSRF-Token",	"{x-csrf-token}");


	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.8");
	 
	
	 
	
	web_url("logoff", 
		"URL={HOST}/sap/public/bc/icf/logoff", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t99.inf", 
		"Mode=HTTP", 
		"LAST");

	 

	lr_end_transaction("08_logoff",2);

	lr_think_time(tt);

	
	return 0;
}
# 11 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "Load_LaunchPad.c" 1
Load_LaunchPad()
{
	int i = 0;
	web_add_auto_header("Accept", "application/json, text/javascript, */*; q=0.01");
	web_add_auto_header("X-Requested-With", "XMLHttpRequest");
	web_add_auto_header("Connection", "keep-alive");


	web_add_auto_header("oucrstlqawumntvfithbntpyv", "{oucrstlqawumntvfithbntpyv}");
	



	lr_start_transaction("03_Load_Launchpad");

		if (use_hcproxy==1)
		{
			Static_Content_Part_1();
		}
		
	
		 
		 
		
		
		 
		 
		
		 
		web_reg_find("Text=pagesOrder" , "LAST");
		
		if (use_translation==1){
			 
			lr_vuser_status_message(" Use locale=[%s]", lr_eval_string("{locale}"));			
		}else {
			 
		}

		lr_start_sub_transaction("031_Sites_API" ,"03_Load_Launchpad");

			web_url("Sites API", 
				"URL=https://{hostname}/fiori/cp/runtime/v1/sites/{site_id}?sap-statistics=true",  
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={site_url}", 
				"Snapshot=t91.inf", 
				"Mode=HTTP", 
				"LAST");
	
		lr_end_sub_transaction("031_Sites_API", 2 );
	
		 
	
		
		if (use_hcproxy==1)
		{
			Static_Content_Part_2();
		}

		 
# 92 "Load_LaunchPad.c"
	
		if (use_hcproxy==1)
		{
			 
		}

	lr_end_transaction("03_Load_Launchpad",2);
	

	lr_think_time(tt);

	return 0;
}

Static_Content_Part_1()
{

web_concurrent_start(0);

	web_url("uis_fiori.js", 
		"URL=https://{hostname}/{uis_version}/runtime/sap/hana/uis/flp/bootstrap/uis_fiori.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	
	web_url("core-min-0.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-0.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	
	web_url("core-min-1.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-1.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	
	web_url("core-min-2.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-2.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	
	web_url("core-min-3.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-3.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");


web_concurrent_end(0);

return 0;
}

Static_Content_Part_2()
{
	
	web_url("library.preload.json", 
		"URL=https://{hostname}/{uis_version}/runtime/sap/hana/uis/flp/library-preload.json?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
		
	web_url("library.css", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/themes/sap_bluecrystal/library.css?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");	
	
	if (use_translation==1)
	{
		web_url("messagebundle-preload_{locale}.js",
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/fiori/messagebundle-preload_{locale}.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
		
		web_url("Messages.properties", 
		"URL=https://{hostname}//{uis_version}/runtime/sap/hana/uis/flp/resources/resources/Messages_{locale}.properties", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	}else {
		web_url("messagebundle-preload.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/messagebundle-preload.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");	
		
		web_url("Messages.properties", 
		"URL=https://{hostname}/{uis_version}/sap/hana/uis/clients/flp/js/sap/hana/uis/flp/resources/resources/Messages.properties", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	}
	
	web_url("Image.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/m/Image.js?ts=={timestamp}", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	 
# 235 "Load_LaunchPad.c"
	
	web_url("library-parameters.json", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/themes/sap_bluecrystal/library-parameters.json?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	
	web_url("core-ext-light.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/fiori/core-ext-light.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
		
	web_url("Component-preload.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ushell/components/flp/Component-preload.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
		
	web_url("flp-controls.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/fiori/flp-controls.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
		
	web_url("sap_50x26.png", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ui/core/mimes/logo/sap_50x26.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");

	web_url("SAP-icons.ttf", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ui/core/themes/base/fonts/SAP-icons.ttf", 
		"Resource=1", 
		"RecContentType=font/ttf", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");

	web_url("resources.properties", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ushell/renderers/fiori2/resources/resources.properties", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
		
	web_url("launchpad_favicon.ico", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ushell/themes/base/img/launchpad_favicon.ico", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");

	web_url("loader.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/discovery/all_libs", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");

	return 0;
}

App_data()
{
	
web_concurrent_start(0);

	web_url("count1", 
		"URL=https://{hostname}/flp/designer/v1/apps/count?a=a", 
		"Resource=1", 
		"RecContentType=application/json; odata=fullmetadata", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		"LAST");
	
	web_url("count2", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?b=b", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");
	
	web_url("count3", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?c=c", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");
	
	web_url("count4", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?d=d", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");
	
	web_url("count5", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?e=e", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");
	
	web_url("count6", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?f=f", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");
	
	web_url("count7", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?g=g", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");	

		web_url("count8", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?h=h", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			"LAST");

web_concurrent_end(0);
return 0;
}


# 12 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 13 "c:\\master\\panda\\internal\\on_demand\\performance\\scripts\\flp_cloud\\\\combined_FLP_Cloud.c" 2

