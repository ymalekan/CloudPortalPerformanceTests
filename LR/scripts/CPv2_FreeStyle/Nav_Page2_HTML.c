Nav_Page2_HTML()
{
	lr_start_transaction("004_Nav_HTML_Page");
	web_concurrent_start(NULL);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
		
	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/htmlwidget/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);

	web_url("Component.js_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/ecmWidget/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t131.inf",
		LAST);

	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/htmlwidget/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		LAST);

	web_url("ecmview.controller.js_3",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/ecmWidget/view/ecmview.controller.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t133.inf",
		LAST);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	web_add_header("X-CSRF-Token:", lr_eval_string("{CSRF-token}")); 
	web_add_header("x-sap-dont-debug","1");
	web_add_header("Expires","0"); 
	
	web_add_header("Cache-Control","no-cache, no-store, must-revalidate");
	web_add_header("Pragma","no-cache");
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=Albert%20Einstein.html&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);

	web_concurrent_end(NULL);
	
	lr_end_transaction("004_Nav_HTML_Page" , LR_AUTO);
	
	lr_think_time(tt);
			
	return 0;
}
