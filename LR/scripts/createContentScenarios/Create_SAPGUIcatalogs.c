int appStartingIndex, appEndingIndex;
Create_SAPGUIcatalogs()
{
	lr_output_message("totalNumberOfSAPGUICatalogs = %d", totalNumberOfSAPGUICatalogs);
	for (counter=50 ; counter < totalNumberOfSAPGUICatalogs+50 ; counter++) {
		
		buffer[0] = '\0';
		uuid[0] = '\0';
		
		appsList[0] = '\0';
		tilesList[0] = '\0';
				
		lr_save_int(counter, "index");
		lr_save_string(getSaltedId(buffer, counter, uuid, "SAPGUI_catalog"), "catalogUUID");
		lr_save_string(getSaltedId(buffer, counter, uuid, "SAPGUI_group"), "groupUUID");
	
		appStartingIndex = counter*SAPGUIappsPerCatalog;
		appEndingIndex = (counter+1)*SAPGUIappsPerCatalog;
		
		for (appCounter= appStartingIndex ; appCounter < appEndingIndex ; appCounter++) {

			if( appCounter < totalNumberOfSAPGUIApps){
				
				if (strlen(appsList) >= 1){
					strcat(appsList, ",");
				}
				if (strlen(tilesList) >= 1){
					strcat(tilesList, ",");
				}
				
				lr_save_int(appCounter, "appID");
				lr_save_string(getSaltedId(appBuffer, appCounter, appId, "SAPGUI_app"), "appUUID");
				lr_save_string(getSaltedId(appBuffer, appCounter, appId, "SAPGUI_tile"), "tileUUID");
				
				strcat(appsList, lr_eval_string("{\"namespace\":\"\",\"id\":\"{appUUID}\"}"));
				strcat(tilesList, lr_eval_string("{\"target\":{\"semanticObject\":\"AccountingClerk{appID}\",\"action\":\"t\"},\"id\":\"{tileUUID}\",\"entityType\":\"tile\"}"));
				
				appBuffer[0] = '\0';
				appId[0] = '\0';
			}
		}

		lr_output_message("appsList = %s", appsList);
		lr_save_string(appsList, "assignedApps");
		lr_output_message("tilesList = %s", tilesList);
		lr_save_string(tilesList, "semanticObjects");
		
		
		catalogsList[0] = '\0';
		groupsList[0] = '\0';
		
		strcat(catalogsList, lr_eval_string("{\"operation\":\"CREATE\",\"data\":{\"_version\":\"1.1\",\"identification\":{\"id\":\"{catalogUUID}\",\"title\":\"SAPGUICatalog{index}\",\"description\":\"Performance_Package\",\"entityType\":\"catalog\",\"i18n\":\"i18n/{catalogUUID}.properties\"},\"payload\":{\"appDescriptors\":[{assignedApps}],\"groups\":[{\"namespace\":\"\",\"id\":\"{groupUUID}\"}],\"suggestedRolesAssignment\":[\"SAPGUIRole\"]}}}"));
		lr_output_message("catalogsList = %s", catalogsList);
		strcat(groupsList, lr_eval_string("{\"operation\":\"CREATE\",\"data\":{\"_version\":\"1.0\",\"identification\":{\"id\":\"{groupUUID}\",\"title\":\"SAPGUICGroup{index}\",\"description\":\"Performance_Group\",\"entityType\":\"group\"},\"payload\":{\"locked\":false,\"tags\":[],\"links\":[],\"tiles\":[{semanticObjects}]}}}"));
		lr_output_message("groupsList = %s", groupsList);		
		
		lr_think_time(1);
			
		lr_save_string(groupsList, "fullGroupList");
		lr_save_string(catalogsList, "fullCatalogList");
		
		lr_output_message("BATCH = %s", lr_eval_string("{\"BATCH\":[{fullGroupList},{fullCatalogList}]}"));
		
		web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}"));
		
		web_custom_request("create_catalog_group",
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
				
	}
	
	return 0;
}

