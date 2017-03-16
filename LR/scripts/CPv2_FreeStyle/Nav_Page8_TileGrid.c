Nav_Page8_TileGrid()
{
	lr_start_transaction("010_Nav_TileGrid_Page");
	web_concurrent_start(NULL);

	web_add_header("X-Requested-With","XMLHttpRequest");
	web_add_header("X-XHR-Logon","accept=\"iframe\""); 
	

	web_url("Component.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/Component.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);

	web_url("Component-preload.js_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/Component-preload.js?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
	
	web_url("manifest.json_2",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/manifest.json?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/json",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
	
	web_url("style.css",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/css/style.css?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		LAST);		
	
	web_url("view/Widget.view.xml",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/view/Main.view.xml?ts={build-timestamp}",
		"Resource=1",
		"RecContentType=application/xml",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t132.inf",
		LAST);

	web_url("Widget.controller.js",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/controller/Main.controller.js?ts={build-timestamp}",
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
	
	web_custom_request("{siteID}_4", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=Tile_Grid_Page_Tile_Grid_1483878561915.html&isRuntime=truee", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);
	
	web_custom_request("{siteID}_5", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);

	web_custom_request("{siteID}_6", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);


	web_custom_request("{siteID}_7", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);

	web_custom_request("{siteID}_8", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);

	web_custom_request("{siteID}_9", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);


	web_custom_request("{siteID}_10", 
		"URL=https://{hostUrl}/fiori/portal/v2/ecm/document/{siteID}?documentName=..%2fsap%2ffiori&isRuntime=true", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://{hostUrl}/sites?siteId={siteID}", 
		"Snapshot=t139.inf", 
		"EncType=application/json", 
		LAST);
		
	web_url("emptyT.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/templates/images/emptyT.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
		
	web_url("tile1.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/templates/images/tile1.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);
		
	web_url("tile2.png",
		"URL=https://{hostUrl}/sap/fiori/portalapptemplates/rtewidget/widgets/tilegrid/templates/images/tile2.png",
		"Resource=1",
		"RecContentType=image/*",
		"Referer=https://{hostUrl}/sites?siteId={siteID}",
		"Snapshot=t130.inf",
		LAST);		
		
	web_concurrent_end(NULL);
	
	lr_end_transaction("010_Nav_TileGrid_Page" , LR_AUTO);
	
	lr_think_time(tt);
			
	return 0;
}

