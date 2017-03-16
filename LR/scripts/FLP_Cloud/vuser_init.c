vuser_init()
{
	web_set_sockets_option("SSL_VERSION", "TLS");
    web_set_sockets_option("OVERLAPPED_SEND", "0");
    web_set_sockets_option("IGNORE_PREMATURE_SHUTDOWN", "1");


	tt = atoi((lr_get_attrib_string("THINK_TIME")));
	lr_save_string(lr_get_attrib_string("HOST"), "hostname");

	//lr_save_string("fiorilaunchpad-x664602fe.perf.hcproxy.neo.ondemand.com", "hostname");
	//lr_save_string("{hostname}", "hostname");

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

	//Choose random site
	//Site example 00000000-0064-0008-0000-100000000000
	
	//perf6 has only 100 sites
	
	//perf5 1000
	//TODO lr_save_string(lr_eval_string("00000000-0064-0008-0000-1000000000{site_id_postfix}"), "site_id");
	
	//lr_save_string(lr_eval_string("00000000-0000-0000-0000-000000000750"), "site_id");
	//lr_save_string(lr_eval_string("00000000-0064-0008-0000-100000000001"), "site_id");
	//lr_save_string(lr_eval_string("00000000-0000-0000-0000-000000000000"), "site_id");
	
	//randomly pick from 1 out of 10 -  750 app site
	//lr_save_string(lr_eval_string("{random_site_id}"), "site_id");
	
	//one site load
	lr_save_string(lr_eval_string("00000000-0064-0008-0000-100000000001"), "site_id");
	
	// TODO: ADD LOGIC FOR STARTING FROM JAVA LAYER

	if (use_translation==1){
		translation_distribution();
	}
	//user_distribution();

	return 0;
}


void print_message(){
	lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "error_date");
	lr_output_message("%s - INFO - [%s]", lr_eval_string("{error_date}") , lr_eval_string("{PRINT_MESSAGE}"));
	lr_vuser_status_message("%s - INFO - [%s]", lr_eval_string("{error_date}") , lr_eval_string("{PRINT_MESSAGE}"));
}

void translation_distribution(){
	int user_num=-1;

	//user_num = atoi(lr_eval_string("7{USER_ID}6"));
	user_num = atoi(lr_eval_string("700006"));
	if (user_num >= 700000 && user_num < 701999) 
	{
		web_add_auto_header("Accept-Language", "it-IT"); 
		lr_save_string("it","locale");
		//lr_save_string( lr_eval_string ("{protocol}://{hostname_with_tenant}/{site_alias_id}?locale=es_ES"), "site_url");
		//lr_save_string( lr_eval_string ("{protocol}://{hostname_with_tenant}/portal/{version}/sites/{site_id_to_nav}?locale=es_ES"), "site_layout_url");
		//lr_save_string(lr_eval_string("01_1_Get_Site_Layout_Private_Spanish"),"Get_Site_Layout");
	} else if (user_num >= 702000 && user_num < 703999)
	{
		web_add_auto_header("Accept-Language", "he-IL"); 
		lr_save_string("he","locale");
		//lr_save_string(lr_eval_string("01_1_Get_Site_Layout_Private_Danish"),"Get_Site_Layout");
	} else if (user_num >= 704000 && user_num < 705999)
	{
		web_add_auto_header("Accept-Language", "de-DE"); 
		lr_save_string("de","locale");
		//lr_save_string(lr_eval_string("01_1_Get_Site_Layout_Private_German"),"Get_Site_Layout");
	} else if (user_num >= 706000 && user_num < 707999) 
	{
		web_add_auto_header("Accept-Language", "es-ES"); 
		lr_save_string("es","locale");
		//lr_save_string(lr_eval_string("01_1_Get_Site_Layout_French"),"Get_Site_Layout");
	} else // user_num >= 708000 && user_num < 709999
	{
		web_add_auto_header("Accept-Language", "fr-FR"); 
		lr_save_string("fr","locale");
		//lr_save_string(lr_eval_string("01_1_Get_Site_Layout_English_Default"),"Get_Site_Layout");

	}

}

void user_distribution()
{
	int site_number = 0;

	//Random number between 1-1000
	site_number = atoi(lr_eval_string("{RandonNum}"));
	lr_save_int(site_number, "site_id");

	/*
	P700000 - P701999 - ROLE_01 - siteNum % 10 = 0 - sap.hana.uis.content-HANAHomePage10 - sap.hana.uis.content-HANAHomePage20
	P702000 - P703999 - ROLE_02 - siteNum % 10 = 1  - sap.hana.uis.content-HANAHomePage1  - sap.hana.uis.content-HANAHomePage11
	P704000 - P705999 - ROLE_03 - siteNum % 10 = 2  - sap.hana.uis.content-HANAHomePage2  - sap.hana.uis.content-HANAHomePage12
	P706000 - P707999 - ROLE_04 - siteNum % 10 = 3  - sap.hana.uis.content-HANAHomePage3  - sap.hana.uis.content-HANAHomePage13
	P708000 - P709999 - ROLE_05 - siteNum % 10 = 4  - sap.hana.uis.content-HANAHomePage4  - sap.hana.uis.content-HANAHomePage14
	P710000 - P711199 - ROLE_06 - siteNum % 10 = 5  - sap.hana.uis.content-HANAHomePage5  - sap.hana.uis.content-HANAHomePage15
	P712000 - P713999 - ROLE_07 - siteNum % 10 = 6  - sap.hana.uis.content-HANAHomePage6  - sap.hana.uis.content-HANAHomePage16
	P714000 - P715999 - ROLE_08 - siteNum % 10 = 7  - sap.hana.uis.content-HANAHomePage7  - sap.hana.uis.content-HANAHomePage17
	P716000 - P717999 - ROLE_09 - siteNum % 10 = 8  - sap.hana.uis.content-HANAHomePage8  - sap.hana.uis.content-HANAHomePage18
	P718000 - P719999 - ROLE_10 - siteNum % 10 = 9  - sap.hana.uis.content-HANAHomePage9  - sap.hana.uis.content|HANAHomePage19
    */
	
	switch(site_number % 10)
	{
	case 0: //ROLE_01 users - P700000 - P701999
		lr_save_string(lr_eval_string("P7{Role_01_Users}"), "{USER_ID}");
		break;
	case 1: //ROLE_02 users - P702000 - P703999
		lr_save_string(lr_eval_string("P7{Role_02_Users}"), "{USER_ID}");
		break;
	case 2:	//ROLE_02 users - P704000 - P705999
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

	lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "date_time");
	lr_vuser_status_message(" %s  -  user [%s] logging in to site [sap.hana.uis.content-HANAHomePage%s]", lr_eval_string("{date_time}"), lr_eval_string("{{USER_ID}}"), lr_eval_string("{site_id}"));
}
