Create_Site()
{
	/*
	web_reg_save_param_ex(
			"ParamName=CSRF-token",
			"LB/IC=x-csrf-token: ", 
			"RB=\r\n", 
			SEARCH_FILTERS,
			"Scope=Headers",
			LAST);
	
	web_add_header("X-CSRF-Token","fetch");
	//Authorization: Basic aTAyODA2MDpQcmJjbDIzMw==
	//web_add_auto_header("Authorization","Basic aTAyODA2MDpQcmJjbDIzMw==");
	//web_add_header("Suppress-Authentication-Popup","true");
	web_add_header("X-XHR-Logon","accept=\"iframe\"");
	web_add_header("X-Requested-With","XMLHttpRequest");
	
	web_reg_save_param("portalsitetemplates_activeVersion",
		"LB=application\":\"portalsitetemplates\",\"path\":\"blanksiteV2\",\"activeVersion\":\"",
		"RB=\"",
		LAST);
	
	web_url("get_templates", 
		"URL=https://{hostname}/fiori/cp/design/v1/sites/html5/templates?_={timestamp}", 
		"Resource=0",
		"RecContentType=application/json; charset=UTF-8",
		"Referer=https://{hostname}/sites/adminspace", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);
	*/
	//lr_save_string(getSaltedId(buffer, totalNumberOfApps, uuid, ""), "currentSiteID");
	lr_save_string("00000000-0000-0000-0000-000000000750", "currentSiteID");
	lr_save_string("00000000-0000-0000-0000-000000000750", "siteID");
	lr_save_string("Site750", "currentSiteName");
	//lr_save_string("00000000-0000-0000-0000-000000000100", "currentSiteID");
	//lr_save_string("Site100", "currentSiteName");
	
	/*
	web_reg_save_param("siteID",
			"LB={\"status\": \"OK\",\"siteID\":\"",
			"RB=\"}",
			LAST);
	*/
	//web_add_header("X-XHR-Logon","accept=\"iframe\"");
	//web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
	//web_add_header("X-Requested-With","XMLHttpRequest");
	//web_add_header("Accept","application/json, text/javascript, */*; q=0.01");
	
	/*
	web_custom_request("create_site", 
		"URL=https://{hostname}/fiori/cp/design/v1/sites/html5/instance", 
		"Method=PUT", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{hostname}/sites/adminspace", 
		"Snapshot=t99.inf", 
		"Mode=HTTP", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"id\":\"hcp://portalsitetemplates/flp/site.json\",\"siteId\":\"{currentSiteID}\",\"name\":\"{currentSiteName}\",\"description\":\"\",\"thumbnail\":\"portalsitetemplates/flp/preview.png\",\"account\":\"cpci\",\"application\":\"portalsitetemplates\",\"path\":\"flp\",\"activeVersion\":\"{portalsitetemplates_activeVersion}\"}", 
		//"Body={\"id\":\"hcp://portalsitetemplates/flp/site.json\",\"name\":\"{currentSiteName}\",\"description\":\"\",\"thumbnail\":\"portalsitetemplates/flp/preview.png\",\"account\":\"cpci\",\"application\":\"portalsitetemplates\",\"path\":\"flp\",\"activeVersion\":\"{portalsitetemplates_activeVersion}\"}", 
		LAST);
	*/
	/*
	web_url("getSites", 
		"URL=https://{hostname}/fiori/cp/runtime/v1/sites?_={timestamp}", 
		"Resource=0",
		"RecContentType=application/json; charset=UTF-8",
		"Referer=https://{hostname}/sites/adminspace", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);
	*/
	web_url("getSiteAdmin", 
		"URL=https://{hostname}/sites?siteId={siteID}&mode=admin", 
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://{hostname}/sites/adminspace", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);
		
	web_reg_save_param_ex(
		"ParamName=CSRF-token",
		"LB/IC=x-csrf-token: ", 
		"RB=\r\n", 
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);
	
	web_add_header("X-CSRF-Token","fetch");
	
	web_url("getSiteAdminRuntime",
		"URL=https://{hostname}/fiori/cp/runtime/v1/sites/{siteID}/mode/admin?_={timestamp}", 
		"Resource=0",
		"RecContentType=application/json; charset=UTF-8",
		"Referer=https://{hostname}/sites?siteId={siteID}&mode=admin", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);
	
	return 0;
}
