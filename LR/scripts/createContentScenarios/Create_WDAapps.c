Create_WDAapps()
{
	lr_output_message("totalNumberOfApps = %d", totalNumberOfWDAApps);
	for (appCounter=1000 ; appCounter < (totalNumberOfWDAApps+1000) ; appCounter++) {
		
		appBuffer[0] = '\0';
		appId[0] = '\0';
			
		lr_save_int(appCounter, "appID");
		lr_save_string(getSaltedId(appBuffer, appCounter, appId, "WDA_app"), "appUUID");
			
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
			"Body={\"BATCH\":[{\"operation\":\"CREATE\",\"data\":{\"_version\":\"1.3.0\",\"sap.app\":{\"_version\":\"1.3.0\",\"id\":\"{appUUID}\",\"title\":\"Othello{appID}\",\"description\":\"\",\"tags\":{\"keywords\":[\"\"]},\"crossNavigation\":{\"context\":{},\"inbounds\":{\"Othello{appID}display\":{\"semanticObject\":\"Othello{appID}\",\"action\":\"display\",\"deviceTypes\":{\"desktop\":true,\"tablet\":true,\"phone\":true},\"title\":\"Othello{appID}\",\"subTitle\":\"WDA app\",\"size\":\"1x1\",\"signature\":{\"parameters\":{},\"additionalParameters\":\"allowed\"}}}},\"destination\":{\"name\":\"ABAP_BACKEND_FOR_DEMO\"}},\"sap.platform.hcp\":{\"_version\":\"1.1.0\",\"appName\":\"\",\"uriNwbc\":\"/ui2/nwbc/~canvas;window=app/wda/OTHELLO/?sap-client=000&sap-theme=sap_bluecrystal\"},\"sap.flp\":{\"_version\":\"1.1.0\",\"type\":\"WDA\",\"config\":{\"skipVariantResolving\":\"\"}},\"sap.ui\":{\"_version\":\"1.3.0\",\"technology\":\"WDA\",\"deviceTypes\":{\"desktop\":true,\"tablet\":true,\"phone\":true}},\"sap.ui5\":{},\"sap.platform.abap\":{\"_version\":\"1.1.0\",\"appName\":\"\",\"uriNwbc\":\"/ui2/nwbc/~canvas;window=app/wda/OTHELLO/?sap-client=000&sap-theme=sap_bluecrystal\"},\"sap.wda\":{\"_version\":\"1.3.0\",\"applicationId\":\"OTHELLO\"}}}]}",
			LAST);
		
		web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
		web_add_header("X-Requested-With","XMLHttpRequest");		
	}
		
	return 0;
}
