Login_SDN()
{
	
		char *userLogin;
		int status = 0 ;		 

		web_global_verification("Text/IC=The SAP Community Network is currently down",  "Fail=Found",  "ID=Gonduras", LAST); 

		web_set_max_html_param_len("16384");		
		web_set_option("MaxRedirectionDepth", "0", LAST); 
			

		lr_save_string("https://accounts.sap.com/saml2/idp/sso/accounts.sap.com", "SAML_REDIRECT_URL");

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
								
		web_reg_save_param("oucrsmltesrdhxjmwtvioopfy",
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


		lr_start_transaction("01_SAML");
		
		///////////////////////////////////////////////////////////////////
		// index html before SAML
		// ///////////////////////////////////////////////////////////////////

		// TODO: REMOVE DEV=TRUE WHEN POSSIBLE

		lr_save_string( lr_eval_string ("https://{hostname}/sap/hana/uis/clients/ushell-app/shells/fiori/FioriLaunchpad.html?dev=true&siteID={site_id}"), 
		               "site_url");
		
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

		web_reg_save_param("ids",
			"LB=Set-Cookie: ids=",
			"RB=;",
			"Ord=1",
			"Search=Headers",
			LAST);

 		web_reg_save_param("JSESSIONID_SDN",
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
		
		web_reg_save_param("Accounts500_Response",
 			"LB=",
 			"RB=",
 			"Ord=1",
 			"Search=All",
 			LAST);

// 		status = LR_FAIL;
// 		while (status == LR_FAIL)
// 		{
			status = web_submit_data("redirected to {SAML_REDIRECT_URL}", 
						"Action={SAML_REDIRECT_URL}", 
						"Method=POST", 
						"RecContentType=text/html", 
						"Referer={site_url}", 
						"Snapshot=t2.inf", 
						"Mode=HTTP", 
						ITEMDATA, 
						"Name=SAMLRequest", "Value={SAMLRequest}", ENDITEM, 
						"Name=RelayState", "Value={RelayState}", ENDITEM, 
						LAST);

			if ( status == LR_FAIL ) 
			{
				lr_save_string(lr_eval_string("Response for accounts request request {Accounts500_Response}"),"PRINT_MESSAGE");
				print_message();		
				lr_exit(LR_EXIT_VUSER, LR_FAIL);
			}
//		}

		lr_end_transaction("01_SAML" , LR_AUTO);
		
		lr_think_time(tt);
		
		lr_start_transaction("02_Logon_SDN");


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

		web_reg_save_param("IDP_J_COOKIE",
					"LB/IC=Set-Cookie: IDP_J_COOKIE=",
					"RB=;",
					"Ord=1",
					"Search=Headers",
					LAST);


		status = web_submit_data("submit user to accounts.sap.com/saml2/idp/sso/accounts.sap.com", 
					"Action={SAML_REDIRECT_URL}", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=text/html", 
					"Referer={SAML_REDIRECT_URL}", 
					"Mode=HTTP", 
					ITEMDATA, 
					"Name=method", "Value=POST", ENDITEM, 
					"Name=idpSSOEndpoint", "Value={idpSSOEndpoint}", ENDITEM, 
					"Name=j_username", "Value=I046774", ENDITEM, 
					"Name=j_password", "Value=Abcd1234", ENDITEM, 
					"Name=SAMLRequest", "Value={SAMLRequest_2}", ENDITEM, 
					"Name=RelayState", "Value={RelayState_2}", ENDITEM, 
					"Name=targetUrl", "Value={targetUrl}", ENDITEM, 
					"Name=sourceUrl", "Value={sourceUrl}", ENDITEM, 
					LAST);
		

		if ( status == LR_FAIL ) 
		{
			lr_save_string(lr_eval_string("Problem with accounts for user [{viewer_id}]"),"PRINT_MESSAGE");
			print_message();			
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
		
		web_reg_save_param("oucrsmltesrdhxjmwtvioopfy",
					"LB/ALNUMIC=set-cookie: ^^^^^^^^^^^^^^^^^^^^^^^^^=",
					"RB=;",
					"Ord=1",
					"Search=Headers",
					LAST);
		web_reg_save_param("oucrsmltesrdhxjmwtvioopfy_anchor",
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
			EXTRARES,
			//"Url=/sap/bc/ui5_ui5/ui2/ushell/resources/sap/ushell_abap/library-preload.json", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/bootstrap/uis_fiori.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/external-files/css/IconFonts.css", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/external-files/css/flower-standalone.css", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/fiori/core-min-3.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/fiori/core-min-1.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/fiori/core-min-2.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/fiori/core-min-0.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/external-files/ushell-chips-preload.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/fiori/themes/sap_bluecrystal/library.css", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/fiori/messagebundle-preload_en.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/library.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/library.properties", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/library-preload.json", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/themes/sap_bluecrystal/library.css", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/shells/fiori/img/grid.png", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/ushell/adapters/fiori/ContainerAdapter.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/ui5/1/resources/sap/ui/core/themes/sap_bluecrystal/img/bg_white_transparent.png", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/model/UISFioriModel.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/CRUDManager.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/SimpleDeferredsManager.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/model/FioriConverter.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/UISUtils.js", "Referer={site_url}", ENDITEM, 
			//"Url=/sap/hana/uis/clients/ushell-app/HashURLObject.js", "Referer={site_url}", ENDITEM, 
			LAST);
		
		lr_end_transaction("02_Logon_SDN" , LR_AUTO);

		lr_think_time(tt);
		
		web_set_max_html_param_len("1024");
		web_set_option("MaxRedirectionDepth", "10", LAST); 

		lr_save_string(lr_eval_string("Login user {viewer_id} logged in to site id [{site_id}]"),"PRINT_MESSAGE");
		print_message();

		return 0;
}

