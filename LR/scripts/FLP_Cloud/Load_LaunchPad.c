Load_LaunchPad()
{
	int i = 0;
	web_add_auto_header("Accept", "application/json, text/javascript, */*; q=0.01");
	web_add_auto_header("X-Requested-With", "XMLHttpRequest");
	web_add_auto_header("Connection", "keep-alive");


	web_add_auto_header("oucrstlqawumntvfithbntpyv", "{oucrstlqawumntvfithbntpyv}");
	



	lr_start_transaction("03_Load_Launchpad");

		if (use_hcproxy==1)
		{
			Static_Content_Part_1();
		}
		
	
		//for(i=0;i<30;i++)
		//{
		
		
		//750 tile site
		//web_reg_find("Text=appsOrder" , LAST);
		
		//64 tile site
		web_reg_find("Text=pagesOrder" , LAST);
		
		if (use_translation==1){
			//web_reg_find("Text=TILE0000-WDA0-0000-0000-000000000000-000000000037" , LAST);		
			lr_vuser_status_message(" Use locale=[%s]", lr_eval_string("{locale}"));			
		}else {
			//web_reg_find("Text=TILE0000-WDA0-0000-0000-000000000000-000000000037" , LAST);
		}

		lr_start_sub_transaction("031_Sites_API" ,"03_Load_Launchpad");

			web_url("Sites API", 
				"URL=https://{hostname}/fiori/cp/runtime/v1/sites/{site_id}?sap-statistics=true", //?_={timestamp}",
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={site_url}", 
				"Snapshot=t91.inf", 
				"Mode=HTTP", 
				LAST);
	
		lr_end_sub_transaction("031_Sites_API", LR_AUTO );
	
		//}
	
		
		if (use_hcproxy==1)
		{
			Static_Content_Part_2();
		}

		/*
		lr_save_datetime("Tomorrow is %B %d %Y", DATE_NOW, "Curr_Date"); 
		//lr_output_message(lr_eval_string("{next}"));
	
		lr_start_transaction("01_2_Properties_REST_API");
	
			web_custom_request("properties REST dup", 
				"URL=https://{hostname}/sap/hana/uis/server/rest/v2/user/sites/sap.hana.uis.content%7CHANAHomePage10/properties/%7BPROPID%7D",                   
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={site_referer}", 
				"Snapshot=t114.inf", 
				"Mode=HTTP", 
				"EncType=application/javascript; charset=UTF-8", 
				"Body={\"personalizedSite\":{\"properties\":[{\"key\":\"ITEM#AppsUsage\"}]}}",
				LAST);
	
			web_custom_request("properties REST dup", 
				"URL=https://{hostname}/sap/hana/uis/server/rest/v2/user/sites/sap.hana.uis.content%7CHANAHomePage10/properties",                   
				"Method=PUT", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={site_referer}", 
				"Snapshot=t114.inf", 
				"Mode=HTTP", 
				"EncType=application/javascript; charset=UTF-8", 
				"Body={\"personalizedSite\":{\"properties\":[{\"key\":\"ITEM#AppsUsage\",\"value\":\"{\\\"recentDay\\\":\\\"{Curr_Date}\\\",\\\"recentAppsUsageMap\\\":{}}\"}]}}",
				LAST);
	
		lr_end_transaction("01_2_dynamic_tile_navigation_API",LR_AUTO);
		*/
	
		if (use_hcproxy==1)
		{
			//App_data();
		}

	lr_end_transaction("03_Load_Launchpad",LR_AUTO);
	

	lr_think_time(tt);

	return 0;
}

Static_Content_Part_1()
{

web_concurrent_start(NULL);

	web_url("uis_fiori.js", 
		"URL=https://{hostname}/{uis_version}/runtime/sap/hana/uis/flp/bootstrap/uis_fiori.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("core-min-0.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-0.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("core-min-1.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-1.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("core-min-2.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-2.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("core-min-3.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/core-min-3.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);


web_concurrent_end(NULL);

return 0;
}

Static_Content_Part_2()
{
	
	web_url("library.preload.json", 
		"URL=https://{hostname}/{uis_version}/runtime/sap/hana/uis/flp/library-preload.json?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
		
	web_url("library.css", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/themes/sap_bluecrystal/library.css?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);	
	
	if (use_translation==1)
	{
		web_url("messagebundle-preload_{locale}.js",
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/fiori/messagebundle-preload_{locale}.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
		
		web_url("Messages.properties", 
		"URL=https://{hostname}//{uis_version}/runtime/sap/hana/uis/flp/resources/resources/Messages_{locale}.properties", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	}else {
		web_url("messagebundle-preload.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/messagebundle-preload.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);	
		
		web_url("Messages.properties", 
		"URL=https://{hostname}/{uis_version}/sap/hana/uis/clients/flp/js/sap/hana/uis/flp/resources/resources/Messages.properties", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	}
	
	web_url("Image.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/m/Image.js?ts=={timestamp}", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	/*	
	web_url("applauncher.chip.xml", 
		"URL=https://{hostname}/sap/hana/uis/clients/flp/external-files/chips/applauncher.chip.xml", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("applauncher_dynamic.chip.xml", 
		"URL=https://{hostname}/sap/hana/uis/clients/flp/external-files/chips/applauncher_dynamic.chip.xml", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	*/
	
	web_url("library-parameters.json", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/resources/sap/fiori/themes/sap_bluecrystal/library-parameters.json?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("core-ext-light.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/fiori/core-ext-light.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
		
	web_url("Component-preload.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ushell/components/flp/Component-preload.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
		
	web_url("flp-controls.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/fiori/flp-controls.js?ts={timestamp}", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
		
	web_url("sap_50x26.png", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ui/core/mimes/logo/sap_50x26.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);

	web_url("SAP-icons.ttf", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ui/core/themes/base/fonts/SAP-icons.ttf", 
		"Resource=1", 
		"RecContentType=font/ttf", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);

	web_url("resources.properties", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ushell/renderers/fiori2/resources/resources.properties", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
		
	web_url("launchpad_favicon.ico", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/resources/sap/ushell/themes/base/img/launchpad_favicon.ico", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);

	web_url("loader.js", 
		"URL=https://{hostname}/{uis_version}/sap/ui5/1/innovation/discovery/all_libs", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);

	return 0;
}

App_data()
{
	
web_concurrent_start(NULL);

	web_url("count1", 
		"URL=https://{hostname}/flp/designer/v1/apps/count?a=a", 
		"Resource=1", 
		"RecContentType=application/json; odata=fullmetadata", 
		"Referer={site_url}", 
		"Snapshot=t52.inf", 
		LAST);
	
	web_url("count2", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?b=b", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);
	
	web_url("count3", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?c=c", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);
	
	web_url("count4", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?d=d", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);
	
	web_url("count5", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?e=e", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);
	
	web_url("count6", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?f=f", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);
	
	web_url("count7", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?g=g", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);	

		web_url("count8", 
			"URL=https://{hostname}/flp/designer/v1/apps/count?h=h", 
			"Resource=1", 
			"RecContentType=application/json; odata=fullmetadata", 
			"Referer={site_url}", 
			"Snapshot=t52.inf", 
			LAST);

web_concurrent_end(NULL);
return 0;
}


