Login_EP()
{
		char *userLogin;
		int status = 0 ;		 


		lr_save_string("http://10.26.156.125:50000/saml2/idp/sso", "SAML_REDIRECT_URL");		
		
		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", LAST); 
			
		web_url("launch site", 
			"URL=https://{hostUrl}/sites/herug20171479124548905", 				
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
			"URL=https://{hostUrl}/sites/herug20171479124548905&hc_login", 				
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


		status = web_submit_data("submit user to ilperf125", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"RecContentType=application/x-www-form-urlencoded", 
					"Referer=https://{hostUrl}/sites/herug20171479124548905", 
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

		
		lr_save_string(lr_eval_string("P700{user}"), "USER_ID");	
		//lr_save_string("P700000", "USER_ID");	
		
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
			lr_error_message(" %s  -  Problem with for user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{USER_ID}"));
			lr_vuser_status_message(" %s  -  Problem with user[%s]", lr_eval_string("{error_date}"), lr_eval_string("{USER_ID}"));
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

		// window["sap-hana-uis-build-timestamp"] = '201609250946';
		web_reg_save_param("build-timestamp",
			"LB=window[\"sap-hana-uis-build-timestamp\"] = \'",
			"RB=\';",
			"Ord=1",
			"Search=Body",
			LAST);
		
		//  window["sap-hana-uis-build-version"] = 'cloud/flp/3.18.0';
			web_reg_save_param("heliumVersion",
				"LB=window[\"sap-hana-uis-build-version\"] = \'",
				"RB=\';",
				"Ord=1",
				"Search=Body",
				LAST);
			
		
		if (use_CDN ==0){
			
			//ui5InnovationVersion: '1.38.8',
			web_reg_save_param("ui5InnovationVersion",
				"LB=ui5InnovationVersion: \'",
				"RB=\',",
				"Ord=1",
				"Search=Body",
				LAST);
		}else{ 
			// siteUi5VersionNumber: '1.36.6',
			web_reg_save_param("siteUi5VersionNumber",
				"LB=siteUi5VersionNumber: \'",
				"RB=\',",
				"Ord=1",
				"Search=Body",
				LAST);
		}
				
		web_submit_data("index 1", 
			"Action=https://{hostUrl}/sites/herug20171479124548905&hc_login",
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={SAML_REDIRECT_URL}", 
			"Mode=HTTP", 
			ITEMDATA, 
			"Name=SAMLResponse", "Value={SAMLResponse}", ENDITEM, 
			"Name=RelayState", "Value={RelayState_3}", ENDITEM, 
			LAST);

		if (use_CDN==1){
			lr_save_string(lr_eval_string("{ui5_server}/{siteUi5VersionNumber}/resources"), "ui5_prefix");
		}else{ 
			lr_save_string(lr_eval_string("{hostUrl}/{heliumVersion}/sap/ui5/1/innovation/resources"), "ui5_prefix");			
			//lr_save_string(lr_eval_string("{hostUrl}/{heliumVersion}/sap/ui5/1/{ui5InnovationVersion}/resources"), "ui5_prefix");			
		} 
		
		lr_end_transaction("002_Logon_SDN" , LR_AUTO);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", LAST); 

		lr_save_string(lr_eval_string("Login user {USER_ID} logged in to site id [{siteID}]"),"PRINT_MESSAGE");
		
		print_message();
		
		lr_think_time(10);

		return 0;

}