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
	lr_save_string(lr_get_attrib_string("protocol"), "protocol");
	
	lr_save_string(lr_eval_string("{host}-{account}.{domain}"), "hostUrl");
	lr_save_string(lr_get_attrib_string("ui5_server"), "ui5_server");
	
	use_CDN = atoi((lr_get_attrib_string("use_CDN")));
				
	web_set_sockets_option("MAX_TOTAL_CONNECTIONS" , "6");
	web_set_sockets_option("MAX_CONNECTIONS_PER_HOST" , "6");
	web_set_max_html_param_len("10485760");
	web_add_auto_header("Accept-Language", "en-US,en;q=0.8");
	web_add_auto_header("Upgrade-Insecure-Requests", "1");
												   
	lr_save_string(lr_eval_string("9a28bae7-bf1c-407f-93ea-cd32ac523859"), "siteID");														   
	
	return 0;
}
