Login_SDN500()
{
	
		char *userLogin;
		int status = 0 ;		 

		web_global_verification("Text/IC=The SAP Community Network is currently down",  "Fail=Found",  "ID=Gonduras", LAST); 

		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", LAST); 
			
// 		web_reg_save_param("SAML_REDIRECT_URL",
// 					"LB=action=\"",
// 					"RB=\"",
// 					"Ord=1",
// 					"Search=Body",
// 					LAST);
		lr_save_string("https://accounts500.sap.com/saml2/idp/sso/accounts.sap.com", "SAML_REDIRECT_URL");

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
								
		web_reg_save_param("oucrsrzhqitptowviwhfmseri",
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
/*
		web_reg_save_param("X-CSRF-Token",
			"LB=X-CSRF-Token: ",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);
*/
		lr_start_transaction("001_SAML");
		
		///////////////////////////////////////////////////////////////////
		// index html before SAML
		// ///////////////////////////////////////////////////////////////////

		lr_save_string( lr_eval_string ("https://{hostname}/sap/hana/uis/clients/ushell-app/shells/fiori/FioriLaunchpad.html?siteID={site_id}"), "site_url");

		//web_add_header("X-CSRF-Token","fetch");
 
		// launch site
		web_url("launch site", 
			"URL={site_url}", 				
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


 		web_reg_save_param("JSESSIONID_SDN500",
 			"LB=Set-Cookie: JSESSIONID=",
 			"RB=;",
 			"Ord=1",
 			"Search=Headers",
 			LAST);

//		web_reg_save_param("JSESSIONID_SDN500",
// 			"LB=jsessionid=",
// 			"RB=\"",
// 			"Ord=1",
// 			"Search=Body",
// 			LAST);

		web_reg_save_param("idpSSOEndpoint",
 			"LB=idpSSOEndpoint\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			LAST);

/*
		web_reg_save_param("ids_500",
			"LB=Set-Cookie: ids_500=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);

		web_reg_save_param("targetUrl",
 			"LB=targetUrl\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			LAST);

		web_reg_save_param("sourceUrl",
 			"LB=sourceUrl\" value=\"",
 			"RB=\"",
 			"Ord=1",
 			"Search=All",
 			LAST);
*/
		web_reg_save_param("loginXSRF",
			"LB=\"loginXSRF\" value=\"",
			"RB=\"",
			"Ord=1",
			"Search=Body",
			LAST);

		web_reg_save_param("Accounts500_Response",
 			"LB=",
 			"RB=",
 			"Ord=1",
 			"Search=All",
 			LAST);


		//web_add_header("X-CSRF-Token","{X-CSRF-Token}");
		
			status = web_submit_data("redirected to https://accounts500.sap.com/saml2/idp/sso/accounts.sap.com", 
						"Action={SAML_REDIRECT_URL}", 
						"Method=POST", 
						"RecContentType=application/x-www-form-urlencoded", 
						"Referer={site_url}", 
						"Snapshot=t2.inf", 
						"Mode=HTTP", 
						ITEMDATA, 
						"Name=SAMLRequest", "Value={SAMLRequest}", ENDITEM, 
						"Name=RelayState", "Value={RelayState}", ENDITEM, 
						LAST);

			if ( status == LR_FAIL ) 
			{
				lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "error_date");
				lr_error_message(" %s  -  Response for accounts 500 request %s", lr_eval_string("{error_date}") , lr_eval_string("{Accounts500_Response}"));
				lr_exit(LR_EXIT_VUSER, LR_FAIL);
			}
//		}

		lr_end_transaction("001_SAML" , LR_AUTO);
		
		lr_think_time(tt);
		
		
		lr_start_transaction("002_Logon_SDN");


		//////////////////////////////////////////////////////////////////////////////
		// SUBMIT LOGON FORM to accounts500
		// //////////////////////////////////////////////////////////////////////////

		web_reg_save_param("SAMLResponse",
				"LB=\"SAMLResponse\" value='",
				"RB='",
				"Ord=1",
				"Search=Body",
				LAST);

		web_reg_save_param("RelayState_3",
				"LB=\"RelayState\" value='",
				"RB='",
				"Ord=1",
				"Search=Body",
				LAST);
/*
		web_reg_save_param("IDP_J_COOKIE",
					"LB/IC=Set-Cookie: IDP_J_COOKIE=",
					"RB=;",
					"Ord=1",
					"Search=Headers",
					LAST);
*/
		//web_add_header("XSRF_COOKIE","{loginXSRF}");
		

		status = web_submit_data("submit user to accounts.sap.com/saml2/idp/sso/accounts.sap.com", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=text/html", 
					"Referer={SAML_REDIRECT_URL}", 
					"Mode=HTTP", 
					ITEMDATA, 
					"Name=_rememberme", "Value=on", ENDITEM, 
					"Name=idpSSOEndpoint", "Value={idpSSOEndpoint}", ENDITEM,
					"Name=j_password", "Value=Start123!", ENDITEM, 
					"Name=j_username", "Value={{USER_ID}}", ENDITEM, 
					"Name=loginXSRF", "Value={loginXSRF}", ENDITEM,
					"Name=method", "Value=POST", ENDITEM, 
					"Name=overlayOnIds", "Value=", ENDITEM, 
					"Name=RelayState", "Value={RelayState_2}", ENDITEM, 
					"Name=SAMLRequest", "Value={SAMLRequest_2}", ENDITEM, 
					"Name=targetUrl", "Value=", ENDITEM, 
					"Name=sourceUrl", "Value=", ENDITEM,
					LAST);
		

		if ( status == LR_FAIL ) 
		{
			lr_save_datetime("%B %d %Y at %H:%M", DATE_NOW, "error_date");
			lr_error_message(" %s  -  Problem with accounts 500 for user[%s]", lr_eval_string("{error_date}") , lr_eval_string("{viewer_id}"));
			lr_vuser_status_message(" %s  -  Problem with accounts 500 for user[%s]", lr_eval_string("{error_date}") , lr_eval_string("{viewer_id}"));
		}

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

		web_submit_data("index 1", 
			"Action={site_url}",
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

		lr_save_string(lr_eval_string("Login user {viewer_id} logged in to site id [{site_id_to_nav}]"),"PRINT_MESSAGE");
		print_message();

		return 0;
}

