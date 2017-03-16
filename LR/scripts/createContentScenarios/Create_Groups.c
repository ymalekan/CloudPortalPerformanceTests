Create_Groups()
{
/*	appBuffer[0] = '\0';
	appId[0] = '\0';
	groupsList[0] = '\0';
	
	for (groupCounter = 0 ; groupCounter < totalNumberOfGroups ; groupCounter++) {
			
		appsList[0] = '\0';
		groupBuffer[0] = '\0';
		groupId[0] = '\0';

		if (strlen(groupsList) >= 1){
			strcat(groupsList, ",");
		}
	
		lr_save_string(getSaltedId(groupBuffer, groupCounter, groupId, "group"), "groupUUID");
		lr_save_int(groupCounter, "index");
		
		appStartingIndex = groupCounter*appsPerCatalog;
		appEndingIndex = (groupCounter+1)*appsPerCatalog;
		
		for (appCounter = appStartingIndex ; appCounter < appEndingIndex ; appCounter++) {
			
			if (strlen(appsList) >= 1){
				strcat(appsList, ",");
			}
			
			lr_save_int(appCounter, "semanticObjectCounter");
			lr_save_string(getSaltedId(appBuffer, appCounter, appId, "app"), "appUUID");
			strcat(appsList, lr_eval_string("{\"target\":{\"semanticObject\":\"App{appUUID}\",\"action\":\"Display\"},\"id\":\""));
			strcat(appsList, getSaltedId(appBuffer, appCounter, appId, "tile"));
			strcat(appsList, "\",\"entityType\":\"tile\"}");
			
			appBuffer[0] = '\0';
			appId[0] = '\0';			
		}
		
		lr_output_message("appsList = %s", appsList);
		lr_save_string(appsList, "semanticObjects");
			
		lr_think_time(1);
		
		strcat(groupsList, lr_eval_string("{\"operation\":\"CREATE\",\"data\":{\"_version\":\"1.0\",\"identification\":{\"id\":\"{groupUUID}\",\"title\":\"Group{index}\",\"description\":\"Performance_Group\",\"entityType\":\"group\"},\"payload\":{\"locked\":false,\"tags\":[],\"links\":[],\"tiles\":[{semanticObjects}]}}}"));
		lr_output_message("groupsList = %s", groupsList);
		
		lr_think_time(1);	

	}	
	
	lr_save_string(groupsList, "fullGroupList");
	lr_save_string(catalogsList, "fullCatalogList");
	
	lr_output_message("BATCH = %s", lr_eval_string("{\"BATCH\":[{fullGroupList},{fullCatalogList}]}"));
	
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
	
	web_custom_request("create_assign_group",
		"URL=https://{hostname}/fiori/cp/design/v1/sites/{siteID}/entities",
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=https://{hostname}{flpURL}?siteId={siteID}&{adminMode}", 
		"Snapshot=t49.inf", 
		"Mode=HTTP", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"BATCH\":[{fullGroupList},{fullCatalogList}]}",		
		LAST);
*/
	return 0;
}
