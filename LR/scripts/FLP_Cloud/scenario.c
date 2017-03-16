scenario()
{
	
	lr_start_transaction("02_open_catalogs");

	web_add_auto_header("Accept-Language", 
		"en");

	web_add_auto_header("MaxDataServiceVersion", 
		"3.0");

	web_add_auto_header("x-csrf-token",	"{x-csrf-token}");

	web_reg_find("Text=PAGE_BUILDER_PERS" , LAST);
	
	web_url("allCatalogs", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_PERS/Pages('%2FUI2%2FFiori2LaunchpadHome')/allCatalogs?$expand=Chips/ChipBags/ChipProperties&$orderby=id&$filter=type%20eq%20'CATALOG_PAGE'%20or%20type%20eq%20'H'%20or%20type%20eq%20'SM_CATALOG'%20or%20type%20eq%20'REMOTE'", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t76.inf", 
		"Mode=HTTP", 
		LAST);
	
	lr_end_transaction("02_open_catalogs",LR_AUTO);
	fire_count ();
	lr_think_time(tt);
	
	
//instanceId='007O7WORPNAHRI8DXI7ODAFCL'
/*
	web_reg_save_param("instanceId", 
		"LB/IC=instanceId=\'", 
		"RB/IC=\'", 
		"Ord=1", 
		"Search=Body", 
		"RelFrameId=1", 
		LAST);

	
	lr_start_transaction("03_add_tile");

	web_custom_request("PageChipInstances", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_PERS/PageChipInstances", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t77.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"pageId\":\"/UI2/Fiori2LaunchpadHome\",\"instanceId\":\"\",\"chipId\":\"X-SAP-UI2-PAGE:X-SAP-UI2-CATALOGPAGE:ZFF2BCH1CATALOG_001:ZFF2BCH1GADGET_003\",\"title\":\"sasha was here\",\"configuration\":\"\",\"layoutData\":\"\"}", 
		LAST);



	
	


	lr_end_transaction("03_add_tile",LR_AUTO);
	fire_count ();
	lr_think_time(tt);
	

	lr_start_transaction("05_remove_tile");

	web_custom_request("remove tile", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_PERS/PageChipInstances(pageId='%2FUI2%2FFiori2LaunchpadHome',instanceId='{instanceId}')", 
		"Method=DELETE", 
		"Resource=0", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t84.inf", 
		"Mode=HTTP", 
		LAST);
	

	lr_end_transaction("05_remove_tile",LR_AUTO);
	fire_count ();
	lr_think_time(tt);
	*/


	lr_start_transaction("06_refersh_home");

	web_revert_auto_header("MaxDataServiceVersion");

	web_revert_auto_header("X-CSRF-Token");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.8");
	lr_start_sub_transaction("06_1_FioriLaunchpad_html","06_refersh_home");
	web_url("FioriLaunchpad.html_3", 
		"URL={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t87.inf", 
		"Mode=HTTP", 
		LAST);
	lr_end_sub_transaction("06_1_FioriLaunchpad_html",LR_AUTO);

	
	lr_start_sub_transaction("06_2_startup_service","06_refersh_home");
	web_url("start_up_2", 
		"URL={HOST}/sap/bc/ui2/start_up?sap-language=EN&sap-client=100&shellType=FLP&depth=0", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t90.inf", 
		"Mode=HTTP", 
		LAST);
	
	lr_end_sub_transaction("06_2_startup_service",LR_AUTO);

	web_add_header("X-CSRF-Token", 
		"fetch");
	web_reg_find("Text=PAGE_BUILDER_PERS" , LAST);

	lr_start_sub_transaction("06_3_page_sets_API","06_refersh_home");
	web_url("PageSets('%2FUI2%2FFiori2LaunchpadHome')_2", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_PERS/PageSets('%2FUI2%2FFiori2LaunchpadHome')?$expand=Pages/PageChipInstances/Chip/ChipBags/ChipProperties,Pages/PageChipInstances/RemoteCatalog,Pages/PageChipInstances/ChipInstanceBags/ChipInstanceProperties,AssignedPages,DefaultPage", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t91.inf", 
		"Mode=HTTP", 
		LAST);
	
	lr_end_sub_transaction("06_3_page_sets_API",LR_AUTO);
	web_save_timestamp_param("zbb" , LAST);
	
	//lr_start_sub_transaction("06_4_static_chip","06_refersh_home");
	web_url("applauncher.chip.xml_2", 
		"URL={HOST}/sap/bc/ui5_ui5/ui2/ushell/chips/applauncher.chip.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t92.inf", 
		"Mode=HTTP", 
		LAST);
	
	//lr_end_sub_transaction("06_4_static_chip",LR_AUTO);

	//lr_start_sub_transaction("06_5_dynamic_chip","06_refersh_home");
	
	web_url("applauncher_dynamic.chip.xml_2", 
		"URL={HOST}/sap/bc/ui5_ui5/ui2/ushell/chips/applauncher_dynamic.chip.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t93.inf", 
		"Mode=HTTP", 
		LAST);
	
//	lr_end_sub_transaction("06_5_dynamic_chip",LR_AUTO);


	lr_end_transaction("06_refersh_home",LR_AUTO);

	fire_count ();
	lr_think_time(tt);
		
	
	
	
	return 0;
}

void fire_count (){
	lr_start_transaction("99_count");
	
	web_url("count", 
		"URL={HOST}/sap/opu/odata/UI2/PAGE_BUILDER_CUST/Pages/$count", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t78.inf", 
		LAST);	
	
	lr_end_transaction("99_count",LR_AUTO);

}
