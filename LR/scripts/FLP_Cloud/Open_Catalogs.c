Open_Catalogs()
{
	
	//https://flpperf5-x664602fe.perf.hcproxy.neo.ondemand.com/sap/hana/uis/server/rest/v2/catalogs?siteId=00000000-0064-0008-0000-100000000000&_=1434018886083
	//https://flpperf5-x664602fe.perf.hcproxy.neo.ondemand.com/sap/hana/uis/odata/uis_catalogs.xsodata/UIS_CATALOGS?$format=json&$filter=TYPE%20eq%20%27REMOTE_CATALOG%27&_=1434018886084

	
	//https://fiorilaunchpad-x664602fe.perf.dispatcher.neo.ondemand.com/sap/hana/uis/odata/uis_catalogs.xsodata/UIS_CATALOGS?$format=json&$filter=TYPE%20eq%20%27REMOTE_CATALOG%27&_=1400998084436

    //https://fiorilaunchpad-x664602fe.perf.dispatcher.neo.ondemand.com/sap/hana/uis/server/rest/v1/catalogs?_=1400998084437

		web_add_auto_header("Accept", "application/json, text/javascript, */*; q=0.01");
		web_add_auto_header("X-Requested-With", "XMLHttpRequest");
		web_add_auto_header("Connection", "keep-alive");


		//750 tile site
		//web_reg_find("Text=Sample Catalog" , LAST);
		
			//64 tile site
		web_reg_find("Text=ContentPackage_8" , LAST);

		lr_start_transaction("02_2_Catalogs_API");

		web_url("Catalogs", 
			"URL=https://{hostname}/fiori/cp/runtime/v1/catalogs?siteId={site_id}&sap-statistics=true&_={timestamp}", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={site_url}", 
			"Snapshot=t91.inf", 
			"Mode=HTTP", 
			LAST);

		lr_end_transaction("02_2_Catalogs_API",LR_AUTO);

		lr_think_time(tt);
			
	return 0;
}
