Nav_Page9_SocialNetworks()
{
	lr_start_transaction("011_Nav_SocialNetworks_Page");
	web_concurrent_start(NULL);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);

	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
	
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
	
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		LAST);		
	
	web_url("i18n_en.properties_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/i18n/i18n_en.properties?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/plain",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		LAST);
	
	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		LAST);

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/controller/Main.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/js",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);		

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_url("emptyT.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/images/facebook.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
		
	web_url("tile1.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget//images/youtube.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
		
	web_url("tile2.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/socialNetworksWidget/images/twitter.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);		
		
	web_concurrent_end(NULL);
	
	lr_end_transaction("011_Nav_SocialNetworks_Page" , LR_AUTO);
	
	lr_think_time(tt);
			
	return 0;
}

