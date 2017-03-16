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

	//Choose random site
	//Site example 00000000-0064-0008-0000-100000000000
	//lr_save_string(lr_eval_string("00000000-0000-0000-0000-0000000000{site_index}"), "siteID");														   
	lr_save_string(lr_eval_string("00000000-0000-0000-0000-000000000000"), "siteID");														   
	
	// TODO: ADD LOGIC FOR STARTING FROM JAVA LAYER
	
	if (use_translation==1){
		index = atoi(lr_eval_string("{site_index}"));
		translation_distribution(index);
	}

	return 0;
}


void print_message(){
	lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "error_date");
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