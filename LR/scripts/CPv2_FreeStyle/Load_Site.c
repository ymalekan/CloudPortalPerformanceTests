Load_Site()
{
	//web_add_auto_header("Accept", "application/json, text/javascript, */*; q=0.01");
	//web_add_header("Accept", "application/json");
	web_add_auto_header("Connection", "keep-alive");

	web_save_timestamp_param("timestamp",LAST);
	
	lr_start_transaction("003_Load_Site");
	web_concurrent_start(NULL);
		
	web_url("core-min-0.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-0.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		LAST);

	web_url("core-min-1.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-1.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		LAST);
	
	
	web_url("core-min-2.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-2.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		LAST);

	web_url("core-min-3.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-3.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		LAST);

		web_url("core-min-0.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-0.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		LAST);

	web_url("core-min-1.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-1.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		LAST);
	
	
	web_url("core-min-2.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-2.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t455.inf", 
		LAST);

	web_url("core-min-3.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-min-3.js.map?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		LAST);
	
	web_url("sap-ui-version.json_6", 
		"URL=https://{ui5_prefix}/sap-ui-version.json?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t456.inf", 
		LAST);
	
	web_reg_save_param_ex(
			"ParamName=CSRF-token",
			"LB/IC=x-csrf-token: ", 
			"RB=\r\n", 
			SEARCH_FILTERS,
			"Scope=Headers",
			LAST);
	
	web_add_header("X-CSRF-Token", 
		"fetch");
		
	web_url("{siteID}_20", 
		"URL=https://{hostUrl}/fiori/cp/runtime/v1/sites/{siteID}?_={timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t457.inf", 
		LAST);
	
	
	if (atoi(lr_eval_string("{iter_num}"))==1){
		//"version": "1.34.9",
		web_reg_save_param("sapui5-sdk-dist-version",
				"LB=\"version\": \"",
				"RB=\",",
				"Ord=1",
				"Search=Body",
				LAST);
	}
	
	web_url("sap-ui-version.json_8", 
		"URL=https://{ui5_prefix}/sap-ui-version.json", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t459.inf", 		LAST);
	
	web_concurrent_end(NULL);
	
	web_concurrent_start(NULL);
	
	web_url("library.css_8", 
		"URL=https://{ui5_prefix}/sap/fiori/themes/sap_bluecrystal/library.css?sap-ui-dist-version={sapui5-sdk-dist-version}",
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t459.inf", 
		LAST);
	
	web_url("library-preload.js_17", 
		"URL=https://{hostUrl}/{heliumVersion}/runtime/sap/hana/uis/flp/library-preload.js.map", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t462.inf", 
		LAST);
	
	web_url("library-preload.json_17", 
		"URL=https://{hostUrl}/{heliumVersion}/cpv2-services/sap/ushell/cpv2/services/library-preload.json", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t462.inf", 
		LAST);
		
	web_url("messagebundle-preload_iw.js_3", 
		"URL=https://{ui5_prefix}/sap/fiori/messagebundle-preload_en.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t464.inf", 
		LAST);

	web_url("Component-preload.js_7", 
		"URL=https://{ui5_prefix}/sap/ushell/components/flp/Component-preload.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t465.inf", 
		LAST);

	web_url("library-parameters.json_8", 
		"URL=https://{ui5_prefix}/sap/fiori/themes/sap_bluecrystal/library-parameters.json?version={sapui5-sdk-dist-version}&sap-ui-dist-version={sapui5-sdk-dist-version}",
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t468.inf", 
		LAST);

	web_url("sap_50x26.png_6", 
		"URL=https://{ui5_prefix}/sap/ui/core/mimes/logo/sap_50x26.png", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t469.inf", 
		LAST);

	web_url("SAP-icons.ttf", 
		"URL=https://{ui5_prefix}/sap/ui/core/themes/base/fonts/SAP-icons.ttf", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/x-font-ttf",
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t470.inf", 
		LAST);

	web_url("Menu.js_5", 
		"URL=https://{ui5_prefix}/sap/ui/unified/Menu.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t471.inf", 
		LAST);

	

	web_url("style.css_11", 
		"URL=https://{hostUrl}/sap.ushell.apps.cpv2MenuPlugin/css/style.css?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t475.inf", 
		LAST);


	web_url("core-ext-light.js_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-ext-light.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t478.inf", 
		LAST);
	
	web_url("core-ext-light.js.map_6", 
		"URL=https://{ui5_prefix}/sap/fiori/core-ext-light.js.map", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t478.inf", 
		LAST);	

	web_url("Component.js_13", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/pageTemplates/BlankPage/Component.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t479.inf", 
		LAST);

	web_url("main.css_5", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/css/main.css?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t480.inf", 
		LAST);

	web_url("Template.view.xml_5", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/pageTemplates/BlankPage/Template.view.xml?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t481.inf", 
		LAST);

	web_url("Template.controller.js_5", 
		"URL=https://{hostUrl}/sap/fiori/portalsitetemplates/blanksite/pageTemplates/BlankPage/Template.controller.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t482.inf", 
		LAST);

	web_url("Widget.js_5",
		"URL=https://{hostUrl}/{heliumVersion}/cpv2-services/sap/ushell/cpv2/services/control/widget/Widget.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		LAST);
	
	web_url("Widget.js_5",
		"URL=https://{hostUrl}/sap.ushell.apps.cpv2MenuPlugin/css/style.css?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		LAST);
	
	web_url("Component-preload_5",
		"URL=https://{hostUrl}/{heliumVersion}/sap.ushell.apps.cpv2MenuPlugin/Component-preload.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		LAST);
	
	web_url("megaMenuControl.js_5",
		"URL=https://{hostUrl}/{heliumVersion}/sap.ushell.apps.cpv2MenuPlugin/horizontalMenu/controls/megaMenuControl.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		LAST);
	
	web_url("megaMenuItem.js_5",
		"URL=https://{hostUrl}/{heliumVersion}/sap.ushell.apps.cpv2MenuPlugin/horizontalMenu/controls/megaMenuItem.js?ts={build-timestamp}", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t483.inf", 
		LAST);

	web_concurrent_end(NULL);
	
	lr_end_transaction("003_Load_Site" , LR_AUTO);
	
	lr_think_time(tt);
	
	return 0;
}
