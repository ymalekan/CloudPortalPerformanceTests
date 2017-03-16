Create_SAPGUIapps()
{
	lr_output_message("totalNumberOfApps = %d", totalNumberOfSAPGUIApps);
	for (appCounter=1424 ; appCounter < (totalNumberOfSAPGUIApps+1000) ; appCounter++) {
		
		appBuffer[0] = '\0';
		appId[0] = '\0';
		
		lr_save_int(appCounter, "appID");
		lr_save_string(getSaltedId(appBuffer, appCounter, appId, "SAPGUI_app"), "appUUID");
			
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
			"Body={\"BATCH\":[{\"operation\":\"CREATE\",\"data\":{\"_version\":\"1.3.0\",\"sap.app\":{\"_version\":\"1.3.0\",\"id\":\"{appUUID}\",\"title\":\"ABAP EDITOR{appID}\",\"description\":\"\",\"tags\":{\"keywords\":[\"\"]},\"crossNavigation\":{\"context\":{},\"inbounds\":{\"AccountingClerk{appID}t\":{\"semanticObject\":\"AccountingClerk{appID}\",\"action\":\"t\",\"deviceTypes\":{\"desktop\":true,\"tablet\":true,\"phone\":true},\"title\":\"ABAP EDITOR{appID}\",\"subTitle\":\"SAP GUI app\",\"size\":\"1x1\",\"signature\":{\"parameters\":{},\"additionalParameters\":\"allowed\"}}}},\"destination\":{\"name\":\"ABAP_BACKEND_FOR_DEMO\"}},\"sap.platform.hcp\":{\"_version\":\"1.1.0\",\"appName\":\"\",\"uriNwbc\":\"/ui2/nwbc/~canvas;window=app/transaction/SE38?sap-client=000&sap-theme=sap_bluecrystal\"},\"sap.flp\":{\"_version\":\"1.1.0\",\"type\":\"GUI\",\"config\":{\"skipVariantResolving\":\"\"}},\"sap.ui\":{\"_version\":\"1.3.0\",\"technology\":\"GUI\",\"deviceTypes\":{\"desktop\":true,\"tablet\":true,\"phone\":true}},\"sap.ui5\":{},\"sap.platform.abap\":{\"_version\":\"1.1.0\",\"appName\":\"\",\"uriNwbc\":\"/ui2/nwbc/~canvas;window=app/transaction/SE38?sap-client=000&sap-theme=sap_bluecrystal\"},\"sap.gui\":{\"_version\":\"1.3.0\",\"transaction\":\"SE38\"}}}]}",
			LAST);
		
		web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
		web_add_header("X-Requested-With","XMLHttpRequest");		
	}
		
	return 0;
}
