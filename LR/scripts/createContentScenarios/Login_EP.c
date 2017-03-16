Login_EP()
{
		char *userLogin;
		int status = 0 ;		 


		lr_save_string("http://ilperf125.perflab.com:50000/saml2/idp/sso", "SAML_REDIRECT_URL");		
		
		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", LAST); 
			
		web_url("launch site", 
			"URL=https://{hostname}/sites/adminspace", 				
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			LAST);
		
		web_reg_save_param("SAMLRequest",
			"LB=\"SAMLRequest\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);
	
		web_reg_save_param("RelayState",
			"LB=\"RelayState\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);
								
		web_reg_save_param("oucrszdwftirmqxbqmeaiksqa",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);

		web_reg_save_param("cookie_v",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);



		lr_start_transaction("001_SAML");
				
		// launch site
		web_url("launch site", 
			"URL=https://{hostname}/sites/adminspace?hc_login", 				
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			LAST);

		web_reg_save_param("SAMLRequest_2",
			"LB=\"SAMLRequest\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);

		web_reg_save_param("RelayState_2",
			"LB=\"RelayState\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);
		
		// name="j_salt" value="TyNyRznBQfOoMKaWqOeWVLuNRJA="
		web_reg_save_param("j_salt",
			"LB=j_salt\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);

		//name="sap.com/initial_post_parameters" value="
		web_reg_save_param("initial_post_parameters",
			"LB=name=\"sap.com/initial_post_parameters\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);

		web_reg_save_param("IDP_Response",
 			"LB=",
 			"RB=",
 			"Ord=1",
 			"Search=All",
 			LAST);

		web_add_header("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
	
		status = web_submit_data("submit user to ilperf125", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"RecContentType=application/x-www-form-urlencoded", 
					"Referer=https://{hostname}/sites/adminspace", 
					"Snapshot=t2.inf", 
					"Mode=HTTP", 
					ITEMDATA, 
					"Name=SAMLRequest", "Value={SAMLRequest}", ENDITEM, 
					"Name=RelayState", "Value={RelayState}", ENDITEM, 
					LAST);


		if ( status == LR_FAIL ) 
		{
			lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "error_date");
			lr_error_message(" %s  -  Response for user %s", lr_eval_string("{error_date}") , lr_eval_string("{user}"));
			lr_exit(LR_EXIT_VUSER, LR_FAIL);
		}

		lr_end_transaction("001_SAML" , LR_AUTO);
		
		lr_think_time(tt);
		
		
		lr_start_transaction("002_Logon_SDN");


		//////////////////////////////////////////////////////////////////////////////
		// SUBMIT LOGON FORM to http://ilperf125.perflab.com:50000/saml2/idp/sso
		// //////////////////////////////////////////////////////////////////////////

		web_reg_save_param("SAMLResponse",
				"LB=\"SAMLResponse\" value=\"",
				"RB=\"",
				"Ord=1",
				"Search=Body",
				LAST);

		web_reg_save_param("RelayState_3",
				"LB=\"RelayState\" value=\"",
				"RB=\"",
				"Ord=1",
				"Search=Body",
				LAST);

		
		lr_save_string("P700000", "USER_ID");	
		
		status = web_submit_data("submit user to ilperf125", 
			"Action={SAML_REDIRECT_URL}", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			ITEMDATA, 
			"Name=method", "Value=POST", ENDITEM, 
			"Name=j_username", "Value={USER_ID}", ENDITEM, 
			"Name=j_password", "Value=Start123!", ENDITEM, 
			"Name=SAMLRequest", "Value={SAMLRequest_2}", ENDITEM, 
			"Name=RelayState", "Value={RelayState_2}", ENDITEM,
			"Name=j_salt", "Value={j_salt}", ENDITEM,
			"Name=sap.com/initial_post_parameters", "Value={initial_post_parameters}", ENDITEM,
            "Name=uidPasswordLogon","Value=Log On", ENDITEM,
			LAST);
	
		if ( status == LR_FAIL ) 
		{
			lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "error_date");
			lr_error_message(" %s  -  Problem with for user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{user}"));
			lr_vuser_status_message(" %s  -  Problem with user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{user}"));
		}

		lr_vuser_status_message(" Logged in with user[%s]", lr_eval_string("{USER_ID}"));

		//////////////////////////////////////////////////////////////////////////////
		// come back to index with the SAML response 302 moved
		// //////////////////////////////////////////////////////////////////////////
	
		web_set_option("MaxRedirectionDepth", "10", LAST); 
	

		web_reg_save_param("SERVER_JSESSONID",
			"LB/IC=Set-Cookie: JSESSIONID=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);
		
		web_reg_save_param("oucrspalbaihdguwdjbbpejpr",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);
		
		web_reg_save_param("oucrspalbaihdguwdjbbpejpr_anchor",
			"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^_anchor=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST); 
		
		web_reg_save_param("JTENANTSESSIONID_{account}",
			"LB/IC=Set-Cookie: JTENANTSESSIONID_{account}=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);

		lr_save_string("201610050917", "build-timestamp");
		// window["sap-hana-uis-build-timestamp"] = "201512150917"
		/*
		web_reg_save_param("build-timestamp",
			"LB=window[\"sap-hana-uis-build-timestamp\"] = \"",
			"RB=\";",
			"Ord=1",
			"Search=Body",
			LAST);
		*/
		
		
				
		web_submit_data("index 1", 
			"Action=https://{hostname}/sites/adminspace?hc_login",
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			ITEMDATA, 
			"Name=SAMLResponse", "Value={SAMLResponse}", ENDITEM, 
			"Name=RelayState", "Value={RelayState_3}", ENDITEM, 
			LAST);

		lr_end_transaction("002_Logon_SDN" , LR_AUTO);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", LAST); 
		
		web_reg_save_param_ex(
			"ParamName=CSRF-token",
			"LB/IC=x-csrf-token: ", 
			"RB=\r\n", 
			SEARCH_FILTERS,
			"Scope=Headers",
			LAST);
	
		web_add_header("X-CSRF-Token","fetch");
		
		
		lr_save_string("9a28bae7-bf1c-407f-93ea-cd32ac523859", "siteDirectoryID");
		
		web_url("{siteID}_20", 
			"URL=https://{hostname}/fiori/cp/runtime/v1/sites/{siteDirectoryID}?_={timestamp}", 
			"TargetFrame=", 
			"Resource=1", 
			"RecContentType=application/json", 
			"Referer=https://{hostname}/sites/adminspace", 
			"Snapshot=t457.inf", 
			LAST);
		
		lr_think_time(10);

		return 0;

}