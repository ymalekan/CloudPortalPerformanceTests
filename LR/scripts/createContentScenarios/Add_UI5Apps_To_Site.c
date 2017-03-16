Add_UI5Apps_To_Site()
{
	web_add_header("X-CSRF-Token","fetch");
	
	web_url("gethtml5Apps",
		"URL=https://{hostname}/fiori/flp/v1/appIndex/html5Apps?_={timestamp}", 
		"Resource=0",
		"RecContentType=application/json; charset=UTF-8",
		"Referer=https://{hostname}/sites?siteId={siteID}&mode=admin", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	lr_output_message("totalNumberOfUI5Apps = %d", totalNumberOfUI5Apps);
	for (appCounter=0 ; appCounter < totalNumberOfUI5Apps ; appCounter++) {
		
		appBuffer[0] = '\0';
		appId[0] = '\0';

		lr_save_int(appCounter, "appID");	
		lr_save_string(lr_eval_string("finapbalancesdisplay{appID}"), "appName");	
		lr_save_string(getSaltedId(appBuffer, appCounter, appId, "UI5_app"), "appUUID");
			
		web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
		web_add_header("X-Requested-With","XMLHttpRequest");
		
		web_custom_request("addApp",
			"URL=https://{hostname}/fiori/cp/design/v1/sites/{siteID}/entities", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/plain", 
			"Referer=https://{hostname}/sites?siteId={siteID}&mode=admin",
			"Snapshot=t49.inf", 
			"Mode=HTTP", 
			"EncType=application/json; charset=UTF-8", 			
			"Body={\"BATCH\":[{\"operation\":\"CREATE\",\"data\":{\"sap.app\":{\"crossNavigation\":{\"context\":{\"sapSite\":{\"value\":\"\"}},\"inbounds\":{\"0\":{\"semanticObject\":\"finapbalancesdisplay{appID}\",\"action\":\"display\",\"tileImplementation\":{\"id\":\"none\"}}}},\"title\":\"finapbalancesdisplay{appID}\",\"id\":\"{appUUID}\",\"_version\":\"1.3.0\"},\"sap.platform.hcp\":{\"uri\":\"/\",\"appName\":\"finapbalancesdisplay{appID}\",\"_version\":\"1.2.0\"},\"sap.flp\":{\"_version\":\"1.1.0\",\"type\":\"UI5\",\"config\":{\"skipVariantResolving\":\"\"}},\"sap.ui\":{\"technology\":\"UI5\",\"_version\":\"1.3.0\"},\"sap.ui5\":{\"componentName\":\"fin.ap.balances.display\",\"_version\":\"1.2.0\"},\"_version\":\"1.3.0\"},\"fetch\":true}]}",
			LAST);
		
		web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
		web_add_header("X-Requested-With","XMLHttpRequest");
		
		web_custom_request("updateApp",
			"URL=https://{hostname}/fiori/cp/design/v1/sites/{siteID}/entities", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/plain", 
			"Referer=https://{hostname}/sites?siteId={siteID}&mode=admin",
			"Snapshot=t49.inf", 
			"Mode=HTTP", 
			"EncType=application/json; charset=UTF-8", 			
			"Body={\"BATCH\":[{\"operation\":\"CREATE\",\"data\":{\"sap.app\":{\"crossNavigation\":{\"context\":{\"sapSite\":{\"value\":\"\"}},\"inbounds\":{\"finapbalancesdisplay{appID}display\":{\"semanticObject\":\"finapbalancesdisplay{appID}\",\"action\":\"display\",\"deviceTypes\":{\"desktop\":true,\"tablet\":true,\"phone\":true},\"title\":\"finapbalancesdisplay{appID}\",\"subTitle\":\"fin test app\",\"size\":\"1x1\",\"signature\":{\"parameters\":{},\"additionalParameters\":\"allowed\"}}}},\"title\":\"finapbalancesdisplay{appID}\",\"id\":\"{appUUID}\",\"_version\":\"1.3.0\",\"i18n\":\"i18n/{appUUID}.properties\",\"tags\":{\"keywords\":[\"\"]}},\"sap.platform.hcp\":{\"uri\":\"/\",\"appName\":\"finapbalancesdisplay{appID}\",\"_version\":\"1.2.0\"},\"sap.flp\":{\"_version\":\"1.1.0\",\"type\":\"UI5\",\"config\":{\"skipVariantResolving\":\"\"}},\"sap.ui\":{\"technology\":\"UI5\",\"_version\":\"1.3.0\",\"deviceTypes\":{\"desktop\":true,\"tablet\":true,\"phone\":true}},\"sap.ui5\":{\"componentName\":\"fin.ap.balances.display\",\"_version\":\"1.2.0\"},\"_version\":\"1.3.0\",\"sap.fiori\":{\"registrationIds\":[]}}}]}",
			LAST);
	}
		
	return 0;
}
